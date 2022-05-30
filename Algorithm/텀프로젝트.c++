# include <iostream>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 100001
int arr[MAX];
int in_degree[MAX] = {0,};
int N;

void topology_sort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    int cnt = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (--in_degree[arr[cur]] == 0)
            q.push(arr[cur]);
        cnt++;
    }
    cout << cnt << "\n";
}

int main() {

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        memset(in_degree, 0, sizeof(int)*MAX);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
            in_degree[arr[i]]++;
        }
        topology_sort();
    }
}