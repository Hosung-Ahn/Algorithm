# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

# define ll long long

class Gem {
public:
    int weight, value;
    Gem(int w, int v) : weight(w), value(v) {}
};

bool cmp(Gem left, Gem right) {
    if (left.value == right.value) {
        return left.weight < right.weight;
    }
    return left.value > right.value;
}

int main() {
    vector<Gem> gems;
    multiset<int> begs;

    int n,k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int w,v; scanf("%d %d", &w,&v);
        gems.push_back(Gem(w,v));
    }
    for(int i = 0; i < k; i++) {
        int beg; scanf("%d", &beg);
        begs.insert(beg);
    }

    sort(gems.begin(), gems.end(), cmp);

    ll result = 0;
    for (Gem gem : gems) {
        if (gem.weight <= *begs.rbegin()) { 
            result += gem.value;
            // cout << gem.value << " " << *begs.lower_bound(gem.weight) << endl;
            begs.erase(begs.lower_bound(gem.weight)); 
        }

        if (begs.empty()) break;
    }

    cout << result;
    
}