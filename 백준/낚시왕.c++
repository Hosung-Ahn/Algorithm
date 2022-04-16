# include <iostream>
# include <algorithm>
# include <vector>
# include <math.h>
using namespace std;

int R,C,M;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1}; 

void change_d(int &d) {
    switch(d) {
        case 0 :
            d = 1;
        break;

        case 1 :
            d = 0;
        break;

        case 2 :
            d = 3;
        break;

        case 3 :
            d = 2;
        break;
    }
}

class Shark{ 
public:
    int r,c,s,d,z;
    Shark(int r, int c, int s, int d, int z) : r(r), c(c), s(s), d(d), z(z) { }

    void move() {
        int start;
        int end;
        if (d < 2) {
            start = r;
            end = R;
        }
        else {
            start = c;
            end = C;
        }

        int moved = start + (dr[d]+dc[d])*s;
        if (moved > 0 && moved <= end) {
            if (d < 2) r = moved;
            else c = moved;
            return;
        }
        int go = s;
        switch(d) {
            case 0 :
                go -= start - 1;
                if(((go-1)/(end-1)) % 2 == 0) {
                    change_d(d);
                    r = 1 + (go-1)%(end-1) + 1;
                }
                else {
                    r = end - ((go-1)%(end-1)+1);
                }
            break;

            case 1 :
                go -= (end-start);
                if (((go-1)/(end-1))%2 == 0) {
                    change_d(d);
                    r = end - ((go-1)%(end-1)+1);
                }
                else {
                    r = 1 + (go-1)%(end-1) + 1;
                }
            break;

            case 2 :
                go -= (end - start);
                if ((go-1)/(end-1)%2 == 0) {
                    change_d(d);
                    c = end - ((go-1)%(end-1)+1);
                }
                else {
                    c = 1 + (go-1)%(end-1) + 1;
                }
            break;

            case 3 :
                go -= start - 1;
                if ((go-1)/(end-1)%2==0) {
                    change_d(d);
                    c = 1 + (go-1)%(end-1) + 1;
                }
                else {
                    c = end - ((go-1)%(end-1)+1);
                }
            break;
        }
    }
};

bool cmp(const Shark &a, const Shark &b){
    if (a.c == b.c) {
        if (a.r == b.r) {
            return a.z < b.z;
        }
        return a.r < b.r;
    }
    return a.c < b.c;
}

vector<Shark> sharks;
int result = 0;

void catch_shark(int person) {
    int remove = -1;
    for (int i = 0; i < sharks.size(); i++) {
        if (sharks[i].c == person) {
            result += sharks[i].z;
            remove = i;
            break;
        }
    }
    if (remove >= 0)
        sharks.erase(sharks.begin()+remove);
}

vector<Shark> party_time() {
    vector<Shark> ret;
    if (sharks.size() <= 1) return sharks;

    for (int i = 1; i < sharks.size(); i++) {
        if (sharks[i].r == sharks[i-1].r && sharks[i].c == sharks[i-1].c) 
            continue;
        ret.push_back(sharks[i-1]);
    }
    ret.push_back(sharks.back());
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        sharks.push_back(Shark(r,c,s,d-1,z));
    }

    sort(sharks.begin(), sharks.end(), cmp);

    for (int person = 1; person <= C; person++) {
        catch_shark(person);
        for(Shark &shark : sharks) {
            shark.move();
        }
        sort(sharks.begin(), sharks.end(), cmp);
        sharks = party_time();
    }

    cout << result;
}