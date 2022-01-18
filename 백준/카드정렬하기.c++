# include <iostream>
# include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        pq.push(x);
    }

    long long result = 0;

    if (n == 1) cout << 0;

    else {
        while(1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            result += a+b;

            if (pq.empty()) {
                cout << result;
                break;
            }
            pq.push(a+b);
        }
    }
    
}