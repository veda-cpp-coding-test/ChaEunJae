// 백준 문제 : 회전하는 큐

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<int> wantNum;
    for(int i=0;i<M;i++){
        int e;
        cin >> e;
        wantNum.push_back(e);
    }

    deque<int> di;
    for(int i=1;i<N+1;i++){
        di.push_back(i);
    }

    int answer = 0;
    for(int w:wantNum){
        deque<int>::iterator it = find(di.begin(),di.end(),w);
        int dstToBegin = distance(di.begin(),it);
        int dstToEnd = distance(it,prev(di.end()));
        // cout << "거리 : "<< dstToBegin << "/" << dstToEnd << "\n";
        // cout << "answer : " << answer << "\n"; 
        if(dstToBegin <= dstToEnd){ // front에서부터 pop, 거리가 같으면 연산의 비용은 back부터 Pop하는 것이 1 더 들기때문에 front에서 pop하는 방향으로 결정 
            int e = di.front();
            while(e != w){
                // for(int i=0;i<di.size();i++){
                //     cout << di[i] << " ";
                // }
                // cout << "\n";
                di.pop_front();
                di.push_back(e);
                answer++;
                e = di.front();
            }
            di.pop_front();
        } else { // back에서부터 pop
            int e = di.back();
            while(e != w){
                // for(int i=0;i<di.size();i++){
                //     cout << di[i] << " ";
                // }
                // cout << "\n";
                di.pop_back();
                di.push_front(e);
                answer++;
                e = di.back();
            }
            di.pop_back();
            answer++;
        }
    }

    cout << answer;
}