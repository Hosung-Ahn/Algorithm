# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int N;
vector<int> A[4];
vector<int> A23;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            int x; cin >> x;
            A[j].push_back(x);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A23.push_back(A[2][i] + A[3][j]);
        }
    }

    sort(A23.begin(), A23.end());

    long long result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur = A[0][i] + A[1][j];
            result += upper_bound(A23.begin(), A23.end(), -cur) - lower_bound(A23.begin(), A23.end(), -cur);
        }
    }

    cout << result;

}