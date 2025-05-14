// 백준 문제 : 암호 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char password[15];
char arr[15];
int L,C;
vector<string> answers;

void p(vector<bool> isUsed, int count){
	// cout << "=======" << count << "=======\n";
	if(count == L){
		string str;
		for(int i=0;i<L;i++){
			str += password[i];
		}
		answers.push_back(str);
		return;
	}
	
	for(int i=0;i<C;i++){
		if(isUsed[i] == false){
			/*
			for(int j=0;j<count;j++){
				cout << password[j];
			}
			cout << "\n";
			*/
			if(count > 0 && password[count-1] < arr[i]){
				password[count] = arr[i];
				isUsed[i] = true;
				p(isUsed,count+1);
				isUsed[i] = false;
			} else if(count == 0){
				password[count] = arr[i];
				isUsed[i] = true;
				p(isUsed,count+1);
				isUsed[i] = false;
			}
		}
	}
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
	
	cin >> L >> C;
	
	for(int i=0;i<C;i++){
		cin >> arr[i];
	}
	
	vector<bool> isUsed(C,false);
	
	p(isUsed,0);
	
	stable_sort(answers.begin(),answers.end());
	vector<char> vowels = {'a','e','i','o','u'};
	for(auto str:answers){
		int count = 0;
		for(auto v:vowels){
			if(find(str.begin(),str.end(),v) != str.end()){
				count++;
			}
		}
		if(count >= 1 && L-count >= 2){
			cout << str << "\n";
		}
	}
	return 0;
}