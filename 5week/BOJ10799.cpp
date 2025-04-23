// 백준 문제 : 쇠막대기

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	string batch;
	cin >> batch;
	
	stack<int> si;
	int answer = 0;
	int cnt = 0; // stack의 사이즈 보관
	for(int i=0;i<batch.size();i++){
		if(batch[i]=='(' && i+1 < batch.size() && batch[i+1]==')'){ // ()가 붙어있는 경우
			answer += cnt;
			i++;
		} else if(batch[i] == '('){
			si.push(cnt);
			cnt++;
		} else {
			si.pop();
			cnt--;
			answer++;
		}
	}
	cout << answer << "\n";
}

// (가 열리면 stack.push
// )가 닫히면 stack.pop하고 answer += 1
// ()가 붙어있으면 answer += stack.size()