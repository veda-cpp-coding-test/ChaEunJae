// 백준 문제 : 선 긋기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int,int> > lines;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;

        lines.push_back(make_pair(x,y));
    }

    sort(lines.begin(),lines.end(),Compare);
    // for(auto i:lines){
    //     cout << i.first << " " << i.second << "\n";
    // }

    int answer = 0;
    int lastIdx = lines[0].first;
    for(int i=0;i<N;i++){
        if(lines[i].first > lastIdx){
            lastIdx = lines[i].first;
        } else if(lines[i].second < lastIdx){
            continue;
        }
        answer += lines[i].second - lastIdx;
        lastIdx = lines[i].second;
    }
    cout << answer << "\n";
}