#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <ctime>
#include <algorithm>
#include <climits>
#include <list>
#include <queue>

using namespace std;

void task();

int main(){
#ifdef TEAM
    freopen("./inp.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
#ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
#endif
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

string name_change(string s){
    size_t ind = 0;
    while (true){
        ind = s.find('u', ind);
        if (ind == string:: npos)
            break;
        s.replace(ind, 1, "oo");
    }

    while (true){
        ind = 0;
        ind = s.find("kh", ind);
        if (ind == string:: npos)
            break;
        s.replace(ind, 2, "h");
    }
    return s;
}

void task() {
    int n;
    cin >> n;
    string s;
    set<string> names;
    for (int i = 0; i < n; ++i ){
        cin >> s;
        s = name_change(s);
        names.insert(s);
        //cout << s << endl;
    }


    cout << names.size() << endl;
}