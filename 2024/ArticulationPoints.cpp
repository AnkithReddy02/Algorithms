#include<bits/stdc++.h>
using namespace std;

/*
Author: @Ankith
*/

vector<bool> visited;
vector<int> discoveryTime;
vector<int> lowTime;
vector<bool> articulationPoints;
set<pair<int,int>> bridges;

int currTime;

void dfs(vector<vector<int>> & graph, int node, int parent) {

	visited[node] = true;
	discoveryTime[node] = lowTime[node] = currTime++;

	int children = 0;

	for(int adjNode : graph[node]) {

		/*
			a -- b -- c (c -- b is not a back edge)
			So continue.
			
			Okay, let's assume that the below condition is not required.

			Counter Example:

			A -- B -- C

			Now, A explored B. However, now B explored A, and B sees that A is already
			visited. So B updates its low time. In the same way, C's low time is updated
			to A's low time. Now, if we check for the condition of Articulation Point for 
			node B, then we can see that discoveryTime[B] = 2 and lowTime[c] = 1
			and gives the output as false. However, B is actually the articulation point. 
		*/
		if(adjNode == parent) continue;

		if(!visited[adjNode]) {
			dfs(graph, adjNode, node);

			lowTime[node] = min(lowTime[node], lowTime[adjNode]);

			/*

					1
					|
					2
				   / \
				  3 - 4

				  Note:
				  4 - 2 is a backedge. While, 4-3, 3-2, 2-1 are not backedges.

				  If we remove 2, you can form 2 different components.
				  However, asumme there is no parent for 2(i.e, 1). Now, still the number of 
				  components are 1. Hence, parent != -1 condition is required.

				  Example dry run:
						DiscoveryTime    LowTime
				    1 		1				1
					2		2				2
					3		3				3
					4		4				4
					4		4				2
					3		3				2
					2		2				2
					1		1				1

					The below condition says that the adjNode of the current node
					is unable to reach the ancestor of the current node. The maximum
					that is able to reach is the curr node. IF THAT IS THE CASE then removing
					the curr node breaks the graph into two or more components. If not, the
					adjacent node can be reach the curr node ancestor and cannot be 
					disconnected.
			*/
			if(discoveryTime[node] <= lowTime[adjNode] && parent != -1) {
				articulationPoints[node] = true;
			}
		}
		else {
			/*
				In the above example, 2 is already visited. Hence, you just update
				the low time of the curr node.
			*/
			lowTime[node] = min(lowTime[node], lowTime[adjNode]);
		}


		/*
			Consider the same above example.
			If the discoveryTime[node] >= lowTime[adjNode], the 'adjNode' can reach the 
			'node' or its ancestor. If it reaches the ancestor of 'node', obviously 
			it can reach the 'node'
		*/
		if(discoveryTime[node] < lowTime[adjNode]) {
			bridges.insert({min(node, adjNode), max(node, adjNode)});
		}

		children++;
	}

	/*
		This is a special case for root node.
		If there are more than one children, it is a articulation point.

		Example:

			1
			|\
			2 5
		   / \
		  3 - 4

		Explanation:
			We have two traversals for 1
			1. 1-2-3-4
			2. 1-5

			So we have two children and it is a articulation point.


		NOTE: Leaf Node is not a ARTICULATION POINT because if we remove the leaf
		node, the number of connected components is still 1.

	*/
	if(children > 1 && parent == -1) {
		articulationPoints[node] = true;
	}
}

void init(int n) {
	currTime = 0;
	visited.resize(n, false);
	articulationPoints.resize(n, false);
	discoveryTime.resize(n, 0);
	lowTime.resize(n, 0);
	bridges.clear();
}
int main() {

	// driver code
}