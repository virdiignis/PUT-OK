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

double f(Instance instance) {
    SolutionsPool pool(instance, 50);
    pool.ranking();
    double randomScore = pool[0].getScore();
//    unsigned i = 0;
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
//        pool.mutate();
//    for (unsigned i = 0; i < 100; ++i) {
        pool.mutate();
        pool.randomizedRanking(10, 10);
        pool.breed();
        pool.ranking();
        pool.trimEnd();
//        ++i;
    }
//    std::cout << i << std::endl;
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double g(Instance instance) {
    SolutionsPool pool(instance, 50);
    pool.ranking();
    double randomScore = pool[0].getScore();
//    unsigned i = 0;
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + RUNTIME * CLOCKS_PER_SEC * THREADS) {
//        pool.mutate();
//    for (unsigned i = 0; i < 100; ++i) {

        pool.randomizedRanking(10, 10);
        pool.breed();
        pool.mutate();
        pool.ranking();
        pool.trimEnd();
//        ++i;
    }
//    std::cout << i << std::endl;
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
//    std::ofstream file("/home/prance/CLionProjects/PUT-OK/logBreedImprvOverRuns.txt", std::ofstream::app);
//
//    std::future<double> futures[1000];
//    Instance instances[100];
////    for(unsigned i = 0; i< 100 ; i++) instances[i] = Instance();
//
////    for (unsigned unrandomedTop = 0; unrandomedTop < 100; unrandomedTop++) {
//    double Rf = 0, Rg = 0;
//    for (unsigned k = 0; k < 100 / THREADS; k++) {
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
//    file << Rf << " " << Rg / 10.0 << std::endl;
//    std::cout << Rf << " " << Rg << std::endl;
//    file.flush();
//
//    file.close();

    Instance i;
    std::cout << "Dupa";
    Solution s(&i);
    std::cout << "Dupa2";
    s.toFile();
    return 0;
}
