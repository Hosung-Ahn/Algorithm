# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 32001

int in_degree[MAX] = {0,};
vector<int> order[MAX];
int N,M;

void topology_sort() {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) 
            q.push(i);
    }

    for (int i = 0; i < N; i++) {
        int cur = q.front();
        q.pop();

        result.push_back(cur);

        for (int next : order[cur]) {
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int x : result) {
        cout << x << " ";
    }
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s,e; scanf("%d %d", &s, &e);
        order[s].push_back(e);
        in_degree[e]++;
    }
    topology_sort();
}