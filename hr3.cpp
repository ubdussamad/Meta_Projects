#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void p (string a , int sa , int diff) {
    for (int i = 0; i  < diff ; i++) {
        cout << a[sa-i];
    }
    cout << endl;
}


string morganAndString(string a, string b) {
    
    string Buffer = "";
    
    int sA = 0, sB = 0; // Stack Pointers for strings a & b.

    for ( auto i = 1; i < a.size()+b.size(); i++) {
        
        if  ( sA == a.size()) {for (int j = sB ; j < b.size() ; j++ ) {Buffer.push_back(b[j]);}return Buffer;} // If first stirng finishes
        if  ( sB == b.size()) {for (int j = sA ; j < a.size() ; j++ ) {Buffer.push_back(a[j]);}return Buffer;} // If second string finishes
        
        if ( int(a[sA]) > int(b[sB])  ) { Buffer.push_back(b[sB]); sB++; } // Pop from B
        else if ( int(a[sA]) < int(b[sB]) ) { Buffer.push_back(a[sA]);sA++; } // Pop form A
        
        else { // Current tops are equal!
            // Edge Cases: One list is finished.
            bool breakCalled = false;

            for ( int j = 0 ; j <= min(a.size(), b.size()); j++) {

                if ( int(a[sA+j]) > int(b[sB+j]) ) {
                    Buffer.push_back(b[sB]);
                    breakCalled = true;sB++;
                    break;

                }

                if ( int(a[sA+j]) < int(b[sB+j]) ) {
                    Buffer.push_back(a[sA]);
                    breakCalled = true;sA++;
                    break;
                }

            }

            if (!breakCalled) { 
                // 1. All stirng were same till the end of one or both stacks.
                if ( a.size()-sA > b.size()-sB ) { Buffer.push_back(b[sB]);sB++; }
                if ( a.size()-sA <= b.size()-sB ) { Buffer.push_back(a[sA]);sA++; }
            }

        }
        
        
        // cout << "S: -> "; p(Buffer, Buffer.size()-1, 6);
        }
        
    return Buffer;
}






int main( ) {
    

    cout << "File is too big: " << a.size() << ", " << b.size() << endl;


    string o = morganAndString(a,b);

    cout << "Size of o is: " << o.size() << endl;
    cout << o << endl;
    return 0;
}





// string morganAndString(string a, string b) {
//     string Buffer = "";
//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
    
//     int sA = a.size() - 1, sB = b.size() - 1; // Get their sizes.

//     for ( auto i = 1; i < a.size()+b.size(); i++) {
        
//         if  (sA < 0) {for (int j = sB ; j >= 0 ; j-- ) {Buffer.push_back(b[j]);}return Buffer;} // If first stirng finishes
//         if  (sB < 0) {for (int j = sA ; j >= 0 ; j-- ) {Buffer.push_back(a[j]);}return Buffer;} // If secind string finishes
        
//         if ( int(a[sA]) > int(b[sB])  ) { Buffer.push_back(b[sB]); sB--; } // Pop from B
//         else if ( int(a[sA]) < int(b[sB]) ) { Buffer.push_back(a[sA]);sA--; } // Pop form A
        
//         else { // Current tops are equal!
//             // Edge Cases: One list is finished.
//             bool breakCalled = false;

//             for ( int j = 0 ; j <= min(sA, sB); j++) {

//                 if ( int(a[sA-j]) > int(b[sB-j]) ) {
//                     Buffer.push_back(b[sB]);
//                     breakCalled = true;sB--;
//                     break;

//                 }

//                 if ( int(a[sA-j]) < int(b[sB-j]) ) {
//                     Buffer.push_back(a[sA]);
//                     breakCalled = true;sA--;
//                     break;
//                 }

//             }

//             if (!breakCalled) { 
//                 // 1. All stirng were same till the end of one or both stacks.
//                 if (sA > sB) { Buffer.push_back(b[sB]);sB--; }
//                 if (sA <= sB) { Buffer.push_back(a[sA]);sA--; }
//             }

//         }
        
        
//         cout << "S: -> "; p(Buffer, Buffer.size()-1, 6);
//         }
        
//     return Buffer;
// }
