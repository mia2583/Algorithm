// 2798�� ���� �����2
// https://www.acmicpc.net/problem/2798
// 15�� ���Ʈ����

#include<bits/stdc++.h>
using namespace std;

int N, M, card, maxSum=0;
vector<int> cards;

void input() {
    cin >> N >> M; // N�� ī�� ����, M�� ��ǥ ����
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