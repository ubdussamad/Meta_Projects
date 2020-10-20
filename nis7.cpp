#include <bits/stdc++.h>
using namespace std;

int findMin(int n, int k, string &str) {
	int start = 0;
	int count = 0;

	string temp;
	for(int i=0; i<26; i++) {
		if(str.find('a' + i) == string::npos) temp.push_back('a' + i);
	}

	int tempIndex = 0;

	while(k!=0 && count!=str.length()-1) {
		if(str.length() == 1) return 1;

		for(int i=0; i<str.length()-1; i++) {
			if(str[i] != str[i+1]) {
				str[i+1] = temp[tempIndex];
				(tempIndex == temp.length()-1) ? tempIndex = 0 : tempIndex += 1;

				str.erase(i, 1);

				k--;
				(i == str.length()-2) ? start = 0 : start = i;
				count = 0;
				break;
			}
			else {
				count++;
			}
		}
	}

	return (str.length());
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;

		string str;
		cin.ignore();
		getline(cin, str);

		cout<<findMin(n, k, str);
	}
	return 0;
}