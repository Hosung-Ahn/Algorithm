# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main() {
    int N,K; cin >> N >> K;
    string num; cin >> num;

    vector<char> result;

    for (int i = 0; i < num.size(); i++) {
        while (K && !result.empty() && result.back() < num[i]) {
            result.pop_back();
            K--;
        }
        result.push_back(num[i]);
    }

    while (K > 0) {
        result.pop_back();
        K--;
    }

    for (char x : result) {
        cout << x;
    }
}