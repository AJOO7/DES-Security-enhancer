#include<bits/stdc++.h>
using namespace std;

string encryptRail(string text,int key)
{
    int len=text.length();
    char** rail = new char*[key];
    for(int i = 0; i < key; ++i)
	{
        rail[i] = new char[len];
    }
    for(int i=0;i<key;i++)
	{
    	for(int j=0;j<len;j++)
		{
        	rail[i][j]=NULL;
  		}
	}
    bool decline=true;
    bool incline=false;
    int j=0;
	for(int i=0;i<len;i++)
	{
    	rail[j][i]=text[i];
    	if(j==(key-1))
		{
        	decline=false;
        	incline=true;
    	}
    	
    	if(j==0)
		{
        	incline=false;
        	decline=true;
    	}
    	
    	if(decline)
		{
        	j++;
    	}

    	if(incline)
		{
        	j--;
    	}
	}
	
	string result;
	for(int i=0;i<key;i++)
	{
    	for(int j=0;j<len;j++)
		{
            if(rail[i][j]!=NULL)
			{
        		result.push_back(rail[i][j]);
        	}
    	}
	}
	
	return result;

}

int main(){
    int key=125642;
    string text="attack at once";
    int temp=key;
    int noOfRows,noOfRounds;
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
            continue;
        }else{
            int task2=temp%10;
            temp=temp/10;
            swap(text[task],text[task2]);
        }
    }
 while(noOfRounds!=0){
    text=encryptRail(text, noOfRows);
    noOfRounds--;
 }
cout<<text<<endl;
return 0;
}
