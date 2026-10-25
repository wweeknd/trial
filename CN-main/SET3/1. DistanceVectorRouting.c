
#include <stdio.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main()
{
    int dmat[20][20];
    int n, i, j, k, count;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dmat[i][j]);
        }

        dmat[i][i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do
    {
        count = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] >
                        dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] =
                            dmat[i][k] + rt[k].dist[j];

                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }

    } while (count != 0);

    for (i = 0; i < n; i++)
    {
        printf("\n\nState value for router %d is:\n", i + 1);

        for (j = 0; j < n; j++)
        {
            printf("\nNode %d via %d Distance %d",
                   j + 1,
                   rt[i].from[j] + 1,
                   rt[i].dist[j]);
        }
    }

    printf("\n\n");

    return 0;
}

// Sample input:
// Enter the number of nodes: 3

// Enter the cost matrix:
// 0 2 3
// 2 0 5
// 4 5 0


// Output:
// State value for router 1 is:

// Node 1 via 1 Distance 0
// Node 2 via 2 Distance 2
// Node 3 via 3 Distance 3

// State value for router 2 is:

// Node 1 via 1 Distance 2
// Node 2 via 2 Distance 0
// Node 3 via 3 Distance 5

// State value for router 3 is:

// Node 1 via 1 Distance 4
// Node 2 via 2 Distance 5
// Node 3 via 3 Distance 0