#include<bits/stdc++.h>
using namespace std;

class Quicksort {

	

public:
	

	int partition(vector<int> & a, int low, int high) {

		int pivot = a[high];

		int i = low - 1;

		for(int j = low; j<high; j++) {

			if(a[j] < pivot) {

				i++;
				swap(a[i], a[j]);
			}
		}

		swap(a[i+1], a[high]);

		return i+1;
	}

	void quickSort(vector<int> & arr, int low, int high) {

		if(low < high) {
			int index = partition(arr, low, high);

			quickSort(arr, low, index - 1);
			quickSort(arr, index+1, high);
		}

		return;
	}

	void quickSelect(vector<int> & a, int low, int high, int k) {
		if(low < high) {
			int index = partition(a, low, high);


			if(a.size() - index >= k) {
				quickSelect(a, index+1, high, k);


			}
			else if(a.size() - index < k) {
				quickSelect(a, low, index-1, k);
			}
		}
	}
};

ostream& operator << (ostream& cout, vector<int> & a) {

	for(int x : a) {
		cout  << setw(3) << x << ' ';
	}

	cout << endl;

	return cout;
}
int main() {
	vector<int> arr;

	int n;

	cin >> n;

	srand(10+n);


	for(int i=0;i<n;i++) {
		arr.push_back(rand()%100 + 1);
	}

	for(int x : arr) {
		cout << x << ' ';
	}

	cout << endl;

	Quicksort qs;
	qs.quickSelect(arr, 0, arr.size() - 1, 3);

	cout << arr << endl;
	


}