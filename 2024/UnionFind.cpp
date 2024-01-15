#include<bits/stdc++.h>
using namespace std;


class UnionFind {
private:
	int numNodes;
	vector<int> componentParent;
	vector<int> componentSize;

public:
	UnionFind(int numNodes) : numNodes(numNodes) {

		componentParent.resize(numNodes+1, 0);
		componentSize.resize(numNodes+1, 1);
		for(int i=0;i<componentParent.size(); i++) {
			componentParent[i] = i;
		}
	}

	void unionNodes(int a, int b) {
		int parentA = find(a);
		int parentB = find(b);

		if(componentSize[parentA] > componentSize[parentB]) {
			swap(parentA, parentB);
		}
		componentParent[parentA] = parentB;
		componentSize[parentB] += componentSize[parentA];

		find(parentA);
		find(parentB);

	}

	int find(int a) {
		if(a == componentParent[a]) return a;

		return componentParent[a] = find(componentParent[a]);
	}

	int getParent(int node) {
		return find(node);
	}

	int getSize(int node) {
		return componentSize[getParent(node)];
	}
};


int main() {

	// Driver code

}