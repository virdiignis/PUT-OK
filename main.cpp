#include <iostream>
#include <thread>
#include "Instance.hpp"
#include "Solution.hpp"


int main() {
    Instance i = Instance();
    i.toFile(1, "/home/prance/c/aisd/OK/ins1.txt");
    auto s = Solution(i);
    std::cout << s.getScore() << "\n";
    std::flush(std::cout);
//    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto f = Solution(i);
    std::cout << s.getScore() << "\n";
    std::cout << f.getScore();
    std::flush(std::cout);
//    for (int j = 0; j < 1000; ++j) {
//        s.mutate();
//        std::cout << j << "\t" << s.getScore() << "\n";
//        std::flush(std::cout);
//    }
    return 0;
}