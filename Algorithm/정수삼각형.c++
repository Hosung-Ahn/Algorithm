# include <iostream> 
# include <algorithm>
# include <vector>
# define MAX 500
using namespace std;

void find_max_path(vector<vector<int> >& t, int index){ 
    if (index == 0) return;
    for (int i = 0; i < index; i++) {
        t[index-1][i] += max(t[index][i], t[index][i+1]);
    }
    find_max_path(t, index-1);
}

int main() {
    vector<vector<int> > triagle;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> sub_t;
        for (int j = 1; j <= i; j++) {
            int x; cin >> x;
            sub_t.push_back(x);
        }
        triagle.push_back(sub_t);
    }
    find_max_path(triagle, n-1);
    cout << triagle[0][0] << endl;
}