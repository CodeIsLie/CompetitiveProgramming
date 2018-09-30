#define FILE2 "comb"

#include <set>
#include <vector>
#include <iostream>
#include <string>
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

long long GSD(long long n1, long long n2){
    if (n2 == 0)
        return n1;
    return GSD(n2, n1 % n2);
}

long long cntCombinations(int n, int k){
    int k2 = n-k;
    k = max(k2, k);

    long long mul1 = 1, mul2 = 1;
    for (int i = k+1; i <= n; ++i){
        mul1 *= i;
        mul2 *= (i-k);
        long long gsd = GSD(mul1, mul2);
        mul1 /= gsd;
        mul2 /= gsd;
    }

    return mul1 / mul2;
}

void task(){
    int n, k;
    long long p;
    cin >> n >> k >> p;

    long long combs;
    int remain_n = n;
    int remain_k = k;
    while (p != 0) {
        combs = cntCombinations(remain_n-1, remain_k-1);
        while (p >= combs) {
            p -= combs;
            combs = cntCombinations(--remain_n-1, remain_k-1);
        }
        remain_n--;
        remain_k--;
        cout << n-remain_n << ' ';

        if (remain_k == 0)
            break;
    }

    for (int i = n-remain_n+1; i < n-remain_n+1+remain_k; ++i){
        cout << i << ' ';
    }
}