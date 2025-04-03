// 백준 문제 : 두 수의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int num[n];
	for(int i=0;i<n;i++){
		cin >> num[i];
	}
	
	int x;
	cin >> x;
	
	sort(num,num+n); // 이진탐색을 위한 정렬
	vector<int> minusNum; // x와의 차를 담을 벡터
	for(int i=0;i<n;i++){ 
		minusNum.push_back(x-num[i]);
	}
	
	int cnt = 0;
	for(auto i:minusNum){
		if(binary_search(num,num+n,i)) cnt += 1; // x와의 차를 정렬해놓은 배열에서 이진탐색으로 찾기
	}
	cout << cnt/2 << "\n"; // 쌍이 2번 카운트됐으므로 나누기 2
	
	/*
	for(int i=0;i<n-1;i++){ // 2중 for문 풀이 (시간초과)
		int ai = num[i];
		for(int j=i+1;j<n;j++){
			int aj = num[j];
			if(x==(ai+aj)) cnt += 1;
		}
	}
	cout << cnt << "\n";
	*/
}
