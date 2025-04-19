// 백준 문제 : AC

#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

deque<int> split(const string& str, char delimiter) {
    deque<int> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(stoi(token));
    }

    return result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T;
    cin >> T;

    for(int tt=0;tt<T;tt++){
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;
        arr.replace(arr.find('['),1,"");
        arr.replace(arr.find(']'),1,"");
        deque<int> numArr = split(arr,',');

        bool isRev = false; // 뒤집혀 있는지 여부
        bool isError = false;
        for(auto i:p){
            if(i == 'R'){
                isRev = !isRev;
            } else {
                if(numArr.empty()){
                    isError = true;
                    break;
                } else {
                    if(!isRev) numArr.pop_front();
                    else numArr.pop_back();
                }
            }
        }

        if(isError == true){
            cout << "error\n";
            continue;
        }

        if(isRev) reverse(numArr.begin(),numArr.end()); // R이 들어올때마다 reverse를 수행하면 시간초과 가능성 있음
        cout << "[";
        for(int i=0;i<numArr.size();i++){
            if(i == numArr.size()-1){
                cout << numArr[i];
            } else {
                cout << numArr[i] << ",";
            }
        }
        cout << "]\n";
    }
}