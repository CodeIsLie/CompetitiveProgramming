//
// Created by admin on 12.09.2018.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void brackets(){
    long long n, k;
    string impossible = "Impossible";
    string s;

    cin >> n >> k;

    if (n*(n-1)/2 < k){
        cout << impossible << endl;
        return;
    }

    long long sum = 0;
    int p = 0;
    for (int i = 0; i < 2*n; ++i){
        if (sum + p <= k) {
            s += "(";
            sum += p;
            p++;
        }
        else{
            s += ")";
            p--;
        }

    }
    if (p == 0)
        cout << s << endl;
    else
        cout << impossible << endl;
}

int main(){
    brackets();
    return 0;
}

