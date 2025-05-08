// 백준 문제 : DFS 스페셜 저지

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[100001];
vector<int> adj[100001];
int cnt = 0;
vector<int> dfsStep;

void dfs(int x){

    if (check[x] == true) {
        return;
    }
    
    check[x] = true;
    cnt++;
    while(find(adj[x].begin(),adj[x].end(),dfsStep[cnt]) != adj[x].end()){
		if(check[dfsStep[cnt]] == false){
			// cout << x << " " << dfsStep[cnt] << "\n";
			dfs(dfsStep[cnt]);
		}
	} 
}

// adj[x]에 dfsStep[cnt]가 존재하는지 while문으로 반복하며 검사
// 존재하면 dfs 재귀 수행하고 cnt++, 방문처리 
// 없으면 다음 while 반복 수행

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=0;i<N-1;i++){
        int e1,e2;
        cin >> e1 >> e2;

        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    for(int i=0;i<N;i++){
        int e;
        cin >> e;

        dfsStep.push_back(e);
    }

    for(int i=1;i<N+1;i++){
        check[i] = false;
    }

    dfs(1);
    for(int i=1;i<N+1;i++){
        if(check[i] == false){
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0;
}

// 모든 노드 방문했으면 1 출력
// 하나라도 방문안했으면 0 출력