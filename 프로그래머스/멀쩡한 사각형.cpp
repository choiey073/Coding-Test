using namespace std;

// 최대공약수 구하기
int GCD(int w, int h){
    int c;
    while(h != 0){
        c = w % h;
        w = h;
        h = c;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    // (w/최대공약수 + h/최대공약수 -1) * 최대공약수
    // 사용 불가한 사각형 == (w + h - 최대공약수) -> 사용할 수 없는 사각형의 개수
    // 사용 가능한 사각형 == w x h - (w + h - 최대공약수)
    answer = (long long)w * (long long)h - (w+h);
    answer += GCD(w,h);
    
    return answer;
}