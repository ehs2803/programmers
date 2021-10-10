// level1
// 성공. 시간초과 문제
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    vector<int> v;
    while(n){ //n!=1로 하고 v에 1을 더해주면 시간초과남... n!=0으로 했는데 시간초과문제 해결
        int temp = n%3;
        v.push_back(temp);
        n=n/3;
    }
    //v.push_back(1);
    //reverse(v.begin(), v.end());

    int answer = 0;
    int inc=0;
    for(int i=v.size()-1;i>=0;i--){
        answer+=v[i]*pow(3,v.size()-i-1);
    }
    return answer;
}
