#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Segment Tree for **Min Queries**.

Sample Input:

5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5

Sample Output:
1
1
2
1


*/
class SegmentTree {
private:
    // Depending upon the use case, decide whether to use the reference to the array or not.
    vector<int> &arr;
    vector<int> tree;

    int queryUtil(int node, int nodeLeft, int nodeRight, int left, int right) {
        // Base conditions vary according to the type of query. (min, max, etc.)
        if (left > right || nodeLeft > right || nodeRight < left)
            return INT_MAX;

        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];

        int mid = (nodeLeft + nodeRight) / 2;

        return min(queryUtil(2 * node + 1, nodeLeft, mid, left, right), queryUtil(2 * node + 2, mid + 1, nodeRight, left, right));
    }

    int updateUtil(int root, int index, int left, int right, int val) {
        // Base conditions vary according to the type of query. (min, max, etc.)
        if (left > right)
            return INT_MAX;

        if (index < left || right < index)
            return tree[root];

        if (left == right) {
            return tree[root] = val;
        }

        int mid = (left + right) / 2;

        return tree[root] = min(updateUtil(root * 2 + 1, index, left, mid, val), updateUtil(root * 2 + 2, index, mid + 1, right, val));
    }

public:
    SegmentTree(vector<int> &arr) : arr(arr) {
        int n = arr.size();
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        // size is the next power of two.
        tree.resize(2 * size, INT_MAX); // Initialization vary according to the type of query. (min, max, etc.)
        buildTree(0, 0, n - 1);
    }

    int buildTree(int root, int left, int right) {
        // Base conditions vary according to the type of query. (min, max, etc.)
        if (left > right) {
            return INT_MAX;
        }
        if (left == right) {
            tree[root] = arr[left];
            return tree[root];
        }

        int mid = (left + right) / 2;

        tree[root] = min(buildTree(2 * root + 1, left, mid), buildTree(2 * root + 2, mid + 1, right));

        return tree[root];
    }

    int query(int left, int right) {
        return queryUtil(0, 0, arr.size() - 1, left, right);
    }

    bool update(int pos, int val) {
        if (pos < 0 || pos >= arr.size()) {
            return false;
        }
        updateUtil(0, pos, 0, arr.size() - 1, val);
        arr[pos] = val;

        return true;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    int l, r;

    while (q--) {
        char type;
        cin >> type;
        cin >> l >> r;

        if (type == 'q') {
            l--;
            r--;
            cout << segTree.query(l, r) << endl;
        } else {
            l--;
            segTree.update(l, r);
        }
    }

    return 0;
}
