# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define MAX 10000 

int main() {
    int N,K; cin >> N >> K;

    vector<int> arr;
    for (int i = 0; i < N; i++) { 
        int x; scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    vector<int> diff;
    for (int i = 1; i < N; i++) {
        diff.push_back(arr[i] - arr[i-1]);
    }
    sort(diff.begin(), diff.end());

    int result = 0;
    for (int i = 0; i < N-K; i++)
        result += diff[i];

    cout << result; 

    
}