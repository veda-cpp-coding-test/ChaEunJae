// 백준 문제 : 큐 2

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	queue<int> qi;
	for(int i=0;i<N;i++){
		string command;
		cin >> command;
		if(command == "push"){
			int X;
			cin >> X;
			qi.push(X);
		} else if(command == "pop"){
			if(qi.empty()){
				cout << -1 << "\n";
			} else {
				cout << qi.front() << "\n";
				qi.pop();
			}
		} else if(command == "size"){
			cout << qi.size() << "\n";
		} else if(command == "empty"){
			cout << qi.empty() << "\n";
		} else if(command == "front"){
			if(qi.empty()){
				cout << -1 << "\n";
			} else {
				cout << qi.front() << "\n";
			}
		} else {
			if(qi.empty()){
				cout << -1 << "\n";
			} else {
				cout << qi.back() << "\n";
			}
		}
	}
}