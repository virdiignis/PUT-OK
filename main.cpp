#include <iostream>
#include <thread>
#include <algorithm>
#include <fstream>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"
#include <future>

#define THREADS 8
#define RUNTIME 5

// Mutate then Crossover vs Crossover then Mutate test.
//double f(Instance instance) {
//    SolutionsPool pool(instance, 50);
//    pool.ranking();
//    double randomScore = pool[0].getScore();
////    unsigned i = 0;
//    std::clock_t timeStart = std::clock();
//    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
////        pool.mutate();
////    for (unsigned i = 0; i < 100; ++i) {
//        pool.mutate();
//        pool.randomizedRanking(10, 10);
//        pool.breed();
//        pool.ranking();
//        pool.trimEnd();
////        ++i;
//    }
//    pool[0].toFile(randomScore);
////    std::cout << i << std::endl;
//    return 1.0 - (double) pool[0].getScore() / randomScore;
//}
//
//double g(Instance instance) {
//    SolutionsPool pool(instance, 50);
//    pool.ranking();
//    double randomScore = pool[0].getScore();
////    unsigned i = 0;
//    std::clock_t timeStart = std::clock();
//    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
////        pool.mutate();
////    for (unsigned i = 0; i < 100; ++i) {
//
//        pool.randomizedRanking(10, 10);
//        pool.breed();
//        pool.mutate();
//        pool.ranking();
//        pool.trimEnd();
////        ++i;
//    }
//
//    pool[0].toFile(randomScore);
////    std::cout << i << std::endl;
//    return 1.0 - (double) pool[0].getScore() / randomScore;
//}
//
//int main() {
//    srand(static_cast<unsigned int>(time(nullptr)));
//    std::ofstream file("/home/prance/OK/MtCvsCtM.txt", std::ofstream::app);
//
//    std::future<double> futures[1000];
//    Instance instances[1000];
//    for (auto &instance : instances) instance.toFile();
//
////    for (unsigned unrandomedTop = 0; unrandomedTop < 100; unrandomedTop++) {
//    double Rf = 0, Rg = 0;
//    for (unsigned k = 0; k < 1000 / THREADS; k++) {
//        for (unsigned i = 0; i < THREADS; ++i) {
//            futures[k * THREADS + i] = std::async(std::launch::async, f, instances[k * THREADS + i]);
//        }
//        for (unsigned i = 0; i < THREADS; ++i) {
//            Rf += futures[k * THREADS + i].get();
//        }
//        for (unsigned i = 0; i < THREADS; ++i) {
//            futures[k * THREADS + i] = std::async(std::launch::async, g, instances[k * THREADS + i]);
//        }
//        for (unsigned i = 0; i < THREADS; ++i) {
//            Rg += futures[k * THREADS + i].get();
//        }
//    }
////        std::cout << avgPercentImprvSum << std::endl;
//    file << Rf / 10.0 << " " << Rg / 10.0 << std::endl;
//    std::cout << Rf / 10.0 << " " << Rg / 10.0 << std::endl;
//    file.flush();
//
//    file.close();
//    return 0;
//}

#define INSTANCES 1000

//ranking breed vs random breed
double f(Instance instance, unsigned end) {
    SolutionsPool pool(instance, 50);
    pool.ranking();
    double randomScore = pool[0].getScore();
//    unsigned i = 0;
//    std::clock_t timeStart = std::clock();
//    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
//        pool.mutate();
    for (unsigned i = 0; i < end; ++i) {
        pool.mutate();
//        pool.randomizedRanking(10, 10);
        pool.randomize();
        pool.breed();
        pool.ranking();
        pool.trimEnd();
//        ++i;
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
//    std::cout << i << std::endl;
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

//double g(Instance instance) {
//    SolutionsPool pool(instance, 50);
//    pool.ranking();
//    double randomScore = pool[0].getScore();
////    unsigned i = 0;
//    std::clock_t timeStart = std::clock();
//    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
////        pool.mutate();
////    for (unsigned i = 0; i < 100; ++i) {
//        pool.mutate();
//        pool.randomize();
//        pool.breed();
//        pool.ranking();
//        pool.trimEnd();
////        ++i;
//    }
//    pool[0].toFile();
////    std::cout << i << std::endl;
//    return 1.0 - (double) pool[0].getScore() / randomScore;
//}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::ofstream file("/home/prance/OK/ImprvOverIterations.txt", std::ofstream::app);

    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned end = 1; end < 10000; end *= 2) {
    double Rf = 0, Rg = 0;
        for (unsigned k = 0; k < INSTANCES / THREADS; k++) {
        for (unsigned i = 0; i < THREADS; ++i) {
            futures[k * THREADS + i] = std::async(std::launch::async, f, instances[k * THREADS + i], end);
        }
        for (unsigned i = 0; i < THREADS; ++i) {
            Rf += futures[k * THREADS + i].get();
        }
    }
//        std::cout << avgPercentImprvSum << std::endl;
        file << end << " " << Rf / 10.0 << std::endl;
        std::cout << end << " " << Rf / 10.0 << std::endl;
    file.flush();
    }
    file.close();
    return 0;
}
//krzyżowanie then mutacja!!!!!!!.
// rozmnażanie losowe.