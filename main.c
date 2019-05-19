#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int findPivot(int size,double matrix[][size], int col)
{
    int ans;
    double big=0;
    for(int i=col;i<=size;i++)
    {
        if(fabs(matrix[i][col])>fabs(big))
	{
            big=matrix[i][col];
            ans=i;
        }
    }
    return ans;
}

void Switch(int size,double matrix[][size], int rowK, int rowI)
{
    double tmp;
    for(int i=0;i<size;i++)
    {
        tmp=matrix[rowK][i];
        matrix[rowK][i]=matrix[rowI][i];
        matrix[rowI][i]=tmp;
    }
}

int main()
{
    int n,bigger;
    srand(time(NULL));
    scanf("%d",&n);
    double matrix[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)matrix[i][j]=(rand()%1000)-500;
	
    printf("Before:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)printf("%8.3lf ",matrix[i][j]);
        printf("\n");
    }
    printf("\n");

    double devide,product;
    for(int k=0;k<n;k++)
    {
        bigger=findPivot(n,matrix,k);
        Switch(n,matrix,bigger,k);
        devide=matrix[k][k];
        for(int i=k;i<n;i++)matrix[k][i]/=devide;
        for(int i=k;i<n;i++)
	{
            product=matrix[i+1][k];
            for(int j=k;j<n;j++)
                matrix[i+1][j]=(-matrix[k][k])*product+matrix[i+1][j];
        }
    }
	
    printf("After:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)printf("%8.3lf ",matrix[i][j]);
        printf("\n");
    }
}
