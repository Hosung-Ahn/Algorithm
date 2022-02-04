# include <iostream>
# include <string>
# include <map>
# include <string.h>
# include <cstdio>

using namespace std;

# define MAX 200001

int set[MAX];
int cnt[MAX];

int get_parent(int a) {
    if (a == set[a]) return a;
    return set[a] = get_parent(set[a]);
}

void union_node(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a < b) {
        set[b] = a;
        cnt[a] += cnt[b];
    }
    else {
        set[a] = b;
        cnt[b] += cnt[a];
    }
}

bool find(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) return true;
    return false; 
}

void print_cnt(int a) {
    a = get_parent(a);
    cout << cnt[a] << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);


    int T; cin >> T;
    for (int t = 0; t < T; t++) { 
        int M; cin >> M;
        map<string,int> names;
        for (int i = 0; i < MAX; i++) {
            set[i] = i;
            cnt[i] = 1;
        }
        int idx = 1;
        for (int i = 0; i < M; i++) {
            string n1,n2; cin >> n1 >> n2;
            int n1_idx, n2_idx;
            if (names[n1] == 0) {
                names[n1] = idx++;
                n1_idx = names[n1];
            }
            else {
                n1_idx = names[n1];
            }

            if (names[n2] == 0) {
                names[n2] = idx++;
                n2_idx = names[n2];
            }
            else {
                n2_idx = names[n2];
            }

            if (!find(n1_idx, n2_idx)) {
                union_node(n1_idx, n2_idx);
            }

            print_cnt(n1_idx);
        }
        
    }
}