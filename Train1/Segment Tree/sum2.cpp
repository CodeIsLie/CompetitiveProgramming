//
// Created by Ilya on 23.09.2018.
//

#define FILE2 "sum2"

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
vector<long long> tsum;

void build (int v, int tl, int tr) {
    if (tl == tr) {
        tsum[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        tsum[v] = tsum[v*2] + tsum[v*2+1];
    }
}

long long sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tsum[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}


void task(){
    int n;
    scanf("%d", &n);

    a.assign(n, 0);
    int num;
    for (int i = 0; i < n; ++i){
        scanf("%d", &num);
        a[i]=num;
    }

    tsum.assign(4*n, 0);
    build(1, 0, n-1);

    int k;
    scanf("%d", &k);
    int l, r;
    for (int i = 0; i < k; ++i){
        scanf("%d %d", &l, &r);
        printf("%lld\n", sum(1, 0, n-1, l-1, r-1));
    }
}
