# include <iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;


int main() {
    vector<vector<int>> v;
    v.assign(4, vector<int>(4,0));

    v[2][3] = 3;

    cout << v[2][3] << " " << v[3][0];



}