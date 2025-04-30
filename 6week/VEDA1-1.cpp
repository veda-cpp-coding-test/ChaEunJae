// 한화비전 베다 레벨 테스트 1-1 문제 (테케 3개만 통과, 검증 필요)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arrSize;
	cin >> arrSize;
	vector<long> arr;
	vector<long> A;
	for(int i=0;i<arrSize;i++){
		long e;
		cin >> e;
		arr.push_back(e);
		A.push_back(0);
	}
	
	int answer = 0;
	long maxE = *max_element(arr.begin(),arr.end());
	long minE = *min_element(arr.begin(),arr.end());
	while(maxE >= minE){
		// cout << minE << ":" << answer << "\n";
		
		// 비교부분
		bool isBigger = false;
		for(int i=0;i<arrSize;i++){
			if(arr[i] >= minE && A[i] < arr[i]){
				isBigger = true;
				A[i] = minE;

			} else {
				if(isBigger == true){
					// cout << i << "에서 카운트\n";
					answer++;
					isBigger = false;
					
					// 중간에 끊겼을 때 최소값 갱신 부분
					long beforeMinE = minE;
					minE = 100000000;
					bool isOk = false;
					for(int j=i+1;j<arrSize;j++){	
						while(arr[j] > beforeMinE){
							if(minE > arr[j]) minE = arr[j];
							isOk = true;
							j++;
						}
						if(isOk == true) {
							// cout << minE << ":" << answer << "\n";
							break;
						}
					}
					if(minE == 100000000) minE = beforeMinE;
					// i+1 원소부터 원래 minE보다 크면서 제일 작은값 저장
					// minE보다 작거나 같은 원소를 만나며 반복 종료
				}
			}
		}
		if(isBigger == true){
			// cout << arrSize<< "에서 카운트\n";
			answer++;
		}
		
		/*
		for(auto ae:A){
			cout << ae << " ";
		}
		cout << "\n";
		*/
		
		// 최소값 갱신부분
		long beforeMinE = minE;
		minE = 100000000;
		for(int s=0;s<arrSize;s++){
			if(beforeMinE >= arr[s]) continue;
			if(minE > arr[s]) minE = arr[s];
		}
	}

	cout << answer << "\n";
}

// ex : [1, 2 ,6 , 5 , 8 , 8 ,4 , 1], answer : 6

// - 반복
// arr[i] 원소가 최소 원소보다 크거나 같으면 && A[i]가 arr[i]보다 작으면 isBigger = true;와 A에 값 누적
// arr[i] 원소가 최소 원소보다 작으면 -> isBigger = true면 answer++, isBigger = false 
// 위 반복 중에 끊기면 minE보다 큰 것 중에 제일 작은 것으로 최소값 갱신해서 반복 계속하기 (j 반복자 이용)
// A 배열에 계속 누적하기

// 순회 반복이 끝나면 최소값 갱신


