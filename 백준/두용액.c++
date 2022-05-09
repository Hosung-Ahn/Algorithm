# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
using namespace std;

vector<int> a;
vector<int> b;

bool next_x(int &ai, int &bi, int &x) {
    if (ai == a.size()-1 && bi == b.size()-1) return false;
    else if (ai == a.size()-1) {
        bi++;
        x = b[bi];
    }
    else if (bi == b.size()-1) {
        ai++;
        x = a[ai];
    }
    else {
        if (abs(a[ai+1]) < abs(b[bi+1])) {
            ai++;
            x = a[ai];
        }
        else {
            bi++;
            x = b[bi];
        }
    }
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x < 0) a.push_back(x);
        else b.push_back(x);
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end()); 

    int last, cur, ai = -1, bi = -1;
    next_x(ai,bi,last);
    next_x(ai,bi,cur);
    int tmp = abs(cur + last);
    int result_a, result_b;
    result_a = last;
    result_b = cur;

    while(1) {
        last = cur;
        if (!next_x(ai,bi,cur)) break;
        if (tmp > abs(cur + last)) {
            result_a = last;
            result_b = cur;
            tmp = abs(cur + last);
        }
    }

    cout << min(result_a, result_b) << " " << max(result_a, result_b) << endl;

}