
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, j = 0, n, pos;
    char a[20], b[50], ch;

    printf("Enter string\n");
    scanf("%19s", a);

    n = strlen(a);

    printf("Enter position\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position");
        return 0;
    }

    printf("Enter the character\n");
    scanf(" %c", &ch);

    b[j++] = 'd';
    b[j++] = 'l';
    b[j++] = 'e';
    b[j++] = 's';
    b[j++] = 't';
    b[j++] = 'x';

    while (i < n)
    {
        if (i == pos - 1)
        {
            b[j++] = 'd';
            b[j++] = 'l';
            b[j++] = 'e';
            b[j++] = ch;
            b[j++] = 'd';
            b[j++] = 'l';
            b[j++] = 'e';
        }

        if (i + 2 < n && a[i] == 'd' &&
            a[i + 1] == 'l' && a[i + 2] == 'e')
        {
            b[j++] = 'd';
            b[j++] = 'l';
            b[j++] = 'e';
        }

        b[j++] = a[i++];
    }

    b[j++] = 'd';
    b[j++] = 'l';
    b[j++] = 'e';
    b[j++] = 'e';
    b[j++] = 't';
    b[j++] = 'x';
    b[j] = '\0';

    printf("\nFrame after stuffing:\n%s\n", b);

    return 0;
}

//Sample Input/Output:
// Enter string
// CMRCET
// Enter position
// 2
// Enter the character
// A

// Frame after stuffing:
// dlestxCdleAdleMRCETdleetx