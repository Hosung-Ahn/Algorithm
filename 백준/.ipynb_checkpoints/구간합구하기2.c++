# include <iostream>
# include <vector>
using namespace std;

# define ll long long

vector<ll> arr;
vector<ll> arr_sum;
vector<pair<int,ll>> changed_nums;

void change_num(int i, ll n) {
    changed_nums.push_back(make_pair(i, n - arr[i]));
    arr[i] = n;
}

ll sum_1_to_i(int i) {
    ll ret = arr_sum[i];
    for (pair<int,ll> num : changed_nums ) {
        if (num.first <= i)
            ret += num.second;
    }
    return ret;
}

void print_num(int s, int e) {
    cout << sum_1_to_i(e) - sum_1_to_i(s-1) << "\n";
}

int main() {
    int N, K, M; scanf("%d %d %d", &N, &K, &M);
    arr.push_back(0);
    arr_sum.push_back(0);

    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        ll n; scanf("%lld", &n);
        arr.push_back(n);
        sum += n;
        arr_sum.push_back(sum);
    }

    for (int i = 0; i < K+M; i++) {
        int op, s;
        ll x;
        scanf("%d %d %lld", &op, &s, &x);
        switch (op) {
            case 1 : 
            change_num(s,x);
            break;
            case 2 : 
            print_num(s,x);
            break;
        }
    }
}