#define FILE2 "inverse"

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
//    for (unsigned i = 0; i < a.size(); i++)
//        inc (i, a[i]);
}

void task(){
    scanf("%d", &n);
    vector<pair<int, int>> arr;
    arr.resize(n);
    int k;
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        arr[i] = make_pair(k, i);
    }
    init(n);

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i){
        arr[i].first = i;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int> p1, const pair<int,int> p2){
        return p1.second < p2.second;
    });

    int inversions = 0;
    for (int i = n-1; i >= 0; --i){
        inversions += sum(0, (arr[i].first > 0)? arr[i].first-1: 0);
        inc(arr[i].first, 1);
    }
    cout << inversions << endl;
}