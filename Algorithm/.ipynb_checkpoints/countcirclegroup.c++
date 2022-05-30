# include <iostream>
# include <vector>
# include <set>
# include <math.h>
# include <string.h>
using namespace std;

# define MAX 3001

struct Point {
    int x,y,r;
    Point(int x, int y, int r) : x(x), y(y), r(r) { }
};

int arr[MAX] = {0,};
vector<Point> points;

bool is_linked(Point a, Point b) {
    int point_d = pow(b.x - a.x, 2) + pow(b.y - a.y, 2);
    int circle_d = pow(a.r + b.r, 2);

    if (circle_d >= point_d) return true;
    return false;
}

void include_set(int last, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == last) arr[i] = n;
    }
}

void find_set(Point cur, int n) {
    for (int i = 0; i < n; i++) {
        if (is_linked(points[i], cur)) {
            include_set(arr[i], n);
        }
    }
}


int main(){
    int T; cin >> T;
        for (int t = 0; t < T; t++) {

        int N; cin >> N;
        int x,y,r;

        scanf("%d %d %d", &x, &y, &r);
        points.push_back({x,y,r});

        for (int i = 1; i < N; i++) {
            scanf("%d %d %d", &x, &y, &r);
            Point cur = Point(x,y,r);
            points.push_back({x,y,r});
            find_set(cur, i);
            arr[i] = i;
        }

        set<int> result;
        for (int i = 0; i < N; i++) {
            result.insert(arr[i]);
        }

        cout << result.size() << endl;

        // for (int i = 0; i < N; i++) {
        //     cout << arr[i] << " ";
        // }

        memset(arr, 0, sizeof(int)*MAX);
        points.clear();
    }
}   