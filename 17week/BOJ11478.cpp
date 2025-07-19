// 백준 문제 : 서로 다른 부분 문자열의 개수

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    unordered_set<string> subStrings;
    for(int i=1;i<=S.length();i++){
        // i : 부분 문자열의 길이
        for(int j=0;j+i<=S.length();j++){
            // j : 부분 문자열의 시작 인덱스
            string subStr = S.substr(j,i);
            subStrings.insert(subStr);
        }
    }
    cout << subStrings.size() << "\n";
}