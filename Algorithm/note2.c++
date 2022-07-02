# include <iostream>
#include <vector>
# include <queue>
# include <cmath>
using namespace std;

int main() {
    vector<int> a,b;
    for (int i = 0; i < 3; i++) {
        a.push_back(i);
        b.push_back(i);
    }
    b.push_back(3);

    cout << (a == b); 
}