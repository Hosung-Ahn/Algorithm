# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};

    remove(v.begin(), v.end(), 1);

    for (int x : v) {
        cout << x << " ";
    }
}