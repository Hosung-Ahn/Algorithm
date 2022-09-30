#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321
int N;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Node {
    int r,c,d;
    Node(int r, int c, int d) : r(r), c(c), d(d) {}
};

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return false;
    return true;
}

int bfs(const vector<vector<int>> &board) {
    queue<Node> q;
    int visited[25][25][4];
    for (int i=0;i<25;i++) for(int j=0;j<25;j++) for (int k=0;k<4;k++) {
        visited[i][j][k] = INF;
    }
    for(int i=0;i<4;i++) {
        int r = dr[i];
        int c = dc[i];
        if (!in_range(r,c) || board[r][c] == 1) continue;
        q.push(Node(r,c,i));
        visited[r][c][i] = 100;
    }

    while(!q.empty()) {
        int cr = q.front().r;
        int cc = q.front().c;
        int cd = q.front().d;
        q.pop();
        cout << cr << " " << cc << " " << cd << " " << visited[cr][cc][cd] << endl;

        for (int nd=0;nd<4;nd++) { 
            int nr = cr+dr[nd];
            int nc = cc+dc[nd];
            if (!in_range(nr,nc) || board[nr][nc] == 1) continue;
            if ((nd+2)%4 == cd) continue;
            int cost = visited[cr][cc][cd];

            if (nd==cd) cost += 100;
            else cost += 600;

            if (visited[nr][nc][nd] <= cost) continue;
            visited[nr][nc][nd] = cost;
            q.push(Node(nr,nc,nd));
        }
    }
    int ans = INF;
    for(int i=0;i<4;i++) {
        ans = min(ans, visited[N-1][N-1][i]);
    }
    return ans;
}

int solution(vector<vector<int>> board) {
    N = board.size(); 
    return bfs(board);
}

int main() {
    vector<vector<int>> board = {{0,0,0}, {0,0,0}, {0,0,0}};
    cout << solution(board);
}