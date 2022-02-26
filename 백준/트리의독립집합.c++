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
vector<int> arr_1_choosed;
vector<int> arr_1_not_choosed;
bool choosed_1 = true;

int find_dp(int cur, int choosed) {
    visited[cur] = true;
    if (dp[cur][choosed] != 0) return dp[cur][choosed];

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
            int tmp1 = find_dp(next,0);
            int tmp2 = find_dp(next,1);
            if (tmp2 > tmp1) {
                if (choosed_1) arr_1_choosed.push_back(next);
                else arr_1_not_choosed.push_back(next);
                result += tmp2;
            }
            else {
                result += tmp1;
            }
        }
    }
    
    visited[cur] = false;
    dp[cur][choosed] = result;
    return result;
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
    arr_1_choosed.push_back(1);
    int tmp1 = find_dp(1,1);
    
    for (int i = 0; i < MAX; i++) {
        memset(dp[i], 0, sizeof(int)*2);
    }
    choosed_1 = false;
    int tmp2 = find_dp(1,0);

    sort(arr_1_choosed.begin(), arr_1_choosed.end());
    sort(arr_1_not_choosed.begin(), arr_1_not_choosed.end());

    if (tmp1 > tmp2) {
        cout << tmp1 << endl;
        for (int x : arr_1_choosed) cout << x << " ";
    }

    else {
        cout << tmp2 << endl;
        for (int x : arr_1_not_choosed) cout << x << " ";
    }
    
}

