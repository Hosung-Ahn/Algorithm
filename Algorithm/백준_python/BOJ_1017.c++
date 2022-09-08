#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
vector<int> odd, even, ans;
int link[1001] = {0,};
bool done[1001] = {0,};
int first;

bool is_prime(int a, int b) {
    int n = a+b;
    int check = pow(n, 0.5);
    for(int d=2;d<=check;d++) {
        if(n%d==0) return false;
    }
    return true;
}

bool dfs_odd(int cur) {
    for(int next : even) {
        if (!is_prime(cur,next) || done[next]) continue;
        done[next] = true;
        if (link[next] == 0 || dfs_odd(link[next])) {
            link[next] = cur;
            return true;
        }
    }
    return false;
}

bool dfs_even(int cur) {
    for(int next : odd) {
        if(!is_prime(cur,next) || done[next]) continue;
        done[next] = true;
        if (link[next] == 0 || dfs_even(link[next])) {
            link[next] = cur;
            return true;
        }
    }
    return false;
}

bool all_match_even(int link_first) {
    for(int e : even) {
        memset(done, 0, sizeof(bool)*1001);
        done[link_first] = true;
        if (!dfs_even(e)) return false;
    }
    return true;
}

bool all_match_odd(int link_first) {
    for(int o : odd) {
        memset(done, 0, sizeof(bool)*1001);
        done[link_first] = true;
        if (!dfs_odd(o)) return false;
    }
    return true;
}

void even_solve() {
    for(int o : odd) {
        memset(link,0,sizeof(int)*1001);
        if(!is_prime(first, o)) continue;
        if (all_match_even(o)) ans.push_back(o);
    }
}

void odd_solve() {
    for(int e : even) {
        memset(link,0,sizeof(int)*1001);
        if(!is_prime(first, e)) continue;
        if(all_match_odd(e)) ans.push_back(e);
    }
}

void solve() {
    if (first%2==0) {
        if (even.size()+1 != odd.size()) {
            cout << -1;
            return;
        }
        even_solve();
    }
    else {
        if (even.size() != odd.size()+1) {
            cout << -1;
            return;
        }
        odd_solve();
    }

    if (ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(int x : ans) cout << x << " ";
    }
}


int main() {
    int N; cin >> N;
    cin >> first;
    for(int i=0;i<N-1;i++) {
        int x; cin >> x;
        if(x%2 == 0) even.push_back(x);
        else odd.push_back(x);
    }
    solve();
    
}