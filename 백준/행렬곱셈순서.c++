# include <iostream>
# include <vector>
using namespace std;

# define MAX 500
# define INF 2147483647
int dp[MAX][MAX] = {0,};

class Matrix {
public:
    int a,b;

    Matrix(int a, int b) : a(a), b(b) {}
};

vector<Matrix> matrices;

int multiple(int left, int mid, int right) {
    return matrices[left].a * matrices[mid].b * matrices[right].b; 
}

int find_dp(int left, int right) {
    if (left == right) return 0;
    if (left + 1 == right) return multiple(left, left, right);

    if (dp[left][right] != 0) return dp[left][right];

    int result = INF;

    for (int mid = left; mid < right; mid++) {
        result = min(result, find_dp(left, mid) + find_dp(mid + 1, right) + 
                              multiple(left, mid, right));
    }

    dp[left][right] = result;
    return result;
}


int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b; scanf("%d %d", &a, &b);
        matrices.push_back(Matrix(a,b));
    }

    cout << find_dp(0,N-1);


}