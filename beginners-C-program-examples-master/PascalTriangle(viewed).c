#include<stdio.h>
int main()
{
    long long int r,k,j,i,coeff;
 // input nuber of rows
    scanf("%lld",&r);

    
    for(i=0;i<r;i++)
    {
      printf("\n");

 // for maintaing the space in initial par
        for(j=0;j<r-1-i;j++)
        {
            printf("  ");
        }

// algorithm 
        for(k=0;k<=i;k++){
            if(i==0 || k==0)
                coeff=1;
            else
                coeff=coeff*(i-k+1)/k;
            printf("%4lld",coeff);  //// gcc не понял что такое %4lld
        }
        printf("\n");

    }
    return 0;
}
