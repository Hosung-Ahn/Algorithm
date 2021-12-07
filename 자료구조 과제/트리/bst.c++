# include <iostream>
# include <vector>
# include <algorithm>
# include <string>

# define NP nullptr

using namespace std;

struct node{
    node* left;
    node* right;
    string str;
};

class bts{
    public : 
        node* root;

        bts():root(NP){};

        void add_node   ();
        void remove_node();
        void print_depth();
        void print_leaf ();

        node* remove_procees (node* p, string s);
        node* get_max_node   (node* p);
        node* get_min_node   (node* p);
        int   depth_process  (int k, int n, node* p);
        void  leaf_process   (node* p); 
};

int main() {
    vector<string> menu = {"+","-","depth","leaf","quit"};
    bool run = true;
    bts my_bts = bts();

    while (run) {
        string s;
        cin >> s;

        int select = find(menu.begin(), menu.end(), s) - menu.begin();
        switch(select) {
            case 0: my_bts.add_node   (); break;
            case 1: my_bts.remove_node(); break;
            case 2: my_bts.print_depth(); break;
            case 3: my_bts.print_leaf (); break;
            case 4: run = false;          break;
           default: exit(1);
        }
    }
} // end of main()

void bts::add_node() {
    string s;
    cin >> s;

    node* new_node = new node(NP,NP,s);
}