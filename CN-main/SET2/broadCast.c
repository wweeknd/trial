
#include <stdio.h>

#define MAX 10

int adjacencyMatrix[MAX + 1][MAX + 1];
int numNodes;

void displayAdjacentNodes(int rootNode)
{
int i;

printf("\nAdjacent nodes of node %d:\n", rootNode);  

for (i = 1; i <= numNodes; i++)  
{  
    if (adjacencyMatrix[rootNode][i] == 1 ||  
        adjacencyMatrix[i][rootNode] == 1)  
    {  
        if (i != rootNode)  
            printf("%d\t", i);  
    }  
}  

printf("\n");

}

int main()
{
int i, j, rootNode;

printf("Enter number of nodes: ");  
scanf("%d", &numNodes);  

for (i = 1; i <= numNodes; i++)  
{  
    for (j = 1; j <= numNodes; j++)  
    {  
        printf("Is there a connection from node %d to node %d (1=yes, 0=no): ",  
               i, j);  
        scanf("%d", &adjacencyMatrix[i][j]);  
    }  
}  

printf("Enter root node (1 to %d): ", numNodes);  
scanf("%d", &rootNode);  

displayAdjacentNodes(rootNode);  

return 0;

}

// Output:
// Enter number of nodes: 3
// Is there a connection from node 1 to node 1 (1=yes, 0=no): 0
// Is there a connection from node 1 to node 2 (1=yes, 0=no): 1
// Is there a connection from node 1 to node 3 (1=yes, 0=no): 0
// Is there a connection from node 2 to node 1 (1=yes, 0=no): 1
// Is there a connection from node 2 to node 2 (1=yes, 0=no): 0
// Is there a connection from node 2 to node 3 (1=yes, 0=no): 1
// Is there a connection from node 3 to node 1 (1=yes, 0=no): 0
// Is there a connection from node 3 to node 2 (1=yes, 0=no): 1
// Is there a connection from node 3 to node 3 (1=yes, 0=no): 0
// Enter root node (1 to 3): 2

// Adjacent nodes of node 2:
// 1    3