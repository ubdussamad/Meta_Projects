#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include "logX.hpp"

class LogFile {
    std::mutex  _mu;
    // std::ofstream    _f;

    public:
        LogFile () {
            // _f.open("print.txt");
        }

        void shared_print ( std::string id, int value) {
            std::lock_guard<std::mutex> locker (_mu); // Lock releases the moment we run out of this scope.
            // _f << "From: " << id << ": " << value << std::endl;
            std::cout << "From: " << id << ": " << value << std::endl;
        }
};

void function_1 ( LogFile& log ) {
    std::cout << INFO_COLOR_GREEN_BEGIN_ "BLocking function 1!" CLEAR_COLOR_ << std::endl;
    std::chrono::milliseconds timespan(5000); // 10 Second sleep delay.
    std::this_thread::sleep_for(timespan);
    std::cout << INFO_COLOR_GREEN_BEGIN_ "Function 1 released!!" CLEAR_COLOR_ << std::endl;
    for (int i=0; i>-1000; i--) {
        log.shared_print(ERROR_COLOR_RED_BEGIN_ "Thread 1" CLEAR_COLOR_ ,i);
    }
}

void function_2 ( LogFile& log ) {
    for (int i=0; i>1000; i++) {
        log.shared_print(WARN_COLOR_YELLOW_BEGIN_ "Thread 2" CLEAR_COLOR_ ,i);
    }
}



int main ( )   {
    LogFile log;
    std::thread t1 ( function_1, std::ref (log));


    // for ( int i=0; i < 1000; i++) {
    //     for ( int h = 0; h < 90; h++ ) {
    //         int  s = 44 / (i + h + 1);
    //     }
    //     log.shared_print( "From main thread: ", i );
    // }

    std::thread t2 ( function_2 , std::ref (log));
    
    t2.join();
    t1.join();

    return (0);

}