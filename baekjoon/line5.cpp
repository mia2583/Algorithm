// 11931번 수정렬하기 실버5
// https://www.acmicpc.net/problem/11931
// 17분
#include<bits/stdc++.h>
using namespace std;

int N, number;
vector<int>line;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> number;
        line.push_back(number);
    }
}

void solve() {
    while(N--) {
        int j=0;
        while(true) {
            if(j+1>N) break;
            if(line[j]<line[j+1]) swap(line[j], line[j+1]);
            j++;
        }
    }
}

void output() {
    for(int n: line) {
        cout << n << endl;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
