#include<stdio.h>
#include<string.h>
int main()
{
	char strExp[]="2+2*3+2/2-1";
	char strTmp[strlen(strExp)];
	int strTmpIndex=-1;
	for(int i=0;i<strlen(strExp);i++)
	{
		if(strExp[i]=='*')
		{
			int left=strTmp[strTmpIndex]-'0';
			int right=strExp[i+1]-'0';
			strTmp[strTmpIndex]=left*right+'0';
			i++; 
		}
		else if(strExp[i]=='/')
		{
			int left=strTmp[strTmpIndex]-'0';
			int right=strExp[i+1]-'0';
			strTmp[strTmpIndex]=left/right+'0';
			i++; 
		}
		else strTmp[++strTmpIndex]=strExp[i];
	}
	int res=strTmp[0]-'0';
	for(int i=1;i<strlen(strTmp);i++)
	{
		if(strTmp[i]=='+')res+=strTmp[++i]-'0';
		else if(strTmp[i]=='-')
		res-=strTmp[++i]-'0'; 
	}
	printf("%d\n",res);
	return 0;
}