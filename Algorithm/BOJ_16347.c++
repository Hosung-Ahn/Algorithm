#include <iostream>
#include <vector>
using namespace std; 
#define MAX 200000
#define ll long long
bool wolf[MAX] = {0,};
ll cnts[MAX] = {0,};
vector<int> edges[MAX];

ll dfs(int cur) {
    ll ret = 0;
    for(int next : edges[cur]) {
        ret += dfs(next);
    }
    if (wolf[cur]) return max(0, ret-cnts[cur]);
    return ret + cnts[cur];
}

int main() {
    int N; cin >> N;
    for(int i=2;i<=N;i++) {
        char w; int a, p;
        cin >> w >> a >> p;
        if (w == 'W') wolf[i] = true;
        cnts[i] = a;
        edges[p].push_back(i);
    }
    cout << dfs(1);
}