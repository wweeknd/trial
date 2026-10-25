
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int packets[5];
    int i, clk;
    int bucket_size, output_rate;
    int packet_size;
    int packet_size_remaining = 0;
    int packet_time;

    srand(time(NULL));

    /* Generate random packet sizes */
    for (i = 0; i < 5; i++)
    {
        packets[i] = rand() % 10 + 1;
    }

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("\n========LEAKY BUCKET SIMULATION========\n");

    for (i = 0; i < 5; i++)
    {
        if ((packets[i] + packet_size_remaining) > bucket_size)
        {
            if (packets[i] > bucket_size)
            {
                printf("\nIncoming packet size: %d is greater than bucket capacity.\n",
                       packets[i]);
            }
            else
            {
                printf("\nBucket size exceeded. Packet %d is discarded.\n",
                       packets[i]);
            }
        }
        else
        {
            packet_size = packets[i];
            packet_size_remaining += packet_size;

            printf("\n----------------------------------------------------------\n");
            printf("\nIncoming packet size: %d\n", packet_size);
            printf("Bytes in bucket      : %d\n", packet_size_remaining);

            packet_time = rand() % 5 + 1;

            printf("Next packet will come after %d seconds\n", packet_time);

            for (clk = 0;
                 clk < packet_time && packet_size_remaining > 0;
                 clk++)
            {
                printf("\nTime %d: ", clk + 1);

                printf("Transmitted %d bytes\n",
                       (packet_size_remaining < output_rate)
                       ? packet_size_remaining : output_rate);

                if (packet_size_remaining < output_rate)
                    packet_size_remaining = 0;
                else
                    packet_size_remaining -= output_rate;

                printf("Bytes remaining in bucket: %d\n",
                       packet_size_remaining);
            }
        }
    }

    printf("\n===============================================================\n");
    printf("Transmitting remaining packets....\n");

    while (packet_size_remaining > 0)
    {
        if (packet_size_remaining < output_rate)
            packet_size_remaining = 0;
        else
            packet_size_remaining -= output_rate;

        printf("Bytes remaining: %d\n", packet_size_remaining);
    }

    printf("Simulation completed\n");

    return 0;
}


// Sample Input/Output:
// Enter output rate: 4
// Enter bucket size: 10

// ========LEAKY BUCKET SIMULATION========

// ----------------------------------------------------------

// Incoming packet size: 6
// Bytes in bucket      : 6
// Next packet will come after 2 seconds

// Time 1: Transmitted 4 bytes
// Bytes remaining in bucket: 2

// Time 2: Transmitted 2 bytes
// Bytes remaining in bucket: 0

// ----------------------------------------------------------

// Incoming packet size: 8
// Bytes in bucket      : 8
// Next packet will come after 3 seconds

// Time 1: Transmitted 4 bytes
// Bytes remaining in bucket: 4

// Time 2: Transmitted 4 bytes
// Bytes remaining in bucket: 0

// Bucket size exceeded. Packet 5 is discarded.

// ===============================================================
// Transmitting remaining packets....
// Simulation completed