#include<stdio.h>
#define INF 9999
void floyds(int n)
{
    int d[n][n],i,j,k,a[n][n];
    printf("\nenter the weight of adjcent matrix:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if( i!=j && a[i][j]==0)
            {
                a[i][j]=INF;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            d[i][j]=a[i][j];
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    printf("the shortest paths are:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",d[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("ENTER NO.OF VERTES:");
    scanf("%d",&n);

    floyds(n);
    return 0;
}
