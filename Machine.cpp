//
// Created by prance on 04.12.18.
//

#include "Machine.hpp"

Machine::Machine(bool number) : number(number) {}

void Machine::add_maitenance(Maitenance *m) {
    maitenances.push_back(m);
}

Operation *Machine::operator[](int x) {
    return operations[x];
}

int Machine::score() {
    int sum = 0;
    for (auto o: operations) sum += o->getEnd();
    return sum;
}

const std::vector<Maitenance *> &Machine::getMaitenances() const {
    return maitenances;
}

