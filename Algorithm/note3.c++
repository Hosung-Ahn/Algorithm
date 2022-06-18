#include <iostream>
#include <set>
using namespace std;


int main() {
    set<int> s;
    s.insert(-5);
    auto a = s.begin();
    s.insert(-5);
    s.insert(-5);
    s.insert(-5);
    cout << *a << endl;
    a--;
    cout << *a << endl;

}