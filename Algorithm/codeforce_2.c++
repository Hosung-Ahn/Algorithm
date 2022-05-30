# include <iostream>
using namespace std;

# define MAX 100000
# define ll long long
int arr[MAX] = {0,};
int n,x;
ll y;

void print_result(int cnt_odd) {
    if ((y + x + cnt_odd) % 2 == 0) cout << "Alice\n"; 
    else cout << "Bob\n";
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        scanf("%d %d %lld", &n, &x, &y);

        int cnt_odd = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] % 2 == 1) cnt_odd++;
        }
        print_result(cnt_odd);
    }
}