// 1436�� ��ȭ���� �� �ǹ�5
// https://www.acmicpc.net/problem/1436
// �ð� �ʰ�
#include<bits/stdc++.h>
using namespace std;

int N;
int number = 6659;

void input() {
    cin >> N; // N��° ��ȭ
}

void solve() {
    if(N < 7) number = (N-1)*1000 + 666;
    else {
        int n=6;
        while(n<N) {
            number+=1;
            if(to_string(number).find("666")!=string::npos) n++;
        }
    }
}

void output() {
    cout << number << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}

/*
 �Ʒ��� ó���� �ۼ��ߴ� solve() �Լ�
 �ʹ� �����ϰ� �ۼ���.�Դٰ� ������ �ִ� �ڵ�.
 ���� �Է��̾��� 500�� ��� ���� �߸���.
 ���߿� ���� �ذ��� ����!
*/

/*int findLength(int decimal) {
    int d=0;
    do {
        d++;
        decimal/=10;
    } while(decimal);
    return d;
}

bool contain666(int decimal) {
    int d = findLength(decimal);
    for(int i=0; i<d-3; i++) {
        if((decimal/(10*(d-i-3))%1000) == 666) return true;
    }
    if(decimal%1000 == 666) return true;
    return false;
}

void solve() {
    if(N < 7) number = (N-1)*1000 + 666;
    else {
        int n=6;
        while(n<N) {
            number+=1;
            if(contain666(number)) n++;
        }
    }
}*/
