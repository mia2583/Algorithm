// 1157번 단어공부 브론즈1
// https://www.acmicpc.net/problem/1157
// 24분

#include<bits/stdc++.h>
using namespace std;

string word;
int words[26] = {0, };
char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int answer=0, maxN=0;

void input() {
    cin >> word;
}

void solve() {
    for(char character : word) {
        //cout << character - 'A' << endl;
        if(character-'A'>26) {
            words[character-'a']++;
        } else {
            words[character-'A']++;
        }
    }
    for(int i=0; i<26; i++) {
        if(words[i]>maxN) {
            maxN=words[i];
            answer=i;
        }
    }
}

void output() {
    int countMax=0;
    for(int j=0; j<26; j++) {
        if(words[j]==maxN) {
            countMax++;
        }
    }
    if(countMax>1) cout << "?" << endl;
    else cout << alphabet[answer] << endl;

}

int main() {
    input();
    solve();
    output();
    return 0;
}
