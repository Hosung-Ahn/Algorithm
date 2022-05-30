# include <iostream>
# include <string.h>
# include <queue>
using namespace std;
# define MAX 500001
# define INF 987654321

vector<pair<int,int>> sister;
int visited[MAX][2];
int N,K; 

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
    visited[start][0] = 0;

    while (!q.empty()) {
        int cur_point = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next_point = next_step[i](cur_point);
            int next_cnt = cur_cnt + 1;
            if (!in_range(next_point) || visited[next_point][next_cnt%2] != -1) continue;

            q.push({next_point, next_cnt});
            visited[next_point][next_cnt%2] = next_cnt;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < MAX; i++)
        memset(visited[i], -1, sizeof(int)*2);

    int idx = K;
    for (int i = 0; idx < MAX; i++) {
        idx += i;
        if (idx >= MAX) break;
        sister.push_back({idx,i});
    }
    bfs(N);

    int result = INF;

    for (pair<int,int> sis : sister) {
        int point = sis.first;
        int cnt = sis.second;
        if (cnt >= visited[point][0] && (cnt - visited[point][0]) % 2 == 0) {
            result = min(result, cnt);
        } 
        if (cnt >= visited[point][1] && (cnt - visited[point][1]) % 2 == 0) {
            result = min(result, cnt);
        } 
        
    }

    if (result == INF) cout << -1;
    else cout << result;
}
