#include<bits/stdc++.h>

using namespace std;

ostream& operator << (ostream& cout, vector<int> & a) {
	for(int & x : a) {
		cout << x << ' ';
	}

	cout << endl;
}


void merge(vector<int> & a, int l1, int r1, int l2, int r2) {

	int l = l1;
	int r = r2;
	vector<int> res;
	while(l1 <= r1 && l2 <= r2) {
		if(a[l1] < a[l2]) {
			res.push_back(a[l1++]);
		}
		else {
			res.push_back(a[l2++]);
		}
	}

	while(l1 <= r1) {
		res.push_back(a[l1++]);
	}

	while(l2 <= r2) {
		res.push_back(a[l2++]);
	}

	for(int & x : res) {
		a[l++] = x;
	}


	return;
}
void mergesort(vector<int> & a, int low, int high) {

	if(low == high) {
		return;
	}
	if(low < high) {
		int mid = (low + high + 1)/2;



		mergesort(a, low, mid-1);
		mergesort(a, mid, high);

		merge(a, low, mid - 1, mid, high);

	}


	return;
}
int main() {
	
	int n;

	cin >> n;

	vector<int> a(n);

	for(int i=0;i<n;i++) {

		a[i] = rand()%1000;
	}


	mergesort(a, 0, a.size() - 1);

	cout << a << endl;
}