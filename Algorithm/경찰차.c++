# include <iostream>
# include <vector>
# include <string.h>
# include <math.h>
using namespace std;

# define MAX 1002

int N,K;
vector<pair<int,int>> points;
int dp[MAX][MAX];

int next_point(int a, int b) {
    if (b == K+1) return a + 1;
    return max(a,b) + 1;
}

int distance(const pair<int,int> &a, const pair<int,int> &b) { 
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int find_dp(int a, int b) {
    int next = next_point(a,b);
    if (next == K+1) return 0;
    if (dp[a][b] != -1) return dp[a][b];

    int move_a = distance(points[a], points[next]) + find_dp(next, b);
    int move_b = distance(points[next], points[b]) + find_dp(a,next);
    dp[a][b] = min(move_a, move_b);
    return dp[a][b];
}

void dfs(int a, int b) {
    int next = next_point(a,b);
    if (next == K+1) return;
    int move_a = distance(points[a], points[next]) + dp[next][b];
    int move_b = distance(points[next], points[b]) + dp[a][next];
    if (move_a > move_b) {
        cout << "2\n";
        dfs(a,next);
    }
    else {
        cout << "1\n";
        dfs(next,b);
    }
}

int main() {
    cin >> N >> K;
    points.push_back({1,1});
    for (int i = 0; i < K; i++) {
        int x,y; scanf("%d %d", &x,&y);
        points.push_back({x,y});
    }
    points.push_back({N,N});

    for (int i = 0; i < MAX; i++) 
        memset(dp[i], -1, sizeof(int)*MAX);

    cout << find_dp(0,K+1) << "\n";
    dfs(0,K+1);
}
