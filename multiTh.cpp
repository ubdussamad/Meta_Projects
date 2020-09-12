#include <iostream>
#include <atomic>
#include <thread>



int main () {
    std::atomic<int> x(0);
    x++;
    return(-1);
}