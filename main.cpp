#include <iostream>
#include <thread>
#include <algorithm>
#include <fstream>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"
#include <future>

#define THREADS 2

double f(Instance instance, unsigned generationSize) {
    SolutionsPool pool(instance, generationSize);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + 6 * CLOCKS_PER_SEC * THREADS) {
        pool.mutate();
        pool.randomizedRanking(10, 10);
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

int main() {
    std::ofstream file("/home/prance/c/aisd/OK/logGenerationSize_MandB.txt");

    std::future<double> futures[100];
    Instance instances[100];

    for (unsigned generationSize = 1; generationSize < 100; ++generationSize) {
        double avgPercentImprvSum = 0;
        for (unsigned k = 0; k < 100 / THREADS; k++) {
            for (unsigned i = 0; i < THREADS; ++i) {
                futures[k * THREADS + i] = std::async(std::launch::async, f, instances[i], generationSize);
            }
            for (unsigned i = 0; i < THREADS; ++i) {
                avgPercentImprvSum += futures[k * THREADS + i].get();
            }
        }
        file << generationSize << " " << avgPercentImprvSum << std::endl;
        file.flush();
    }
    return 0;
}