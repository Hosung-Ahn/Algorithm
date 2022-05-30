# include <iostream>
# include <queue>
# include <string.h>
# include <vector>
using namespace std;

# define MAX 100001

int cnt[MAX] = {0, };
vector<int> path;

int plus_1(int a){
    return a + 1;
}
int minus_1(int a) {
    return a - 1;
}
int mul_2(int a) {
    return a * 2; 
}

int (*funcptr[])(int) = {plus_1, minus_1, mul_2};

bool in_range(int a) {
    if (a < 0 || a >= MAX) return false;
    return true;
}

void bfs(int start, int end) {
    cnt[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == end) {
            cout << cnt[end] << endl;
            return;
        }

        for (int i = 0; i < 3; i++) {
            int next = funcptr[i](cur);
            if (!in_range(next) || cnt[next] != -1) continue;
            cnt[next] = cnt[cur] + 1;
            q.push(next);
        }
    }
}

void find_path(int start, int end) {
    path.push_back(end);

    if (start == end) {
        return;
    }

    int cur_cnt = cnt[end];
    if (cnt[end-1] == cur_cnt - 1) 
        return find_path(start, end - 1);

    if (cnt[end+1] == cur_cnt - 1)
        return find_path(start, end + 1);

    if (end % 2 == 0 && cnt[end/2] == cur_cnt - 1)
        return find_path(start, end/2);
        
}

int main() {
    memset(cnt, -1, sizeof(int)*MAX);

    int s,e; cin >> s >> e;
    bfs(s,e);
    find_path(s,e);
    
    vector<int>::reverse_iterator iter;
    for (iter = path.rbegin(); iter != path.rend(); iter++)
        cout << *iter << " ";
}
