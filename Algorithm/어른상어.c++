#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 21
int N,M,K;

int shark[MAX][MAX] = {0,};
vector<vector<vector<int>>> shark_copy(MAX, vector<vector<int>>(MAX, vector<int>()));
int shark_D[MAX*MAX] = {0,};
int smell[MAX][MAX][2] = {0,};
int go[MAX*MAX][5][4] = {0,};
int dr[] = {0,-1,1,0,0};
int dc[] = {0,0,0,-1,1};
bool no_smell[5] = {0,};
bool my_smell[5] = {0,};

bool in_range(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N) return false;
    return true;
}

bool is_no_smell(int r, int c) {
    bool ret = false;
    for (int d = 1; d <= 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (!in_range(nr,nc) || smell[nr][nc][1] > 0) continue;
        no_smell[d] = true;
        ret = true;
    }
    return ret;
}

bool is_my_smell(int r, int c) {
    int ret = false;
    for (int d = 1; d <= 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (!in_range(nr,nc) || smell[r][c][0] != smell[nr][nc][0]) continue;
        my_smell[d] = true;
        ret = true;
    }
    return ret;
}

bool one_time() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int n = shark[r][c];
            int d = shark_D[n];
            if (shark[r][c] == 0) continue;

            memset(no_smell, 0, sizeof(bool)*5);
            memset(my_smell, 0, sizeof(bool)*5);
            if (is_no_smell(r,c)) {
                for (int i = 0; i < 4; i++) {
                    if (no_smell[go[n][d][i]]) {
                        int nr = r + dr[go[n][d][i]];
                        int nc = c + dc[go[n][d][i]];
                        shark_copy[nr][nc].push_back(n);
                        shark_D[n] = go[n][d][i];
                        break;
                    }
                }
            }
            else if (is_my_smell(r,c)) {
                for (int i = 0; i < 4; i++) {
                    if (my_smell[go[n][d][i]]) {
                        int nr = r + dr[go[n][d][i]];
                        int nc = c + dc[go[n][d][i]];
                        shark_copy[nr][nc].push_back(n);
                        shark_D[n] = go[n][d][i];
                        break;
                    }
                }
            }
            
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (smell[r][c][1] > 0) smell[r][c][1]--;
        }
    }

    for (int r = 0; r < MAX; r++) {
        memset(shark[r], 0, sizeof(int)*MAX);
    }

    int cnt = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (shark_copy[r][c].empty()) continue;
            sort(shark_copy[r][c].begin(), shark_copy[r][c].end());
            shark[r][c] = shark_copy[r][c].front();
            smell[r][c][0] = shark[r][c];
            smell[r][c][1] = K;
            shark_copy[r][c].clear();
            cnt++;
        }
    }

    return cnt == 1;
}

void solution() {
    int result = 1;

    while(!one_time()) {
        result++;
        if (result > 1000) {
            cout << -1;
            return;
        }
    }
    cout << result;
}

int main() {
    cin >> N >> M >> K;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> shark[r][c];

            if (shark[r][c] != 0) {
                smell[r][c][0] = shark[r][c];
                smell[r][c][1] = K;
            }
            
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> shark_D[i];
    }
    for (int i = 1; i <= M; i++) {
        for (int d = 1; d <= 4; d++) {
            for (int j = 0; j < 4; j++) {
                cin >> go[i][d][j];
            }
        }
    }
    solution();
}