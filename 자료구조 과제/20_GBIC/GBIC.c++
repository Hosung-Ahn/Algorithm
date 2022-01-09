# include <iostream>
# include <map>
# include <set>
# include <bitset>

using namespace std;

map<set<int>, bitset<101>> GBIC;

void RInput() {
    int x;
    set<int> dna;
    while (1) {
        cin >> x;

        if (x < 0) {
            if (GBIC.count(dna) == 0 ) {
                bitset<101> diseases;
                diseases.reset();
                diseases[-x] = 1;
                GBIC.insert(make_pair(dna, diseases));
            }
            else 
                GBIC[dna][-x] = 1;

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
                bitset<101> diseases = GBIC[dna];
                for (int i = 1; i <= 100; i++) {
                    if (diseases[i] == 1) cout << -i << " ";
                }
                cout <<"\n";
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