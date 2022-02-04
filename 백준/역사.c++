# include <iostream>
using namespace std;

# define MAX 401

bool go[MAX][MAX] = {0,};

int N, M;

void floyd() {
    for (int bridge = 1; bridge <= N; bridge++) {
        for (int start = 1; start <= N; start++) {
            if (bridge == start) continue;
            for (int end = 1; end <= N; end++) {
                if (end == bridge || end == start) continue;

                if (go[start][bridge] && go[bridge][end])
                    go[start][end] = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        go[s][e] = true;
    }

    floyd();

    int K; cin >> K;

    for (int i = 0; i < K; i++) {
        int s,e; scanf("%d %d", &s, &e);
        if (go[s][e]) cout << "-1\n";
        else if (go[e][s]) cout << "1\n";
        else cout << "0\n";
    }


}