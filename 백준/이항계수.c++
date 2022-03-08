# include <iostream>
# include <vector>
# include <string.h>
using namespace std;
# define ll long long

ll N,K,M;
int comb[2001][2001];

int get_comb(int n, int k) {
    if (n < k) return 0;
    if (k == 0) return 1;
    if (comb[n][k] != -1) return comb[n][k];

    int result = (get_comb(n-1,k) + get_comb(n-1,k-1)) % M;
    comb[n][k] = result;
    return result;
}

vector<int> get_arr(ll n) {
    vector<int> ret;
    while (n != 0) {
        ret.push_back(n%M);
        n/=M;
    }
    return ret;
}

int main() {
    cin >> N >> K >> M;
    for (int i = 0; i < 2001; i++)
        memset(comb[i], -1, sizeof(int)*2001);

    vector<int> N_arr, K_arr;
    N_arr = get_arr(N);
    K_arr = get_arr(K);

    int result = 1;
    for (int i = 0; i < min(N_arr.size(), K_arr.size()); i++) {
        result *= get_comb(N_arr[i], K_arr[i]);
        result %= M;
    }   
    cout << result;
}