#include <iostream>
#include <thread>
#include <algorithm>
#include <fstream>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"
#include <future>

#define THREADS 10
#define RUNTIME 800000
#define INSTANCES 1000

double helperGenerationSizeConstIterations1000(Instance instance, unsigned size) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
//    std::clock_t timeStart = std::clock();
//    while (std::clock() < timeStart + 2000) {
    for (int i = 0; i < 1000; ++i) {
        pool.randomize();
        pool.breed();
        pool.mutate();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

void GenerationSizeConstIterations1000() {
    std::ofstream file("OKf/GenerationSize.txt", std::ofstream::app);

    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned generationSize = 2; generationSize < 10000; generationSize *= 2) {
        double result = 0; // average percentage increase
        for (unsigned k = 0; k < INSTANCES / THREADS; k++) {
            for (unsigned i = 0; i < THREADS; ++i) {
                futures[k * THREADS + i] = std::async(std::launch::async, helperGenerationSizeConstIterations1000,
                                                      instances[k * THREADS + i], generationSize);
            }
            for (unsigned i = 0; i < THREADS; ++i) {
                result += futures[k * THREADS + i].get();
            }
        }
//        std::cout << avgPercentImprvSum << std::endl;
        file << generationSize << " " << result / (INSTANCES / 100.0) << std::endl;
        std::cout << generationSize << " " << result / (INSTANCES / 100.0) << std::endl;
        file.flush();
    }
    file.close();
}

double helperGenerationSizeConstCPUTicks15000(Instance instance, unsigned size) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + 15000 * THREADS) {
//    for (int i = 0; i < 1000; ++i) {
        pool.randomize();
        pool.breed();
        pool.mutate();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

void GenerationSizeConstCPUTicks15000() {
    std::ofstream file("OKf/GenerationSizeConstCPUTicks15000.txt", std::ofstream::app);

    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned generationSize = 2; generationSize < 10000; generationSize *= 2) {
        double result = 0; // average percentage increase
        for (unsigned k = 0; k < INSTANCES / THREADS; k++) {
            for (unsigned i = 0; i < THREADS; ++i) {
                futures[k * THREADS + i] = std::async(std::launch::async, helperGenerationSizeConstCPUTicks15000,
                                                      instances[k * THREADS + i], generationSize);
            }
            for (unsigned i = 0; i < THREADS; ++i) {
                result += futures[k * THREADS + i].get();
            }
        }
//        std::cout << avgPercentImprvSum << std::endl;
        file << generationSize << " " << result / (INSTANCES / 100.0) << std::endl;
        std::cout << generationSize << " " << result / (INSTANCES / 100.0) << std::endl;
        file.flush();
    }
    file.close();
}

