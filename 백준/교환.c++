# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
using namespace std;

bool dp[11][1000001] = {0,};
vector<int> arr;
int k;

void change(int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int to_int() {
    int ret = 0;
    for (int n : arr) {
        ret *= 10;
        ret += n;
    }
    return ret;
}

void find_ab(int &a, int &b, const vector<int> &choose) {
    bool first = true;
    for (int i = 0; i < choose.size(); i++) {
        if (choose[i] == 1) {
            if (first) {
                a = i;
                first = false;
            }
            else {
                b = i;
            }
        }
    }
}

void find_dp(int n) {
    if (arr[0] == 0 || arr.size() < 2) return;
    int cur = to_int();

    if (dp[n][cur]) return;
    dp[n][cur] = true;
    if (n == k) return;

    vector<int> choose;
    for (int i = 0; i < arr.size()-2; i++) {
        choose.push_back(0);
    }
    for (int i = 0; i < 2; i++) {
        choose.push_back(1);
    }

    int a,b;
    do {
        find_ab(a,b,choose);
        change(a,b);
        find_dp(n+1);
        change(a,b);
    } while(next_permutation(choose.begin(), choose.end()));
}

void print_result() {
    for (int i = 1000000; i >= 0; i--) {
        if (dp[k][i]) {
            cout << i;
            return;
        }
    }
    cout << -1;
}

int main() {
    string n;
    
    cin >> n >> k;
    for (char x : n) {
        arr.push_back(x-'0');
    }
    find_dp(0);
    print_result();
}