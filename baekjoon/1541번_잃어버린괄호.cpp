/*

- 백준 1541번 : 잃어버린 괄호 (실버2)

- 문제 유형 : 그리디

- 풀이 방법 도출 과정
1. 합이 최소여야하는데 나오는 연산자가 +랑 -밖에 없다. 
2. -는 괄호를 통해 뒤에 나오는 숫자를 원하는만큼 음수로 만들 수 있다.
3. - 뒤로 모든 숫자를 음수로 만들면 합이 최소가 된다.

- 시간 복잡도
입력된 식 크기만큼 for문을 수행하므로 식의 길이를 n(n<50)이라 하면 O(n)

- 문제 풀이 핵심 설명
처음으로 빼기가 나오면 is_minus를 true로 활성화 후 다음 피연산자부터는 덧셈이 아닌 뺄셈으로 계산한다.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operand;
string expression, number;
bool is_minus = false;
int location = 0;
int answer = 0;

int main()
{
    cin >> expression;
    
    for(char s: expression) {
        if (s=='+' || s=='-') {
            if(is_minus) {
                answer -= stoi(number);
            } else {
                answer += stoi(number);
            }
            number = "";
        } else {
            number += s;
        }
        
        if (s=='-' && !is_minus) {
            is_minus = true;
        }
    }
    
    
    if(is_minus) {
        answer -= stoi(number);
    } else {
        answer += stoi(number);
    }
    
    cout << answer << endl;

    return 0;
}