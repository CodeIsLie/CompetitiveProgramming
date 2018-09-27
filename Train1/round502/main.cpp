//#define FILE2 "rsq"

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


void task(){
    int n;
    cin >> n;

    vector<int> a;
    n*=2;
    a.assign(n, 0);
    for (int &el: a){
        cin >> el;
    }

    sort(a.begin(), a.end());
    long long mini = LLONG_MAX;
    for (int i = 0; i < n-1; ++i) {
        int dx = abs(a[(i+n/2-1) % n] - a[i]);
        int dy = abs(a[n-1] - a[(i==0)?n/2:0]);

        long long area = 1LL * dx * dy;
        mini = min(area, mini);
    }

    cout << mini;
}
