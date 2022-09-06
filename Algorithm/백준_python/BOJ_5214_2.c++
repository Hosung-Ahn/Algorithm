#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,K,M;
int board[1000][1000] = {0,};
bool visited[1000][1000] = {0,};
vector<pair<int,int>> link[100001];
struct Node {
    int m, k, d;
    Node(int m, int k, int d) : m(m), k(k), d(d) { }
    bool operator<(const Node &other) const {
        return d > other.d;
    } 
};

void bfs(queue<Node> &q) {
    while(!q.empty()) {
        int cm = q.front().m;
        int ck = q.front().k;
        int cd = q.front().d;
        q.pop();
        if (board[cm][ck] == N) {
            cout << cd;
            return;
        }
        for(int nk=0;nk<K;nk++) {
            if (visited[cm][nk]) continue;
            q.push(Node(cm,nk,cd+1));
            visited[cm][nk] = true;
        }
        for(auto p : link[board[cm][ck]]) {
            int nm = p.first;
            int nk = p.second;
            if (visited[nm][nk]) continue;
            visited[nm][nk] = true;
            q.push(Node(nm,nk,cd));
        }
    }
    cout << -1;
}

int main() {
    cin >> N >> K >> M;
    queue<Node> q;
    for(int m=0;m<M;m++) {
        for(int k=0;k<K;k++) {
            cin >> board[m][k];
            link[board[m][k]].push_back({m,k});
            if (board[m][k] == 1) {
                q.push(Node(m,k,1));
                visited[m][k] = true;
            }
        }
    }
    bfs(q);
}