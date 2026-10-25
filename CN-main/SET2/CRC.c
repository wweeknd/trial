
#include <stdio.h>

int main()
{
int data[50], gen[20], temp[70];
int dl, gl, i, j, choice, error = 0;

printf("1. Generate  2. Check\n");  
printf("Choice: ");  
scanf("%d", &choice);  

printf("Enter the length of data: ");  
scanf("%d", &dl);  

if (dl < 1 || dl > 50)  
{  
    printf("Invalid data length\n");  
    return 0;  
}  

printf("Enter the data: ");  
for (i = 0; i < dl; i++)  
    scanf("%d", &data[i]);  

printf("Enter the length of generator: ");  
scanf("%d", &gl);  

if (gl < 2 || gl > 20 || gl > dl)  
{  
    printf("Invalid generator length\n");  
    return 0;  
}  

printf("Enter the generator: ");  
for (i = 0; i < gl; i++)  
    scanf("%d", &gen[i]);  

if (gen[0] != 1)  
{  
    printf("Generator must start with 1\n");  
    return 0;  
}  

if (choice == 1)  
{  
    for (i = 0; i < dl; i++)  
        temp[i] = data[i];  

    for (i = dl; i < dl + gl - 1; i++)  
        temp[i] = 0;  

    for (i = 0; i < dl; i++)  
    {  
        if (temp[i] == 1)  
        {  
            for (j = 0; j < gl; j++)  
                temp[i + j] ^= gen[j];  
        }  
    }  

    printf("CRC: ");  

    for (i = 0; i < dl; i++)  
        printf("%d", data[i]);  

    for (i = dl; i < dl + gl - 1; i++)  
        printf("%d", temp[i]);  

    printf("\n");  
}  
else if (choice == 2)  
{  
    for (i = 0; i < dl; i++)  
        temp[i] = data[i];  

    for (i = 0; i < dl - gl + 1; i++)  
    {  
        if (temp[i] == 1)  
        {  
            for (j = 0; j < gl; j++)  
                temp[i + j] ^= gen[j];  
        }  
    }  

    for (i = dl - gl + 1; i < dl; i++)  
    {  
        if (temp[i] != 0)  
            error = 1;  
    }  

    if (error == 0)  
        printf("No error detected\n");  
    else  
        printf("Error detected\n");  
}  
else  
{  
    printf("Invalid choice\n");  
}  

return 0;

}

// Sample Input/Output:
// 1. Generate  2. Check
// Choice: 1
// Enter the length of data: 4
// Enter the data: 1 0 1 1
// Enter the length of generator: 3
// Enter the generator: 1 1 1
// CRC: 101101