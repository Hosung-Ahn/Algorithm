# include <iostream>
# include <queue>
# include <cstring>
# include <vector>
# include <algorithm>
using namespace std;
# define MAX 21

bool Wall[MAX][MAX] = {0,}, Start[MAX][MAX] = {0,};
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int sr,sc,er,ec, fuel, N,M;
vector<vector<int>> start_end(400, vector<int>());

class Point {
    public:
    int r,c,d;

    Point(int r, int c, int d) : r(r) , c(c), d(d) {}

    bool operator<(const Point& a) const {
        if (d == a.d) {
            if (r == a.r) {
                return c < a.c;
            }
            return r < a.r;
        }
        return d < a.d;
    }
};

bool in_range(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N) return false;
    return true;
}

bool find_next(int &r, int &c) {
    int cnt[MAX][MAX];
    for(int i = 0; i < MAX; i++)
        memset(cnt[i], -1, sizeof(int)*MAX);

    cnt[r][c] = 0;
    queue<pair<int,int>> q;
    q.push({r,c});

    vector<Point> arr;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (Start[cr][cc]) {
            arr.push_back(Point(cr,cc,cnt[cr][cc]));
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || Wall[nr][nc] || cnt[nr][nc] >= 0) continue;

            cnt[nr][nc] = cnt[cr][cc] + 1;
            q.push({nr,nc});
        }

    }

    if (arr.empty()) return false;

    sort(arr.begin(), arr.end());
    r = arr.front().r;
    c = arr.front().c;
    Start[r][c] = false;
    fuel -= arr.front().d;

    if (fuel < 0) return false;
    return true;
}

void find_end(int sr, int sc, int& er, int& ec) {
    for (vector<int> v : start_end) {
        if (v[0] == sr && v[1] == sc) {
            er = v[2];
            ec = v[3];
            return;
        }
    }
}

bool find_dist(int sr, int sc, int er, int ec) {
    int cnt[MAX][MAX];
    for (int i = 0; i < MAX; i++) {
        memset(cnt[i], -1, sizeof(int)*MAX); 
    }
    cnt[sr][sc] = 0;
    
    queue<pair<int,int>> q;
    q.push({sr,sc});

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (cr == er && cc == ec) {
            if (fuel-cnt[cr][cc] < 0) return false;
            fuel += cnt[cr][cc];
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || Wall[nr][nc] || cnt[nr][nc] >= 0 ) continue;
            cnt[nr][nc] = cnt[cr][cc] + 1;
            q.push({nr,nc});
        }
    }

    return false;
}

void solution() {
    while(1){
        // cout << sr << " " << sc << " " << fuel << endl;
        if (!find_next(sr,sc)) {
            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++) {
                    if (Start[r][c]) {
                        cout << -1;
                        return;
                    }
                }
            }
            cout << fuel;
            return;
        }
        // cout << sr << " " << sc << " " << fuel << endl;
        // cout << endl;

        find_end(sr,sc,er,ec);

        if (!find_dist(sr,sc,er,ec)) {
            cout << -1;
            return; 
        }

        sr = er;
        sc = ec;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> fuel;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> Wall[r][c];
        }
    }

    cin >> sr >> sc;

    for (int i = 0; i < M; i++) {
        int si,sj,ei,ej;
        cin >> si >> sj >> ei >> ej;
        start_end[i].push_back(si);
        start_end[i].push_back(sj);
        start_end[i].push_back(ei);
        start_end[i].push_back(ej);
        Start[si][sj] = true;
    }

    solution();
}