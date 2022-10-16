#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int len = commands.size();
    
    for(int i =0;i<len;i++){
        int start = commands[i][0]-1;
        int end = commands[i][1]-1;
        int size = commands[i][2]-1;
        
        vector <int> tmp(end-start+1);
        copy(array.begin()+start, array.begin()+end+1, tmp.begin());
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[size]);
    }
    return answer;
}