# include <iostream>
using namespace std;

int N,M;
# define MOD 1000
# define MAX 1000001
# define ll long long

ll cnt[MOD] = {0,};
int sum[MAX] = {0,};

int main() {
    cin >> N >> M;
    ll result = 0;

    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        sum[i] = (sum[i-1] + x) % M;
        if (sum[i] == 0) result++;
        cnt[sum[i]]++;
    }

    for (int i = 0; i < M; i++) {
        result += cnt[i] * (cnt[i]-1) / 2;
    }

    cout << result;
}