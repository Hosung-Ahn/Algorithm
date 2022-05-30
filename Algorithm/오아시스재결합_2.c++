# include <iostream>
# include <stack>
# include <vector>
using namespace std;
# define ll long long

stack<pair<int,int>> s;

int main() {
    ll ret = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        while (!s.empty() && s.top().first < x) {
            ret += s.top().second;
            s.pop();
        }

        if (!s.empty()) {
            if (s.top().first == x) {
                ret += s.top().second;
                pair<int,int> tmp = {s.top().first, s.top().second+1};
                s.pop();

                if (!s.empty()) ret++;
                s.push(tmp);
            }
            else {
                ret++;
                s.push({x,1});
            }
        }
        else {
            s.push({x,1});
        }
    }
    cout << ret;
}




