# include <iostream>
# include <string>
using namespace std;

bool match(const string& w, const string& s) { 
    int pos = 0;
    while(pos < s.size() &&  pos < w.size() && 
          (w[pos] == '?' || w[pos] == s[pos])) 
        ++pos;

    if (pos == w.size())
        return pos == s.size();

    if (w[pos] == '*') 
        for(int skip = 0; pos+skip <= s.size(); skip++)
            if (match(w.substr(pos+1), s.substr(pos+skip)))
                return true;    
    return false;
}

int main() { 
    string wc;
    cin >> wc;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {

    }
}