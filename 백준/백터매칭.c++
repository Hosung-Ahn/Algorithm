# include <iostream>
# include <vector>
# include <math.h>
# include <algorithm>

using namespace std;

# define ll long long

int N;
vector<pair<int,int>> vectors;
vector<double> result;

double vector_sum() {
    ll total_x = 0, total_y = 0;
    for (auto vec : vectors) {
        total_x += vec.first;
        total_y += vec.second;
    }
    return sqrt(total_x*total_x + total_y*total_y);
}

void multiply_minus(int i) {
    vectors[i].first *= -1;
    vectors[i].second *= -1;
}

void find_vector_sum(int i, int minus, int plus) {
    if (minus == N/2) {
        result.push_back(vector_sum());
        return;
    }
    if (plus == N/2) {
        for (int ni = i; ni < N; ni++) multiply_minus(ni);
        result.push_back(vector_sum());
        for (int ni = i; ni < N; ni++) multiply_minus(ni);
        return;
    }

    find_vector_sum(i+1, minus, plus+1);
    multiply_minus(i);
    find_vector_sum(i+1, minus+1, plus);
    multiply_minus(i);
}


int main() {
    int T; scanf("%d", &T);
    for (int t = 0; t < T; t++){
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            int x,y; scanf("%d %d", &x, &y);
            vectors.push_back(make_pair(x,y));
        }

        find_vector_sum(0,0,0);

        printf("%.10lf\n", *min_element(result.begin(), result.end()));

        vectors.clear();
        result.clear();
    }
}