# include <iostream>
# include <vector>
# include <queue>
# include <string.h>
using namespace std;

# define MAX 10000

int to_cnt[MAX];

int D(int n) {
    n *= 2;
    n %= MAX;
    return n;
}

int D_inverse(int n, bool plus_10000 = false) {
    if(plus_10000) n += 10000;
    n /= 2;
    return n;
}

int S(int n) {
    if (n == 0) return 9999;
    return n-1;
}

int S_inverse(int n) {
    if (n == 9999) return 0;
    return n + 1;
}

int L(int n) {
    n *= 10;
    int last = n / MAX;
    n += last;
    n %= MAX;
    return n;
}

int R(int n) {
    int last = n % 10;
    n /= 10;
    n += last * 1000;
    return n;
}

int (*funcptr[])(int) = {D,S,L,R};

void bfs(int start, int end) {
    to_cnt[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == end) return;

        for (int i = 0; i < 4; i++) {
            int next = (*funcptr[i])(cur);
            if (to_cnt[next] != -1) continue;

            to_cnt[next] = to_cnt[cur] + 1;
            q.push(next);
        }
    }
}

vector<char> result;
void print_inverse(int end, int cnt) {
    if (cnt == 0) return;

    int next;

    if (end % 2 == 0) {
        next = D_inverse(end);
        if (to_cnt[next] == cnt-1) {
            result.push_back('D');
            return print_inverse(next, cnt-1);
        }
        next = D_inverse(end, true);
        if (to_cnt[next] == cnt-1) {
            result.push_back('D');
            return print_inverse(next, cnt-1);
        }
    }

    next = S_inverse(end);
    if (to_cnt[next] == cnt-1) {
        result.push_back('S');
        return print_inverse(next, cnt-1);
    }

    next = L(end);
    if (to_cnt[next] == cnt-1) {
        result.push_back('R');
        return print_inverse(next, cnt-1);
    }

    next = R(end);
    if (to_cnt[next] == cnt-1) {
        result.push_back('L');
        return print_inverse(next, cnt-1);
    }
}

int main() {
    int T; cin >> T;

        for (int t = 0; t < T; t++) {

        result.clear();
        memset(to_cnt, -1, sizeof(int)*MAX);
        int start, end; scanf("%d %d", &start, &end);
        bfs(start, end);

        print_inverse(end, to_cnt[end]);

        vector<char>::reverse_iterator iter;
        for (iter = result.rbegin(); iter != result.rend(); iter++)
            cout << *iter;

        cout << "\n";
    }
}