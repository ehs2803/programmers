#include <string>
#include <vector>
using namespace std;

bool check[1001];

vector<int> solution(vector<int> enter, vector<int> leave) {
    int n = enter.size();
    vector<int> result(n+1,0);

    int index_enter=0, index_leave=0;
    while(true){
        if(index_enter<=n-1){
            check[enter[index_enter]]=true;
            index_enter++;
            for(int i=1;i<=n;i++){
                if(check[i]==true && i!=enter[index_enter-1]){
                    result[i]+=1;
                }
            }
        }
        if(index_leave<=n-1 && check[leave[index_leave]]==true){
            int cnt=0;
            vector<int> temp;
            for(int i=1;i<=n;i++){
                if(check[i]==true && i!=leave[index_leave]) {
                    cnt++;
                    temp.push_back(i);
                }
            }
            result[leave[index_leave]]=cnt;
            check[leave[index_leave]]=false;
            //for(int i=0;i<temp.size();i++) result[temp[i]]=cnt;
            index_leave++;
            while(true){
                if(index_enter==n && index_leave==n) break;
                bool ch=false;
                for(int i=0;i<temp.size();i++){
                    if(leave[index_leave]==temp[i]){
                        check[temp[i]]=false;
                        temp.erase(temp.begin()+i);
                        index_leave++;
                        ch=true;
                        break;
                    }
                }
                if(ch==false) break;
            }

        }
        else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(check[i]==true && i!=enter[index_enter-1]){
                    cnt++;
                }
            }
            result[enter[index_enter-1]]=cnt;
        }
        if(index_enter==n && index_leave==n) break;
    }

    vector<int> answer;
    for(int i=1;i<=n;i++) answer.push_back(result[i]);

    return answer;
}