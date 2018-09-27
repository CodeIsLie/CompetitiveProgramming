//#define FILE2 "stars"

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

vector<long long> t;
int n;

void init (int nn)
{
    t.assign (nn, 0);
}

long long sum (long long r)
{
    long long result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    return result;
}

void inc (int i, int x)
{
    for (; i < n; i = (i | (i+1)))
        t[i] += x;
}

long long sum (int l, int r)
{
    return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
    init ((int) a.size());
    for (unsigned i = 0; i < a.size(); i++)
        inc (i, a[i]);
}

vector<int> arr;

void task(){
    int m;
    scanf("%d", &n);
    arr.assign(n, 0);


    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    init(arr);

    int t, x, y;
    for (int i = 0; i < m; ++i){
        scanf("%d %d %d", &t, &x, &y);
        if (t == 0){
            if (y > 1)
                printf("%lld\n", sum(x-1, y-1));
            else
                printf("%lld\n", sum(x-1));
        }else{
            inc(x-1, y-arr[x-1]);
            arr[x-1] = y;
        }
    }
}