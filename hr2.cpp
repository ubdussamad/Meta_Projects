#include <iostream>
#include <vector>
#include <set>
using namespace std;


int check_plus(int x , int y , vector<string> grid ) {
    
    if (grid[x][y] != 'G') {return(-1);}

    for (auto i = 1; i < max( grid.size() , grid[0].size() ) ; i++) {
        // Bounds Check 
        if ( !(x+i < grid.size())  || (x-i<0) ) {return(i);}
        if ( !(y+i < grid[0].size())  || (y-i<0) ) {return(i);}
        // Trying to expand
        if ( grid[x-i][y] != 'G') {return (i); } // top
        if ( grid[x+i][y] != 'G') {return (i); } // bottom
        if ( grid[x][y-i] != 'G') {return (i); } // right
        if ( grid[x][y+i] != 'G') {return (i); } // left
    }
    
    return(-1);
}

int twoPluses(vector<string> grid, int m , int n) {
    int maxArea = 0;
    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            
            int offset1 = check_plus(i, j, grid);
            if (offset1 == -1) {continue;} // Bad Center Point
            
            for (int of = 0; of < offset1; of++) {
                auto gridCpy = grid;
                
                for (int of2 = 0; of2 <= of ; of2++) {
                    gridCpy[i-of2][j] = 'B'; // Top
                    gridCpy[i+of2][j] = 'B'; // Bottom
                    gridCpy[i][j-of2] = 'B'; // Right
                    gridCpy[i][j+of2] = 'B'; // Left
                }

                int area1 = (of)*4 + 1;

                std::cout << "Area1 is: " << area1 << endl;

                if (i==3 && j==3) {
                    
                    for (auto itr1 = gridCpy.begin(); itr1 < gridCpy.end() ; itr1++ ) {
                        for (auto itr2 = (*itr1).begin(); itr2 < (*itr1).end() ; itr2++ ) {
                            cout << *itr2 << "  ";
                        }
                        cout << endl;
                    }

                    cout << " ------------------------- \n\n";
                    
                }
                
                for (int x = 0; x < gridCpy.size(); ++x ) {
                    for (int y = 0; y < gridCpy[0].size() ; y++ ) {
                        
                        int offset2 = check_plus(x, y, gridCpy );
                        if (offset2 == -1) {continue;}
                        int area2 = (offset2 - 1)*4 + 1;

                        if (i==3 && j==3) {cout << "Area 2 is: " << area2 << endl;}
                        
                        if ( area2 * area1 > maxArea ) { maxArea = area1 * area2 ;}

                    }
                }
                
            }
        }
    }
    return maxArea;
}




int main () { 
    vector < string > arr = {
        "BBBGBGBBB",
        "BBBGBGBBB",
        "BBBGBGBBB",
        "GGGGGGGGG",
        "BBBGBGBBB",
        "BBBGBGBBB",
        "GGGGGGGGG",
        "BBBGBGBBB",
        "BBBGBGBBB",
        "BBBGBGBBB"
    };

    cout << twoPluses(arr , 8 , 8) << endl;
    return 0;

}