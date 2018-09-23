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
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}




void task(){
    int n, m, k;
    cin >> n;

    vector<int> ps;
    ps.assign(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> ps[i];
    }

    sort(ps.rbegin(), ps.rend());
    map<int, int> isPs;
    isPs[1]
    long long mult = 1;
    bool add1= false;
    for (int p: ps){
        if (!isPs[p]) {
            isPs[p] = 1;
            mult = mult*p % 1000000007;
        }else
        if (isPs[p] == 1) {
            isPs[p] = 2;
            if (mult % (p-1) != 0)
                mult = mult*(p-1) % 1000000007;
            isPs[p-1] = 1;
        }else{
            add1 = true;
        }
    }
    mult += (int)add1;

    cout << mult;
}
