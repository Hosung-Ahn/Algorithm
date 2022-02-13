# include <iostream>
# include <vector>
# include <climits>
# include <algorithm>
using namespace std;

# define MAX 1000001

int indexing[MAX] = {0,};
int arr[MAX] = {0,};

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    vector<int> cnt_arr;
    cnt_arr.push_back(INT_MIN);
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        int x = arr[i];
        int index = 0;

        if (x > cnt_arr.back()) {
            cnt++;
            cnt_arr.push_back(x);
            index = cnt_arr.size()-1;
        }
        else {
            vector<int>::iterator iter = lower_bound(cnt_arr.begin(), cnt_arr.end(), x);
            *iter = x;
            index = iter - cnt_arr.begin();
        }
        indexing[i] = index;
    }

    cout << cnt << endl;

    vector<int> result;
    for (int i = N; i > 0; i--) {
        if (indexing[i] == cnt) {
            result.push_back(arr[i]);
            cnt--;
        }
    }

    vector<int>::reverse_iterator iter;
    for (iter = result.rbegin(); iter != result.rend(); iter++) {
        cout << *iter << " ";
    }
}