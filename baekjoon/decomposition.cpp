// 2231 ������ �����2
// https://www.acmicpc.net/problem/2231
// 13��

#include<bits/stdc++.h>
using namespace std;

int N, M, sum; // M�� ������

void input() {
    cin >> N; // N�� ������
}

void solve() {
    for(int n=0; n<N; n++) {
        sum = n + n%10;
        int m=n;
        while(m/10) { // m�� n�� �ڸ��� ���� ���� ����
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
