# include <iostream>
# include <set>
# include <vector>
using namespace std;

int main() {
    set<pair<int,int>> s;
    s.insert({1,2});
    s.insert({1,3});
    s.insert({0,4});

    cout << s.lower_bound({0,2})->first << endl;

    for (pair<int,int> p : s) {
        cout << p.first << " " << p.second << endl;
    }
}