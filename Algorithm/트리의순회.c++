# include <iostream>
# include <cstdio>
using namespace std;
# define MAX 100001

int n;
int in[MAX] = {0,};
int post[MAX] = {0,};

int find_root_in_inorder(int in_s, int in_e, int root_data) {
    for (int index = in_s; index <= in_e; index++) {
        if (in[index] == root_data) return index;
    }
    return 0;
}
void find_tree(int in_s, int in_e, int post_s, int post_e) {
    int root_data = post[post_e];
    int root_i = find_root_in_inorder(in_s, in_e, root_data);
    if (!root_i || in_s > in_e || post_s > post_e) return;
    cout << root_data << " ";

    int left_in_s = in_s;
    int left_in_e = root_i-1;
    int right_in_s = root_i+1;
    int right_in_e = in_e;

    int left_post_s = post_s;
    int left_post_e = post_s + (left_in_e - left_in_s);
    int right_post_s = left_post_e + 1;
    int right_post_e = post_e - 1;

    find_tree(left_in_s, left_in_e, left_post_s, left_post_e);
    find_tree(right_in_s, right_in_e, right_post_s, right_post_e);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &post[i]);
    }
    find_tree(1,n,1,n);

}