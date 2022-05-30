# include <iostream>
# include <cstdio>
# include <map>
# include <string>
# include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        map<string, int> clothes;
        int n; cin >> n;
        int result = 1;
        for (int i = 0; i < n; i++) {
            string name, key;
            cin >> name >> key;

            if (clothes.count(key) == 0) clothes[key] = 1; 
            else clothes[key] += 1;
        }

        map<string, int>::iterator iter;
        for (iter = clothes.begin(); iter != clothes.end(); iter++) {
            result *= iter->second +1; 
        }
        cout << result - 1 << "\n";
    }
}