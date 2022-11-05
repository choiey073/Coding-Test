#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 1 <= n <= 1,000,000,000
// 1<= times[i] <= 1,000,000,000
// 너무 크다! 이분탐색 생각해야함.

long long solution(int n, vector<int> times) {
    long long answer = 0;
                                              
    // 이분 탐색을 위해서 정렬                     
    sort(times.begin(), times.end());
    
    // 최소한으로 걸리는 시간 : 1명 * 1분                                              
    long long start = 1;
    
    // 최대로 걸리는 시간 : n명 * (가장 오래 걸리는 시간)                                       
    long long end = n * (long long)times[times.size()-1];
    
    // 탐색 범위(시간) 기준
    long long mid;
    
    while(start <= end){
        // 중앙값 구하기
        mid = (start + end)/2;
        cout << mid << endl;
        // cnt : mid 시간 내에 처리 가능한 모든 사람의 수
        long long cnt = 0;
        
        for(int i =0;i<times.size();i++){
            // 각 시간별 mid 시간 안에 처리할 수 있는 사람의 수 더해주기
            cnt += mid/times[i];
        }
        
        // 해당 시간 내에 처리할 수 있는 사람의 수가 n보다 적다면
        // 조건을 만족하지 않으므로
        if(cnt < n){
            // 최솟값을 mid + 1로 늘려주기
            start = mid+1;
        }
        // 해당 조건을 만족한다면
        else{   // cnt >= n
            // mid는 최소 시간이 될 수 있기 때문에 answer에 넣어줌 
            answer = mid;
            end = mid-1;
        }
    }                                                                
    return answer; 
}