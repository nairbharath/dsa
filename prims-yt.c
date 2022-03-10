#include<stdio.h>
#include<stdlib.h>
 
int main()
 
{
    int i,j,n,cost[10][10];
	printf("\nEnter the number of nodes:");
 
	scanf("%d",&n);
 
	printf("\nEnter the adjacency matrix:\n");
 
	for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	{
 
		scanf("%d",&cost[i][j]);
 
		if(cost[i][j]==0)
 
			cost[i][j]=999;
 
	}
    }
    prims(n,cost);
    return 0;
}
void prims(int n, int cost[10][10])
{
    int i,j,u,v,min,mincost=0,visited[10],ne=1;
    //mark all the vertex as unvisited.not considering for MST

    for(i=1;i<=n;i++)
        visited[i]=0;

    printf("The edges considered for MST are:\n "); 
	visited[1]=1;
 
 
	while(ne < n)
 
	{
 
		for(i=1,min=999;i<=n;i++)
        {
		for(j=1;j<=n;j++)
        {
		if(cost[i][j]< min)
        {
		if(visited[i]==0)
            continue;
        else
		{
 
			min=cost[i][j];
 
			u=i;
 
			v=j;
 
		}
        }
        }
        }
       
 
		if(visited[u]==0 || visited[v]==0)
 
		{
 
			printf("\n Edge %d:(%d %d) cost:%d",ne++,u,v,min);
 
			mincost+=min;
 
			visited[v]=1;
 
		}
 
		cost[u][v]=cost[v][u]=999;
 
	}
 
	printf("\n Minimun cost=%d",mincost);
 
	
 
}
 /*
Enter the number of nodes:6
Tyepe in anything random, even 4 will do
Enter the adjacency matrix:
0 3 1 6 0 0
3 0 5 0 3 0
1 5 0 5 6 4
6 0 5 0 0 2
0 3 6 0 0 6
0 0 4 2 6 0
The edges considered for MST are:

 Edge 1:(1 3) cost:1
 Edge 2:(1 2) cost:3
 Edge 3:(2 5) cost:3
 Edge 4:(3 6) cost:4
 Edge 5:(6 4) cost:2
 Minimun cost=13

 */