// 백준 문제 : 덱

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    deque<int> di;
    for(int i=0;i<N;i++){
        string command;
        cin >> command;
        if(command == "push_front"){
            int X;
            cin >> X;
            di.push_front(X);
        } else if(command == "push_back"){
            int X;
            cin >> X;
            di.push_back(X);
        } else if(command == "pop_front"){
            if(di.empty()) cout << -1 << "\n";
            else {
                cout << di.front() << "\n";
                di.pop_front();
            }
        } else if(command == "pop_back"){
            if(di.empty()) cout << -1 << "\n";
            else {
                cout << di.back() << "\n";
                di.pop_back();
            }
        } else if(command == "size"){
            cout << di.size() << "\n";
        } else if(command == "empty"){
            cout << di.empty() << "\n";
        } else if(command == "front"){
            if(di.empty()) cout << -1 << "\n";
            else {
                cout << di.front() << "\n";
            }
        } else {
            if(di.empty()) cout << -1 << "\n";
            else {
                cout << di.back() << "\n";
            }
        }
    }
}