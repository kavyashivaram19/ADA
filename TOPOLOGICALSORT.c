#include<stdio.h>
#define max 10
int n,m,a[max][max],q[max],topo[max];
void topologysort(int n,int a[10][10])
{
    int id[30],i,j,front=0,rear=-1,v,k=0,c=0;
    for(i=0;i<n;i++)
    {
        id[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
                id[j]+=1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(id[i]==0)
        {
            rear++;
            q[rear]=i;
        }
    }
    while(front<=rear)
    {
        v=q[front++];
        topo[k++]=v;
        c++;
        for(j=0;j<n;j++)
        {
            if(a[v][j]==1)
            {
                a[v][j]=0;
                id[j]--;
                if(id[j]==0)
                    q[++rear]=j;
            }
        }
    }
    if(c!=n)
    {
        printf("cycle exist, topo order not possible");
        return;
    }
    printf("topo order is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",topo[i]);
    }
}
int main()
{
    int i,j;
    printf("enter the no.of vertices:");
    scanf("%d",&n);
    printf("enter the weights of adjacent graph:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    topologysort(n,a);
}
