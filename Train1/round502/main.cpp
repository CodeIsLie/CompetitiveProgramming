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

    long long prime = 998244353;

    vector<long long> factorial(n);
    vector<long long> rev_factorial(n);
    long long sum = 0;

    factorial[0] = 1;
    rev_factorial[0] = n;
    for (int i = 2; i <= n; ++i){
        factorial[i-1] = (factorial[i-2] * i) % prime;
        rev_factorial[i-1] = (rev_factorial[i-2] * (n - i + 1)) % prime;
    }

    sum = factorial[n-1];
    for (int i = 1; i < n-1; ++i){
        long long addition = (factorial[n-1-i] - 1) * rev_factorial[i-1] % prime;
        sum = (sum + addition) % prime;
    }

    cout << sum << endl;
}