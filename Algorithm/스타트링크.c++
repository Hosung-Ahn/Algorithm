# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 1000001
bool visited[MAX] = {0,};
int cnt[MAX] = {0,};
int F,S,G,U,D;
vector<int> dm;

void bfs(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next = cur + dm[i];
            if (next < 1 || next > F || visited[next]) continue;
            cnt[next] = cnt[cur] + 1;
            visited[next] = true;
            q.push(next);
        }
    }


}

int main() {
    cin >> F >> S >> G >> U >> D;
    dm.push_back(U);
    dm.push_back(-D);

    bfs(S);

    if (cnt[G] == 0 && S != G) cout << "use the stairs";
    else cout << cnt[G]; 
}