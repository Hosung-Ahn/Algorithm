#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 101

struct WALL {
    int x,y,r;
    WALL(int x, int y, int r) : x(x), y(y), r(r) { }
};

vector<WALL> walls;
vector<int> go[MAX];

int max_dist = 0;
int end_point = 0;
bool visited[MAX] = {0,};

bool cmp(const WALL &a, const WALL &b) {
    return a.r < b.r;
}

bool is_include(const WALL &a, const WALL &b) {
    int d = (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y);
    return d <= (a.r-b.r)*(a.r-b.r);
}

void dfs(int cur, int dist) {
    if (visited[cur]) return;
    if (dist > max_dist) {
        max_dist = dist;
        end_point = cur;
    }
    visited[cur] = true;
    for (int next : go[cur]) {
        dfs(next, dist+1);
    }
    visited[cur] = false;
}

void clear() {
    max_dist = 0;
    end_point = 0;
    walls.clear();
    for (int i = 0; i < MAX; i++) {
        go[i].clear();
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            int x,y,r; cin >> x >> y >> r;
            walls.push_back(WALL(x,y,r));
        }

        sort(walls.begin(), walls.end(), cmp);

        for (int i = 0; i < N; i++) {
            for (int pi = i+1; pi < N; pi++) {
                if (is_include(walls[i], walls[pi])) {
                    go[i+1].push_back(pi+1);
                    go[pi+1].push_back(i+1);
                    break;
                }
            }
        }

        dfs(1,0);
        dfs(end_point, 0);

        cout << max_dist << "\n";
        clear();
    }
}

