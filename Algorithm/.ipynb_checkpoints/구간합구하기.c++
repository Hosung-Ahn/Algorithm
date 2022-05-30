# include <iostream>
# include <vector>
# include <queue>
using namespace std;

# define ll long long

vector<pair<ll,ll>> changed_nums;
vector<ll> arr;
vector<ll> arr_sum;

void change_num(ll i, ll n) {
    changed_nums.push_back(make_pair(i, n-arr[i]));
    arr[i] = n;
}

ll sum_1_to_n(ll n) {
    ll ret = arr_sum[n];
    for (pair<ll,ll> nums : changed_nums) { 
        if (nums.first <= n)
            ret += nums.second;
    }

    return ret;
}

void prll_sum(ll s, ll e) {
    ll result = sum_1_to_n(e) - sum_1_to_n(s-1);
    cout << result << "\n";
}

int main() {
    ll N,K,M; scanf("%d %d %d", &N, &K, &M);

    ll sum = 0;
    arr.push_back(0);
    arr_sum.push_back(0);


    ll num;
    for (ll i = 1; i <= N; i++) {
        scanf("%lld", &num);
        arr.push_back(num);
        sum += num;
        arr_sum.push_back(sum);
    }

    ll op, x, y;
    for (ll i = 0; i < K + M; i++) {
        scanf("%d %d %d", &op, &x, &y);
        switch (op) {
            case 1 : 
            change_num(x,y);
            break;
            case 2 :
            prll_sum(x,y);
            break;
        }
    }
}

