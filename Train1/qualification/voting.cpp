//
// Created by admin on 12.09.2018.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void voting(){
    int n, k;
    int a, m;
    cin >> n >> k;
    cin >> a >> m;

    vector<pair<int, int>> votes(n+1);
    for (int i = 1; i <= n; ++i){
        votes[i].second = i;
    }

    int vote;
    for (int i = 0; i < a; ++i) {
        cin >> vote;
        votes[vote].first++;
    }
    vector<int> answers(n+1);

    // always pass - 1
    // if can pass - 2
    // always cannot pass - 3
    // first, check 1, if not 1 -> check 2, if not 2 -> 3

    for (int i = 1; i <= n; ++i){
        cout << answers[i] << ' ';
    }
}

int main(){
    voting();
    return 0;
}