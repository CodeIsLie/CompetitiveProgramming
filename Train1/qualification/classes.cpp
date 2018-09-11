//
// Created by admin on 12.09.2018.
//
#include <list>
#include <iostream>
#include <vector>

using namespace std;

void classes(){
    int n;
    cin >> n;
    string s;
    vector<int> countClasses(7, 0);
    for (int i = 0; i < n; ++i){
        cin >> s;
        for (int j = 0; j < 7; ++j){
            if (s[j] == '1')
                countClasses[j] ++;
        }
    }

    int max = 0;
    for (int i = 0; i < 7; i++)
        if (countClasses[i] > max)
            max = countClasses[i];

    cout << max << endl;
}

int main(){
    classes();
    return 0;
}