# include <iostream>
# include <math.h>
using namespace std;

# define ll long long

ll N,K,Q;

ll find_parent(ll n) {
    if (n % K == 0 || n % K == 1) return n / K;
    return n / K + 1;
}

int find_depth(ll n) {
    if (n == 1) return 0;
    return 1 + find_depth(find_parent(n));
}

void swap(ll &a, ll &b) {
    ll tmp = a;
    a = b;
    b = tmp;
}

void set_depth(ll &a, ll &b) {
    int a_depth = find_depth(a);
    int b_depth = find_depth(b);
    int diff = abs(a_depth - b_depth);
    if (b_depth > a_depth) swap(a,b);
    while (diff > 0) {
        a = find_parent(a);
        diff--;
    }
}

ll find_co_ancestor(ll a, ll b) {
    set_depth(a,b);
    while (a != b) {
        a = find_parent(a);
        b = find_parent(b);
    }
    return a;
}

int main() {
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        ll a,b; scanf("%lld %lld", &a, &b);

        if (K == 1) {
            cout << abs(a-b) << "\n";
            continue;
        }
        ll c = find_co_ancestor(a,b);
        cout << find_depth(a) + find_depth(b) - 2*find_depth(c) << "\n";
    }
}