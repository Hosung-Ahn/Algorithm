# include <iostream>
using namespace std;

# define MAX 201
int set[MAX];
int arr[1000];
int N,M;

int get_parent(int a) {
    if (a == set[a]) return a;
    return set[a] = get_parent(set[a]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

bool find(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) return true;
    return false;
}

void print_result() {
    int start = get_parent(arr[0]);

    for (int i = 1; i < M; i++) {
        if (get_parent(arr[i]) != start) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
    return;
}

int main() {
    for (int i = 0; i < MAX; i++)
        set[i] = i;

    cin >> N >> M;
    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            int x; scanf("%d", &x);
            if (x == 1) {
                union_node(a,b);
            }
        }
    }

    for (int i = 0; i < M; i++)
        scanf("%d", &arr[i]);

    print_result();
}