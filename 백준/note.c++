# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

int main() {
    queue<int> q;
    queue<int> q2;

    q.push(1);
    
    swap(q,q2);

    cout << q2.front() << endl;
    cout << q.front() << endl;

}