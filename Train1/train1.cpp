#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void sumAB(){
    char inFile[] = "sum.in";
    ifstream ifs(inFile);

    int a, b;
    ifs >> a >> b;

    char outFile[] = "sum.out";
    ofstream ofs(outFile);
    ofs << a + b << endl;
}

void productAB(){
    string inFile = "product.in";
    ifstream ifs(inFile);

    long long a, b;
    ifs >> a >> b;

    string outFile = "product.out";
    ofstream ofs(outFile);
    ofs << a * b << endl;
}

void sumViceVersa(){
    string inFile = "apbtest.in";
    ifstream ifs(inFile);

    long long c;
    ifs >> c;

    string outFile = "apbtest.out";
    ofstream ofs(outFile);
    long long a, b;
    a = c / 2;
    b = c / 2 + (c % 2);
    ofs << a << ' ' << b << endl;
}

long long gcd(long long a, long long b){
    if (a == 0 && b == 0)
    {
        return 1;
    }

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void GCD(){
    string inFile = "gcd.in";
    ifstream ifs(inFile);

    long long a, b;
    ifs >> a >> b;
    if (b > a){
        long long t = b;
        b = a;
        a = t;
    }

    string outFile = "gcd.out";
    ofstream ofs(outFile);
    long long d = gcd(a, b);
    ofs << d << endl;
}

long long fib(long long a, long long b, int n){
    if (n == 0)
        return a;
    return fib(a + b, a, n-1);
}

void fib(){
    string inFile = "fib.in";
    ifstream ifs(inFile);

    int n;
    ifs >> n;

    long long fibNumber;
    if (n < 2){
        fibNumber = 1;
    }
    else{
        fibNumber = fib(1, 1, n-1);
    }

    string outFile = "fib.out";
    ofstream ofs(outFile);
    ofs << fibNumber << endl;
}

void skateboard(){
    string inFile = "skateboard.in";
    ifstream ifs(inFile);

    int n;
    ifs >> n;
    vector<int> coordinates(n, 0);
    for (int i = 0; i < n; ++i){
        ifs >> coordinates[i];
    }

    int knollCnt = 0;
    for (int i = 1; i < n - 1; ++i){
        if (coordinates[i] > coordinates[i-1] && coordinates[i] > coordinates[i+1]){
            knollCnt++;
        }
    }

    string outFile = "skateboard.out";
    ofstream ofs(outFile);
    ofs << knollCnt << endl;
}

void numbers(){
    string inFile = "numbers.in";
    ifstream ifs(inFile);

    long long a, b;
    ifs >> a >> b;
//    int d = gcd(a, b);
//    a /= d;
//    b /= d;

    int u = 0, v = 0;
    for (int i = -1000; i < 1001; ++i){
        for (int j = -1000; j < 10001; ++j){
            if (a*i + b*j == 1){
                u = i;
                v = j;
                break;
            }
        }
    }

    string outFile = "numbers.out";
    ofstream ofs(outFile);
    ofs << u << ' ' << v << endl;
}

void symposium(){
    string inFile = "symposium.in";
    ifstream ifs(inFile);

    int n;
    ifs >> n;
    vector<int> values(n, 0);
    for (int i = 0; i < n; ++i){
        ifs >> values[i];
    }
    ifs.close();
    sort(values.begin(), values.end());

    int bagCnt = 0;
    int prevGap = 0;
    for (int i = 1; i < n; ++i){
        if (values[i] >= 2 * values[i-1]){
            int currentBagCnt = i - prevGap;
            if (currentBagCnt > bagCnt)
                bagCnt = currentBagCnt;
            prevGap = i;
        }
    }

    if (n - prevGap > bagCnt)
        bagCnt = n- prevGap;

    string outFile = "symposium.out";
    ofstream ofs(outFile);
    ofs << bagCnt << endl;
    ofs.close();
}


int main1() {
    symposium();
    return 0;
}