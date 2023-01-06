// 1436번 영화감독 숌 실버5
// https://www.acmicpc.net/problem/1436
// 시간 초과
#include<bits/stdc++.h>
using namespace std;

int N;
int number = 6659;

void input() {
    cin >> N; // N번째 영화
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
 아래는 처음에 작성했던 solve() 함수
 너무 복잡하게 작성함.게다가 오류가 있는 코드.
 예제 입력이었던 500의 결과 값이 잘못됨.
 나중에 오류 해결해 볼것!
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
