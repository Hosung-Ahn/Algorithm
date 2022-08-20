#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
# define MAX 501

bool edge[MAX][MAX] = {0,};
int in_degree[MAX] = {0,};
int N;

void topology_sort() {
    vector<int> ans;
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if (in_degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        if (q.size() > 1) {
            cout << "?\n";
            return;
        }
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int next=1; next<=N; next++) {
            if(!edge[cur][next]) continue;
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
    if (ans.size() != N) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(auto x : ans) { 
        cout << x << " ";
    }
    cout << "\n";
}

void swap(int &a, int &b) { 
    int tmp = a;
    a = b;
    b = tmp;
}

void solve() {
    memset(in_degree, 0, sizeof(int)*MAX);
    for(int i=0;i<MAX;i++) memset(edge[i], 0, sizeof(bool)*MAX);

    cin >> N;
    bool first[MAX] = {0,};
    for(int i=0;i<N;i++) {
        int x; cin >> x;
        first[x] = true;
        for(int e=1;e<=N;e++) {
            if (first[e]) continue;
            edge[x][e] = true;
            in_degree[e]++;
        }
    }
    int M; cin >> M;
    for (int i=0;i<M;i++){
        int s,e; cin >> s >> e;
        if (!edge[s][e]) {
            swap(s,e);
        }
        edge[s][e] = false;
        edge[e][s] = true;
        in_degree[e]--;
        in_degree[s]++;
    }

    topology_sort();
}

int main() {
    int T; cin>>T;
    while(T--) {
        solve();
    }
}