# include <iostream>
using namespace std;
# define ll long long
# define MOD 1000000000
# define MAX 1000

bool up_mod = false;
int arr_1[MAX] = {0,};
int arr_2[MAX] = {0,};


ll cal_gcd(int a, int b) {
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

ll mul(ll a, ll b) {
    ll result = a * b;
    if (result >= MOD) {
        result %= MOD;
        up_mod = true;
    }
    return result;
}



int main() {
    int N,K;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr_1[i]);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr_2[i]);
    }

    ll result = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            ll gcd = cal_gcd(arr_1[i], arr_2[j]);
            arr_1[i] /= gcd;
            arr_2[j] /= gcd;
            result = mul(result, gcd);
        }
    }
    if (up_mod) {
        printf("%09lld", result);
    }
    else {
        printf("%lld", result);
    }
}