//
// Created by prance on 04.12.18.
//

#include <algorithm>
#include "Machine.hpp"

Machine::Machine(bool number) : number(number) {}

void Machine::addMaitenance(Maitenance *m) {
    maitenances.push_back(m);
}

Operation *&Machine::operator[](unsigned int x) {
    return operations[x];
}

unsigned int Machine::score() const {
    unsigned sum = 0;
    for (const auto &o: operations) sum += o->getEnd();
    return sum;
}

const std::vector<Maitenance *> &Machine::getMaitenances() const {
    return maitenances;
}

unsigned Machine::getSize() {
    return operations.size();
}

void Machine::sortMaitenances() {
    std::sort(maitenances.begin(), maitenances.end(), [](Maitenance *a, Maitenance *b) { return a->getStartTime() <
            b->getStartTime(); });
}

unsigned Machine::getIndex(Operation *ops) {
    unsigned i = 0;
    for (auto &op: operations) {
        if (op == ops) return i;
        else i++;
    }
    throw std::runtime_error("Indexed operation not in machine.");
}

void Machine::setMaitenances(const std::vector<Maitenance *> &maitenances) {
    Machine::maitenances = maitenances;
}

unsigned Machine::getEnd() {
    return operations[operations.size() - 1]->getEnd();
}
