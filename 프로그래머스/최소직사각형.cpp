#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int col_max = 0;
    int row_max = 0;
    
    for(int i =0; i<sizes.size();i++){  //모든 명함 가로가 길게 눕혀주기
        if(sizes[i][0] < sizes[i][1]){
            int tmp=0;
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }   
    }
    
    for(int i =0; i<sizes.size();i++){  // 가로 최대 * 세로 최대
        if(sizes[i][0] > col_max)   col_max = sizes[i][0];
        if(sizes[i][1] > row_max)   row_max = sizes[i][1];
    }
    
    return col_max*row_max;
}