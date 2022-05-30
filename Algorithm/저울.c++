# include <iostream>
using namespace std;

# define MAX 101

bool go[MAX][MAX] = {0,};
int total_cnt[MAX] = {0,};
int N;

void floyd() {
    for (int bridge = 1; bridge <= N; bridge++) {
        for (int start = 1; start <= N; start++) {
            if (start == bridge) continue;

            for (int end = 1; end <= N; end++) {
                if (end == start || end == bridge) continue;

                if (go[start][bridge] && go[bridge][end]) {
                    go[start][end] = true;
                }
                    
            }
        }
    }
}

void cal_count() {
    for (int start = 1; start <= N; start++) {
        int cnt = 0;
        for (int end = 1; end <= N; end++) {
            if (start == end) continue;

            if (go[start][end]) cnt++;
        }
        total_cnt[start] = N - cnt - 1;
    }

    for (int end = 1; end <= N; end++) {
        for (int start = 1; start <= N; start++) {
            if (go[start][end]) total_cnt[end]--;
        }
    }

}

int main() {
    int M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        go[s][e] = true;
        total_cnt[e] = 1;
    }

    floyd();
    cal_count();

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << go[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= N; i++) {
        cout << total_cnt[i] << "\n";
    }

}