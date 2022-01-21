# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <set>
# include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int> > pq_1;
    pq_1.push(1);
    pq_1.push(2);

    cout << pq_1.top();
}