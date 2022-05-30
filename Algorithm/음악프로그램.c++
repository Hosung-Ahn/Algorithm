# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 1001

vector<int> edges[MAX];
vector<int> result;
int in_degree[MAX] = {0,};
int N,M;

void typology_sort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : edges[cur]) {
            if (--in_degree[next] == 0) {
                q.push(next);
                result.push_back(next);
            }
        }
    }

    if (result.size() < N) {
        cout << 0;
        return;
    }

    for (int x : result) cout << x << "\n";
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int K; scanf("%d", &K);
        vector<int> arr;
        for (int j = 0; j < K; j++) {
            int x; scanf("%d", &x);
            arr.push_back(x);
        }

        for (int j = 0; j < K-1; j++) {
            edges[arr[j]].push_back(arr[j+1]);
            in_degree[arr[j+1]]++;
        }
    }

    typology_sort();

}