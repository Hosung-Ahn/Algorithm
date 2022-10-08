#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001
#define MOD 100000007
int res[MAX] = {0,};

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end());
    res[0] = 1;
    for(int m : money) {
        int tmp[MAX] = {0,};
        for(int t=m;t<=n;t++) {
            for (int nm=t-m;nm>=0;nm-=m) {
                tmp[t] += res[nm];
                tmp[t] %= MOD;
            }
        }
        for(int i=1;i<=n;i++) {
            res[i] += tmp[i];
            res[i] %= MOD;
        }

        for(int i=1;i<=n;i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return res[n];
}

int main() {
    vector<int> arr = {1,2,5};
    cout << solution(5,arr); 
}