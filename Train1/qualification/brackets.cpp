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

    int sum = 0;
    int p = 0;
    int cntBrackets = 0;
    for (int i = 0; i < 2*n; ++i){
        if (sum == k && p==0)
            break;
        if (sum + p <= k) {
            s += "(";
            sum += p;
            p++;
        }
        else{
            s += ")";
            p--;
        }
        cntBrackets++;
    }
    for (int i = 0; i < n-cntBrackets; ++i){
        s+= "()";
    }

    cout << s << endl;
}

int main(){
    brackets();
    return 0;
}

