#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100001
vector<pair<int,int>> arr;
vector<pair<int,int>> edges[MAX];
int dist_A[MAX];
int dist_B[MAX];

void bfs_A(int A) {
    queue<int> q;
    q.push(A); 
    dist_A[A] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            if (dist_A[next] >= 0) continue;
            dist_A[next] = dist_A[cur] + edges[cur][i].second;
            q.push(next);
        }
    }
}

void bfs_B(int B) {
    queue<int> q;
    q.push(B);
    dist_B[B] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0;i<edges[cur].size();i++) {
            int next = edges[cur][i].first;
            if (dist_B[next] >= 0) continue;
            dist_B[next] = dist_B[cur] + edges[cur][i].second;
            q.push(next);
        }
    }
}

int solve() {
    int N,A,B; cin >> N >> A >> B;
    for(int i=0;i<N-1;i++) {
        int a,b,d; cin >> a >> b >> d;
        edges[a].push_back({b,d});
        edges[b].push_back({a,d});
        arr.push_back({a,b});
    }
    bfs_A(A);
    bfs_B(B);
    if(A==B) return 0;
    int ret = 987654321;
    for(auto p : arr) {
        ret = min(ret, dist_A[p.first] + dist_B[p.second]);
        ret = min(ret, dist_A[p.second] + dist_B[p.first]);
    }
    return ret;;
}

int main() {
    memset(dist_A, -1, sizeof(dist_A));
    memset(dist_B, -1, sizeof(dist_B));
    cout << solve();
}