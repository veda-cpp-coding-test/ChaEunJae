// 백준 문제 : 싸이버개강총회

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int timeToMinutes(const std::string& timeStr) {
    size_t colonPos = timeStr.find(':');
    if (colonPos == std::string::npos) {
        return -1; // 유효하지 않은 형식
    }
    int hour = std::stoi(timeStr.substr(0, colonPos));
    int minute = std::stoi(timeStr.substr(colonPos + 1));
    return hour * 60 + minute;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string startTime, endOtTime, endOtStreamingTime;
    cin >> startTime >> endOtTime >> endOtStreamingTime;
    int startTimeNum, endOtTimeNum, endOtStreamingTimeNum;
    startTimeNum = timeToMinutes(startTime);
    endOtTimeNum = timeToMinutes(endOtTime);
    endOtStreamingTimeNum = timeToMinutes(endOtStreamingTime);

    string timestamp, name;
    unordered_map<string,bool> attendance;
    
    while(cin >> timestamp >> name){
        int timestampNum = timeToMinutes(timestamp);
        if(timestampNum <= startTimeNum){
            attendance.insert({name,false});
        } else if(timestampNum >= endOtTimeNum && timestampNum <= endOtStreamingTimeNum){
            if(attendance.find(name) != attendance.end()){
                attendance[name] = true;
            }
        } 
    }

    int answer = 0;
    for(auto at:attendance){
        if(at.second == true){
            answer++;
        }
    }
    cout << answer << "\n";
}