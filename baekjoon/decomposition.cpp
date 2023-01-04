// 2231 분해합 브론즈2
// https://www.acmicpc.net/problem/2231
// 13분

#include<bits/stdc++.h>
using namespace std;

int N, M, sum; // M은 생성자

void input() {
    cin >> N; // N은 분해합
}

void solve() {
    for(int n=0; n<N; n++) {
        sum = n + n%10;
        int m=n;
        while(m/10) { // m은 n의 자리수 합을 위한 변수
            m = m/10;
            sum += m%10;
        }
        if(sum==N) { M=n; break; }
    }
}

void output() {
    cout << M << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
