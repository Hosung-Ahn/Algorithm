    # include <iostream>
    using namespace std;

    # define MAX 501

    int arr[MAX] = {0,};
    int dp[MAX] = {0,};
    int N;

    int find_dp(int idx, int value) {
        int result = 0;

        for (int i = 1; i < idx; i++) {
            if (arr[i] < value && dp[i] > result) 
                result = dp[i];
        }

        return result;
    }


    int main() {
        cin >> N;
        int last_idx = 0;
        for (int i = 0; i < N; i++) {
            int s,e; scanf("%d %d", &s,&e);
            arr[s] = e;
            if (s > last_idx) last_idx = s;
        }

        int result = 0;
        for (int i = 1; i <= last_idx; i++) {
            if (arr[i] == 0) continue;
            dp[i] = 1 + find_dp(i, arr[i]);

            if (dp[i] > result) result = dp[i];
        }
        
        cout << N - result << endl;
    }