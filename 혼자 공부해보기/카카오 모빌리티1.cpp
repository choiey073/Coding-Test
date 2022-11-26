#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> flowers) {
    int answer = 0;
    vector <int> days(366,0);
    
    for(int i =0; i<flowers.size();i++){
        int start = flowers[i][0];
        int end = flowers[i][1];
        
        for(int j=start; j<end;j++){
            days[j] = 1;
        }
    }
    answer = count(days.begin(), days.end(), 1) ;

    return answer;
}