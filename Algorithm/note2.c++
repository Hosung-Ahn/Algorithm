# include <iostream>
# include <queue>
# include <cmath>
using namespace std;

class Point {
public: 
    int r,c;

    Point(int r, int c) : r(r), c(c) {}

    bool operator<(const Point &a) const {
        if (c == a.c) {
            return r > a.r;
        }
        return c > a.c;
    }
};

int main() {
    // priority_queue<Point> pq;
    // pq.push(Point(3,2));
    // pq.push(Point(4,2));

    // cout << pq.top().r << " " << pq.top().c << endl;   
    priority_queue<int> pq;
    cout << round(2);   
}