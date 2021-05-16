#include "comlib.cpp"
template <typename T>
T genPentagonal (T index);
template <typename T>
T genTriangular (T index);
template <typename T>
T genHexagonal (T index);

int main ()  {
    long int index = 120;
    std::cout << genHexagonal(120)/3 << std::endl;
}


template <typename T>
T genPentagonal (T index) {
    return ( (index*(3*index - 1)) / 2 );
}
template <typename T>
T genTriangular (T index) {
    return ( (index*(index + 1)) / 2 );
}
template <typename T>
T genHexagonal (T index) {
    return index*(2*index - 1);
}
