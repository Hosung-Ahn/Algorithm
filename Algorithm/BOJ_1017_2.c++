#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 1001

int first;
vector<int> arr1, arr2, ans;
int link[MAX] = {0,};
bool done[MAX] = {0,};

bool is_prime(int a, int b) {
    int n = a+b;
    int check = pow(n,0.5);
    for(int d=2;d<=check;d++) {
        if (n%d==0) return false;
    }
    return true;
}

void swap(vector<int> &v1, vector<int> &v2) {
    vector<int> tmp;
    tmp = v1;
    v1 = v2;
    v2 = tmp;
}

bool dfs(int cur) {
    for(int next : arr2) {
        if (done[next] || !is_prime(cur, next)) continue;
        done[next] = true;
        if (link[next] == 0 || dfs(link[next])) {
            link[next] = cur;
            return true;
        }
    }
    return false;
}

bool all_match(int first_link) {
    for(int start : arr1) {
        memset(done, 0, sizeof(bool)*MAX);
        done[first_link] = true;
        if (!dfs(start)) return false;
    }
    return true;
}

void solve() {
    if (arr1.size()+1 != arr2.size()) {
        cout << -1;
        return;
    }
    for(int first_link : arr2) {
        memset(link, 0, sizeof(int)*MAX);
        if(!is_prime(first, first_link)) continue;
        if(all_match(first_link)) {
            ans.push_back(first_link);
        }
    }
    if (ans.empty()) {
        cout << -1;
        return;
    }

    sort(ans.begin(), ans.end());
    for(int a : ans) {
        cout << a << " ";
    }
}

int main() {
    int N; cin >> N;
    cin >> first;
    for(int i=0;i<N-1;i++) {
        int x; cin >> x;
        if(x%2==1) arr1.push_back(x);
        else arr2.push_back(x);
    }
    if (first%2==0) swap(arr1, arr2);
    
    solve();
}