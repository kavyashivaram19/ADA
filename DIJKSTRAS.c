#include<stdio.h>
void dijkstras(int c[30][30],int n,int s,int d[30])
{
    int i,u,min,j,v[15];
    for(i=0;i<n;i++)
    {
        d[i]=c[s][i];
        v[i]=0;
    }
    v[s]=1;
    for(i=0;i<n;i++)
    {
        min=9999;
        for(j=0;j<n;j++)
        {
            if(v[j]==0&&d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }
        v[u]=1;
        for(j=0;j<n;j++)
        {
            if(v[j]==0&&d[u]+c[u][j]<d[j])
                d[j]=d[u]+c[u][j];
        }
    }
    printf("\nthe shortest distance are:");
    for(i=0;i<n;i++)
    {
        printf("\n%d->%d=%d",s,i,d[i]);
    }
}

int main()
{
    int n,s;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    int c[30][30],d[30];
    printf("\nenter cost of edges:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0)
                c[i][j]=9999;
        }
    }
    printf("\nenter the start vertex:");
    scanf("%d",&s);
    dijkstras(c,n,s,d);

}
