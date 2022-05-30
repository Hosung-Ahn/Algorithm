# include <iostream>
# include <vector>
# include <string>
# include <string.h>
# include <queue>
using namespace std;

# define MAX 20000+1
bool visited[MAX] = {0,};
int MOD;

void bfs() {
    queue<pair<int,string>> q;
    q.push({1,"1"});
    visited[1] = true;

    while (!q.empty()) {
        int cur_mod = q.front().first;
        string cur_nums = q.front().second;
        q.pop();

        if (cur_mod == 0) {
            cout << cur_nums << "\n";
            return;
        }

        int nexts[2];
        nexts[0] = (cur_mod*10+0) % MOD;
        nexts[1] = (cur_mod*10+1) % MOD;

        string next_nums[2];
        next_nums[0] = cur_nums + "0";
        next_nums[1] = cur_nums + "1";

        for (int i = 0; i < 2; i++) {
            int next = nexts[i];
            if (visited[next]) continue;

            q.push({next, next_nums[i]});
            visited[next] = true;
        }
    }

    cout << "BRAK\n";
}

void clear() {
    memset(visited, 0, sizeof(bool)*MAX);
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> MOD;
        bfs();
        clear();
    }
}
