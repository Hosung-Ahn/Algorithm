# include <iostream>
# include <vector>
using namespace std;

# define ll long long

vector<int> buildings;

void remove_buildings(int h) {
    while (!buildings.empty() && buildings.back() <= h) {
        buildings.pop_back();
    }
}

int main() {
    int n; cin >> n;
    ll result = 0;
    
    for (int i = 0; i < n; i++) {
        int h; scanf("%d", &h);
        remove_buildings(h);
        result += buildings.size();
        buildings.push_back(h);
    }

    cout << result << endl;
}