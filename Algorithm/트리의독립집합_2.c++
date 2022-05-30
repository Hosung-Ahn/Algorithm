# include <iostream>
# include <vector>
# include <string.h>
# include <algorithm>
using namespace std;

# define MAX 10001
int arr[MAX] = {0,};
vector<int> edges[MAX];
int N;
int dp[MAX][2] = {0,};
bool visited[MAX] = {0,};
vector<int> result_arr;

int find_dp(int cur, int choosed) {
    if (dp[cur][choosed] != 0) return dp[cur][choosed];
    visited[cur] = true;

    int result = 0;

    if (choosed) {
        result += arr[cur];
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            result += find_dp(next, 0);
        }
    }
    else {
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            result += max(find_dp(next,0), find_dp(next,1));
        }
    }
    
    visited[cur] = false;
    dp[cur][choosed] = result;
    return result;
}

void dfs(int cur, int choosed) {
    visited[cur] = true;
    if (choosed) {
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            dfs(next,0);
        }
    }
    else {
        for (int next : edges[cur]) {
            if (visited[next]) continue;

            if (dp[next][1] > dp[next][0]) {
                result_arr.push_back(next);
                dfs(next,1);
            }
            else dfs(next,0);
        }
    }
    visited[cur] = false;
}



int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < N-1; i++) { 
        int s,e; scanf("%d %d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
    }

    int choosed_1 = find_dp(1,1);
    int not_choosed_1 = find_dp(1,0);

    if (choosed_1 > not_choosed_1) {
        cout << choosed_1 << endl;
        result_arr.push_back(1);
        dfs(1,1);
    }
    else {
        cout << not_choosed_1 << endl;
        dfs(1,0);
    }

    sort(result_arr.begin(), result_arr.end());

    for (int x : result_arr) cout << x << " ";

    
}

