#include <iostream>
#include <limits>

// template < typename primitive >
// primitive* max ( const primitive * list , primitive len ) {
//     primitive* ret = new primitive[2];
//     ret[1] = std::numeric_limits<primitive>::min();
//     for ( primitive i = 0; i < len; i++) {
//         if ( ret[1] < *list) {
//             ret[1] = *list;
//             ret[0] =  i;
//         }
//         list++;
//     }
//     return ret;
// }

// template < typename primitive >
// primitive* min ( const primitive * list , primitive len ) {
//     primitive* ret = new primitive[2];
//     ret[1] = constexpr std::numeric_limits<primitive>::max();
    
//     for ( primitive i = 0; i < len; i++) {
//         if ( ret[1] > *list) {
//             ret[1] = *list;
//             ret[0] =  i;
//         }
//         list++;
//     }
//     return ret;
// }
int arr[1000000];
int mo ( int l[]; , int r[] , int n , int maxx) {
    memset();

int main ( void ) {
    int l [4] = {1,4,3,1};
    int r [4] = {15,8,5,4};
    std::cout << "\nThe most ubiquitous term is: " << maxOccured(l , r , 4 ,5) << std::endl;
    return 0; 
}