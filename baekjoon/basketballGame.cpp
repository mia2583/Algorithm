// 1159번 농구경기 브론즈2
// https://www.acmicpc.net/problem/1159
// 11분

#include<bits/stdc++.h>
using namespace std;

int N;
string firstName;
vector<string> firstNames;
int firstLetter[26] = {0, };
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z'};

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> firstName;
        firstNames.push_back(firstName);
    }
}

void solve() {
    for(int j=0; j<N; j++) {
        firstLetter[firstNames[j][0]-'a']++;
    }
}

void output() {
    int countAnswer = 0;
    for(int k=0; k<26; k++) {
        if(firstLetter[k] > 4) {
            cout << alphabet[k];
            countAnswer++;
        }
    }
    if(countAnswer==0) cout << "PREDAJA";
    cout << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
