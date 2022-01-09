# include <iostream>
# include <set>
# include <map>

using namespace std;

map<set<int>, multiset<int>> GData;

void RInput() {
    int x;
    set<int> dnaSet;

    while (1) {
        cin >> x;
        if (x < 0) {
            
            if ( GData.find(dnaSet) == GData.end()  ) { 
                multiset<int> diseases;
                diseases.insert(x);
                GData.insert(make_pair(dnaSet, diseases));
            }
            else {
                GData[dnaSet].insert(x);
            }
            return;
        }
        dnaSet.insert(x);
    }
}

void printMS(multiset<int> ms) {
    multiset<int>::reverse_iterator iter;
    for (iter = ms.rbegin(); iter != ms.rend(); iter++) {
        cout << *iter << " ";
    }
    cout << endl;
}

void QPrint() {
    int x;
    set<int> dnaSet;

    while (1) {
        cin >> x;

        if (x == 0) {
            if (GData.find(dnaSet) == GData.end()) {
                cout << "None\n";
                return;
            }
            else {
                printMS(GData[dnaSet]);
            }
            return;
        }
        dnaSet.insert(x);
    }
}


int main() {
    char op;
    while (1) {
        cin >> op;
        if ( op == '$' ) break;

        switch (op) {
        case 'R' : 
            RInput();
            break;
        case 'Q' :
            QPrint();
            break;
        }
    }
}