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

int n, m;

long long to_code(int x, int y){
    return x*n + y;
}


void task() {
    int n;
    cin >> n;

    multiset<double> h;
    double max_n;
    double min_n;
    int a;
    for (int i = 0; i < n; ++i){
        cin >> a;
        h.insert(a);
    }
    set<double> deleted;
    max_n = *prev(h.end());
    min_n = *h.begin();
    double k = 1.0*min_n/max_n;
    for (int i = 0; i < n-1; ++i){
        double del = *prev(h.end());
        deleted.insert(1.0*del/2);
        h.erase(prev(h.end()));

        min_n = min(*deleted.begin(), *h.begin());
        max_n = max(*prev(deleted.end()), *prev(h.end()));
        double new_k = min_n / max_n;
        k = max(k, new_k);
    }
    printf("%.10f",k);
}