# include <iostream>
# include <queue>
using namespace std;




void plus_num(int &result, priority_queue<int> pq, bool is_minus = false) {
    while (pq.size() >= 2) {
        int x =  pq.top();
        pq.pop();
        x *= pq.top();
        pq.pop();
        result += x;
    }
    while (!pq.empty()) {
        if (is_minus) result -= pq.top();
        else result += pq.top();
        pq.pop();
    }
}

int main() {
    int N; cin >> N;
    priority_queue<int> pq_plus;
    priority_queue<int> pq_minus;
    
    int result = 0;

    for (int i = 0; i < N; i++) {
        int num; scanf("%d", &num);
        if (num == 1) result += 1;
        else if (num <= 0) pq_minus.push(-num);
        else pq_plus.push(num);
    }

    
    plus_num(result, pq_plus);
    plus_num(result, pq_minus, true);

    cout << result;
    
}