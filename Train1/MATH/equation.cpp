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


void task(){
    int n;
    cin >> n;

    long long cntSolutions = 0;
    long long nsquare = n*n;
    for (long long y = 1; y*y < n; ++y){
        if (nsquare % y == 0)
            cntSolutions++;
    }
//    cntSolutions *= 2;
//    if ((int)sqrt(n) * (int)sqrt(n) == n)
//        cntSolutions++;

    // graphic is symmetric
    cntSolutions *= 2;
    // point on line x = y always integer
    cntSolutions++;

    cout << cntSolutions;
}