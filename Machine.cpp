//
// Created by prance on 04.12.18.
//

#include <algorithm>
#include "Machine.hpp"

Machine::Machine(bool number) : number(number) {}

void Machine::add_maitenance(Maitenance *m) {
    maitenances.push_back(m);
}

Operation *&Machine::operator[](unsigned int x) {
    return operations[x];
}

unsigned int Machine::score() {
    unsigned sum = 0;
    for (auto o: operations) sum += o->getEnd();
    return sum;
}

const std::vector<Maitenance *> &Machine::getMaitenances() const {
    return maitenances;
}

unsigned Machine::getSize() {
    return operations.size();
}

void Machine::sort_maitenances() {
    std::sort(maitenances.begin(), maitenances.end(), [](Maitenance *a, Maitenance *b) { return a->getStartTime() <
            b->getStartTime(); });
}

