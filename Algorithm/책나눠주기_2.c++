#include <iostream>
#include <cstring>
using namespace std;
# define MAX 1001

pair<int,int> person[MAX];
int owner[MAX] = {0,};
bool visited[MAX] = {0,};
int N,M;

bool dfs(int p) {
    for (int book = person[p].first; book <= person[p].second; book++) {
        if (visited[book]) continue;
        visited[book] = true;
        if (owner[book] == 0 || dfs(owner[book])) {
            owner[book] = p;
            return true;
        }
    }
    return false;
} 


int main() {
    int T; cin >> T;
    while(T--) {
        cin >> N >> M;
        int cnt = 0;
        for (int p = 1; p <= M; p++) {
            int a,b; cin >> a >> b;
            person[p] = {a,b};
            memset(visited, 0, sizeof(bool)*MAX);
            if (dfs(p)) cnt++;
        }    
        cout << cnt << endl;
        memset(owner, 0, sizeof(int)*MAX);
    }
}