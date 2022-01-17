# include<iostream>
using namespace std;

# define MAX 1000001
int set[MAX] = {0,};

int get_parent(int a) {
    if (a == set[a]) return a;
    return set[a] = get_parent(set[a]);
}

void union_set(int a, int b) {
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

int main(){
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; i++)
        set[i] = i;

    for (int i = 0; i < M; i++) {
        int op, a,b; scanf("%d %d %d", &op, &a, &b);
        switch (op) {
            case 0 :
            union_set(a,b);
            break;
            case 1 :
            if (find(a,b)) cout << "YES\n";
            else cout << "NO\n";
            break;
        }
    }
}