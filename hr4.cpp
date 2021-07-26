#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

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
    char buff[1024];
    // buff[1023] = '\0';
    int count = 0;
    
    count += sprintf(&buff[count],"%u", dec[--j]);

    while (j-- > 0) { 
        count += sprintf( &buff[count], "%09u", dec[j]);
    }
    
    return string(buff);
    
}


#define ul unsigned int

// Creating a trie DS especially for numerix only strings
struct tnode {
    // unordered_map<char, tnode* > children; // Generic Case
    struct tnode * children[10] = {nullptr}; // if the tnode ptr at numeric offset is null then the child dosen't exists.
    bool value = false;
};


// Param: root doesn't nessesarily need to be absolute root if you know what you're doing.
bool tnodeInsert (struct tnode *root , string elem) {
    struct tnode * rootCpy = root;
    for ( auto& itr : elem ) {
        
        // if that child is already there
        // cout << "S1" << endl;
        if (rootCpy->children[ itr-48 ] != nullptr) {rootCpy = rootCpy->children[ itr-48 ];}
        
        else {
            struct tnode* babyNode = new struct tnode;
            memset(babyNode->children, 0 , 10 );
            // cout << "S3" << endl;
            rootCpy->children[ itr-48 ] = babyNode;
            rootCpy = babyNode;
        }
    }
    rootCpy->value = true;
    return true;
}


int tnodeSubstrings (struct tnode *root, string query , unsigned int start , unsigned int end) {
    struct tnode * rootCpy = root;
    int substringCount = 0;
    for (unsigned int itr = start; itr < end; itr++) {
        cout << "Loop!" << endl;
        
        if ( rootCpy->children[ query[itr]-48 ] ) {
            
            rootCpy = rootCpy->children[ query[itr]-48 ];
            
            if (rootCpy->value) {++substringCount;}
        }
        
        else {
            return substringCount;
        }
    }
    return substringCount;
}


struct tnode pow2trie;


int twoTwo(string a) {
    
    ul po2Count(0);
    
    // cout << tnodeSubstrings( &pow2trie, string("0") , 0, 1) << endl;
    ul limit = a.size();
    
    for (ul i(0); i < limit; i++ ) {
        po2Count += tnodeSubstrings(&pow2trie, a, i, a.size());
    }
    return po2Count;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    for (int i(0); i < 801; i++ ) {
        string k = po2n(i);
        // cout << k << "     Len: " << k.size() <<  endl;
        tnodeInsert(&pow2trie, k);
        if (k[0] == '1' && k[1] == '9') {cout << k << endl;}
    }

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
