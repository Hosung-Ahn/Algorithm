# include <iostream>
using namespace std;
# define MAX 100001

int n;
int in[MAX] = {0,};
int post[MAX] = {0,};

struct Node{
    int data;
    Node *left, *right;
    Node(int data) : data(data) {
        left = nullptr;
        right = nullptr;
    }
};

int find_root_in_inorder(int in_s, int in_e, int root_data) {
    for (int index = in_s; index <= in_e; index++) {
        if (in[index] == root_data) return index;
    }
    return 0;
}

bool in_range(int in_s, int in_e, int post_s, int post_e) {
    if (in_s < 1 || in_e > n || post_s < 1 || post_e > n ||
        (in_e - in_s != post_e - post_s) ||
        in_e - in_s < 0 || post_e - post_s < 0) return false;
    return true;
}

void find_tree(int in_s, int in_e, int post_s, int post_e, Node* node) {
    int root_data = post[post_e];
    node->data = root_data;

    int root_i = find_root_in_inorder(in_s, in_e, root_data);
    if (!root_i || in_s == in_e) return;

    int left_in_s = in_s;
    int left_in_e = root_i-1;
    int right_in_s = root_i+1;
    int right_in_e = in_e;

    int left_post_s = post_s;
    int left_post_e = post_s + (left_in_e - left_in_s);
    int right_post_s = left_post_e + 1;
    int right_post_e = post_e - 1;

    if (in_range(left_in_s, left_in_e, left_post_s, left_post_e)) {
        Node* new_left = new Node(0);
        node->left = new_left;
        find_tree(left_in_s, left_in_e, left_post_s, left_post_e, node->left);
    }
    if (in_range(right_in_s, right_in_e, right_post_s, right_post_e)) {
        Node* new_right = new Node(0);
        node->right = new_right;
        find_tree(right_in_s, right_in_e, right_post_s, right_post_e, node->right);
    }
}

void print_preorder(Node* node) {
    cout << node->data << " ";
    if (node->left) print_preorder(node->left);
    if (node->right) print_preorder(node->right);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &post[i]);
    }

    Node* root_node = new Node(0);
    find_tree(1,n,1,n,root_node);
    print_preorder(root_node);

}