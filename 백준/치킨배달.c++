# include <iostream>
# include <algorithm>
# include <vector>
# include <math.h>
using namespace std;

# define INF 987654321

class Point {
public:
    int r,c;
    Point(int r, int c) : r(r), c(c) {}

    int dist(Point point) {
        return abs(this->r - point.r) + abs(this->c - point.c);
    }
};

vector<Point> houses, chickens;
vector<int> selected;

int find_result(){
    int result = 0;
    for (Point house : houses) {
        int min_dist = INF;

        for (int i = 0; i < chickens.size(); i++) {
            if (selected[i] == 1) {
                min_dist = min(min_dist, house.dist(chickens[i]));
            }
        }

        
        result += min_dist;
    }
    return result;
}


int main() {
    int N, M; cin >> N >> M;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int x; scanf("%d", &x);
            switch (x) {
                case 1 :
                houses.push_back(Point(r,c));
                break;

                case 2 :
                chickens.push_back(Point(r,c));
                break;
            }
        }
    }

    for (int i = 0; i < chickens.size() - M; i++) 
        selected.push_back(0);
    
    for (int i = 0; i < M; i++) 
        selected.push_back(1);

    int min_result = INF;
    do {
        min_result = min(min_result, find_result());
    } while (next_permutation(selected.begin(), selected.end()));

    cout << min_result;


}