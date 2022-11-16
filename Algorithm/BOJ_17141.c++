#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50
#define INF 987654321
int N,M;
int board[MAX][MAX];
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
vector<pair<int,int>> viruses;

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}


int bfs(const vector<int> &arr) {
    int visited[MAX][MAX];
    for(int r=0;r<N;r++)for(int c=0;c<N;c++) visited[r][c] = INF;
    queue<pair<int,int>> q;
    for(int i=0;i<arr.size();i++) if(arr[i]==1) {
        int r = viruses[i].first;
        int c = viruses[i].second;
        q.push({r,c});
        visited[r][c] = 0;
    }

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            if (!in_range(nr,nc) || board[nr][nc] == 1 ||
                visited[nr][nc] != INF) continue;
            visited[nr][nc] = visited[cr][cc] + 1;
            q.push({nr,nc});
        }
    }

    int ret = 0;
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) if(board[r][c] != 1){
        ret = max(ret, visited[r][c]);
    }

    // for(int r=0;r<N;r++) {
    //     for(int c=0;c<N;c++) {
    //         cout << (visited[r][c] == INF ? -1 : visited[r][c]) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return ret;
}

void solve() {
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) if(board[r][c]==2) {
        viruses.push_back({r,c});
    }
    vector<int> arr;
    for(int i=0;i<viruses.size();i++) {
        arr.push_back((i<M ? 1 : 0));
    }
    reverse(arr.begin(), arr.end());

    int ans = INF;

    do {
        // int tmp = bfs(arr);
        // cout << tmp << endl;
        ans = min(ans, bfs(arr));
    } while(next_permutation(arr.begin(), arr.end()));

    cout << (ans == INF ? -1 : ans);
}

int main() {
    cin >> N >> M;
    for(int r=0;r<N;r++) for(int c=0;c<N;c++) cin >> board[r][c];
    solve();
}