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
    int n, m;
    cin >> n >> m;
    multiset<int> heights;
    long long all = 0;
    int h;
    for (int i = 0; i < n; ++i){
        cin >> h;
        heights.insert(h);
        all += h;
    }

    vector<int> hs = vector<int>(heights.rbegin(), heights.rend());
    int dels = 0;
    int cur = min(m, hs[0]);
    for (int i = 1; i < hs.size(); ++i){
        dels = max(1, cur - min(cur, hs[i]));
        all -= dels;
        cur = cur - dels;
    }
    dels = max(1, cur);
    all -= dels;
    cout << all << endl;
}