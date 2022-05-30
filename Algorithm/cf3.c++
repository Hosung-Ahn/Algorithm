# include <iostream>
# include <vector>
using namespace std;

vector<int> arr1,arr2,ret1,ret2;
int N;

void swap(int i, int j) {
    int tmp1 = arr1[i], tmp2 = arr2[i];
    arr1[i] = arr1[j];
    arr2[i] = arr2[j];
    arr1[j] = tmp1;
    arr2[j] = tmp2;
}


void solution1() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (arr1[j] < arr1[j-1]) {
                swap(j,j-1);
                ret1.push_back(j+1);
                ret2.push_back(j);
            }
        }
    }
}

void solution2() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (ret1.size() > 10000) {
                cout << -1 << "\n";
                return;
            }
            if (arr2[j] < arr2[j-1]) {
                if (arr1[j] != arr1[j-1]) {
                    cout << -1 << "\n";
                    return;
                }
                swap(j,j-1);
                ret1.push_back(j+1);
                ret2.push_back(j);
            }
        }
    }
    cout << ret1.size() << "\n";
    for (int i = 0; i < ret1.size(); i++) {
        cout << ret1[i] << " " << ret2[i] << "\n";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr1.push_back(x);
        }
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr2.push_back(x);
        }
        solution1();
        solution2();
        arr1.clear();
        arr2.clear();
        ret1.clear();
        ret2.clear();
    }
}