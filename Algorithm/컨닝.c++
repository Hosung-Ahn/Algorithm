#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
#define MAX 210
#define INF 987654321

int N,M; 
int cp[MAX][MAX] = {0,}, fl[MAX][MAX] = {0,};
int dr[] = {-1,0,1,-1,0,1};
int dc[] = {-1,-1,-1,1,1,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void networkflow(int s, int e) {
    int totalFlow = 0;

    while(1) {
        vector<int> parent(MAX, -1);
        parent[s] = s;
        queue<int> q;
        q.push(s);

        while(!q.empty() && parent[e] == -1) {
            int cur = q.front(); q.pop();

            for (int next = 0; next < MAX; next++) {
                if (cp[cur][next] - fl[cur][next] > 0 && parent[next] == -1) {
                    parent[next] = cur;
                    q.push(next);
                }
            }
        }

        if (parent[e] == -1) break;

        int flow = INF;
        for (int p = e; p != s; p = parent[p]) {
            flow = min(flow, cp[parent[p]][p] - fl[parent[p]][p]);
        }
        for (int p = e; p != s; p = parent[p]) {
            fl[parent[p]][p] += flow;
            fl[p][parent[p]] -= flow;
        }
        totalFlow += flow;
    }
    cout << totalFlow << "\n";
}

void solve() {
    memset(cp, 0, sizeof(cp));
    memset(fl, 0, sizeof(fl));
    cin >> N >> M;
    vector<string> board;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    for (int i = 1; i <= N*M; i++) {
        for (int j = 1+N*M; j <= 2*N*M; j++) {
            cp[i][j] = 1;
        }
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == 'x') continue;
            int idx = r*M + c + 1;
            cp[0][idx] = 1;
            for (int i = 0; i < 6; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!in_range(nr,nc)) continue;
                int nidx = nr*M +nc + 1;
                cp[idx][nidx] = 0;
            }
        }
    }

    for (int i = 1; i <= N*M; i++) {
        cp[i+N*M][2*N*M+1] = 1;
    }
    networkflow(0,2*N*M+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}