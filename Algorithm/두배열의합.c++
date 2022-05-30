# include <iostream>
# include <vector>
# include <map>
using namespace std;
# define ll long long

map<int,int> cnt;

int main() {
    int T,N,M;
    cin >> T;

    cin >> N;
    vector<int> arr; 
    int sum = 0 ,x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        sum += x;
        arr.push_back(sum);
    }

    vector<int> arr2;
    sum = 0;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        sum += x;
        arr2.push_back(sum);

        cnt[sum]++;
        for (int j = 0; j < i; j++) {
            cnt[sum-arr2[j]]++;
        }
    }

    ll result = 0;
    for (int i = 0; i < N; i++) {
        int cur = arr[i];
        int side = T-cur;
        result += cnt[side];

        for (int j = 0; j < i; j++) {
            side = T-(cur-arr[j]);
            result += cnt[side];
        }
    }
    cout << result;
}
