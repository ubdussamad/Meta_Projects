#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

inline bool ipo2(unsigned int x) {return (x != 0) && ((x & (x - 1)) == 0);}
string po2n(int n) {
    int i, j, blen = n / 32 + 1, dlen = n / 29 + 1;
    uint32_t bin[blen], dec[dlen];
    uint64_t num;

    for (i = 0; i < blen; i++)
        bin[i] = 0;
    bin[n / 32] = (uint32_t)1 << (n % 32);

    for (j = 0; blen > 0; ) {
        for (num = 0, i = blen; i-- > 0;) {
            num = (num << 32) | bin[i];
            bin[i] = num / 1000000000;
            num = num % 1000000000;
        }
        dec[j++] = (uint32_t)num;
        while (blen > 0 && bin[blen - 1] == 0)
            blen--;
    }
    char buff[64];
    string _s;
    
    sprintf(buff,"%u", dec[--j]);
    _s.append(buff);
    while (j-- > 0) {char nbuff[64]; sprintf(nbuff,"%09u", dec[j]);_s.append(nbuff);}
    
    return string(_s);}
unordered_set<string> pow2map;
#define ul unsigned int

// Creating a trie DS especially for numerix only strings
struct tnode {
    // unordered_map<char, tnode* > children; // Generic Case
    tnode * children[10] = {nullptr}; // if the tnode ptr at numeric offset is null then the child dosen't exists.
    bool value = false;
};


// Param: root doesn't nessesarily need to be absolute root if you know what you're doing.
bool tnodeInsert (tnode *root , string element) {
    tnode * rootCpy = root;
    for (auto& itr: element) {
        
        auto index = (itr-48)%10;
        
        if (rootCpy->children[index] != nullptr) {rootCpy = rootCpy->children[index];} // if that child is already there
        
        else {
            tnode * babyNode = new tnode();
            rootCpy->children[index] = babyNode;
            rootCpy = babyNode;
        }
        
        
    }
    rootCpy->value = true;
    return true;
}


int tnodeSubstrings (tnode *root, string query) {
    tnode * rootCpy = root;
    int substringCount = 0;
    for (auto& itr: query) {
        
        auto index = (itr-48)%10;
        cout << "Query[i]: " << index ;
        if ( rootCpy->children[index] != nullptr) {
            rootCpy = rootCpy->children[index];
            if (rootCpy->value) {cout << "Hit!";substringCount++;}
        } // if that child is already there
        cout << endl;
    }

    return substringCount;
}


tnode pow2trie;


int twoTwo(string a) {
    
    ul po2Count(0);
    ul limit = a.size();
    string q = "256";

    int f = tnodeSubstrings(&pow2trie, q);
    cout << "Copies found: " << f << endl;
    
    // for (ul i(0); i < limit; i++ ) {
    //     // cout << po2n(i) << endl;
    //     string value;
    //     value.push_back(a[i]);
        
    //     if (a[i] == '0') {continue;} // if starting char is 0
    //     // cout << "Testing number: " << a[i];
    //     if ( ipo2(a[i] - 48) ) {// cout << " HIT!" << endl;
    //         po2Count++;}
            
    //     // else {cout << " Miss!" << endl;}
        
    //     for (ul j(i+1); j < limit; j++) {
            
            
    //         value.push_back(a[j]);
            
    //         // cout << "String Testing number: " << value;
    //         if (pow2map.find(value) != pow2map.end()) {
    //             // cout << " Miss!" << endl;
    //             po2Count++;
    //             }
    //         // else {
    //         //     po2Count++;
    //         //     // cout << " HIT!" << endl;
    //         //     }

            
    //     }
    // }
    
    
    return po2Count;
}




int main() {
    // cout << "Ran" << endl;
    for (int i(0); i < 2048*2; i++ ) {
        string k = po2n(i);
        // cout << "Inserting " << k << endl;
        tnodeInsert(&pow2trie, k);
    }

    cout << "Heyy yo" << endl;
    
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        int result = twoTwo(a);

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



