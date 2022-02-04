# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdio>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N; cin >> N;
    vector<int> A;
    vector<int> B;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        B.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int result = 0;

    for (int i = 0; i < N; i++) 
        result += A[i] * B[i];

    cout << result;
}