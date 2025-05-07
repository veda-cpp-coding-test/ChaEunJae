// 백준 문제 : DFS 스페셜 저지

#include <iostream>

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
    for (int y : adj[x]) {
        if (check[y] == false) {
            if(dfsStep[cnt] == y){
                // cout << cnt << "\n";
                dfs(y);
            }
        }
    }
}

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

    dfs(dfsStep[0]);
    for(int i=1;i<N+1;i++){
        if(check[i] == false){
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0;
}