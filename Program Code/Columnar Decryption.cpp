#include<bits/stdc++.h>
using namespace std;
map <int,int> keyMap;
map<char,int>alphaCode;
void SET(){
    char ch='A';
for(int i=0;i<26;i++){
    alphaCode[ch]=i;
    ch++;
}
}
void sort(int key[],string code){
for(int i=0;i<code.length();i++){
    for(int j=i;j<code.length();j++){
          if((code[i]>code[j])&&(key[i]<key[j])){
            swap(key[i],key[j]);
          }
    }
}
}

string decryptColumnar(string text,string key)
{
	int *keyPos= new int[key.length()];
	for(int i=0;i<key.length();i++)
	{
    	keyPos[i]=i;
	}
	sort(keyPos,key);
	for(int i=0;i<key.length();i++)
	{
    	keyMap[keyPos[i]]=i;
	}
	int r=(text.length()/key.length());
	if(text.length()%key.length())
	{
    		r+=1;
	}
	char matrix[r][key.length()];
	for(int i=0;i<r;i++)
	{
    	for(int j=0;j<key.length();j++)
		{
        	matrix[i][j]='_';
    	}
	}
	int out=0;
	for(int i=0;i<key.length();i++)
	{
        int index=keyMap[i];
    	for(int j=0;j<r;j++)
		{

 			if(text[out]!='\0')
			{
        		matrix[j][index]=text[out];
        		out++;
 			}

    	}
	}
	for(int i=0;i<r;i++)
	{
    	for(int j=0;j<key.length();j++)
		{
        	cout<<matrix[i][j];
    	}
    	cout<<endl;
	}
	string result;
	for(int i=0;i<r;i++)
	{
    	for(int j=0;j<key.length();j++)
		{

        	result.push_back(matrix[i][j]);
		}
	}

	return result;
}
int main(){
    SET();
    string key="HACKS";
    string text="efkeoeG Ger sks";
    int noOfRounds=0;
    for(int i=0;key[i]!='\0';i++){
            noOfRounds+=alphaCode[key[i]];
    }
for(int j=0;j<noOfRounds;j++){
text=decryptColumnar(text,key);//key must cantain unique characters
}
cout<<text<<endl;
return 0;
}

