// 1152번 단어의개수 브론즈2
// https://www.acmicpc.net/problem/1152
// 28분 + 5분

#include<bits/stdc++.h>
using namespace std;

string sentence;
int answer = 0;

void input() {
    getline(cin, sentence);
}

void solve() {
    int before=0;
    int now=0;
    for(char word: sentence) {
        if(word==' ') {
            if(before!=now) {
                answer++;
                before=now;
            }
        }
        now++;
    }
    if(now-before>1) answer++;
    else if(sentence.length()==1 && sentence!=" ") answer++;
}

void output() {
    cout << answer << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
