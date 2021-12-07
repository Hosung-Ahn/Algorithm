# include <iostream>
# include <vector>
using namespace std;

int main() { 
    vector<int> result(5, 0);

    vector<int>::iterator iter;
    for(iter = result.begin(); iter != result.end(); iter++ ) {
        cout << *iter << endl; 
    }
    
}