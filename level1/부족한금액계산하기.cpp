using namespace std;

long long solution(int price, int money, int count)
{
    long long answer;
    
    long long totalmoney=0;
    for(int i=1;i<=count;i++){
        totalmoney+=(i*price);    
    }

    if(totalmoney<money) answer=0;
    else answer = totalmoney-money;
    
    return answer;
}
