#include <iostream>
using namespace std;
#define MAX 100000
int month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int cal_index(int m, int d) {
    return month[m-1] + d;
};

pair<int,int> arr[MAX];
int N;

bool next(int &start) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].first <= start) {
            ret = max(ret, arr[i].second);
        }
    }
    if (ret == 0 || start == ret) return false;
    else {
        start = ret;
        return true;
    }
}

int main(){
    int sum = 0;
    for (int i = 0; i <= 12; i++) {
        sum += month[i];
        month[i] = sum;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int sm,sd,em,ed;
        cin >> sm >> sd >> em >> ed;
        arr[i] = {cal_index(sm,sd), cal_index(em,ed)};
    }

    int start = 60;
    int result = 0;
    while(start < 335 && next(start)) {
        result++;
    }
    if (start < 335) cout << 0;
    else cout << result;


    
}