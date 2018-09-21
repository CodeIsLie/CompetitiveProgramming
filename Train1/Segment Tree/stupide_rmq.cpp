//
// Created by admin on 21.09.2018.
//
#define FILE2 "stupid_rmq"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>

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

vector<int> a;
vector<int> stree;

void build (int v, int tl, int tr) {
    if (tl == tr)
        stree[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        stree[v] = min(stree[v*2], stree[v*2+1]);
    }
}

int min (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT32_MAX;
    if (l == tl && r == tr)
        return stree[v];
    int tm = (tl + tr) / 2;
    return min(
            min (v*2, tl, tm, l, min(r,tm)),
            min (v*2+1, tm+1, tr, max(l,tm+1), r)
    );
}

void task(){
    int n;
    cin >> n;

    a.assign(n, 0);
    stree.assign(4*n, 0);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    build(1, 0, n-1);

    int m;
    cin >> m;
    int l, r;
    for (int i = 0; i < m; ++i){
        cin >> l >> r;
        cout << min(1, 0, n-1, l-1, r-1) << endl;
    }
}


