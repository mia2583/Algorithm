/*

- 백준 1149번 : RGB 거리 (실버 1)

- 문제 유형 : 다이나믹 프로그래밍

- 풀이 방법 도출 과정
1. 각 집의 비용이 매번 규칙없이 다르니 처음에는 브루투포스(dfs, bfs)쪽을 생각하였다.
2. 하지만 시간과 N의 값을 고려했을 때, 시간 초과가 의심되어 다른 방법을 모색하였다.
3. i번째 집 색은 i-1과 i+1 번째 집 색과는 달라야 하므로 현재 색을 고를 때, 이전에 선택하지 않은 색 중에 선택한다.
4. 현재 집을 각 색으로 칠할 때 이전 비용들 중 최소값(동일 색 제외)을 고르는 방식으로 진행하였다.

- 시간 복잡도
N 번만큼 각각 최솟값을 구하므로 O(N)

- 문제 풀이 핵심 설명
현재 각 색의 최소비용을 저장하기 위해서 dp 배열을 사용하였다. 그리고 dp배열 값이 모든 계산 전에 덮어써지는 것을 주의하여 새로운 변수들을 사용하였다.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int dp[3] = {0, 0, 0};
int N, red, green, blue;
int red_min, green_min, blue_min;
int answer = 0;

int main() {
    cin >> N; // 집 수
    cin >> dp[0] >> dp[1] >> dp[2];
    for (int i=1; i<N; i++) {
        cin >> red >> green >> blue; // 각 가격

        red_min = red + min(dp[1], dp[2]);
        green_min = green + min(dp[0], dp[2]);
        blue_min = blue + min(dp[0], dp[1]);

        dp[0] = red_min;
        dp[1] = green_min;
        dp[2] = blue_min;
    }

    answer = min(min(dp[0], dp[1]), dp[2]);

    cout << answer << endl;

    return 0;
}
