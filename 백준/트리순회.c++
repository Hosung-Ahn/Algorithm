# include <iostream>
# include <vector>
using namespace std;
# define MAX 26
vector<pair<int,int> > tree(MAX);

void preorder(int start) {
    char ret = start + 'A';
    cout << ret;
    if (tree[start].first >= 0) preorder(tree[start].first);
    if (tree[start].second >= 0) preorder(tree[start].second);
    
}

void inorder(int start) { 
    if (tree[start].first >= 0) inorder(tree[start].first);
    char ret = start + 'A';
    cout << ret;
    if (tree[start].second >= 0) inorder(tree[start].second);
}

void postorder(int start) { 
    if (tree[start].first >= 0) postorder(tree[start].first);
    if (tree[start].second >= 0) postorder(tree[start].second);
    char ret = start + 'A';
    cout << ret;
}


int main() {
    int n; cin >> n;
    char node, left, right;

    for (int i = 0; i < n; i++){
        cin >> node >> left >> right;
        tree[node - 'A'].first = left -'A';
        tree[node - 'A'].second = right -'A';
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
}