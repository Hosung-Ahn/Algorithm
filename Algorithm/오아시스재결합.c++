# include <iostream>
# include <stack>
using namespace std;
# define ll long long

stack<int> s;

// 반례 : 6 - 6 6 6 5 5 5
// 6이 사라지지 않고 남아서 5 차례가 됬을 때 s.size() 에 영향을 미침

int main() {
    ll ret = 0;
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
    
        while (!s.empty() && s.top() < x) {
            s.pop();
            ret++;
        }
        if (!s.empty()) {
            if (s.top() == x) ret += s.size();
            else ret++;
        }
        s.push(x);
        
    }
    cout << ret;
}




