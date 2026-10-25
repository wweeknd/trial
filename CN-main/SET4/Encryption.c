
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, ch, lp;
    char cipher[50], plain[50];
    char key[50];
    int encrypted = 0;

    while (1)
    {
        printf("\n---MENU---");
        printf("\n1.Data Encryption");
        printf("\n2.Data Decryption");
        printf("\n3.Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch)
        {
        case 1:
            printf("\nData Encryption");
            printf("\nEnter the plain text: ");
            fgets(plain, sizeof(plain), stdin);
            plain[strcspn(plain, "\n")] = '\0';

            printf("Enter the encryption key: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';

            lp = strlen(key);

            if (lp == 0)
            {
                printf("Key cannot be empty.\n");
                break;
            }

            for (i = 0; plain[i] != '\0'; i++)
                cipher[i] = plain[i] ^ lp;

            cipher[i] = '\0';
            encrypted = 1;

            printf("\nThe encrypted text is: ");
            puts(cipher);
            break;

        case 2:
            if (!encrypted)
            {
                printf("\nPlease encrypt data first.\n");
                break;
            }

            printf("\nData Decryption");

            for (i = 0; cipher[i] != '\0'; i++)
                plain[i] = cipher[i] ^ lp;

            plain[i] = '\0';

            printf("\nThe decrypted text is: ");
            puts(plain);
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }

    return 0;
}

// Sample Input/Output:
// ---MENU---
// 1.Data Encryption
// 2.Data Decryption
// 3.Exit

// Enter your choice: 1

// Data Encryption
// Enter the plain text: HELLO
// Enter the encryption key: ABC

// The encrypted text is: KFOOL

// ---MENU---
// 1.Data Encryption
// 2.Data Decryption
// 3.Exit

// Enter your choice: 2

// Data Decryption
// The decrypted text is: HELLO

// ---MENU---
// 1.Data Encryption
// 2.Data Decryption
// 3.Exit

// Enter your choice: 3
