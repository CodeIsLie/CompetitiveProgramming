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

long long funny_level(int n, int k){
    long long cnt_members = n/k;
    long long last_member = (n+1-k);
    return (1 + last_member) * cnt_members / 2;
}

void task(){
    int n;
    cin >> n;

    set<long long> members;
    for (int i = 1; i*i <= n; ++i){
        if (n % i == 0){
            members.insert(funny_level(n, i));
            members.insert(funny_level(n, n/i));
        }
    }
    for (auto m: members){
        cout << m << " ";
    }
}