#include <iostream>
#include <thread>
#include <algorithm>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"


int main() {
    //   i->toFile(1, "/home/prance/c/aisd/OK/ins1.txt");
//    SolutionsPool p(i);
//    p.createSolutions(1000);
//    for (int d = 0; d < 100; d++) {
//        p.mutate();
//        p.randomizedRanking();
//        p.trimEnd();
//    }
//    SolutionsPool q(i);
//    q.createSolutions(100);
//    for (int d = 0; d < 1000; d++) {
//        q.mutate();
//        q.randomizedRanking();
//        q.trimEnd();
//    }
//    std::swap(p[0], p[1]);
//    std::cout << p[0].getScore() << "\n" << q[0].getScore();

    unsigned s = 0;
    for (unsigned l = 0; l < 100; l++) {
        Instance i = Instance();
        SolutionsPool pool(i);
        pool.createSolutions(100);

//        if (c.getScore()< a.getScore() && c.getScore() < b.getScore()) s++;
    }
    std::cout << s / 100000.0;


    return 0;
}