double helperGenerationSizeConstCPUTimeMutationOnly(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.mutate();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeRandomCrossover(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.randomize();
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeRankingCrossover(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeRandomizedRankingCrossover(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.randomizedRanking(size / 10, size / 10);
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeMutationRandomCrossover(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.mutate();
        pool.randomize();
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeMutationRankingCrossover(Instance instance, unsigned size, unsigned clocks) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + clocks) {
//    for (int i = 0; i < 1000; ++i) {
        pool.mutate();
        pool.ranking();
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

double helperGenerationSizeConstCPUTimeMutationRandomizedRankingCrossover(Instance instance, unsigned size) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + RUNTIME * THREADS) {
//    for (int i = 0; i < 1000; ++i) {
        pool.mutate();
        pool.randomizedRanking(size / 10, size / 10);
        pool.breed();
        pool.ranking();
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

void GenerationSizeConstCPUTimeDifferentApproaches() {
    std::ofstream file("OKf/randomizedRankingForCrossover.txt", std::ofstream::app);
    file
            << "CPU Clocks,GenerationSize,MutationOnly,RandomCrossover,RankingCrossover,RandomizedCrossover;MutationRandomCrossover;MutationRankingCrossover;MutationRandomizedRankingCrossover"
            << std::endl;
    std::future<double> futures[7][INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned clocks = CLOCKS_PER_SEC * 30; clocks < CLOCKS_PER_SEC * 30 + 2; clocks *= 2) {
        for (unsigned generationSize = 2; generationSize < 2050; generationSize *= 2) {
            double result[7] = {0}; // average percentage increase
            for (unsigned k = 0; k < INSTANCES; k++) {
                futures[0][k] = std::async(std::launch::async, helperGenerationSizeConstCPUTimeMutationOnly,
                                           instances[k], generationSize, clocks);
                futures[1][k] = std::async(std::launch::async, helperGenerationSizeConstCPUTimeRandomCrossover,
                                           instances[k], generationSize, clocks);
                futures[2][k] = std::async(std::launch::async, helperGenerationSizeConstCPUTimeRankingCrossover,
                                           instances[k], generationSize, clocks);
                futures[3][k] = std::async(std::launch::async,
                                           helperGenerationSizeConstCPUTimeRandomizedRankingCrossover, instances[k],
                                           generationSize, clocks);
                futures[4][k] = std::async(std::launch::async, helperGenerationSizeConstCPUTimeMutationRandomCrossover,
                                           instances[k], generationSize, clocks);
                futures[5][k] = std::async(std::launch::async, helperGenerationSizeConstCPUTimeMutationRankingCrossover,
                                           instances[k], generationSize, clocks);
                futures[6][k] = std::async(std::launch::async,
                                           helperGenerationSizeConstCPUTimeMutationRandomizedRankingCrossover,
                                           instances[k], generationSize); //TODO chang to reuse

                result[0] += futures[0][k].get();
                result[1] += futures[1][k].get();
                result[2] += futures[2][k].get();
                result[3] += futures[3][k].get();
                result[4] += futures[4][k].get();
                result[5] += futures[5][k].get();
                result[6] += futures[6][k].get();
            }
            //        std::cout << avgPercentImprvSum << std::endl;

            file << clocks << "," << generationSize << "," << result[0] / (INSTANCES / 100.0) << ","
                 << result[1] / (INSTANCES / 100.0) << "," << result[2] / (INSTANCES / 100.0) << ","
                 << result[3] / (INSTANCES / 100.0) << "," << result[4] / (INSTANCES / 100.0) << ","
                 << result[5] / (INSTANCES / 100.0) << "," << result[6] / (INSTANCES / 100.0) << "," << std::endl;
            std::cout << clocks << "," << generationSize << "," << result[0] / (INSTANCES / 100.0) << ","
                      << result[1] / (INSTANCES / 100.0) << "," << result[2] / (INSTANCES / 100.0) << ","
                      << result[3] / (INSTANCES / 100.0) << "," << result[4] / (INSTANCES / 100.0) << ","
                      << result[5] / (INSTANCES / 100.0) << "," << result[6] / (INSTANCES / 100.0) << "," << std::endl;
            file.flush();
        }
    }
    file.close();
}

void SpecificGenerationSize() {
    std::ofstream file("OKf/SpecificGenereationSize.txt", std::ofstream::app);
    file
            << "CPU Clocks,GenerationSize,MutationOnly,RandomCrossover,RankingCrossover,RandomizedCrossover;MutationRandomCrossover;MutationRankingCrossover;MutationRandomizedRankingCrossover"
            << std::endl;
    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned generationSize = 1; generationSize < 10; generationSize++) {
        double result = 0; // average percentage increase
        for (unsigned k = 0; k < INSTANCES / THREADS; k++) {

            for (int i = 0; i < THREADS; ++i)
                futures[k * THREADS + i] = std::async(std::launch::async,
                                                      helperGenerationSizeConstCPUTimeMutationRandomizedRankingCrossover,
                                                      instances[k * THREADS + i],
                                                      generationSize);

            for (int i = 0; i < THREADS; ++i)
                result += futures[k * THREADS + i].get();
        }
        //        std::cout << avgPercentImprvSum << std::endl;

        file << generationSize << "," << result / 10.0 << std::endl;
        std::cout << generationSize << "," << result / 10.0 << std::endl;

        file.flush();
    }

    file.close();
}

double helperRandomizedRanking(Instance instance, unsigned p1, unsigned p2) {
    SolutionsPool pool(instance, 4);
    pool.ranking();
    double randomScore = pool[0].getScore();
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + RUNTIME * THREADS) {
//    for (int i = 0; i < 1000; ++i) {
        pool.mutate();
        pool.randomize();
        pool.breed();
        pool.randomizedRanking(p1, p2);
        pool.trimEnd();
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

void RandomizedRanking() {
    std::ofstream file("OKf/RandomizedRankingSelection.txt", std::ofstream::app);
    file << "UntouchedTop,UntouchedEnd,Result" << std::endl;
    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned p1 = 0; p1 < 5; p1++) {
        for (unsigned p2 = 0; p2 < 9; p2++) {
            if (p1 + p2 >= 12) continue;
            double result = 0; // average percentage increase
            for (unsigned k = 0; k < INSTANCES / THREADS; k++) {

                for (int i = 0; i < THREADS; ++i)
                    futures[k * THREADS + i] = std::async(std::launch::async, helperRandomizedRanking,
                                                          instances[k * THREADS + i], p1, p2);

                for (int i = 0; i < THREADS; ++i)
                    result += futures[k * THREADS + i].get();
            }
            file << p1 << "," << p2 << "," << result / (INSTANCES / 100.0) << std::endl;
            std::cout << p1 << "," << p2 << "," << result / (INSTANCES / 100.0) << std::endl;

            file.flush();
        }
    }

    file.close();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    RandomizedRanking();
    return 0;
}
//krzyżowanie then mutacja!!!!!!!.
// rozmnażanie losowe.