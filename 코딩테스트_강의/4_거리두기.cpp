#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int n,p=1000;
    //p값을 처음에 큰 값으로 해야 나중에 min 계산할 수 있음
    cin >> n;
    vector <int> seats(n), dist(n);

    for(int i =0;i<n;i++){
        cin >> seats[i];
        if(seats[i]==1){    // 사람이 앉아있으면
            p=0;
            dist[i]=p;
        }
        else{   // 빈좌석이면
            p++;
            dist[i]=p;  // 거리 배열에 왼쪽 사람과의 거리값 넣어줌
        }
    }

    for(int i=n-1;i>=0;i--){// 오른쪽에서 왼쪽으로 for문 돌기
        if(seats[i]==1){    // 사람이 앉아있으면
            p=0;
        }
        else{   // 빈좌석이면
            p++;
            dist[i]=min(p, dist[i]);  // 오른쪽 사람과의 거리와 왼쪽 사람과의 거리 중 더 작은 값 입력
        }
    }

    int res = *max_element(dist.begin(), dist.end());// 벡터 배열에서 max값 구하는 함수
	
    cout << res;
    
	return 0;
}