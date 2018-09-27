#define FILE2 "sum"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>
#include <climits>

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
vector<int> lazy;

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

void push (int v, int tl, int tr) {
    if (lazy[v] == INT_MAX)
        return;
    if (tl == tr){
        tsum[v] = lazy[v];
        lazy[v] = INT_MAX;
    }else{
        lazy[2*v] = lazy[v];
        lazy[2*v+1] = lazy[v];
        tsum[v] = (long long)(tr-tl+1) * lazy[v];
        lazy[v] = INT_MAX;
    }

}

long long sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    push(v, tl, tr);
    if (l == tl && r == tr){
        return tsum[v];
    }
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update(int v, int tl, int tr, int l, int r, int x){
    if (l > r)
        return;
    push(v, tl, tr);
    if (l == tl && tr == r) {
        lazy[v] = x;
        push(v, tl, tr);
    }
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), x);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, x);
        push(2*v, tl, tm);
        push(2*v+1, tm+1, tr);
        tsum[v] = tsum[2*v] + tsum[2*v+1];
    }
}

void task(){
    int n, k;
    scanf("%d %d", &n, &k);
    a.assign(n+1, 0);
    tsum.assign(4*n, 0);
    lazy.assign(4*n, INT_MAX);
    build(1, 0, n-1);

    int l, r, x;
    char c;
    string s;
    for (int i = 0; i < k; ++i){
        scanf("\n%c %d %d", &c, &l, &r);
        if (c == 'Q'){
            printf("%lld\n", sum(1, 0, n-1, l-1, r-1));
        }
        else{
            scanf("%d", &x);
            update(1, 0, n-1, l-1, r-1, x);
        }
    }
}
