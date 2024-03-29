#include<bits/stdc++.h>
using namespace std;


#define pii pair<int, int>

struct Compare {
    bool operator()(const pii & a, const pii & b) const {
        return tie(a.first, b.second) < tie(b.first, a.second);
    }  
};

void print(set<pii, Compare> & s) {
    cout << "PRINT" << endl;
    for(auto x : s) {
        cout << x.first << ' ' << x.second << endl;
    }
    
    cout << endl;
}
int main() {
    set<pii, Compare> s;
    
    s.insert({1, 2});
    s.insert({1, 3});
    s.insert({2, 3});
    s.insert({2, 4});
    
    print(s);

}