# include <iostream>
# include <string.h>
# include <queue>
using namespace std;
# define MAX 500001

int sister[MAX];
int visited[MAX];
int N,K, cnt = 0; 

int plus_1(int a) {
    return a+1;
}
int minus_1(int a) {
    return a-1;
}
int mul_2(int a) {
    return a*2;
}

int (*next_step[])(int) = {plus_1, minus_1, mul_2};

bool in_range(int a) {
    if (a < 0 || a >= MAX) return false;
    return true;
}

void bfs(int start) {
    queue<pair<int,int>> q;
    q.push({start,0});

    while(!q.empty()) {
        int cur_point = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if (sister[cur_point] == cur_cnt) {
            cout << cur_cnt;
            return;
        }

        for (int i = 0; i < 3; i++) {
            int next = next_step[i](cur_point);
            if (!in_range(next) || cur_cnt+1 > cnt || visited[next] == cur_cnt+1) continue;
            q.push({next, cur_cnt+1});
            visited[next] = cur_cnt+1;
        }
    }

    cout << -1;
}

int main() {
    cin >> N >> K;
    memset(sister, -1, sizeof(int)*MAX);
    memset(visited, -1, sizeof(int)*MAX);

    int idx = K;
    for (int i = 0; idx < MAX; i++) {
        idx += i;
        if (idx >= MAX) continue;
        sister[idx] = i;
        cnt = i;
    }
    // cout << cnt << endl;

    bfs(N);
}
