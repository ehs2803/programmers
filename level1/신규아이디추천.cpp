#include <string>

using namespace std;

string solution(string new_id) {
    //1
    for(int i=0;i<new_id.size();i++){
        if('A'<=new_id[i]&&new_id[i]<='Z') new_id[i]+=32;
    }

    //2
    string tempstr="";
    for(int i=0;i<new_id.size();i++){
        if((('a'<=new_id[i]&&new_id[i]<='z')||('0'<=new_id[i]&&new_id[i]<='9')||
            (new_id[i]=='-')||(new_id[i]=='_')||(new_id[i]=='.'))) {
            tempstr+=new_id[i];
        }
    }
    new_id=tempstr;

    //3
    while(true){
        bool check=true;
        for(int i=0;i<new_id.size()-1;i++){
            if(new_id[i]=='.' && new_id[i+1]=='.'){
                check=false;
                int cnt=0;
                for(int j=i;j<new_id.size();j++){
                    if(new_id[j]=='.') cnt++;
                    else break;
                }
                new_id.erase(i,cnt-1);

            }
        }
        if(check) break;
    }
    /*
    for(int i=0;i<new_id.size()-1;i++){
        if(new_id[i]=='.'&&new_id[i+1]){
            int temp=1;
            if(i+2<new_id.size()){
                for(int j=i+2;j<new_id.size();j++){
                    if(new_id[j]=='.') temp++;
                    else break;
                }
            }
            new_id.erase(i+1,temp-1);
        }
    }
    */

    //4
    if(new_id[0]=='.') new_id.erase(0,1);
    if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.size()-1,1);

    //5
    if(new_id.size()==0) new_id='a';

    //6
    if(new_id.size()>=16){
        new_id=new_id.substr(0,15);
        if(new_id[new_id.size()-1]=='.') new_id.erase(new_id.size()-1,1);
    }

    //7
    while(!(new_id.size()>2)){
        new_id+=new_id[new_id.size()-1];
    }
    string answer = new_id;
    return answer;
}