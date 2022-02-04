# include <iostream>
# include <string>
using namespace std;
string str;

int count_1() {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            cnt++;
            while (i < str.size() && str[i] == '1') {
                i++;
            }
        }
    }
    return cnt;
}

int count_0() {
    int cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            cnt++;
            while(i < str.size() && str[i] == '0') {
                i++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> str;
    cout << min(count_0(), count_1());
}