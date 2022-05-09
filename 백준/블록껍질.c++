#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
# define ll long long
vector<pair<ll,ll>> points;

ll ccw(const pair<ll,ll> &a, const pair<ll,ll> &b, const pair<ll,ll> &c) {
    return a.first*b.second + b.first*c.second + c.first*a.second
        - (b.first*a.second + c.first*b.second + a.first*c.second);
}

bool relative_poitns(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    ll left = pow(abs(a.first - points[0].first),2) + pow(abs(a.second - points[0].second),2);
    ll right = pow(abs(b.first - points[0].first),2) + pow(abs(b.second - points[0].second),2); 
    return left < right;
}

bool cmp_ccw(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    ll c = ccw(points[0], a, b);
    if (c == 0) return relative_poitns(a,b);
    return c > 0;
}

bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll x,y; cin >> x >> y;
        points.push_back({x,y});
    }

    sort(points.begin(), points.end(), cmp);
    sort(points.begin()+1 , points.end(), cmp_ccw);

    stack<pair<ll,ll>> st;
    st.push(points[0]);
    st.push(points[1]);

    for (int i = 2; i < N; i++) {

        while(st.size() >= 2) {
            pair<ll,ll> mid = st.top();
            st.pop();
            pair<ll,ll> fst = st.top();
            if (ccw(fst, mid, points[i]) > 0) {
                st.push(mid);
                break;
            }
        }
        st.push(points[i]);
    }    

    cout << st.size();
}