//
// Created by prance on 27.12.18.
//

#include <set>
#include <algorithm>
#include <iostream>
#include "Solution.hpp"

Solution::Solution(Instance &instance) {
    this->instance = &instance;
    machine1 = instance.getMachine1();
    machine2 = instance.getMachine2();
    bool ops1[TASKS_NO] = {false}, ops2[TASKS_NO] = {false};
    std::uniform_int_distribution<unsigned> operationsRange = std::uniform_int_distribution<unsigned>(0, TASKS_NO - 1);
    unsigned n = 0, m1 = 0, m2 = 0;
    std::vector<unsigned> order1, order2;
    for (unsigned j = 0; j < TASKS_NO; ++j) {
        order1.push_back(j);
        order2.push_back(j);
    }
    std::shuffle(order1.begin(), order1.end(), this->instance->generator);
    std::shuffle(order2.begin(), order2.end(), this->instance->generator);
    while (!order1.empty() || !order2.empty()) {
        auto it = order1.begin();
        while (it != order1.end()) {
            n = *it;
            if (!instance.getTasks()[n]->m1()->isSecond() && !ops1[n]) {
                ops1[n] = true;
                machine1[m1++] = instance.getTasks()[n]->m1();
                order1.erase(it);
                break;
            } else if (instance.getTasks()[n]->m1()->isSecond() && ((ops1[n] && !ops2[n]) || m1 == 48)) {
                ops2[n] = true;
                machine1[m1++] = instance.getTasks()[n]->m1();
                order1.erase(it);
                break;
            }
            it++;
        }
        it = order2.begin();
        while (it != order2.end()) {
            n = *it;
            if (!instance.getTasks()[n]->m2()->isSecond() && !ops1[n]) {
                ops1[n] = true;
                machine2[m2++] = instance.getTasks()[n]->m2();
                order2.erase(it);
                break;
            } else if (instance.getTasks()[n]->m2()->isSecond() && ops1[n] && !ops2[n]) {
                ops2[n] = true;
                machine2[m2++] = instance.getTasks()[n]->m2();
                order2.erase(it);
                break;
            }
            it++;
        }
    }
    calculate();
}

Solution::Solution(const Solution &solution1, const Solution &solution2) {


}

Solution::Solution(const Solution &solution) {
    //copy solution
    this->instance = solution.instance;
    machine1 = solution.machine1;
    machine2 = solution.machine2;
}

void Solution::calculate() {
    for (int i = 0; i < TASKS_NO; ++i) {
        machine1[i]->resetPenalty();
        machine2[i]->resetPenalty();
    }
    unsigned m1 = 0, m2 = 0, lastm1 = 0, lastm2 = 0;
    bool op1s[TASKS_NO] = {false};
    while (m1 < TASKS_NO || m2 < TASKS_NO) {
        while (m1 < TASKS_NO && (!machine1[m1]->isSecond() || op1s[machine1[m1]->getTaskNo()])) {
            auto opm1 = machine1[m1];
            if (!op1s[machine1[m1]->getTaskNo()]) { //means that's first operation
                op1s[machine1[m1]->getTaskNo()] = true;
                if (m1) opm1->setStartTime(std::max(opm1->getReadyTime(), machine1[m1 - 1]->getEnd() + 1));
                else opm1->setStartTime(opm1->getReadyTime());
            } else {
                if (m1)
                    opm1->setStartTime(
                            std::max(machine1[m1 - 1]->getEnd() + 1, opm1->getTask()->other(opm1)->getEnd()+1));
                else opm1->setStartTime(opm1->getTask()->other(opm1)->getEnd()+1);
            }
            for (auto m: machine1.getMaitenances()) {
                if (m->getStartTime() == opm1->getStartTime()) opm1->setStartTime(m->getEnd() + 1);
                if (opm1->getStartTime() < m->getStartTime() && opm1->getEnd() >= m->getStartTime()) opm1->disturbed(m);
            }
            m1++;
        }

        while (m2 < TASKS_NO && (!machine2[m2]->isSecond() || op1s[machine2[m2]->getTaskNo()])) {
            auto opm2 = machine2[m2];
            if (!op1s[machine2[m2]->getTaskNo()]) { //means that's first operation
                op1s[machine2[m2]->getTaskNo()] = true;
                if (m2) opm2->setStartTime(std::max(opm2->getReadyTime(), machine2[m2 - 1]->getEnd() + 1));
                else opm2->setStartTime(opm2->getReadyTime());
            } else {
                if (m2)
                    opm2->setStartTime(
                            std::max(machine2[m2 - 1]->getEnd() + 1, opm2->getTask()->other(opm2)->getEnd() + 1));
                else opm2->setStartTime(opm2->getTask()->other(opm2)->getEnd() + 1);
            }
            m2++;
        }
        if (lastm1 == m1 && lastm2 == m2) throw std::runtime_error("Invalid order of operations");
        lastm1 = m1;
        lastm2 = m2;
    }
}

unsigned Solution::getScore() const {
    return machine1.score() + machine2.score();
}

void Solution::mutate() {
    std::uniform_int_distribution<unsigned> taskNoDist = std::uniform_int_distribution<unsigned>(0, TASKS_NO - 2);
    unsigned i=0;
    while (true) {
        Machine *machine = static_cast<bool>(booleanDist(instance->generator)) ? &machine1 : &machine2;
        const unsigned n = taskNoDist(instance->generator);
        auto opn = (*machine)[n];
        (*machine)[n] = (*machine)[n + 1];
        (*machine)[n + 1] = opn;
        try {
            calculate();
            break;
        }
        catch (std::runtime_error &e) {
            opn = (*machine)[n];
            (*machine)[n] = (*machine)[n + 1];
            (*machine)[n + 1] = opn;
            calculate();
            if(i++ == 100) break;
        }
    }
}

bool Solution::operator<(const Solution &rhs) const {
    return getScore() < rhs.getScore();
}

Solution::Solution() {

}
