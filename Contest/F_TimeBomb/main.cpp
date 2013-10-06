#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int decodeDigit(int digit);

char *szDigits[7][5];

char *digitMask[11] = 
   //*** *** *** *** ***
   {"*** * * * * * * *** ", //0
	"  *   *   *   *   * ", //1
	"***   * *** *   *** ", //2
	"***   * ***   * *** ", //3
	"* * * * ***   *   * ", //4
	"*** *   ***   * *** ", //5
	"*** *   *** * * *** ", //6
	"***   *   *   *   * ", //7
	"*** * * *** * * *** ", //8
	"*** * * ***   * *** ", //9
	"                    "}; //Blank


int main(int argc, char **argv)
{
	char *input;
	char sztemp[256];
	char *tok;
	char sztemp2[5];
		
	input = (char*)malloc(sizeof(char)*1024);
	memset(input, 0x00, sizeof(char)*1024);

	//Each line of the numbers
	for(int i=0;i<5;i++)
	{
		gets(sztemp);
		//printf("%s\n", sztemp);
		
		//Each digit is a set of 4 chars
		for(int j=0;j<8;j++)
		{
			szDigits[j][i] = (char*)malloc(sizeof(char)*10);
			memset(szDigits[j][i], 0x00, 10);
			
			if((j*4) < strlen(sztemp))
			{
				//Calc num stars per
				memcpy(szDigits[j][i], sztemp+(j*4), 4);
			}
			
			//printf("%s_", szDigits[j][i]);
		}
		//printf("\n");
	}
	
	//printf("\n\n");
	
	char *results;

	results = (char*)malloc(sizeof(char)*10);
	memset(results,0x00, 10);
	
	//Decode the digits
	for(int i=0;i<8;i++)
	{
		int digit = decodeDigit(i);
		//printf("Digit: %d\n", digit);
		if(digit==-2)
		{
			//printf("BOOM!!");
			return 0;
		}
		
		//Add them to string
		if(digit>-1)
		{
			sprintf(sztemp, "%d", digit);
			results = strcat(results, sztemp);	
		}
		
	}
	
	//printf("%s\n", results);
	int iResult = atoi(results);

	//Divide by 6
	if (iResult % 6 == 0)
	{
		//code for perfect divisor
		printf("BEER!!");
	}
	else
	{
		//the number doesn't divide perfectly by divisor
		printf("BOOM!!");
	}

	return 0;
}

//Is this a valid digit?
int decodeDigit(int digit)
{
	char *szCompleteRow;
	char szRow[5];
	
	szCompleteRow = (char*)malloc(sizeof(char)*256);
	memset(szCompleteRow, 0x00, 256);
	
	for(int row=0;row<5;row++)
	{
		memset(szRow, 0x00, 5);
		sprintf(szRow, "%-4s", szDigits[digit][row]);
		szCompleteRow = strcat(szCompleteRow, szRow);
	}
	//printf("%s\n", szCompleteRow);
	
	//Compare to the digit mask 0 - 9
	for(int mask = 0; mask<11; mask++)
	{
		if(strcmp(szCompleteRow, digitMask[mask])==0)
		{
			free(szCompleteRow);
			if(mask==10)
				return -1;
				
			return mask;
		}
	}
	
	free(szCompleteRow);
	return -2;
}