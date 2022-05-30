# include <iostream>
# include <string>
# include <math.h>
# include <vector>
# include <queue>
# include <string.h>
# include <algorithm>
using namespace std;
# define INF 987654321

vector<string> board;
vector<pair<int,int>> points;
vector<vector<int>> marked(5,vector<int>(5,0));

int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

bool in_range(int r, int c) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5) return false;
    return true;
}

int get_distance(const pair<int,int> &p1, const pair<int,int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int min_distance() {
    vector<pair<int,int>> marked_points;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (marked[r][c]) {
                marked_points.push_back({r,c});
            }
        }
    }

    int ret = INF;
    vector<int> arr;
    for (int i = 0; i < points.size(); i++) {
        arr.push_back(i);
    }

    // cout << points.size() << " " << marked_points.size() << endl;

    do {
        int tmp = 0;
        for (int i = 0; i < points.size(); i++) {
            tmp += get_distance(points[i], marked_points[arr[i]]);
        }
        ret = min(ret, tmp);
    } while (next_permutation(arr.begin(), arr.end()));

    return ret;
}

int dfs(int r, int c, int N) {
    int result = INF;
    if (marked[r][c] == N) {
        return min_distance();
    }                                                                                                          
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!in_range(nr,nc) || marked[nr][nc] >= marked[r][c]) continue;
        
        if (marked[nr][nc] != 0) marked[nr][nc] = marked[r][c];
        else marked[nr][nc] = marked[r][c] + 1;
        result = min(result, dfs(nr,nc,N));
        marked[nr][nc] = 0;
    }
    return result;
}



int main() {
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        board.push_back(s);
    }

    int N = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == '*') {
                N++;
                points.push_back({r,c});
            }
        }
    }

    int result = INF;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            marked[r][c] = 1;
            result = min(result, dfs(r,c,N));
            marked[r][c] = 0;
        }
    }
    cout << result;
}
