# include <iostream>
using namespace std;

# define MAX 100001

int set[MAX] = {0,};
int arr[MAX] = {0,};

int find_parent(int a) {
    if (a == set[a]) return a;
    return set[a] = find_parent(set[a]);
}

void union_node(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

int main() {
    int G,P; cin >> G >> P;
    for (int i = 0; i < MAX; i++) {
        set[i] = i;
    }

    int cnt = 0;

    for (int i = 0; i < P; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < P; i++) {
        int cur = arr[i];
        cur = find_parent(cur);

        if (cur == 0) break;
        else {
            union_node(cur, cur-1);
            cnt++;
        }
    }
    
    cout << cnt;

}