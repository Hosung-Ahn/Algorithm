#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10001
#define ll long long
#define INF 98765432100

struct Node {
    int e,k;
    ll d;
    Node(int e, ll d, int k) : e(e), d(d), k(k) { }

    bool operator<(const Node &b) const{
        return this->d > b.d;
    }
};

vector<pair<int,int>> edges[MAX];
ll d[MAX][21];
int N,M,K;

void dijstra(int start) {
    d[start][0] = 0;
    priority_queue<Node> pq;
    pq.push(Node(start, 0, 0));

    while(!pq.empty()) {
        int cur = pq.top().e;
        ll cur_d = pq.top().d;
        int cur_k = pq.top().k;
        pq.pop();

        // cout << cur << " " << cur_d << " " << cur_k << endl;

        if (d[cur][cur_k] < cur_d) continue;

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].first;
            ll next_d = cur_d + edges[cur][i].second;

            if (d[next][cur_k] > next_d) {
                d[next][cur_k] = next_d;
                pq.push(Node(next, next_d, cur_k));
            }

            if (cur_k < K && d[next][cur_k+1] > cur_d) {
                d[next][cur_k+1] = cur_d;
                pq.push(Node(next, cur_d, cur_k+1));
            }
        }
    }

    ll result = INF;
    for (int i = 0; i <= K; i++){
        // cout << d[N][i] << endl;
        result = min(result, d[N][i]);
    }
    cout << result;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        int s,e,d; cin >> s >> e >> d;
        edges[s].push_back({e,d});
        edges[e].push_back({s,d});
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 21; j++) {
            d[i][j] = INF;
        }
    }

    dijstra(1);


}