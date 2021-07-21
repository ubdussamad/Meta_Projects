#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> ranked = {295,294,291,287};
vector<int> player = {300,300,301,304,306,308};


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {

    vector<int> returnBuffer;
    
    vector<int>::reverse_iterator j = ranked.rbegin();
    int rank = set<int>(ranked.begin(), ranked.end()).size();
    
    for (auto i=player.begin(); i<player.end(); i++) {
        
        
        cout << endl << "Player is: " << *i << endl;
        
        for ( ; j != ranked.rend(); j++ ) {
            
            cout << "Score index: " << *j << " ranked at: " << rank << endl;
            if ( *j > *i ) {
                cout << "Finally " << *i << " ranked at: " << rank+1 << endl;
                returnBuffer.push_back(rank+1);
                break;
                }
                
            if ( *j == *i ) {
                cout << "Finally " << *i << " ranked at: " << rank+1 << endl;
                returnBuffer.push_back(rank);
                break;
                }
                
            if ( *i >= *j && (j+1 == ranked.rend()) ) {
                cout << "Finally " << *i << " is the first" << endl;
                returnBuffer.push_back(rank);
            }
            
            if ( j+1 != ranked.rend() &&  *j != *(j+1)) {
                rank--;
            }
        }
    }
    
    return (returnBuffer);
}


int main() {
    string s = "Hi vtro";
    // s[0] = 'B';
    cout << s << endl;
}