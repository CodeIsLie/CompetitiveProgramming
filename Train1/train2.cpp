//
// Created by Ilya on 02.09.2018.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void invertNumbers(){
    long long a;
    cin >> a;

    long long tenDegree = 1;
    long long b = 0;
    while (a > 9){
        int c = a % 10;
        if (9 - c < c)
            c = 9 - c;
        b = c * tenDegree + b;
        tenDegree *= 10;
        a /= 10;
    }
    if (a != 9){
        if (9 - a < a)
            a = 9 - a;
    }
    b = a * tenDegree + b;

    cout << b << endl;
}

void businessTrip(){
    int k;
    vector<int> grow(12, 0);

    cin >> k;
    for (int i = 0; i < 12; ++i){
        cin >> grow[i];
    }

    sort(grow.rbegin(), grow.rend());

    int cntMonths = 0;
    int growSize = 0;
    for (int i = 0; i < grow.size(); ++i){
        if (growSize >= k)
            break;
        cntMonths++;
        growSize += grow[i];
    }

    if (growSize < k){
        cntMonths = -1;
    }

    cout << cntMonths;
}

void cinema(){
    int n;
    cin >> n;

    vector<int> nominals(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> nominals[i];


    string answer = "YES";
    int cnt25 = 0;
    int cnt50 = 0;
    for (int nom: nominals){
        if (nom == 25){
            cnt25 += 1;
        }else if(nom == 50){
            if (cnt25 < 1){
                answer = "NO";
                break;
            }
            else{
                cnt25 -= 1;
                cnt50 += 1;
            }
        }else if (nom == 100){
            if (cnt50 > 0){
                cnt50 -= 1;
                if (cnt25 > 0)
                    cnt25 -= 1;
                else {
                    answer = "NO";
                    break;
                }
            }
            else{
                if (cnt25 >= 3){
                    cnt25 -= 3;
                }
                else {
                    answer = "NO";
                    break;
                }
            }
        }
    }
    cout << answer;
}

void triples(){
    int n;
    cin >> n;

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int cnt4 = 0;
    int cnt6 = 0;
    int cnt57 = 0;
    vector<int> numbers(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        switch (numbers[i]){
            case 1:
                cnt1 ++;
                break;
            case 2:
                cnt2++;
                break;
            case 3:
                cnt3++;
                break;
            case 4:
                cnt4++;
                break;
            case 6:
                cnt6++;
                break;
            default:
                cnt57++;
        }
    }

    if (cnt57 > 0){
        cout << -1;
        return;
    }
    if (cnt1 != n/3 || (cnt2 + cnt3) != n/3 || cnt6 < cnt3){
        cout << -1;
        return;
    }

    for (int i = 0; i < cnt3; ++i){
        cout << "1 3 6 ";
    }
    cnt6 -= cnt3;
    for (int i = 0; i < cnt6; ++i){
        cout << "1 2 6 ";
    }
    for (int i = 0; i < cnt4; ++i){
        cout << "1 2 4 ";
    }
}

void pigsWolves(){
    int n, m;
    cin >> n >> m;

    int wolvesWithPig = 0;
    vector<string> grid(n+2, string(m+2, '.'));
    string s;
    getline(cin, s);

    for (int i = 1; i < n+1; ++i){
        getline(cin, s);
        grid[i] = "." + s + ".";
    }

    char cLeft, cRight, cTop, cBot;
    for (int i = 1; i < n+1; ++i){
        for (int j = 1; j < m+1; ++j){
            char c = grid[i][j];

            cTop = grid[i+1][j];
            cBot = grid[i-1][j];
            cLeft = grid[i][j-1];
            cRight = grid[i][j+1];

            if (c == 'W'){
                if (cTop == 'P' || cBot == 'P' || cLeft == 'P' || cRight == 'P'){
                    wolvesWithPig += 1;
                }
            }
        }
    }

    cout << wolvesWithPig;
}


int main() {
    pigsWolves();
    return 0;
}