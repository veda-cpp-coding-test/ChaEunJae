// 백준 문제 : 알고리즘 수업 - 깊이 우선 탐색 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<int> adj[100001];
int cnt = 1;
int answer[100001];

void dfs(int cur){
	visited[cur] = true;
	answer[cur] = cnt;
	//cout << cur << ":" << cnt << "\n";
	cnt++;
	for(auto nxt:adj[cur]){
		if(visited[nxt] == false) {
			dfs(nxt);
		}
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int N,M, R;
	cin >> N >> M >> R;
	
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i=1;i<N+1;i++){
		stable_sort(adj[i].begin(),adj[i].end());
	}
	
	for(int i=1;i<N+1;i++){
		visited[i] = false;
		answer[i] = 0;
	}
	
	dfs(R);
	
	for(int i=1;i<N+1;i++){
		cout << answer[i] << "\n";
	}
	
	
}
