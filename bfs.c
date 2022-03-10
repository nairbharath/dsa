#include <stdio.h>
void bfs(int);
int graph[10][10],visited[10],n;
void bfs(int vertex)
{
 int i;
 printf("%d\t",vertex);
 visited[vertex]=1;
 for(i=0;i<n;i++)
 {
 if(graph[vertex][i]==1 && !visited[i])
 {
 bfs(i);
 }
 }
}

void dfs(int vertex)
{
    int i;
    printf("%d\t",i);
    visited[vertex]=1;
    for(i=0;i<n;i++)
    {
        if(graph[vertex][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }

    
}
int main()
{
 
 int i,j;
 printf("Enter no of vertices: ");
 scanf("%d",&n);
 printf("\nMatrix:\n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 scanf("%d",&graph[i][j]);
 }
 }
 for(i=0;i<n;i++)
 {
 visited[i]=0;
 }
 //bfs(0);
 printf("\n");
 dfs(0);
 
 return 0;
}