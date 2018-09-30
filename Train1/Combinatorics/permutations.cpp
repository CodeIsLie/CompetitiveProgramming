#define FILE2 "perm"

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

void printarr(vector<int>& arr){
    for (int i: arr){
        cout << i << ' ';
    }
    cout << endl;
}


void task(){
    int n;
    cin >> n;

    vector<int> numbers;
    numbers.resize(n);
    for (int i = 0; i < n; ++i){
        numbers[i] = i+1;
    }

    do {
        printarr(numbers);
    } while ( std::next_permutation(numbers.begin(),numbers.end()) );
}