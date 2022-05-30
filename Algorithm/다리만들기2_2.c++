# include <iostream>
# include <map>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
# define MAX 10
# define INF 987654321

bool board[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};
int N,M,set_idx = 1;
map<pair<int,int>, int> mapping;
int set[MAX] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

class Edge {
public:
    int a,b,d;
    Edge(int a, int b, int d) : a(a), b(b), d(d) {}
};

int get_parent(int a) {
    if (a == set[a]) return a;
    else return set[a] = get_parent(set[a]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a > b) set[a] = b;
    else set[b] = a;
}

bool is_set(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    return a == b;
}

bool in_range(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    return true;
}

void bfs_visit(int r, int c, int set_idx) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while(!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        mapping[{cr,cc}] = set_idx;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!in_range(nr,nc) || visited[nr][nc] || !board[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
}

void mapping_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;

            if (board[i][j]) {
                bfs_visit(i,j,set_idx++);
            }
        }
    }
}

void find_edge() {
    for (int r = 0; r < N; r++) {
        int last_c = -1;
        for (int c = 0; c < M; c++) {
            if (board[r][c]) {
                if (last_c == -1) {
                    while(c+1 < M && board[r][c+1]) c++;
                    last_c = c;
                }
                else {
                    int last_set = mapping[{r,last_c}];
                    int cur_set = mapping[{r,c}];
                    int d = c - last_c -1;
                    if (d >= 2) {
                        dist[last_set][cur_set] = min(dist[last_set][cur_set], d);
                        dist[cur_set][last_set] = min(dist[cur_set][last_set], d);
                    }
                    while(c+1 < M && board[r][c+1]) c++;
                    last_c = c;
                }
            }
        }
    }

    for (int c = 0; c < M; c++) {
        int last_r = -1;
        for (int r = 0; r < N; r++) {

            if (board[r][c]) {
                if (last_r == -1) {
                    while (r+1 < N && board[r+1][c]) r++;
                    last_r = r;
                }
                else {
                    int last_set = mapping[{last_r,c}];
                    int cur_set = mapping[{r,c}];
                    int d = r - last_r -1;
                    if (d >= 2) {
                        dist[last_set][cur_set] = min(dist[last_set][cur_set], d);
                        dist[cur_set][last_set] = min(dist[cur_set][last_set], d);
                    }
                    while (r+1 < N && board[r+1][c]) r++;
                    last_r = r;
                }
            }
        }
    }
}

bool cmp(Edge &a, Edge &b) {
    return a.d < b.d;
}

vector<Edge> arr;

void mst() {
    int ret = 0;
    int cnt = 0;
    for (Edge node : arr) {
        if (is_set(node.a, node.b)) continue;
        union_node(node.a, node.b);
        ret += node.d;
        cnt++;
        // cout << ret << endl;
    }

    // cout << cnt << " " << set_idx << endl;

    if (cnt != set_idx-2) cout << -1;
    else cout << ret;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < MAX; i++) {
        set[i] = i;
    }

    mapping_board();
    find_edge();

    

    for (int i = 1; i < set_idx; i++) {
        for (int j = i+1; j < set_idx; j++) {
            if (dist[i][j] != INF) {
                arr.push_back(Edge(i,j,dist[i][j]));
                // cout << i << " " << j << " " << dist[i][j] << endl;
            }
        }
    }

    sort(arr.begin(), arr.end(), cmp);
    mst();
}