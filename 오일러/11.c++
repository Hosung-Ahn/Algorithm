# include <iostream>
# include <vector>

using namespace std;

int h_product(const vector<int>& num_i, int index) {
    int ret = 1;
    for (int i = index; i < index + 4; i++) { 
        ret *= num_i[i];
    }
    return ret; 
}
int find_h_max(const vector<vector<int> >& num) {
    int max_product = 0; 
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j <= 16; j++) {
            max_product = max(max_product, h_product(num[i], j));
        }
    }
    return max_product;
}

int v_product(const vector<vector<int> >& num, int r, int c) {
    int ret = 1;
    for (int i = r; i < r + 4; i++) {
        ret *= num[i][c];
    }
    return ret; 
}

int find_v_max(const vector<vector<int> >&num) { 
    int max_product = 0; 
    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j < 20; j++) { 
            max_product = max(max_product, v_product(num, i, j));
        }
    }
    return max_product; 
}

int d_product(const vector<vector<int> >& num, int r, int c) {
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        ret *= num[r+i][c+i];
    }
    return ret; 
}

int find_d_max(const vector<vector<int> >& num) {
    int max_product = 0; 
    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 16; j++) {
            max_product = max(max_product, d_product(num,i,j));
        }
    }
    return max_product;
}

int d2_product(const vector<vector<int> >& num, int r, int c) {
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        ret *= num[r+i][c-i];
    }
    return ret; 
}

int find_d2_max(const vector<vector<int> >& num) {
    int max_product = 0; 
    for (int i = 0; i <= 16; i++) {
        for (int j = 4; j < 20; j++) {
            max_product = max(max_product, d2_product(num,i,j));
        }
    }
    return max_product;
}

int main() {
    vector<vector<int> > num(20);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j <20; j++) {
            int x; cin >> x;
            num[i].push_back(x);
        }
    }

    cout << find_h_max(num) << endl;
    cout << find_v_max(num) << endl;
    cout << find_d_max(num) << endl;
    cout << find_d2_max(num) << endl;


}