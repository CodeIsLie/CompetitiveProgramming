#define FILE2 "colors"

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
    // color ant type of cloth
    set<pair<int, int>> cloth;

    for (int i = 0; i < 4; ++i){
        int n;
        scanf("%d", &n);
        int c;
        for (int j = 0; j < n; ++j){
            scanf("%d", &c);
            cloth.emplace(c, i);
        }
    }

    vector<int> best_cloth(4, -1000000);
    vector<int> cur_cloth(4, - 1000000);
    int max_difference = INT32_MAX;
    for (auto p: cloth){
        int cur_difference = 0;
        for (int i = 0; i < 4; ++i){
            if (p.second != i)
                cur_difference = max(cur_difference, p.first - cur_cloth[i]);
        }
        cur_cloth[p.second] = p.first;
        if (cur_difference < max_difference){
            best_cloth = cur_cloth;
            max_difference = cur_difference;
        }
    }

    for (auto c: best_cloth){
        printf("%d ", c);
    }
}