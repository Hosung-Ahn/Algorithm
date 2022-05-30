# include <iostream>
# include <set>
# include <algorithm>
using namespace std;

int arr[5];
int idx = 0;


int main() {
    multiset<int> ms;
    int n; cin >> n;
    for (int i = 0; i <n*n; i++) {
        int x; scanf("%d", &x);
        if (ms.size() < n) {
            ms.insert(x);
        }
        else {
            if (*ms.begin() >= x) continue;
            else {
                ms.erase(ms.begin());
                ms.insert(x);
            }
        }
    }

    cout << *ms.begin() << endl;


}