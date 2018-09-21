//
// Created by admin on 21.09.2018.
//

#define FILE2 "rvq"

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
vector<int> tmin;
vector<int> tmax;

void build (int v, int tl, int tr) {
    if (tl == tr) {
        tmin[v] = a[tl];
        tmax[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        tmin[v] = min(tmin[v*2], tmin[v*2+1]);
        tmax[v] = max(tmax[v*2], tmax[v*2+1]);
    }
}

int min (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT32_MAX;
    if (l == tl && r == tr)
        return tmin[v];
    int tm = (tl + tr) / 2;
    return min(
            min (v*2, tl, tm, l, min(r,tm)),
            min (v*2+1, tm+1, tr, max(l,tm+1), r)
    );
}

int max (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT32_MIN;
    if (l == tl && r == tr)
        return tmax[v];
    int tm = (tl + tr) / 2;
    return max(
            max (v*2, tl, tm, l, min(r,tm)),
            max (v*2+1, tm+1, tr, max(l,tm+1), r)
    );
}
void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tmin[v] = new_val;
        tmax[v] = new_val;
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        tmin[v] = min(tmin[v*2], tmin[v*2+1]);
        tmax[v] = max(tmax[v*2], tmax[v*2+1]);
    }
}


void task(){
    int n = 100000;

    a.assign(n+1, 0);
    for (long long i = 1; i <= n; ++i){
        a[i] = (i % 12345) * (i % 12345) % 12345 +
               (i % 23456) * (i % 23456) * (i % 23456) % 23456;
    }

    tmin.assign(4*n, 0);
    tmax.assign(4*n, 0);
    build(1, 1, n);

    int k;
    scanf("%d", &k);
    int x, y;
    for (int i = 0; i < k; ++i){
        scanf("%d %d", &x, &y);
        if (x > 0){
            printf("%d\n", max(1, 1, n, x, y)- min(1, 1, n, x, y));
        }else if (x < 0){
            update(1, 1, n, abs(x), y);
        }
    }
}
