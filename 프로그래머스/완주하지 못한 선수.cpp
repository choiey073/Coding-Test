#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map <string, int> map;
    
    for(auto name : participant){
        map[name]++;
    }
    
    for (auto player : completion){
        map[player]--;
    }
    
    for(auto name : participant){
        if(map[name]>0){
            answer = name;
            break;
        }
    }
        
    return answer;
}