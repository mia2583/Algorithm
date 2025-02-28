/*

- 백준 6064번 : 카잉달력 (골드5)

- 문제 유형 : 수학

- 풀이 방법 도출 과정
1. 일정한 규칙에 따라 년도가 표기됩니다.
2. 예를 들어, M=10인 경우에는 1 -> 11 -> 21 -> 31 ... 일때 1의 값을 가집니다.
3. x + M, x+2M, x+ 3M, ..., x + mM 일 때 x로 표기된다. 마찬가지로 y + nN 일 때 y로 표기됩니다.
4. 따라서 x + mM = y + nN이 될 때 <x:y>로 표기됩니다.

- 시간 복잡도
입력을 k번만큼 받고, 최소공배수가 최대 M*N을 가질 수 있므로 내부 for문을 최악의 경우엔 N번 수행하므로 O(kN) (최소공배수 계산시간 고려x)

- 문제 풀이 핵심 설명
1. M과 N의 최소공배수는 <M, N>으로 표기되는 마지막 해를 의미합니다. 따라서 가능한 M과 N의 값의 범위를 제한할 수 있습니다.
2. j의 값을 x -> x+M -> x+2M ... 으로 증가시키면서 최소공배수가 될때까지 탐색을 합니다. j = x + mM = y + nN인 값을 찾고 있으므로 j - y = nN 즉, (j-y)를 N으로 나눴을 때 나머지가 0이어야 합니다. 

*/

#include <iostream>

using namespace std;

int k, M, N, x, y;

int gcd(int a, int b){ // 최대 공약수
    if(b==0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b){ // 최소 공배수
    return (a * b) / gcd(a, b);
}

int main() {
    cin >> k;
    
    for (int i=0; i<k; i++) {
        int answer = -1;
        cin >> M >> N >> x >> y;

        int mn_lcm = lcm(M, N);

        for (int j=x; j<=mn_lcm; j+=M) {
            if ((j-y)%N == 0) {
                answer = j;
                break;
            }
        }
        cout << answer << endl;;
    }
    
    return 0;
}