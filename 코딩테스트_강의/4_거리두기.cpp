#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);	// 입력의 양이 많을 때는 꼭 이 구문 쓰기!
	freopen("input.txt", "rt", stdin);

	int n, p=1000;
    cin >> n;
    vector <int> seats(n), dist(n);

    for(int i =0;i<n;i++){
        cin >> seats[i];
        if(seats[i]==1){
            p=0;
            dist[i]=p;
        }
        else{
            p++;
            dist[i]=p;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(seats[i]==1) p=0;
        else{
            p++;
            dist[i]=min(dist[i],p);
        }
    }
	
	return 0;
}