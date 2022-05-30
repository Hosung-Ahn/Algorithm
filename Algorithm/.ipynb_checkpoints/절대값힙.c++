# include <iostream> 
# include <queue>
# include <vector>
using namespace std;

priority_queue<pair<int,int>> pq;

void print_pq() {
    if (pq.empty()) cout << "0\n";

    else {
        cout << pq.top().first * pq.top().second << "\n";
        pq.pop();
    }
}

void push_pq(int n) {
    if (n < 0) pq.push(make_pair(n, 1));
    else pq.push(make_pair(-n, -1));
}

int main() {
    int n; cin >> n;
    

    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        if (num == 0) print_pq();
        else push_pq(num);
    }
}