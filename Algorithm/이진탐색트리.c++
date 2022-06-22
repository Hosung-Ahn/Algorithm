#include <iostream>
using namespace std;

struct Tree {
    int val;
    Tree (int val) : val(val) { }
    Tree *left, *right;
    void setLeft(Tree *node) {
        this->left = node;
    }
    void setRight(Tree *node) {
        this->right = node;
    }
};

int cnt = 0;

void insert(Tree *cur, int x) {
    cnt++;
    if (x < cur->val) {
        if (cur->left == nullptr) {
            Tree *node = new Tree(x);
            cur->setLeft(node);
        }
        else insert(cur->left, x);
    }
    else {
        if (cur->right == nullptr) {
            Tree *node = new Tree(x);
            cur->setRight(node);
        }
        else insert(cur->right, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int root; cin >> root;
    Tree *tree = new Tree(root);
    cout << cnt << "\n";

    for (int i = 0; i < N-1; i++) {
        int x; cin >> x;
        insert(tree, x);
        cout << cnt << "\n";
    }
}