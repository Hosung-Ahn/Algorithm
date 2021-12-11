# include <iostream>
# include <set>
# include <vector>
# include <string>
using namespace std;
# define MAX

int N;
vector<set<char>> hg;

int main() {
    // cin >> N;
    // char c;
    // for (int i = 0; i < N; i++) { 
    //     set<char> sub_set;
    //     cin >> c;
    //     while (c != '$') { 
    //         if (c & 0x80) {
    //             sub_set.insert(c);
    //             cout << c << endl;
    //         }
    //         cin >> c;
    //     }
    //     hg.push_back(sub_set);
    // }
    string s = "안녕하세요";
    for (auto x : s) cout << x << " ";
}