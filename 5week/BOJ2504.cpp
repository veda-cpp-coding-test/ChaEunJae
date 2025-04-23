// 백준 문제 : 괄호의 값

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string bracket;
    cin >> bracket;

    int sum = 0; // 더할 값
    int cnt = 1; // 곱할 값

    stack<char> sc;
    for(int i=0;i<bracket.size();i++){
        if(bracket[i] == '('){
            sc.push('(');
            cnt *= 2;
        } else if(bracket[i] == '['){
            sc.push('[');
            cnt *= 3;
        } else if(bracket[i] == ')'){
            if(sc.empty() || sc.top() != '(') {
                cout << 0 << "\n";
                return 0;
            }

            if(bracket[i-1] == '(') sum += cnt;
            cnt /= 2;
            sc.pop();
        } else {
            if(sc.empty() || sc.top() != '[') {
                cout << 0 << "\n";
                return 0;
            }

            if(bracket[i-1] == '[') sum += cnt;
            cnt /= 3;
            sc.pop();
        }
    }

    if(!sc.empty()) cout << 0 << "\n";
    else cout << sum << "\n";
}

// 괄호가 열리면 변수 1에 곱하기 + stack push
// 괄호가 닫히면 변수 1에 나누기 + stack pop
// ()면 변수2에 변수1 더하기
// 그 전에 stack이 비었거나 top이 여는 괄호인지 검사 ->  맞다면 0 출력하고 종료
// 정답으로 변수 2 출력
// 제일 마지막 출력에서도 stack이 비었는지 체크

// 분배법칙으로 왼쪽부터 값을 먼저 계산한다 생각하면 됨