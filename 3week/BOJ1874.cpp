// 백준 문제 : 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<char> answer;
    stack<int> si;
    int cur = 0;
    bool isPossible = true;
    for(int i=0;i<n;i++){
        int e;
        cin >> e;
        while(e > cur){
            answer.push_back('+');
            cur++;
            si.push(cur);
        }
        if(e <= cur){
            int e2 = si.top(); si.pop();
            if(e2 != e) {
                isPossible = false;
            }
            answer.push_back('-');
        }   
    }

    if(isPossible == true){
        for(auto i:answer){
            cout << i << "\n";
        }
    } else {
        cout << "NO\n";
    }
    
}