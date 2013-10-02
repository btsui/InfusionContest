#include <stdio.h>

int main(int argc, char **argv)
{
	char szLine1[1024];
	char szLine2[1024];
	int i;
	int j;
	
	memset(szLine1, 0x00, sizeof(szLine1));
	memset(szLine2, 0x00, sizeof(szLine2));
	//gets(szInput);
	scanf("%s %s", szLine1, szLine2);
	
	for(i=0;i<strlen(szLine1)-1;i++)
	{
		if(szLine1[i]=='h')
			break;
	}
	
	for(j=0;j<strlen(szLine2)-1;j++)
	{
		if(szLine2[j]=='h')
			break;
	}
	
	//reset J
	//j=j-(i+1);
	
	if( i>=j )
		printf("go");
	else
		printf("no");
	return 0;
}
