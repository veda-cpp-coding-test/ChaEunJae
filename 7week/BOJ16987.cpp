// 백준 문제 : 계란으로 계란치기

#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int N;

void crashEgg(vector<pair<int,int>> eggs,int cur, int sum){ // egg 배열, 현재 든 계란 위치, 깨진 계란 수
	if(cur == N) { // 가장 오른쪽에 위치할 계란일 경우 계란치기 종료
		if(answer < sum) answer = sum;
		return;
	}
	if(eggs[cur].first <= 0){ // 든 계란이 깨져있을 경우 오른쪽 계란으로 이동
		crashEgg(eggs,cur+1,sum);
		return;
	}
	
	// 계란치기
	bool noCrashEgg = true;
	for(int nxt=0;nxt<N;nxt++){		
		if(eggs[nxt].first > 0 && nxt != cur){
			//cout << "crash : " << cur << " "<<nxt << "\n";
			
			noCrashEgg = false;
			eggs[cur].first -= eggs[nxt].second;
			eggs[nxt].first -= eggs[cur].second;
			if(eggs[cur].first <= 0) {
				//cout << "sum++\n";
				sum++;
			}
			if(eggs[nxt].first <= 0) {
				//cout << "sum++\n";
				sum++;
			}
			
			crashEgg(eggs,cur+1,sum);
			
			if(eggs[cur].first <= 0) sum--;
			if(eggs[nxt].first <= 0) sum--;
			eggs[cur].first += eggs[nxt].second;
			eggs[nxt].first += eggs[cur].second;
			
		}
	}
	
	if(noCrashEgg == true){ // 깨지지 않은 다른 계란이 없을때 오른쪽 계란으로 이동
		crashEgg(eggs,cur+1,sum);
	}
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> N;
	
	vector<pair<int,int>> eggs; // {내구도, 무게}
	for(int i=0;i<N;i++){
		int d,w;
		cin >> d >> w;
		eggs.push_back({d,w});
	}
	
	crashEgg(eggs,0,0);
	cout << answer << "\n";
}