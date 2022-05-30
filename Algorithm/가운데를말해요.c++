# include <iostream>
# include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    int mid; cin >> mid;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    left.push(mid);
    cout << mid << "\n";

    for (int i = 0; i < N-1; i++) {
        mid = left.top();
        int cur; scanf("%d", &cur);

        if (cur >= mid) right.push(cur);
        else left.push(cur); 

        int diff = left.size() - right.size();

        switch (diff) {
            case 2 :
            right.push(left.top());
            left.pop();
            break;

            case -1 :
            left.push(right.top());
            right.pop();
        }

        cout << left.top() << "\n";
    }
    
}