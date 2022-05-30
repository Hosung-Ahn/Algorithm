#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000
int cnt[MAX][MAX] = {0,};
int idx[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int result[MAX][MAX] = {0,};
vector<string> board;
int N,M;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

int find_cnt(int r, int c, int ai) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = 1;
    idx[r][c] = ai;

    int ret = 0;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        ret++;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc] == '1') continue;

            visited[nr][nc] = 1;
            idx[nr][nc] = ai;
            q.push({nr,nc});
        }
    }
    return ret;
}

void set_cnt_idx(int r, int c, int ac) {
    queue<pair<int,int>> q;
    q.push({r,c});
    cnt[r][c] = ac;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || board[nr][nc] == '1' ||
                idx[nr][nc] != idx[cr][cc] || cnt[nr][nc] == cnt[cr][cc]) continue;

            cnt[nr][nc] = ac;
            q.push({nr,nc});
        }
    }
}

void set() {
    int ai = 1;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == '1' || cnt[r][c] > 0) continue;
            int ac = find_cnt(r,c,ai++);
            set_cnt_idx(r,c,ac);
        }
    }
}

bool alreay_counted(const vector<int> &arr, int x) {
    for (int n : arr) {
        if (n == x) return true;
    }
    return false;
}

void solution() {
    vector<int> arr;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (board[r][c] == '0') continue;

            arr.clear();
            int sum = 1;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!in_range(nr,nc) || 
                    board[nr][nc] == '1' || 
                    alreay_counted(arr,idx[nr][nc])) continue;
                arr.push_back(idx[nr][nc]);
                sum += cnt[nr][nc];
            }
            result[r][c] = sum;
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cout << result[r][c] % 10;
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    set();
    solution();

    // for (int r = 0; r < N; r++) {
    //     for (int c = 0; c < M; c++) {
    //         cout << cnt[r][c] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    // for (int r = 0; r < N; r++) {
    //     for (int c = 0; c < M; c++) {
    //         cout << idx[r][c] << " ";
    //     }
    //     cout << endl;
    // }
}