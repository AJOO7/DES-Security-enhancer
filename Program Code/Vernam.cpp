#include<bits/stdc++.h>
using namespace std;
map<char,int>keyCode;
map<int,char>codeKey;
void setKeyCode(){
char ch='a';
for(int i=0;i<26;i++){
    keyCode[ch]=i;
    ch++;
}
char rch='a';
for(int i=0;i<26;i++){
    codeKey[i]=rch;
    rch++;
}
}
string encryptVerman(string text,string key)
{
	int *result=new int[text.length()];
	for(int i=0;i<text.length();i++)
	{
    	result[i]=(keyCode[text[i]]+keyCode[key[i]]);
    	if(result[i]>=26)
		{
        	result[i]=result[i]%26;
    	}
	}
	string ans;
	for(int i=0;i<text.length();i++)
	{
    	ans.push_back(codeKey[result[i]]);
	}
	return ans;
}
	
int main(){
setKeyCode();
cout<<encryptVerman("ramswarupk","ranchobaba");
return 0;
}
