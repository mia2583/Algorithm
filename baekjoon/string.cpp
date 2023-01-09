// 1120번 문자열 실버4
// https://www.acmicpc.net/problem/1120
// 29분
#include<bits/stdc++.h>
using namespace std;

string A, B;
int answer;

void input() {
    cin >> A >> B; //A, B는 각각 문자열
}

// B의 j번째 문자열부터 A와 비교하여
// 차이점 계산하기
int findDifference(int j) {
    int diff = 0;
    for(int i=0; i<A.length(); i++) {
        if(A[i]!=B[j+i]) diff+=1;
    }
    return diff;
}

void solve() {
    // 두 문자열의 길이가 같으면 한번만 비교
    if(A.length() == B.length()) answer = findDifference(0);
    else {
        int leastDiff = A.length();
        // 두 문자열의 길이가 다르면
        // 모든 A길이만큼의 B문자열을 A와 비교
        for(int j=0; j<B.length()-A.length()+1; j++) {
            int diff = findDifference(j);
            if(diff < leastDiff) leastDiff = diff;
        }
        // 그 중에서 최소인 것 찾기
        answer = leastDiff;
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
