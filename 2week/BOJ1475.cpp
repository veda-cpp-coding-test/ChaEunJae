// 백준 문제 : 방 번호

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> extractNumVec(int num){ // int 숫자의 각 자릿수를 추출해서 벡터를 반환하는 함수
	int divideNum = 1000000; // INT_MAX = 20억 언저리로, 10억이 자릿수를 나눌 수 있는 최대값, 문제 입력 범위에 따라 조절
	while(divideNum > num){
		divideNum /= 10;
	}
	
	vector<int> result;
	while(divideNum != 0){
		int e = num / divideNum;
		result.push_back(e);
		
		num %= divideNum;
		divideNum /= 10;
	}
	return result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	vector<int> numVec = extractNumVec(N); // 각 자릿수 보관
	vector<int> num(10,0); // 각 자릿수의 빈도 보관
	for(auto i:numVec){
		num[i] += 1;
	}
	num[6] += num[9];
	num[9] = 0;
	num[6] = num[6]/2 + num[6]%2; // 6과 9를 합치고, 2개씩을 한 세트로 처리
	/*
	for(auto i:num){
		cout << i << " ";
	}
	cout << "\n";
	*/
	
	cout << *max_element(num.begin(),num.end()) << "\n"; // index는 max_element(num.begin(),num.end())-num.begin()으로 구할 수 있음
}