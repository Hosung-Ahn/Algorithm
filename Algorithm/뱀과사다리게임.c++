#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
# define MAX 101
# define INF 987654321

int Ladder[MAX] = {0,};
int Snake[MAX] = {0,};
int cnt[MAX];

void bfs(int start) {
    cnt[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 100) {
            cout << cnt[cur];
            return;
        }

        for (int n = 1; n < 7; n++) {
            int next = cur + n;
            if (Ladder[next]) next = Ladder[next];
            if (Snake[next]) next = Snake[next];

            if (next > 100 || cnt[next] <= cnt[cur] + 1) continue;

            cnt[next] = cnt[cur] + 1;
            q.push(next);
        }
    }
}


int main() {
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        Ladder[x] = y;
    }
    for (int i = 0; i < M; i++) {
        int x,y; cin >> x >> y;
        Snake[x] = y;
    }
    for (int i = 0; i < MAX; i++) {
        cnt[i] = INF;
    }

    bfs(1);
}