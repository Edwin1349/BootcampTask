#include "Timer.h"

Timer::Timer(){
    this->start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer(){
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - this->start);
    std::cout << duration.count() << " ms \n";
}
