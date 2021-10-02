#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    for(int i=0;i<scores.size();i++){
        int min=101, max=-1;
        int sum=0;
        for(int j=0;j<scores.size();j++){
            sum+=scores[j][i];
            if(scores[j][i]>max) max=scores[j][i];
            if(scores[j][i]<min) min=scores[j][i];
        }
        
        double avg;
        if(scores[i][i]==max){
            bool check=false;
            for(int j=0;j<scores.size();j++){
                if(i!=j && max==scores[j][i]){
                    check=true;
                    break;
                }
            }
            if(check==false){
                sum-=max;
                avg = sum/(scores.size()-1);
            }
            else{
                avg = sum/scores.size();  
            }
        }
        else if(scores[i][i]==min){
            bool check=false;
            for(int j=0;j<scores.size();j++){
                if(i!=j && min==scores[j][i]){
                    check=true;
                    break;
                }
            }
            if(check==false){
                sum-=min;
                avg = sum/(scores.size()-1);
            }
            else{
                avg = sum/scores.size();  
            }
        }
        else{
            avg = sum/scores.size();      
        }
        
        if(avg>=90) answer+="A";
        else if(avg>=80) answer+="B";
        else if(avg>=70) answer+="C";
        else if(avg>=50) answer+="D";
        else answer+="F";
    }
    
    return answer;
}
