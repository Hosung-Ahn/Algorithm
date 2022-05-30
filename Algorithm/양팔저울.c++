# include <iostream>
# include <vector>
using namespace std;

# define MAX 40001
vector<bool> dp(MAX,0);
int weights[30] = {0,};

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    for (int i = 0; i < N; i++) {
        int w = weights[i];

        vector<bool> dp_copy = dp;
        for (int j = 0; j < MAX; j++) {
            if (dp_copy[j] && j + w < MAX) dp[j+w] = true;
            if (j == w) dp[j] = true; 
        }
    }

    for (int i = 0; i < N; i++) {
        int w = weights[i];

        vector<bool> dp_copy = dp;
        for (int j = 0; j < MAX; j++) {
            if (dp_copy[j] && j - w >= 0) dp[j-w] = true;
        }
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        int x; scanf("%d", &x);
        if (dp[x]) cout << "Y ";
        else cout << "N ";
    }
}