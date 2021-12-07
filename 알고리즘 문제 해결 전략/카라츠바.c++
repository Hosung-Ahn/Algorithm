# include <iostream>
# include <vector>
# include <algorithm>
# include <string>

using namespace std;

void normalize(vector<int>& num) {
    num.push_back(0);

    for (int i = 0; i < num.size() - 1; i++) {
        if (num[i] < 0) {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow*10;
        }
        else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while (num.size() > 1 && num.back() == 0 )
        num.pop_back();
}

vector<int> mutiply(const vector<int> &a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }

    normalize(c);
    return c;
}

void add_to(vector<int>&a, const vector<int>& b, int k) {
    int original_a_size = a.size();

    if (a.size() < b.size() + k) {
        a.resize(b.size() + k);
    }
    a.push_back(0);

    for (int i = original_a_size; i < a.size(); i++) {
        a[i] = 0;
    }

    for (int i = 0; i < b.size(); i++) {
        a[i+k] += b[i];
    }
    normalize(a);
}

// a >= b 인 경우에만 사용 가능
void sub_from(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();

    if (an < bn) return karatsuba(b,a);

    if (an == 0 || bn == 0) return vector<int>();

    if (an <= 50) return mutiply(a,b);

    int mid = an/2;

    vector<int> a0(a.begin(), a.begin() + mid);
    vector<int> a1(a.begin() + mid, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), mid));
    vector<int> b1(b.begin() + min<int>(b.size(), mid), b.end());

    vector<int> z2 = karatsuba(a1,b1);
    vector<int> z0 = karatsuba(a0,b0);

    add_to(a0,a1,0);
    add_to(b0,b1,0);
    vector<int> z1 = karatsuba(a0,b0);
    sub_from(z1,z0);
    sub_from(z1,z2);

    vector<int> ret(z2.size() + mid*2, 0);
    add_to(ret, z0, 0);
    add_to(ret, z1, mid);
    add_to(ret, z2, mid*2);

    return ret;
}

int main() {
    vector<int> a;
    vector<int> b;

    string sa, sb;
    cin >> sa >> sb;

    string::iterator it_s;
    for (it_s = sa.end() -1; it_s >= sa.begin(); it_s--) {
        a.push_back(*it_s - '0');
    }
    for (it_s = sb.end() -1; it_s >= sb.begin(); it_s--) {
        b.push_back(*it_s - '0');
    }

    vector<int> result = karatsuba(a,b);
    vector<int>::iterator it_v;
    for (it_v = result.end() - 1; it_v >= result.begin(); it_v--) {
        cout << *it_v;
    }
    cout << endl;
}