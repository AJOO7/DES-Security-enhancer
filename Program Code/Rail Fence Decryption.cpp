#include<bits/stdc++.h>
using namespace std;
string decryptRail(string cypher,int key){
    int len=cypher.length();
    char** rail = new char*[key];
    for(int i = 0; i < key; ++i){
        rail[i] = new char[len];
    }
    bool decline=true;
    bool incline=false;
    int j=0;
    for(int i=0;i<len;i++){
    rail[j][i]='*';
    if(j==(key-1)){
        decline=false;
        incline=true;
    }
    if(j==0){
        incline=false;
        decline=true;
    }
    if(decline){
        j++;
    }

    if(incline){
        j--;
    }
}
int out=0;
for(int i=0;i<key;i++){
    for(int j=0;j<len;j++){
        if(rail[i][j]=='*'){
            rail[i][j]=cypher[out];
            out++;
        }
    }
}
string result;
 decline=true;
 incline=false;
 j=0;
for(int i=0;i<len;i++){
    result.push_back(rail[j][i]);
    if(j==(key-1)){
        decline=false;
        incline=true;
    }
    if(j==0){
        incline=false;
        decline=true;
    }
    if(decline){
        j++;
    }

    if(incline){
        j--;
    }
}

return result;

}
int main(){
    int key=125642;
    string text="aak ct tntcaoe";
    int temp=key;
    int noOfRows,noOfRounds;//no of rounds can be btw 1 to 9
    int i=1;
    while(temp!=0){
        int task=temp%10;
        temp=temp/10;
        if(i==1){
            noOfRows=task;
            i++;
            continue;
        }else if(i==2){
            noOfRounds=task;
            i++;
            break;
        }
    }
 while(noOfRounds!=0){
    text=decryptRail(text, noOfRows);
    noOfRounds--;
 }
 while(temp!=0){
        int task=temp%10;
        temp=temp/10;
 if(i>2){
            int task2=temp%10;
            temp=temp/10;
            swap(text[task],text[task2]);
    }
 }
cout<<text<<endl;
return 0;
}
