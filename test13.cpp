#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void p (string a , int sa , int diff) {
    for (int i = 0; i  < diff ; i++) {
        cout << a[sa-i];
    }
    cout << endl;
}


string morganAndString(string a, string b) {
    // cout << "\n\n----------------------" << endl;
    // cout << "A is: " << a <<endl<<"B is: " << b << endl;
    
    int sA = 0, sB = 0; // Stack Pointers for strings a & b.
    int eA = a.size(), eB = b.size();
    char tmpBuff [eA+eB+1];
    tmpBuff[eA+eB] = '\0';
    int currIndex = 0;
    
    for ( auto i = 0; i < eA+eB; i++) {
        // if (sA == eA && sB == eB) {return Buffer;}
        
        if  ( sA == eA) {for (int j = sB ; j < eB ; j++ ) {
            // cout<< "A is empty, pushing only from B"<<endl;
            tmpBuff[currIndex++] = b[j]   ;} break;} // If first stirng finishes
        
        if  ( sB == eB) {for (int j = sA ; j < eA ; j++ ) {
            // cout<< "B is empty, pushing only from A"<<endl;
            tmpBuff[currIndex++] = a[j];} break;} // If second string finishes
        
        if ( a[sA] > b[sB]  ) {
            // cout << "A is bigger, so pushing from B" <<endl;
            tmpBuff[currIndex++] = b[sB];
            char tok = b[sB];
            sB++;
            
            while (1) { if ( sB <= eB && (tok == b[sB] ) ) {tmpBuff[currIndex++] = b[sB];sB++;} else {break;} }
            } // Pop from B
            
        else if ( a[sA] < b[sB] ) {
            // cout << "B is bigger, so pushing from A" <<endl;
            tmpBuff[currIndex++] = a[sA];
            char tok = a[sA];
            sA++;
            
            while (1) { if ( sA <= eA && (tok == a[sA] ) ) {tmpBuff[currIndex++] = a[sA];sA++;} else {break;} }
            } // Pop form A
        
        
        
        
        else { // Current tops are equal!
            // Edge Cases: One list is finished.
            bool breakCalled = false;

            for ( int j = 0 ; j < min(eA-sA, eB-sB); j++) {
                
                // cout<<"Checking tie at ofsset: "<<j<<" Aray A: " << a[sA+j]<<"[sA: "<<sA<<"], Array B: "<<b[sB+j]<<"[sB: "<< sB << "]" << endl;
                
                if ( a[sA+j] > b[sB+j] ) {
                    // cout <<"After tie at index: "<< sB << "[" << b[sB+j] << "], " << sA << "[" << a[sA+j]<<"] Pushing fron B at offset: "<<j<< endl;
                    tmpBuff[currIndex++] = b[sB];
                    breakCalled = true;sB++;
                    break;

                }

                if ( a[sA+j] < b[sB+j] ) {
                    // cout << "After tie at index: "<<sB<<"["<< b[sB+j]<<"], "<<sA<< "[" << a[sA+j] << " ] Pushing fron A at offset: " << j << endl;
                    tmpBuff[currIndex++] = a[sA];
                    breakCalled = true;sA++;
                    break;
                }

            }

            if (!breakCalled) {
                // cout << "Bc: " << breakCalled << endl;
                // 1. All stirng were same till the end of one or both stacks.
                if ( eA-sA < eB-sB ) { tmpBuff[currIndex++] = b[sB];sB++;
                    // cout << "Exausted: B is bigger so pushing from B." << endl;
                }
                if ( eA-sA > eB-sB ) { tmpBuff[currIndex++] = a[sA];sA++;
                    // cout << "Exausted: A is bigger so pushing from A." << endl;
                }
                if ( eA-sA == eB-sB ) {tmpBuff[currIndex++] = a[sA];sA++;
                    // cout << "Exausted: Both are equal in size so pushing fom A" << endl;
                }
            }

        }
        
        
        // cout << "S: -> "; p(Buffer, Buffer.size()-1, 6);
        }
        
    
    
    string Buffer(tmpBuff);
    return Buffer;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
