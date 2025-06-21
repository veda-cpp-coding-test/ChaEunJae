// 백준 문제 : 공주님의 정원

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<tuple<int,int,int,int>> vp(N, make_tuple(0, 0, 0, 0));
    for(int i=0;i<N;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        vp[i] = make_tuple(a, b, c, d);
    }

    sort(vp.begin(), vp.end());

    // cout << "====================\n";
    // for(int i=0;i<N;i++){
    //     cout << get<0>(vp[i]) << " " 
    //          << get<1>(vp[i]) << " " 
    //          << get<2>(vp[i]) << " " 
    //          << get<3>(vp[i]) << "\n";
    // }

    int answer = 0;
    int stMonth = 3;
    int stDay = 1;
    int lastMonth = stMonth;
    int lastDay = stDay;
    for(int i=0;i<N;i++){
        bool isFind = false;
        // cout << "i : "  << i << "\n";
        for(int j=i;j<N;j++){
            // cout << "j : " << j << "\n";
            int a = get<0>(vp[j]);
            int b = get<1>(vp[j]);
            int c = get<2>(vp[j]);
            int d = get<3>(vp[j]);

            if((a < stMonth || (a == stMonth && b <= stDay))&& (c > stMonth || (c == stMonth && d > stDay))){
                isFind = true;
                if(c > lastMonth || (c == lastMonth && d > lastDay)){
                    lastMonth = c;
                    lastDay = d;
                } 
            } else if(a > stMonth || (a == stMonth && b > stDay)){
                break;
            }
            i = j;
        }
        if(isFind == true){
            stMonth = lastMonth;
            stDay = lastDay;
            // cout << stMonth << " " << stDay << "\n";
            answer++;
        }
        if(stMonth > 11){
            if(isFind == false){
                cout << 0 << "\n";
                return 0;
            } else {
                cout << answer << "\n";
                return 0;
            }
        }
    }
    cout << 0 << "\n";
}