#include<iostream>
#include<vector>
using namespace std;


vector<int> computePi(string s) {

	int n = s.size();

	vector<int> pi(n, 0);

	for(int i=1; i<n; i++) {
		int j = pi[i-1];

		while(j > 0 && s[i] != s[j]) {
			j = pi[j-1];
		}

		// s[0 ... 2] == s[6 ... 8]
		// Basically, increase the length.
		if(s[i]==s[j]) {
			j++;
		}

		// Otherwise, there is no matching prefix with suffix. Hence, j = 0;

		pi[i] = j;
	}

	for(int x : pi) {
		cout << x << ' ';
	}

	cout << endl;

	return pi;
}

/*

Find positive integer p such that for every i in [1 ... n-p], 
s[i] = s[i+p]

Examples:

ip : aaaaaaaaaa
op : 1

ip : abcabcabcabcabc
op : 3

ip : 

*/
int computePeriod(string s) {
	vector<int> pi = computePi(s);

	return s.size() - pi.back();
}
int main() {

	srand(time(0));

	string s;

	// for(int i=0;i<7;i++) {
	// 	int r = rand()%(26);

	// 	char c = 'a' + r;

	// 	s.push_back(c);
	// }

	// cout << s << endl;

	cin >> s;

	cout << computePeriod(s) << endl;
}