# include <iostream> 
# include <vector>
# include <algorithm>
using namespace std;

vector<int> arr;
vector<int> result;
int N,L,R,X; 
int cnt = 0;

int sum_result(vector<int> &result) {
    int ret = 0;
    for(int x : result) ret += x;
    return ret;
}

void find(int idx) {
    if (idx == N) {
        if (result.size() < 2) return;

        int sum = sum_result(result);
        if (sum >= L && sum <= R && result.back() - *result.begin() >= X) cnt++;
        return;
    }

    result.push_back(arr[idx]);
    find(idx+1);
    result.pop_back();
    find(idx+1);
}   

int main() {
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    find(0);
    cout << cnt;
}