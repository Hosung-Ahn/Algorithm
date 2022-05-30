# include <iostream> 
# include <vector>
# include <cmath>
using namespace std;
# define ll long long

vector<int> X;
vector<int> Y;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    X.push_back(X[0]);
    Y.push_back(Y[0]);

    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (ll)X[i]*Y[i+1];
        result -= (ll)X[i+1]*Y[i];
    }
    result *= 0.5;

    cout << fixed;
    cout.precision(1);
    
    cout << abs(round(result*10)/10);
}