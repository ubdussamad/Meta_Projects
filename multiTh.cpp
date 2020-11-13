#include <iostream>
#include <atomic>
#include <thread>
#include <memory>

class pubShub { 
    public: 
       int itr;
       int something;
    private:
        short x;
        double y;
    protected:
        int internal_secret; 
};

int main () {
    std::atomic<int> x(0);
    x++;
    pubShub o;

    auto i = static_cast<short>(5);
    auto j = dynamic_cast<pubShub *>( &o );


    return(-1);
}