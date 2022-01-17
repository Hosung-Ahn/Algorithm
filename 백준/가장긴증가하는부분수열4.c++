# include <iostream>
# include <vector>
using namespace std;

# define MAX 1000

int arr[MAX];
int dp[MAX] = {0,};
int N;

int find_dp(int idx, int value) {
    int result = 0;
    for (int i = 0; i < idx; i++) {
        if (arr[i] < value && dp[i] > result)
            result = dp[i];
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int cnt = 0;
    int max_num;

    for (int i = 0; i < N; i++) {
        dp[i] = find_dp(i, arr[i]) + 1;
        if (dp[i] > cnt) {
            cnt = dp[i];
            max_num = arr[i];
        }
    }

    cout << cnt << endl;

    vector<int> inc_arr;

    for (int i = N-1; i >= 0; i--) {
        if (dp[i] == cnt && arr[i] <= max_num) {
            inc_arr.push_back(arr[i]);
            cnt--;
            max_num = arr[i];
        }
    }
    
    vector<int>:: reverse_iterator iter = inc_arr.rbegin();

    for (; iter != inc_arr.rend(); iter++)
        cout << *iter << " ";

    

    
}   