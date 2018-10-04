#define FILE2 "tickets"

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


void task() {
    int n;
    cin >> n;

    int max_time = 23 * 3600 + 59 * 60 + 60;
    multiset<pair<int, int>> time;
    int l, r;
    int s, m, h;
    for (int i = 0; i < n; ++i) {
        cin >> h >> m >> s;
        l = h * 3600 + m * 60 + s;
        cin >> h >> m >> s;
        r = h * 3600 + m * 60 + s;

        if (l == r) {
            time.emplace(0, 1);
            time.emplace(max_time, 2);
        } else if (l > r) {
            time.emplace(l, 1);
            time.emplace(max_time, 2);
            time.emplace(0, 1);
            time.emplace(r, 2);
        } else {
            time.emplace(l, 1);
            time.emplace(r, 2);
        }
    }

    int work_time = 0;
    int start_time = 0;
    int working_windows = 0;
    for (auto p: time){
        if (p.second == 1){
            working_windows++;
            if (working_windows == n){
                start_time = p.first;
            }
        }else{
            if (working_windows == n){
                work_time += p.first - start_time;
            }
            working_windows--;
        }
    }
    cout << work_time << endl;
}