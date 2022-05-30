# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
# define MAX 50

vector<int> edge[MAX];
int cnt[MAX] = {0, };

void dfs(int cur) {
    if (edge[cur].empty()) {
        cnt[cur]++;
        return;
    }
    for (int next : edge[cur]) {
        dfs(next);
    }
}

int main() {
    int n; cin >> n;

    int root;
    for (int s = 0; s < n; s++) {
        int e; cin >> e;
        if (e == -1) {
            root = s;
            continue;
        }
        edge[e].push_back(s);
    }

    int removed_node; cin >> removed_node;
    
    vector<int>::iterator iter;
    for (int i = 0; i < MAX; i++) {
        iter = find(edge[i].begin(), edge[i].end(), removed_node);
        if (iter != edge[i].end() ) {
            edge[i].erase(iter);
        }
    }

    dfs(root);

    if (root == removed_node) {
        cout << 0;
    }
    else {
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 1) result++;
        }
        cout << result;
    }
}