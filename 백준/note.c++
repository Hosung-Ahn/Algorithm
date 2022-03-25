# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main() {
    vector<pair<int,int>> vec;
    vec.push_back({3,4});
    vec.push_back({1,5});

    sort(vec.begin(), vec.end());

    for (pair<int,int> p : vec) {
        cout << p.first << " " << p.second << endl;
    }

}