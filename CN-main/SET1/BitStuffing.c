
#include <stdio.h>

int main()
{
    int a[20], b[30], i, j = 0, count = 0, n;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        b[j++] = a[i];

        if (a[i] == 1)
            count++;
        else
            count = 0;

        if (count == 5)
        {
            b[j++] = 0;
            count = 0;
        }
    }

    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++)
        printf("%d", b[i]);

    return 0;
}

//Sample Input/Output:
// Enter frame length: 5
// Enter input frame (0's & 1's only): 1 1 1 1 1
// After stuffing the frame is: 111110