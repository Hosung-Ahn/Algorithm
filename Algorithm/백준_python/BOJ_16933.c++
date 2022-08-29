#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int N,M,K;
vector<string> board;
int visited[1000][1000][11][2] = {0,};
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

struct Node {
    int r,c,k,day, debug;
    Node(int r, int c, int k, int day) : r(r), c(c), k(k), day(day) {}
};

bool in_range(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=M) return false;
    return true;
}

void bfs() {
    queue<Node> q;
    visited[0][0][0][0] = 1;
    q.push(Node(0,0,0,0));
    while(!q.empty()) {
        int cr = q.front().r; 
        int cc = q.front().c;
        int ck = q.front().k;
        int cday = q.front().day;
        q.pop();

        if (cr == N-1 && cc == M-1) {
            cout << visited[cr][cc][ck][cday];
            return;
        }

        // 최단경로이므로 뚫은 벽을 다시 뚫어야 하는 경우는 일반적으로 발생하지 않는다.
        // 하지만 제자리로 이동할 수 있고 낮과 밤 때문에 제자리로 이동하는 경우가 더 효율적인 상황이 생기므로
        // 뚫은 벽을 다시 뚫어야하는 것처럼 보이는 상황이 발생한다.(ex. 벽을 뚫고 위치한 자리에서 제자리로 이동하는 경우)
        int nday = (cday+1)%2;
        if (visited[cr][cc][ck][nday] == 0 || 
            visited[cr][cc][ck][nday] > visited[cr][cc][ck][cday]+1) {

            visited[cr][cc][ck][nday] = visited[cr][cc][ck][cday]+1;
            q.push(Node(cr,cc,ck,nday));
        }

        for(int i=0;i<4;i++) {
            int nr = cr+dr[i];
            int nc = cc+dc[i];
            int nday = (cday+1)%2;
            if (!in_range(nr, nc)) continue;
            int nk = ck;

            if (board[nr][nc] == '1') {
                if (cday == 1 || ck >= K) continue;
                nk = ck+1;
            }
            
            if (visited[nr][nc][nk][nday] != 0 && 
                (visited[nr][nc][nk][nday] <= visited[cr][cc][ck][cday]+1)) 
                continue;
            visited[nr][nc][nk][nday] = visited[cr][cc][ck][cday]+1;
            q.push(Node(nr,nc,nk,nday));
        }
    }
    cout << -1;
}


int main() {
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    bfs();
}