
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct frame{
    int seqNum;
    char data[20];
};

struct frame a[10],temp;

int divide(char msg[])
{
    int i,j,n=0;

    for(i=0;msg[i]!='\0';i+=3)
    {
        a[n].seqNum=n+1;

        for(j=0;j<3 && msg[i+j]!='\0';j++)
            a[n].data[j]=msg[i+j];

        a[n].data[j]='\0';
        n++;
    }

    return n;
}

void shuffle(int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        j=rand()%n;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

void sortFrames(int n)
{
    int i,j;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j].seqNum>a[j+1].seqNum)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void receive(int n)
{
    int i;

    printf("\nFrames received:\n");
    for(i=0;i<n;i++)
        printf("%d\t%s\n",a[i].seqNum,a[i].data);

    sortFrames(n);

    printf("\nSorted frames:\n");
    for(i=0;i<n;i++)
        printf("%d\t%s\n",a[i].seqNum,a[i].data);

    printf("\nOriginal message: ");
    for(i=0;i<n;i++)
        printf("%s",a[i].data);

    printf("\n");
}

int main()
{
    char msg[31];
    int n;

    srand(time(NULL));

    printf("Enter message: ");
    fgets(msg,sizeof(msg),stdin);
    msg[strcspn(msg,"\n")]='\0';

    n=divide(msg);
    shuffle(n);
    receive(n);

    return 0;
}

// Sample Input/Output:
// Enter message: COMPUTER NETWORK

// Frames received:
// 3     ER 
// 1     COM
// 5     WOR
// 2     PUT
// 6     K
// 4     NET

// Sorted frames:
// 1     COM
// 2     PUT
// 3     ER
// 4     NET
// 5     WOR
// 6     K

// Original message: COMPUTER NETWORK