#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int iSweeps;
	char szSweeps[256];
	char start[1024];
	char result[1024];
	
	scanf("%s", szSweeps);
	iSweeps = atoi(szSweeps);
	
	scanf("%s", start);
	scanf("%s", result);
	
	/*
	printf("%s\n", szSweeps);
	printf("%s\n", start);
	printf("%s\n", result);
	*/
	
	//On odd sweeps the are reversed
	//On even sweeps szline1 & szLine2 will be
	//equals
	if(iSweeps % 2 == 0)
	{
		if(strcmp(start, result)==0)
		{
			printf("Deletion succeeded");
		}
		else
		{
			printf("Deletion failed");
		}
	}
	else
	{
		//Flip the string 1 more time -then should be the same
		//Flip Start -> to the negative
		for(int i=0;i<strlen(start);i++)
		{
			if(start[i]=='1')
				start[i] = '0';
			else
				start[i] = '1';
		}
		
		if(strcmp(start, result)==0)
		{
			printf("Deletion succeeded");
		}
		else
		{
			printf("Deletion failed");
		}
	}
	
	return 0;
}
