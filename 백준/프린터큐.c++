# include <iostream>
# include <queue>
using namespace std;

class Doc{
public:
    int idx, priority;
    Doc (int i, int p) : idx(i), priority(p) { }
};

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N,M; scanf("%d %d", &N, &M);

        queue<Doc> q;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++) {
            int p; scanf("%d", &p);
            q.push(Doc(i,p));
            pq.push(p);
        }

        int result = 1;
        while (!q.empty()) {
            while(q.front().priority != pq.top()) {
                q.push(q.front());
                q.pop();
            }

            if (q.front().idx == M) {
                cout << result << "\n";
                break;
            }
            result++;
            q.pop();
            pq.pop();
        }
    }
}