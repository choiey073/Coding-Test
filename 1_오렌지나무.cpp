#include <bits/stdc++.h>
using namespace std;

//오렌지나무
//오렌지가 있는 위치만 보기.

int main() {
    ios_base::sync_with_stdio(false);   //동기화 비활성화 시켜 속도 높임.
    freopen("input.txt", "rt", stdin);
    
    int n, m, t, s, res =INT_MIN;
    cin >> n >> m >> t >> s;
    // 가로, 세로, 오렌지나무 개수, 땅의 크기
    
    vector<int> x, y;   // 오렌지나무의 x, y 좌표를 각 벡터로 받기
    for(int i=0;i<t; i++){
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    
    for(int i=0;i<t;i++){   // x좌표 접근
        for(int j=0;j<t;j++){   // y좌표 접근
            int cnt=0;
            for(int k = 0; k<t;k++){    //k번째 오렌지나무가 사각형 안에 있는지
                if(x[k]>=x[i] && x[k]<=x[i]+s){ // x[k] 오렌지 나무가 사각형 안에 있는지 확인.
                    if(y[k]>=y[j] && y[k]<=y[j]+s){ // y[k] 오렌지 나무가 사각형 안에 있는지 확인.
                        cnt++;  //x, y 둘 다에 있다면 count
                    }
                }
            }
            res=max(res, cnt);
        }
    }
    
    cout << res;
	
	return 0;
}