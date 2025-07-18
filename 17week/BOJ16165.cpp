// 백준 문제 : 걸그룹 마스터 준석이

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    unordered_map<string,vector<string>> girlGroups;
    unordered_map<string,string> memberToGroupName;
    for(int i=0;i<N;i++){
        string groupName;
        cin >> groupName;
        int groupNum;
        cin >> groupNum;
        vector<string> memberNames;
        for(int j=0;j<groupNum;j++){
            string memberName;
            cin >> memberName;
            memberToGroupName.insert({memberName,groupName});
            memberNames.push_back(memberName);
        }
        sort(memberNames.begin(),memberNames.end());
        girlGroups.insert({groupName,memberNames});
    }

    for(int i=0;i<M;i++){
        string name;
        int quizType;
        cin >> name >> quizType;

        if(quizType == 0){
            for(auto girl:girlGroups[name]){
                cout << girl << "\n";
            }
        } else {
            cout << memberToGroupName[name] << "\n";
        }
    }
}