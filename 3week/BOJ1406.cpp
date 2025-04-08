// 백준 문제 : 에디터

#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    list<char> ll;
    for(auto s:str){
        ll.push_back(s);
    }

    int M;
    cin >> M;

    auto it = ll.end();
    for(int i=0;i<M;i++){
        char command;
        cin >> command;
        switch (command)
        {
            case 'L':
                if(it != ll.begin()) it--; 
                break;
            case 'D':
                if(it != ll.end()) it++;
                break;
            case 'B':
                if(it != ll.begin()){
                    it--;
                    it = ll.erase(it); // 반복자가 새로운 원소를 가리켜야하므로 반환값 대입
                }
                break;
            case 'P':
                char c;
                cin >> c;
                ll.insert(it,c); // it = ll.insert(it,c)시 삽입 후에도 원래 위치를 가리킴
                break;
            default:
                break;
        }
        // for(auto z:ll){
        //     cout << z;
        // }
        // cout << "\n";
    }

    for(auto i:ll){
        cout << i;
    }
    cout << "\n";
}