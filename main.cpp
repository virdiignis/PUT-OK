#include <iostream>
#include <thread>
#include <algorithm>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"


int main() {
    Instance i = Instance();
    i.toFile(1, "/home/prance/c/aisd/OK/ins1.txt");
    SolutionsPool p(i);
    p.createSolutions(1000);
    for (int d = 0; d < 100; d++) {
        p.mutate();
        p.randomizedRanking();
        p.trimEnd();
    }
    SolutionsPool q(i);
    q.createSolutions(100);
    for (int d = 0; d < 1000; d++) {
        q.mutate();
        q.randomizedRanking();
        q.trimEnd();
    }
//    std::swap(p[0], p[1]);
    std::cout << p[0].getScore() << "\n" << q[0].getScore();


    return 0;
}