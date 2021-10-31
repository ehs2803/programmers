// level2
// 성공. 수학적 지식. 최대공약수.
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    ll answer =(long long)w*h - (w+h-gcd(w,h));

    return answer;
}
