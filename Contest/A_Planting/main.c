#include <stdio.h>

int main(int argc, char **argv)
{
	char szLine1[10];
	char *szLine2;
	int numberOfTrees;
	int treeDays;
	int *treeArray;
	int *orderedTreeArray;
	char *pch;
	int i;
	int j;
	int iTree;
	int k;
	int bOrdered;
	
	//szLine1 - number of Trees
	//szLine2 - array
	scanf("%s", szLine1);
	numberOfTrees = atoi(szLine1);
	
	treeArray = (int*)malloc(sizeof(int)*numberOfTrees);
	memset(treeArray, 0x00, numberOfTrees*sizeof(int));
	
	for(i=0;i<numberOfTrees; i++)
	{
		bOrdered = 0;
		scanf("%s", szLine1);
		iTree = atoi(szLine1);
		
		if(i==0)
		{
			treeArray[i] = iTree;
		}
		else
		{
			//Where to put this int?
			for(j=0;j<i;j++)
			{
				int treeNum = treeArray[j];
				if(treeArray[j]>iTree)
				{
					bOrdered = 1;
					//need to insert the iTree into this slot - J - and move the rest over.
					//backwards order
					for(k=i;k>j;k--)
					{
						treeArray[k] = treeArray[k-1];
					}
					treeArray[j] = iTree;
					break;
				}
			}
			
			if(bOrdered==0)
			{
				treeArray[i] = iTree;
			}
		}
	}

	//Debug
	/*
	for(i=0;i<numberOfTrees;i++)
	{
		printf("%d ", treeArray[i]);
	}
	*/
	
	//Order bubble sort - slow, but easy
	//Calc the day = array index + 1
	int dayOfParty = 0;
	int dayIndex=numberOfTrees;
	for(i=0;i<numberOfTrees;i++)
	{
		if((treeArray[i]+dayIndex) > dayOfParty)
		{
			dayOfParty = treeArray[i]+dayIndex+1;	
		}
		dayIndex--;
	}
	
	printf("%d", dayOfParty);
	
	return 0;
}
