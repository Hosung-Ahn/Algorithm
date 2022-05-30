# include <iostream>
# include <vector>
# include <math.h>
# include <algorithm>
using namespace std;

int main() {
    int G; cin >> G;
    int check = pow(G, 0.5);

    if (check * check == G) check--;

    vector<int> result;

    for (int d = 1; d <= check; d++) {
        if (G % d == 0) {
            if ((d+G/d) % 2 == 1) continue;
            result.push_back((d+G/d)/2);
        }
    }

    sort(result.begin(), result.end());

    if (result.empty()) cout << -1;
    else {
        for (int x : result) 
            cout << x << "\n";
    }
}