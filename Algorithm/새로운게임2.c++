#include <iostream>
#include <vector>
using namespace std;
#define MAX 13

class Node {
public:
    int k,d;
    Node(int k, int d) : k(k), d(d) { }  
    void change() {
        if (d == 1 || d == 3) d += 1;
        else d -= 1;
    }
};

int board[MAX][MAX];
int N,K;
vector<Node> nodes[MAX][MAX];
int dr[] = {0,0,0,-1,1};
int dc[] = {0,1,-1,0,0};

bool in_range(int r, int c) {
    if (r < 1 || r > N || c < 1 || c > N) return false;
    return true;
}

void move_white(int r, int c, int nr, int nc, int idx) {
    int maxI = nodes[r][c].size();
    for (int i = idx; i < maxI; i++) {
        nodes[nr][nc].push_back(nodes[r][c][i]);
    }
    for (int i = 0; i < maxI-idx; i++) {
        nodes[r][c].pop_back();
    }
}

void move_Red(int r, int c, int nr, int nc, int idx) {
    int maxI = nodes[r][c].size();
    for (int i = maxI-1; i >= idx; i--) {
        nodes[nr][nc].push_back(nodes[r][c][i]);
    }
    for (int i = 0; i < maxI-idx; i++) {
        nodes[r][c].pop_back();
    }
}

bool moveK(int k) {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (nodes[r][c].empty()) continue;

            // cout << k << " : " << r << " " << c << endl;
            for (int i = 0; i < nodes[r][c].size(); i++) {
                if (nodes[r][c][i].k != k) continue;

                int nr = r + dr[nodes[r][c][i].d];
                int nc = c + dc[nodes[r][c][i].d];
                if(!in_range(nr,nc) || board[nr][nc] == 2) {
                    nodes[r][c][i].change();
                    nr = r + dr[nodes[r][c][i].d];
                    nc = c + dc[nodes[r][c][i].d];

                    if(!in_range(nr,nc) || board[nr][nc] == 2) return false;
                }
                if (board[nr][nc] == 0) {
                    move_white(r,c,nr,nc,i);
                    // cout << k << " : " << nr << " " << nc << " " << nodes[nr][nc].size()<< endl;
                    return nodes[nr][nc].size() >= 4;
                }
                if (board[nr][nc] == 1) {
                    move_Red(r,c,nr,nc,i);
                    // cout << k << " : " << nr << " " << nc << " " << nodes[nr][nc].size()<< endl;
                    return nodes[nr][nc].size() >= 4;
                }
            }
        }
    }
    return false;
}

bool one_time() {
    for (int k = 1; k <= K; k++) {
        if (moveK(k)) return true;
    }
    return false;
}

void solution() {
    int cnt = 1;
    while(!one_time()) {
        cnt++;
        if (cnt > 1000) {
            cout <<-1;
            return;
        }
    }
    cout << cnt;
}

int main() {
    cin >> N >> K;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> board[r][c];
        }
    }
    for (int k = 1; k <= K; k++) {
        int r, c, d;
        cin >> r >> c >> d;
        nodes[r][c].push_back(Node(k,d));
    }

    solution();
    
}
