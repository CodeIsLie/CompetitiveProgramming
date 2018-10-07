// #define FILE2 "cover"

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
    int n, x, y, a0;
    cin >> n >> x >> y >> a0;
    vector<int> as;
    vector<long long> cumulative;
    as.assign(n, 0);
    cumulative.assign(n, 0);
    as[0] = a0;
    cumulative[0] = a0;
    for (int i = 1; i < as.size(); ++i){
        int a = ((long long)as[i-1]*x + y + (1<<16)) % (1<<16);
        as[i] = a;
        cumulative[i] = cumulative[i-1] + a;
    }

    int m, z, t, b0;
    cin >> m >> z >> t >> b0;
    vector<int> bs;
    bs.assign(n, 0);
    bs[0] = a0;
    for (int i = 1; i < bs.size(); ++i){
        int b = ((long long)bs[i-1]*z + t + (1<<30)) % (1<<30);
        bs[i] = b;
    }
}