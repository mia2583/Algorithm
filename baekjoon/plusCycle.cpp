// 1110번 더하기사이클 브론즈1
// https://www.acmicpc.net/problem/1110
// 9분

#include<bits/stdc++.h>
using namespace std;

int n, number;
int tens, units, add;
int answer=0;

void input() {
    cin >> n;
}

void solve() {
    number=n;

    while(true) {
        answer++;
        tens = number/10;
        units = number%10;

        add = tens + units;

        number = units*10 + add%10;
        if(number==n) break;
    }

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
