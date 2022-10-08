#include <bits/stdc++.h>
using namespace std;

// 패턴처리 -> 효율성
// 수학적으로 접근

int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    
    long long n, k; // k는 int 범위를 넘어가기 때문에 long long으로 잡아야함.
    cin >> n;
    vector<long long> T(n+1);   // vector는 0으로 초기화됨.
    //T는 작업의 시간을 입력받을 벡터
    for(int i=1;i<=n;i++)    cin >> T[i];
    cin >> k;
    
    vector<long long> sT(T);   // 정렬된 T vector
    // 괄호에 T를 인자로 넣으면 T 벡터 배열의 값이 그대로 복사됨.
    sort(sT.begin(), sT.end()); // 정렬.
    
    long long rest = n; // 남은 작업의 개수
    
    for(int i=1;i<=n;i++){  // sT[i] 작업을 끝낼 수 없는 경우
        if(k < (rest * (sT[i]-sT[i-1]))){
            int index = k%rest; // 마지막 바퀴에 끝내야 할 작업의 개수
            int cnt = 0;    // 남은 작업들을 0부터 indexing
            for(int j=1; j<=n;j++){
                if(T[j]>=sT[i]){    //이미 끝낸 작업을 건너 뛰기 위한 조건문.
                    if(cnt == index){   
                        cout << j;
                        return 0;
                    }
                    cnt++;
                }   
            }
        }
        else{   // sT[i] 작업을 끝낼 수 있는 경우
            k -= rest * (sT[i]-sT[i-1]);
            rest--;
        }
    }

    cout << "-1";   // 정전이 되기 전에 작업이 모두 처리된 경우.
    
    return 0;
}