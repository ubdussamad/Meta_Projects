#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <fstream>
#include <string>
#include <thread>


class LogFile {
    std::mutex  _mu;
    std::ofstream    _f;

    public:
        LogFile () {
            _f.open("print.txt");
        }

        void shared_print ( std::string id, int value) {
            std::lock_guard<std::mutex> locker (_mu);
            _f << "From: " << id << ": " << value << std::endl;
        }
};

void function_1 ( LogFile& log ) {
    for (int i=0; i>-10; i--) {
        log.shared_print("Thread 1",i);
    }
}

int main ( )   {
    LogFile log;
    std::thread t1 ( function_1, std::ref (log));


    for ( int i=0; i < 10; i++) {
        log.shared_print( std::string("From main thread: ") , i );
    }

    return (0);

}