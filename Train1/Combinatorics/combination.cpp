#define FILE2 "choose"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>
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

list<int> prev_numbers;

void combination(vector<int>& numbers, int l, int k){
    if (k == 0) {
        for (int i: prev_numbers){
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = l; i < numbers.size()-k+1; ++i){
        prev_numbers.push_back(numbers[i]);
        combination(numbers, i+1, k-1);
        prev_numbers.pop_back();
    }
}

void task(){
    int n, k;
    cin >> n >> k;

    vector<int> numbers;
    numbers.resize(n);
    for (int i = 0; i < n; ++i){
        numbers[i] = i+1;
    }

    for (int i = 0; i < n-k+1; ++i){
        prev_numbers = list<int>(1, i+1);
        combination(numbers, i+1, k-1);
    }
}