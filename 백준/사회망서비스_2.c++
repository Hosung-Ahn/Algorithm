# include <iostream>
# include <vector>
# include <string.h>
using namespace std;

# define MAX 1000001
vector<int> edges[MAX];

int dp[2][MAX];
int visited[MAX] = {0,};

int find_dp(int include, int cur) {
    if (edges[cur].empty()) {
        if (include == 1) return 1;
        return 0;
    }

    if (dp[include][cur] != -1) return dp[include][cur];

    int result = 0;
    if (include == 0 ) { 
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            result += find_dp(1, next);
        }
    }

    else {
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            result += min(find_dp(0,next), find_dp(1,next));
        }
        result ++;
    }

    dp[include][cur] = result;
    return result;
}

void print_result() {
    memset(visited, 0, sizeof(int)*MAX);
    visited[1] = true;
    int include_1 = find_dp(1,1);

    memset(visited, 0, sizeof(int)*MAX);
    visited[1] = true;
    int note_include_1 = find_dp(0,1);

    cout << min 

}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    for (int i = 0; i < 2; i++)
        memset(dp[i], -1, sizeof(int)*MAX);

    
}

