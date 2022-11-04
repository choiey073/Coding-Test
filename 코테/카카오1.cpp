#include <bits/stdc++.h>

using namespace std;

int solution(int x,int y,int z){
    int low = 1;
    int high = x + z;
    int answer = -1;

    while(low <= high){
        int mid = (low+high)/2;

        if(abs(mid-y) <= z-(mid-x)) {
            cout << mid << endl;
            answer = max(answer,mid);
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return answer;
}