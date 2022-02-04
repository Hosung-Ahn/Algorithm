# include <iostream>
# include <string.h>
# include <string>
using namespace std;

int room_number[7];


void one_set_find() {
    bool one_set[10] = {0,};

    for (int i = 0; i < 7; i++) {
        int num = room_number[i];
        if (num == -1) continue;

        if (!one_set[num]) {
            one_set[num] = true;
            room_number[i] = -1;
        }

        else if (num == 6 && !one_set[9]) {
            one_set[9] = true;
            room_number[i] = -1;
        }

        else if (num == 9 && !one_set[6]) {
            one_set[6] = true;
            room_number[i] = -1;
        }
    }
}

bool all_clear() {
    for (int i = 0; i < 7; i++) {
        if (room_number[i] != -1) return false;
    }
    return true;
}

void print_result() {
    int cnt = 0;
    while (!all_clear()) {
        one_set_find();
        cnt++;
    }
    cout << cnt;
}

int main() {
    memset(room_number, -1, sizeof(int)*7);
    
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
        room_number[i] = str[i] - '0';
    }

    print_result();
}