# include <iostream> 
using namespace std;

# define MAX 10001

int tree[MAX];

void post_order(int start, int end) {
    if (start >= end) return;

    int next;
    for (next = start + 1; next < end; next++) {
        if (tree[next] > tree[start]) break;    
    }

    post_order(start + 1, next);
    post_order(next, end);

    cout << tree[start] << "\n";
}

int main() {
    int idx = 0;
    int x;
    while (cin >> x) {
        if (x == EOF) break;
        tree[idx++] = x;
    }

    post_order(0,idx);
}