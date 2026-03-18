#include<stdio.h>
int parent[35];
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    int n,e,cost[35][35],u,v,a,b,i,j,ne=0;
    int min,mincost=0;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    printf("\nreading weight of graph:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    for(i=0;i<n;i++)
    {
        parent[i]=0;
    }
    while(ne<n-1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\n%d->%d=%d",a,b,min);
            mincost+=min;
            ne++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nmin cost is:%d",mincost);

}
