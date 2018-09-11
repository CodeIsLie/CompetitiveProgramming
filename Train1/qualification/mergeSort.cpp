//
// Created by admin on 12.09.2018.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void mergeSort(){
    int n;
    cin >> n;
    vector<int> numbers;
    numbers.assign(n, 0);
    for (int i = 0; i < n; ++i){
        cin >> numbers[i];
    }

    vector<vector<int>> seqs;
    set<pair<int, int>> maxNumbers;
    maxNumbers.emplace(-numbers[0], 0);
    seqs.push_back(vector<int>(1, numbers[0]));
    int k = 0;
    for (int i = 1; i < numbers.size(); ++i){
        auto it = maxNumbers.lower_bound(make_pair(-numbers[i], k));
        if (it == maxNumbers.end()){
            k++;
            maxNumbers.emplace(-numbers[i], k);
            seqs.push_back(vector<int>(1, numbers[i]));
        }
        else{
            auto p = *it;
            maxNumbers.erase(it);
            maxNumbers.emplace(-numbers[i], p.second);
            seqs[p.second].push_back(numbers[i]);
        }
    }

    for (auto& s: seqs){
        for (int i: s){
            cout << i << ' ';
        }
        cout << endl;
    }

}

int main(){
    mergeSort();
    return 0;
}

