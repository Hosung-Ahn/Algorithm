# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
# define MAX 10000+1

pair<int,int> Tree[MAX];
int Points[MAX] = {0,};
int x = 1;
bool not_root[MAX] = {0,};
vector<vector<int>> nodes(MAX, vector<int>());

void inorder(int cur, int depth) {
    int left = Tree[cur].first;
    int right = Tree[cur].second;

    if (left != -1) inorder(left, depth+1);
    Points[cur] = x++;
    nodes[depth].push_back(Points[cur]);
    if (right != -1) inorder(right, depth+1);
}

void solution() {
    int result_depth = -1;
    int result_breadth = -1;
    for (int depth = 1; depth < MAX; depth++) {
        if (nodes[depth].size() == 0) break;
        int tmp = 0;

        if (nodes[depth].size() == 1) tmp = 1;
        else {
            int max_x = *max_element(nodes[depth].begin(), nodes[depth].end());
            int min_x = *min_element(nodes[depth].begin(), nodes[depth].end());
            tmp = max_x - min_x + 1;
        }

        if (tmp > result_breadth) {
            result_breadth = tmp;
            result_depth = depth;
        }
    }

    cout << result_depth << " " << result_breadth;
}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int p,l,r; cin >> p >> l >> r;
        Tree[p].first = l;
        Tree[p].second = r;
        not_root[l] = true;
        not_root[r] = true;
    }

    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (!not_root[i]) {
            root = i;
            break;
        }
    }

    inorder(root,1);
    solution();

}