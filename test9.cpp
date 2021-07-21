#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

int main(void) {
    // std::shared_ptr<int> x = std::make_shared<int>();
    // auto s = x;

    // using V = std::vector<std::unique_ptr<int>> ;
    typedef std::vector < std::shared_ptr <int> > spVec;//std::unique_ptr < int > > something;
    typedef std::vector < std::unique_ptr <int> > unqVec;
    typedef std::vector < int * >                 rawVec;


    std::cout << std::is_copy_constructible<spVec>::value << std::endl;
    std::cout << std::is_copy_constructible<unqVec>::value << std::endl;
    std::cout << std::is_copy_constructible<rawVec>::value << std::endl;

    spVec x = {
        std::make_unique<int>(),
        std::make_unique<int>()
    };

    auto y = x;


    // something x = { std::make_shared<int>() , std::make_shared<int>() };

    // int h = 0;

    // something x_cpy = x;

    // int j = 0;

    // auto tmp = x_cpy[0];

    int k = 0;

    return(0);
}