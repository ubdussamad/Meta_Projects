#include <cassert>
#include <type_traits>
#include <iostream>

using Int = int;

template <typename T , typename U >
bool x(T a , U b) {
    return a==b;
}
void f() {
    std::cout << std::is_same<int,Int>::value << std::endl;
    /*assert(*/ x <int, int> ( 1 , 1 ) ;  
}

int main () {
    f();
    return 0;
}