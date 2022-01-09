# include <iostream>
# include <queue>
using namespace std;

priority_queue<int> q[7];
int cnt = 0;

void push_q(int n, int p) {
    if (q[n].empty()) {
        q[n].push(p);
        cnt++;
        return;
    }

    while (q[n].top() > p) {
        cnt++;
        q[n].pop();
        if (q[n].empty()) break;
    }

    if (q[n].empty()) {
        q[n].push(p);
        cnt++;
        return;
    }

    if (q[n].top() == p) return;
    else {
        cnt++;
        q[n].push(p);
    }
}

int main() {
    

    int N,P; cin >> N >> P;
    int n,p;

    for (int i = 0; i < N; i++){
        scanf("%d %d", &n, &p);
        push_q(n,p);
    }

    cout << cnt << endl; 
}