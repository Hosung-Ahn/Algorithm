# include <iostream>
# include <cmath>
using namespace std;

double cal_triangle(double x1,double y1, double x2, double y2, double x3, double y3) {
    return 1.0/2.0 * ((x2*y1 + x3*y2 + x1*y3) - (x1*y2 + x2*y3 + x3*y1));
}

int main() {
    double result = 0;
    int N; cin >> N;
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1; 
    cin >> x2 >> y2;
    for (int i = 2; i < N; i++) {
        cin >> x3 >> y3;
        result += cal_triangle(x1,y1,x2,y2,x3,y3);
        x2 = x3; 
        y2 = y3;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(round(result*10) / 10);
}