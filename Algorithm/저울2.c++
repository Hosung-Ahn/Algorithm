# include <iostream> 
# include <vector>
# include <algorithm>
using namespace std;

void print_result(const vector<int> &arr) {
    int tmp = arr[0];
    if (tmp > 1) {
        cout << 1;
        return;
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= tmp + 1) {
            tmp += arr[i];
        }
        else {
            cout << tmp + 1; 
            return;
        }
    }

    cout << tmp + 1;
}

int main() {
    vector<int> arr;
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    print_result(arr);
}