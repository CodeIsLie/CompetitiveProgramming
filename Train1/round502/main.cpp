#define TEAM

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
    int t;
    scanf("%d", &t);
    while (t--)
        task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

void task(){
    int n;
    scanf("%d", &n);

    long long sum = 0;
    int a;
    for (int i = 0; i < n; ++i){
        scanf("%d", &a);
        sum = (sum + a*(1+sum) ) % (1000000000+7);
    }

    printf("%lld\n", sum);
}
