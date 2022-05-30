# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

bool compare(pair<int,int> l, pair<int,int> r) {
    if (l.first == r.first) return l.second < r.second;
    return l.first < r.first;
}

int main() {
    vector<pair<int,int>> timeTable;
    priority_queue<int, vector<int>, greater<int>> room;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int s,e; scanf("%d %d", &s, &e);
        timeTable.push_back({s,e});
    }

    sort(timeTable.begin(), timeTable.end(), compare);
    room.push(timeTable[0].second);

    for (int i = 1; i < timeTable.size(); i++) {
        if (room.top() <= timeTable[i].first) {
            room.pop();
            room.push(timeTable[i].second);
        }
        else {
            room.push(timeTable[i].second);
        }
    }

    cout << room.size() << endl;

    
}