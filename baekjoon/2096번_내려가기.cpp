/*

- 백준 2096번 : 내려가기 (골드5)

- 문제 유형 : 다이나믹 프로그래밍

- 풀이 방법 도출 과정
1. 아래로 내려가 얻을 수 있는 최소 점수와 최대 점수를 구해야 한다.
2. 내려갈 때 규칙이 정해져 있다.
3. 각 위치별로 가질 수 있는 최소 점수와 최대점수가 전 단계 각 위치에서의 점수와 이동에 따라 정해진다.

- 시간 복잡도
입력 받은 줄의 길이가 N일 때, O(N)

- 문제 풀이 핵심 설명
각 위치에서 얻을 수 있는 최소 점수와 최대 점수를 계산했다.
1. i번째 줄에서 j번 위치에서 얻을 수 있는 최소/최대 점수 = "(i-1)번 줄 j-1 혹은 j 혹은 j+1 위치의 점수 + i번째 j 위치 점수"의 최소/최대
    => 0번과 2번 위치는 -1번이나 3번 위치 접근이 불가능하므로 배열 범위를 넘어가지 않는 선에서 계산

*/

#include <iostream>

using namespace std;

int N;
int a, b, c;
int dp_max[3], pre_max[3];
int dp_min[3], pre_min[3];

int main() {
    cin >> N;
    cin >> a >> b >> c;
    dp_max[0]=a; dp_max[1]=b; dp_max[2]=c;
    dp_min[0]=a; dp_min[1]=b; dp_min[2]=c;
    
    for (int i=1; i<N; i++) {
        cin >> a >> b >> c;
        copy(begin(dp_max), end(dp_max), begin(pre_max));
        copy(begin(dp_min), end(dp_min), begin(pre_min));

        dp_max[0] = max(pre_max[0], pre_max[1]) + a;
        dp_max[1] = max(max(pre_max[0], pre_max[1]), pre_max[2]) + b;
        dp_max[2] = max(pre_max[1], pre_max[2]) + c;
        

        dp_min[0] = min(pre_min[0], pre_min[1]) + a;
        dp_min[1] = min(min(pre_min[0], pre_min[1]), pre_min[2]) + b;
        dp_min[2] = min(pre_min[1], pre_min[2]) + c;
    }

    int answer_max = max(max(dp_max[0], dp_max[1]), dp_max[2]);
    int answer_min = min(min(dp_min[0], dp_min[1]), dp_min[2]);

    cout << answer_max << " " << answer_min << endl;
    
    return 0;
}