#define FILE2 "segmentupdate"

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

vector<long long> tAdd;
vector<long long> tSum;
int n;

void init (int nn)
{
    tAdd.assign (nn, 0);
    tSum.assign (nn, 0);
}

long long sum (long long r)
{
    if (r < 0)
        return 0;
    long long result = 0;
    for(int i=r; i>=0; i=(i&(i+1))-1)
        result += tSum[i] + tAdd[i]*(i-(i&(i+1))+1);
    for(int i=r|(r+1); i<n; i|=i+1)
        result += tAdd[i]*(r-(i&(i+1))+1);
    return result;
}

void add_range(int r, int d){
    if(r<0)
        return;
    for(int i=r; i>=0; i=(i&(i+1))-1)
        tAdd[i] += d;
    for(int i=r|(r+1); i<n; i|=i+1)
        tSum[i] += d*(r-(i&(i+1))+1);
}

void add_range(int l, int r, int d){
    add_range(r, d);
    add_range(l-1, -d);
}

long long get(int ind)
{
    return sum(ind) - sum(ind-1);
}

void task(){
    int q;
    scanf("%d %d\n", &n, &q);
    vector<long long> arr;
    arr.resize(n);
    int k;
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        arr[i] = k;
    }
    init(n);

    int t, ind, l, r, x;
    for (int i = 0; i < q; ++i){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d %d", &l, &r, &x);
            add_range(l-1, r-1, x);
        }else{
            scanf("%d", &ind);
            printf("%lld \n", get(ind-1) + arr[ind-1]);
        }
    }
}