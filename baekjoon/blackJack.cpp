// 2798번 블랙잭 브론즈2
// https://www.acmicpc.net/problem/2798
// 15분 브루트포스

#include<bits/stdc++.h>
using namespace std;

int N, M, card, maxSum=0;
vector<int> cards;

void input() {
    cin >> N >> M; // N은 카드 개수, M은 목표 숫자
    for(int n=0; n<N; n++) {
        cin >> card;
        cards.push_back(card);
    }
}

void solve() {
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if(sum > M) continue;
                else {
                    if(sum > maxSum) maxSum = sum;
                }
            }
        }
    }
}

void output() {
    cout << maxSum << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}