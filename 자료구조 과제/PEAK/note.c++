# include <iostream>
# include <queue>
# include <vector>
# include <fstream>
# include <set>
# define Print(V) for(auto x : V) { cout << x << " "; } cout << endl;
# define ll long long

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    vector<int>::iterator iter_s, iter_e;
    iter_s = iter_e = v.begin();
    iter_s += 3;
    iter_e += 6;

    vector<int> v2(iter_s, iter_e);
    v2[0] = 100;
    Print(v);
    Print(v2);
}