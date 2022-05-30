# include <iostream>
# include <queue>
# include <vector>
using namespace std;

# define MAX 501

int in_degree[MAX] = {0,};
int times[MAX] = {0,};
int total_times[MAX] = {0,};
int N;
vector<int> go[MAX];

void topology_sort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 0; i < N; i++) {
        int cur = q.front();
        q.pop();
        total_times[cur] += times[cur];

        for (int next : go[cur]) {
            if(--in_degree[next] == 0) {
                q.push(next);
            }
            total_times[next] = max(total_times[next], total_times[cur]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << total_times[i] << "\n";
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int in;
        scanf("%d %d", &times[i], &in);
        while (in != -1) {
            go[in].push_back(i);
            in_degree[i]++;
            scanf("%d", &in);
        }
    }

    topology_sort();
}