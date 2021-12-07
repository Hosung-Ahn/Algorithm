# include <iostream>
using namespace std;
# define MAX 100

int n;
int arr[MAX][MAX];
bool arrived = false;

bool in_range(int r, int c) {
    if (r >= n || c >= n) return false;
    return true;
}

void gogo(int r, int c) {
    if (arr[r][c] == 0) {
        if (r == n-1 && c == n-1) arrived = true;
        return;
    }

    int nr = r + arr[r][c];
    int nc = c + arr[r][c];
    arr[r][c] = 0;

    if (in_range(nr, c)) gogo(nr,c);
    if (in_range(r,nc)) gogo (r,nc);

}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                scanf("%d", &arr[i][j]);

        gogo(0,0);
        if (arrived) cout << "YES\n";
        else cout << "NO\n";
        arrived = false;
    }

}