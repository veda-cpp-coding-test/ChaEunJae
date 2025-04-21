// 백준 문제 : 좋은 단어

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	int answer = 0;
	for(int i=0;i<N;i++){
		string word;
		cin >> word;
		
		stack<char> sc;
		for(const char& c:word){
			if(sc.empty()){
				sc.push(c);
			} else {
				if(sc.top() == c){
					sc.pop();
				} else {
					sc.push(c);
				}
			}
		}
		
		if(sc.empty()) answer++;
	}
	
	cout << answer;
} 