#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    if(a>b) return true;
    else return false;
}

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    int answer = 0;
    int indexS=0, indexL=B.size()-1;
    for(int i=0;i<A.size();i++){
        if(A[i]<B[indexS]){
            answer++;
            indexS++;
        }
        else{
            indexL--;
        }
    }
    
    return answer;
}
//20220104