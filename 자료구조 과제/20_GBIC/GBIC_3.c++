# include <iostream>
# include <map>
# include <set>
# include <bitset>

using namespace std;

map<set<int>, set<int>> GBIC;       

void RInput() {
    int x;
    set<int> dna;
    while (1) {
        cin >> x;

        if (x < 0) {
            if (GBIC.count(dna) == 0 ) {
                set<int> diseases;
                diseases.insert(-x);
                GBIC.insert(make_pair(dna, diseases));
            }
            else 
                GBIC[dna].insert(-x);

            return;
        }

        dna.insert(x);
    }
}

void QPrint() {
    int x;
    set<int> dna;
    while (1) {
        cin >> x;
        if (x == 0) {
            if (GBIC.count(dna) == 0 ) {
                cout << "None\n";
            }
            else {
                for (auto x : GBIC[dna]){
                    cout << -x << " ";
                }
                cout << endl;
            }
            return;
        }
        
        dna.insert(x);
    }
}

int main() {

    char op;
    while (1) {
        cin >> op;
        if ( op == '$' ) break;

        switch(op) {
            case 'R' :
            RInput();
            break;

            case 'Q' :
            QPrint();
            break;
        }
    }
}   