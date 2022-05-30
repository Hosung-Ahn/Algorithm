# include <iostream>
# include <string.h>
# include <queue>
using namespace std;

# define MAX 200001

int visited[MAX];
int cnt[MAX] = {0,};

int minus1(int a) {
    return a-1;
}
int plus1(int a) {
    return a + 1;
}
int mul2(int a) {
    return a*2;
}

bool in_range(int a) {
    if (a < 0 || a >= MAX) return false;
    return true;
}

int (*next_num[])(int) = {minus1, plus1, mul2};

void bfs(int start, int end) {
    visited[start] = 0;
    cnt[start] = 1;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int next = next_num[i](cur);
            if (!in_range(next)) continue;

            if (visited[next] == -1) {
                visited[next] = visited[cur] + 1;
                cnt[next] = 1;
                q.push(next);
            }

            else {
                if (visited[next] == visited[cur] + 1) {
                    cnt[next]++;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    int start,end; scanf("%d %d", &start, &end);
    memset(visited, -1, sizeof(int)*MAX);

    bfs(start, end);

    cout << visited[end] << "\n" << cnt[end];
}