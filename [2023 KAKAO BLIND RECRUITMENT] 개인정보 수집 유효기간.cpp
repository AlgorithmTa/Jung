#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 모든 달은 28일까지 있다고 가정합니다.
    
    // today : yyyy.mm.dd
    
    int year, month, day, totalday;
    map<char,int> terms_map;
    
    year = stoi(today.substr(0,4));
    month = stoi(today.substr(5,2));
    day = stoi(today.substr(8,2));
    totalday = year*12*28 + 28 * (month-1) + day;
    
    // 1<=terms의 길이<=20 || terms : "약관종류(알파벳) 유효기간"
    for(int i=0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char type;
        int period;
        ss >> type >> period;
        terms_map[type] = period;
    }
    
    // 1<=privacies의 길이<=100 || privacies : "수집날짜 약관종류"
    for(int i = 0; i < privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4)); 
        int m = stoi(privacies[i].substr(5, 2)); 
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i].back();
        
        // 수집날짜에 유효기간을 더함
        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (terms_map[a] * 28 - 1);
        
        // 오늘이랑 유효기간 끝나는날 비교
        if(tmp<totalday){
            answer.push_back(i+1);
        }
    }
    
    
    return answer;
}
