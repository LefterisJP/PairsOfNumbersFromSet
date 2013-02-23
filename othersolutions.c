#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int partition(int* a,int left,int right,int pivotI)
{
    int swap,newPivotI,i;
    int pivotValue = a[pivotI];
    //move the pivot to the end
    a[pivotI] = a[right];
    a[right] = pivotValue;
    newPivotI = left;//initialize the new pivot position to the leftmost index
    //find the new pivot position
    for(i=left;i<right;i++)
    {//if the value at the iterated index is less than the pivot value then swap that value
    // with the potential pivot position and increase the potential pivot position
        if(a[i] <= pivotValue)
        {
            swap = a[i];
            a[i] = a[newPivotI];
            a[newPivotI] = swap;
            newPivotI++; //increase the potential pivot index
        }
    }
    //in the end move the pivot to its final position
    a[right] = a[newPivotI];
    a[newPivotI] = pivotValue;
    return newPivotI;
}

void quicksort_inplace(int* a,int left,int right)
{
    int pivotI,newPivotI;
    if(left < right)//if the list has at least 2 items
    {
        //choose the pivot
        pivotI = left+(right-left)/2;
        //partition the list
        newPivotI = partition(a,left,right,pivotI);
        //recursively quick sort elements smaller than the pivot
        quicksort_inplace(a,left,newPivotI-1);
        //recursively quick sort elements greater than the pivot
        quicksort_inplace(a,newPivotI+1,right);
    }
}

void quicksort(int* a,int size)
{
    quicksort_inplace(a,0,size-1);
}


int compare(const void* a, const void* b)
{
    if( *(int*)a < *(int*)b)
        return -1;
	return 1;
}


int main()
{
    int N,K,*set,i=0,j=1,diff,lastJ=1;
    char* buff,* token;
    int result = 0;


    //read 1st input line
    scanf("%d %d \n",&N,&K);
    //allocate space for the set numbers string and the actual set
    buff = malloc(13*N);//13 here is for ULONG_MAX number of digits + space
    set = malloc(sizeof(int)*N);

    //read second line of input
    gets(buff);
    //find the individual numbers
    token = strtok(buff," ");
    while(token != NULL)
    {
        sscanf(token,"%d",&set[i]);
        token = strtok(NULL," ");
        i++;
    }

	//first sort the array
	quicksort(set,N);//our implementation of quicksort
	//qsort(set,N,sizeof(int),compare);//stdlib implementation of quicksort

	//finding the pairs 
    for(i=0;i<N;i++)
    {
		j = i+1;
		if(set[lastJ]-set[i]<K)
			j = lastJ+1;
        for(;j<N;j++)
        {
			diff = set[j]-set[i];
			if(diff > K)
				break;
			lastJ = j;
            if( diff == K)
			{
                result++;
				break;
			}
        }
    }
    printf("%d",result);

    return 0;
}
