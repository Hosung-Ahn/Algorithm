# include <iostream>
# include <vector>
# include <string>
using namespace std;

# define ll long long

int N,K;
vector<string> nums;
int mod_10[51] = {0,};
int mod_nums[16] = {0,};
ll dp[(1 << 16)][101] = {0,};

int get_mod(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret *= 10;
        ret += s[i] - '0';
        ret %= K;
    }
    return ret;
}

ll gcd (ll a, ll b) {
    ll c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

ll fact(int n) {
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        nums.push_back(s);
    }
    cin >> K;

    mod_10[0] = 1 % K;
    for (int i = 1; i < 51; i++) {
        mod_10[i] = (mod_10[i-1]*10) % K;
    }
    for (int i = 0; i < N; i++) {
        mod_nums[i] = get_mod(nums[i]);
    }
    dp[0][0] = 1;
    
    for (int cur = 0; cur < (1<<N); cur++) {
        for (int i = 0; i < N; i++) {
            if ((cur & (1<<i)) == 0) {
                int next_state = cur | (1<<i);

                for (int cur_k = 0; cur_k < K; cur_k++) {
                    int next_k = (cur_k * mod_10[nums[i].size()] + mod_nums[i]) % K;
                    dp[next_state][next_k] += dp[cur][cur_k];
                }
            }
        }
    }

    ll denominator = fact(N);
    ll nominator = dp[(1 << N)-1][0];
    ll d = gcd(nominator, denominator);
    denominator /= d;
    nominator /= d;

    printf("%lld/%lld", nominator, denominator);

}