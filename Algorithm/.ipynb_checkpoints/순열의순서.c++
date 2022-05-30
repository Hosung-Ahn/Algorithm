# include <iostream>
# include <vector> 
using namespace std;

# define ll long long

ll fac[21];
bool nums[21] = {0, };
int N;
int p_nums[21];

void print_cnt_nums(int t_cnt) {
    int cnt = 0;
    for (int n = 1; n <= N; n++) {
        if (!nums[n]) cnt++;
        if (t_cnt == cnt) {
            cout << n << " ";
            nums[n] = true;
            return;
        }
    }
}

void print_nums() {
    for (int n = 1; n <= N; n++) {
        if (!nums[n]) cout << n << " ";
    }
}

void print_nst_permutation(int N, ll nst) {
    // cout << nst << endl;
    if (nst == 1) {
        print_nums();
        return;
    }
    int cnt = 1;
    while (nst > fac[N-1]) {
        nst -= fac[N-1];
        cnt++;
    }
    print_cnt_nums(cnt);
    print_nst_permutation(N-1, nst);
}

ll print_nst(int N, int nst) {
    if (N == nst) return 1;

    ll result = 0;
    for (int n = 1; n <= N; n++) {
        if (!nums[n]) {
            if (p_nums[nst] == n) {
                nums[n] = true;
                result += print_nst(N, nst+1);
                break;
            }
            result += fac[N-nst];
        }
    }
    return result;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) 
        fac[i] = fac[i-1] * i;

    cin >> N;

    int op; cin >> op;

    switch (op) {
        case 1 : 
        ll nst; cin >> nst;
        print_nst_permutation(N,nst);
        cout << endl;
        break;
        case 2 :
        for (int i = 1; i <= N; i++) 
            scanf("%d", &p_nums[i]);
        cout << print_nst(N, 1) << endl;
        break;
    }

}