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
    int n;
    cin >> n;
    vector<long long> a(n);
    int max_n = 0;
    for (auto& el: a){
        cin >> el;
        max_n = max(max_n, (int)el);
    }
    long long lnum = 1000000007;

    vector<long long> divisors(max_n+1, 0);
    divisors[1] = 1;
    long long cnt_divs = 0;
    for (int i = 1; i < n; ++i){
        vector<long long> inc_n;
        for (int j = 1; j*j <= min((long long)(i+1)*(i+1), a[i]); ++j){
            if (a[i] % j == 0){
//                cnt_divs = (cnt_divs + divisors[j-1]) % lnum;
//                if (j != a[i]/j && a[i]/j <= i+1)
//                    cnt_divs = (cnt_divs + divisors[a[i]/j-1]) % lnum;
                inc_n.push_back(j);
                if (a[i]/j <= i+1 && a[i]/j != j)
                    inc_n.push_back(a[i]/j);
            }
        }
        sort(inc_n.begin(), inc_n.end());
        reverse(inc_n.begin(), inc_n.end());
        for (auto& inc: inc_n)
            divisors[inc]= (divisors[inc] + divisors[inc-1]) % lnum;
        divisors[1]++;
    }
    for (auto div: divisors){
        cnt_divs += div;
    }
    cnt_divs = cnt_divs % lnum;
    cout << cnt_divs << endl;
}