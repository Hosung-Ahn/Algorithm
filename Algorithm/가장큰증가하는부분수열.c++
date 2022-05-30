# include <iostream>

using namespace std;

#define MAX 1000

int arr[MAX];
int d[MAX];

int under_max_idx(int idx, int value) {
    int ret = -1;

    int max_value = 0;
    for (int i = 0; i < idx; i++) {
        if (arr[i] < value && d[i] > max_value) {
            ret = i;
            max_value = d[i];
        }
    }

    return ret;
}

int main(){
    int n; cin >> n;

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int result = arr[0];

    for (int i = 0; i < n; i++) {
        int idx = under_max_idx(i, arr[i]);
        if (idx == -1) d[i] = arr[i];
        else d[i] = arr[i] + d[idx];

        if (d[i] > result) result = d[i];
    }

    cout << result << endl;
}