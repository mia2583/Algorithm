/*

- 백준 1932번 : 정수 삼각형 (실버)

- 문제 유형 : 다이나믹 프로그래밍

- 풀이 방법 도출 과정
1. 현재 층은 대각선 왼쪽 또는 대각선 오른쪽으로부터 도달할 수 있다.
2. 합이 최대가 되는 값을 구한다.
3. 매 층마다 각 위치에서 가질 수 있는 최대값을 구한다.

- 시간 복잡도
력과 각 위치에서의 계산을 1 + 2 + ... + n = n(n+1)/2 후, 마지막 층에서 최대값을 찾기 위해 for문을 한번 돈다.
O(n^2+2n) = O(n^2)

- 문제 풀이 핵심 설명
j가 i-1일 때와 else문일 때, answer[j]는 answer[j-1]에 영향을 받는다. 현재 층이 아니라 위의 층의 answer[j-1] 값을 사용하기 위해서 j의 값을 0부터 i-1까지가 아닌 i-1부터 0까지 거꾸로 값을 채운다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int triangle[500];
int answer[500] = {0, };
int biggest = 0;

int main() {
    cin >> n;

    for (int i=1; i<n+1; i++) {
        for (int j=0; j<i; j++) {
            cin >> triangle[j];
        }
        
        for (int j=i-1; j>=0; j--) {
            if (j==0) {
                answer[j] = answer[0] + triangle[0];
            } else if (j==i-1) {
                answer[j] = answer[j-1] + triangle[j];
            } else {
                answer[j] = max(answer[j-1], answer[j]) + triangle[j];
            }
        }
    }

    for (int i=0; i<n; i++) {
        biggest = max(biggest, answer[i]);
    }

    cout << biggest << endl;
}
