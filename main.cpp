#include <iostream>
#include <thread>
#include <algorithm>
#include <fstream>
#include "Instance.hpp"
#include "Solution.hpp"
#include "SolutionsPool.hpp"
#include <future>

#define THREADS 4
#define RUNTIME 5
#define INSTANCES 1000

double helperGenerationSize(Instance instance, unsigned size) {
    SolutionsPool pool(instance, size);
    pool.ranking();
    double randomScore = pool[0].getScore();
    unsigned i = 0;
    std::clock_t timeStart = std::clock();
    while (std::clock() < timeStart + 2000) {
        pool.randomize();
        pool.breed();
        pool.mutate();
        pool.ranking();
        pool.trimEnd();
        ++i;
    }
    pool[0].toFile(static_cast<unsigned int>(randomScore));
    std::cout << i << std::endl;
    return 1.0 - (double) pool[0].getScore() / randomScore;
}

void GenerationSize() {
    std::ofstream file("~/OK/GenerationSize.txt", std::ofstream::app);

    std::future<double> futures[INSTANCES];
    Instance instances[INSTANCES];
    for (auto &instance : instances) instance.toFile();

    for (unsigned generationSize = 2; generationSize < 10000; generationSize *= 2) {
        double result = 0; // average percentage increase
        for (unsigned k = 0; k < INSTANCES / THREADS; k++) {
            for (unsigned i = 0; i < THREADS; ++i) {
                futures[k * THREADS + i] = std::async(std::launch::async, helperGenerationSize,
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

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    GenerationSize();

    return 0;
}
//krzyżowanie then mutacja!!!!!!!.
// rozmnażanie losowe.