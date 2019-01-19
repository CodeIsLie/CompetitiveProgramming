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

void task(){
    int n;
    cin >> n;
    int x, y;

    set<pair<int, int>> coords;
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        coords.emplace(x, y);
    }

    vector<pair<int, int>> hints(n);
    for (int i = 0; i < n; ++i){
        cin >> x >> y;
        hints[i] = make_pair(x, y);
    }

    //
    for (auto& h: hints){
        int t_x = coords.begin()->first + h.first;
        int t_y = coords.begin()->second + h.second;
        bool b = true;
        for (auto& hint: hints){
            x = t_x - hint.first;
            y = t_y - hint.second;
            if (coords.find(make_pair(x, y)) == coords.end()){
                b = false;
                break;
            }
        }
        if (b) {
            cout << t_x << " " << t_y << endl;
            break;
        }
    }
}