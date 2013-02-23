#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    int N,K,*set,i=0,j;
    char* buff,* token;
    int result = 0;


    //read 1st input line
    scanf("%d %d \n",&N,&K);
    //allocate space for the set numbers string and the actual set
    buff = malloc(13*N);//13 here is for ULONG_MAX numebr of digits + space
    set = malloc(sizeof(int)*N);

    //read second line of input
    gets(buff);
    //find the individual numbers
    token = strtok(buff," ");
    while(token != NULL)
    {
        sscanf(token,"%d",&set[i]);
        int nn = set[i];
        token = strtok(NULL," ");
        i++;
    }

    int k =0;
    //naive approach
    for(i=k;i<N;i++)
    {
        for(j=k;j<N;j++)
        {
            if( abs(set[i] - set[j]) == K)
                result++;
        }
        k++;
    }

    printf("%d",result);

    return 0;

}
