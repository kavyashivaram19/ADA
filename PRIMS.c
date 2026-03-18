#include<stdio.h>
int prims(int num)
{
    int i,j,cost[35][35],a,b,v,u,visited[35],ne=0,mincost=0;
    printf("enter weights:");
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    visited[0]=1;
    while(ne<num-1)
    {
        int min=999;
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        printf("\n%d->%d=%d",a,b,min);
        mincost+=min;
        visited[b]=1;
        ne++;
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nmincost:%d",mincost);
}
int main()
{
    int num;
    printf("ENTER no.of nodes:");
    scanf("%d",&num);
    prims(num);
}
