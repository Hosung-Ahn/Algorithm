# include <iostream>
# include <vector> 
# include <queue>
# include <cstdio>

using namespace std;

# define MAX 201
int N,M;

vector<int> go[MAX];
int arr[1000];

bool can_go(int start, int end) {
    bool visited[MAX] = {0,};
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) return true;

        for (int next : go[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}

void print_result() {
    if (M == 1) {
        if (arr[0] >= 1 && arr[0] <= N) {
            cout << "YES";
            return;
        }
        cout << "NO";
        return;
    }
    for (int i = 1; i < M; i++) {
        if (!can_go(arr[i-1], arr[i])) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int s = 1; s <= N; s++) {
        for (int e = 1; e <= N; e++) {
            int x; cin >> x;
            if (x == 0) continue;
            go[s].push_back(e);
        }
    }

    for (int i = 0; i < M; i++) 
        scanf("%d", &arr[i]);

    print_result();
    
}
