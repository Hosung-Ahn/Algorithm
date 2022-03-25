# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
# include <math.h>
using namespace std;

# define MAX 11
# define INF 987654321
vector<int> edges[MAX];
vector<int> set;
int P[MAX] = {0,};
int N; 

bool is_connect(int start) {
    int visited[MAX] = {0,};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : edges[cur]) {
            if (visited[next] || set[start-1] != set[next-1]) continue;
            q.push(next);
            visited[next] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (set[i-1] == set[start-1] && !visited[i]) {
            return false;
        }
    }
    return true;
}

int cal_diff() {
    int A = 0, B = 0;
    for (int i = 1; i <= N; i++) {
        if (set[i-1] == 0) A += P[i];
        else B += P[i];
    }
    return abs(A-B);
}

int find_start(int k) {
    for (int i = 1; i <= N; i++) {
        if (set[i-1] == k) return i;
    }
    return -1;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &P[i]);
    
    for (int i = 1; i <= N; i++) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x; scanf("%d", &x);
            edges[i].push_back(x);
        }
    }

    int result = INF;

    for (int i = 1; i <= N/2; i++) {
        for (int j = 0; j < N-i; j++) {
            set.push_back(0);
        }
        for (int j = 0; j < i; j++) {
            set.push_back(1);
        }

        do {
            int A = find_start(0);
            int B = find_start(1);

            if (is_connect(A) && is_connect(B)) {
                result = min(result, cal_diff());
            }
        } while(next_permutation(set.begin(), set.end()));

        set.clear();
    }
    
    if (result == INF) cout << -1;
    else cout << result;
}   