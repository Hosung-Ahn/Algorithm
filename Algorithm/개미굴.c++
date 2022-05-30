# include <iostream>
# include <vector>
# include <map>
# include <string>
using namespace std;

class Node {
public:
    map<string, Node> child;
};

void insert(Node &cur, const vector<string> &arr, int idx) {
    if (idx == arr.size()) return;

    if (!cur.child.count(arr[idx])) cur.child[arr[idx]] = Node();
    insert(cur.child[arr[idx]], arr, idx+1);
}

void dfs(Node &cur, int depth) {
    for (pair<string, Node> i : cur.child) {
        for (int i = 0; i < depth; i++) cout << "--";
        cout << i.first << "\n";
        dfs(i.second, depth+1);
    }
}

int main() {
    int N; cin >> N;
    Node root = Node();
    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        vector<string> arr;
        for (int j = 0; j < K; j++) {
            string s; cin >> s;
            arr.push_back(s);
        }
        insert(root, arr, 0);
    }

    dfs(root, 0);
}