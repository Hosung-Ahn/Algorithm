# include <iostream>
# include <vector>
# include <string.h>
using namespace std;

# define MAX 101
# define INF 987654321


class Node {
public:
    int end, m, d;
    Node(int end, int m, int d) : end(end), m(m), d(d) { }
};

vector<Node> edges[MAX];
int N,M,K; 
int dp[MAX][10001] = {0,};

int find_dp(int start, int M) {
    if (M < 0) return INF;
    if (start == N) return 0;
    if (dp[start][M] != 0) return dp[start][M];

    int result = INF;
    for (Node next : edges[start]) {
        result = min(result, next.d + find_dp(next.end, M - next.m));
    }
    dp[start][M] = result;
    return result;
}

void clear() {
    for (int i = 0; i < MAX; i++)
        edges[i].clear();
    for (int i = 0; i < MAX; i++)
        memset(dp[i], 0, sizeof(int)*10001);
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            int u,v,c,d; scanf("%d %d %d %d", &u, &v, &c, &d);
            edges[u].push_back(Node(v,c,d));
        }

        int result = find_dp(1,M);
        
        if (result == INF) cout << "Poor KCM\n";
        else cout << result << "\n";
        clear();
    }
}

