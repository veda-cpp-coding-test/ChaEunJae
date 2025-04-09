// 백준 문제 : 키로거

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int T;
	cin >> T;
	
	vector<string> answers;
	for(int i=0;i<T;i++){
		string str;
		cin >> str;
		
		list<char> ll;
		list<char>::iterator it = ll.begin();
		for(auto j:str){
			
			/*
			for(auto z:ll){
				 cout << z;
			}
			cout << "\n";
			*/
			
			switch(j){
				case '<':
					if(it != ll.begin()) it--;
					break;
				case '>':
					if(it != ll.end()) it++;
					break;
				case '-':
					if(it != ll.begin()){
						it--;
						it = ll.erase(it);
					}
					break;
				default:
					ll.insert(it,j);
					break;
			}
		}
		
		string s = "";
		for(auto j:ll){
			s += j;
		}
		answers.push_back(s);
	}
	
	for(auto i:answers){
		cout << i << "\n";
	}
}