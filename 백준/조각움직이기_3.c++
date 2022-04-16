# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <queue>
# include <math.h>
using namespace std;
# define INF 987654321

vector<string> board;
vector<pair<int,int>> points;
int N = 0;
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
    return true;
}

bool is_connected(const vector<string> &board) {
    queue<pair<int,int>> q;
    bool visited[5][5] = {0,};
    int cnt = 0;

    for (int i = 0; i < 25; i++) {
        if (board[i/5][i%5]== '*') {
            q.push({i/5, i%5});
            visited[i/5][i%5] = true;
            cnt++;
            break;
        }
    }
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (!in_range(nr,nc) || visited[nr][nc] || board[nr][nc] != '*') {
                continue;
            }

            visited[nr][nc] = true;
            q.push({nr,nc});
            cnt++;
        }
    }

    return cnt==N;
}

int get_dist(const pair<int,int> &p1, const pair<int,int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int min_dist(vector<pair<int,int>> &v1, vector<pair<int,int>> &v2) {
    vector<int> arr;
    for (int i = 0; i < v1.size(); i++) {
        arr.push_back(i);
    } 

    int ret = INF;
    do {
        int tmp = 0;
        for (int i = 0; i < v1.size(); i++) {
            tmp += get_dist(v1[i], v2[arr[i]]);
        }
        ret = min(ret, tmp);
    } while (next_permutation(arr.begin(), arr.end()));

    return ret;
}

int main() {
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == '*') {
                N++;
                points.push_back({r,c});
            }
        }
    }
    vector<int> arr;
    for (int i = 0; i < 25-N; i++) arr.push_back(0);
    for (int i = 0; i < N; i++) arr.push_back(1);

    int result = INF;

    do {
        vector<string> tmp(5, ".....");
        vector<pair<int,int>> tmp_points;

        for (int i = 0; i < 25; i++) {
            if (arr[i] == 1) {
                tmp[i/5][i%5] = '*';
                tmp_points.push_back({i/5, i%5});
            }
        }

        if (is_connected(tmp)) {
            result = min(result, min_dist(points, tmp_points));
        }
    } while(next_permutation(arr.begin(), arr.end()));

    cout << result;
}