//
// Created by Ilya on 13.09.2018.
//


#include <iostream>
#include <vector>
#include <set>

using namespace std;

void testing(){
    int n;
    cin >> n;

    vector<int> queries;
    queries.assign(n, 0);
    int max = 0;
    int maxInd = 0;
    for (int i = 0; i < n; ++i){
        cin >> queries[i];
        if (queries[i] > max) {
            max = queries[i];
            maxInd = i;
        }
    }

    long long additionalSum = 0;
    int left = 0;
    int right = n-1;

    while (right - left > 0) {
        for (int i = left + 1; i <= maxInd; ++i) {
            left = i;
            if (queries[i - 1] >= queries[i]) {
                additionalSum += queries[i - 1] - queries[i] + 1;
                queries[i] = queries[i - 1] + 1;
            }
            if (queries[i] > max) {
                max = queries[i];
                maxInd = i;
                break;
            }
        }

        for (int i = right - 1; i >= maxInd; --i) {
            right = i;
            if (queries[i + 1] >= queries[i]) {
                additionalSum += queries[i + 1] - queries[i] + 1;
                queries[i] = queries[i + 1] + 1;
            }
            if (queries[i] > max) {
                max = queries[i];
                maxInd = i;
                break;
            }
        }
        if (right - left == 2){
            if (queries[left] < queries[left+1] && queries[right-1] > queries[right])
                break;
        }else if (right - left == 1){
            if (queries[left] < queries[left+1] || queries[right-1] > queries[right])
                break;
        }
    }

    cout << additionalSum;
}

int main(){
    testing();
    return 0;
}

