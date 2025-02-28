/*

- 백준 11047번 : 동전 0 (실버4)

- 문제 유형 : 그리디

- 풀이 방법 도출 과정
1. 최소 동전의 개수를 찾는거라 큰 값을 가진 동전부터 가능한만큼 채운다.
2. 가치가 적은 동전부터 입력되므로 stack으로 입력을 받는다.
3. 목표 값을 동전의 값으로 나눈 개수만큼 동전을 가지고, 나머지를 다시 다른 가치의 동전으로 채운다.
   예) K 값은 value 값어치의 동전을 (K/value)개로 구성하고 남은 (K%value)은 더 작은 값의 동전으로 채운다.

- 시간 복잡도
N 크기만큼 for문으로 돌고 while문에서도 최대 N만큼 회전하므로, 시간 복잡도는 O(N)

- 문제 풀이 핵심 설명
값이 K보다 작으면서 가장 큰 가치의 동전부터 가능한만큼 채운다.

*/

#include <iostream>
#include <stack>

using namespace std;

stack<int> values;
int N, K, value;
int answer = 0;

int main() {
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> value;
        values.push(value);
    }
    
    int j=0;
    while(K!=0) {
        if(values.top() > K) {
            values.pop();
        } else {
            answer += K/values.top();
            K = K%values.top();
            values.pop();
        }
    }
    
    cout << answer << endl;
    return 0;
}
