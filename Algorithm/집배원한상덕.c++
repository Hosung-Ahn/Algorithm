#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define MAX 50

vector<string> board;
vector<int> arr;
bool a[1000001] = {0,};
int h[MAX][MAX];
int N,sr,sc, cnt_end = 0;
int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return false;
    return true;
}

bool in_height_range(int lo, int hi, int val) {
    return lo <= val && val <= hi;
}

bool bfs(int lo, int hi) {
    bool visited[MAX][MAX] = {0,};
    queue<pair<int,int>> q;
    q.push({sr,sc});
    visited[sr][sc] = true;
    int cnt = 0;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (!in_height_range(lo,hi,h[cr][cc])) continue;

        if (board[cr][cc] == 'K') cnt++;

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || !in_height_range(lo,hi,h[nr][nc]) || visited[nr][nc]) continue;

            q.push({nr,nc});
            visited[nr][nc] = true;
        }
    }
    // cout << cnt << endl;

    return cnt == cnt_end;
}

void solve() {
    int left = 0, right = 0;
    int ans = 987654321;
    while(right < arr.size()) {
        if (bfs(arr[left],arr[right])) {
            // cout << left << " " << right << endl;   
            ans = min(ans, arr[right]-arr[left]);
            left++;
        }
        else right++;
    }
    cout << ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> h[i][j];
            a[h[i][j]] = true;
            if (board[i][j] == 'P') {
                sr = i;
                sc = j;
            }
            if (board[i][j] == 'K') cnt_end++;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        if (a[i]) arr.push_back(i);
    }

    solve();
}