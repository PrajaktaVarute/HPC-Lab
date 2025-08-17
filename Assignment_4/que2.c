
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BUFFER_SIZE 10
#define NUM_ITEMS 100

int buffer[BUFFER_SIZE];
int count = 0; 
int in = 0;    
int out = 0;   

void producer()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
#pragma omp critical
        {
            if (count < BUFFER_SIZE)
            {                  
                buffer[in] = i; 
                printf("Produced: %d\n", i);
                in = (in + 1) % BUFFER_SIZE;
                count++;
            }
        }
    }
}

void consumer()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
#pragma omp critical
        {
            if (count > 0)
            {                           
                int item = buffer[out]; 
                printf("Consumed: %d\n", item);
                out = (out + 1) % BUFFER_SIZE;
                count--;
            }
        }
    }
}

int main()
{
#pragma omp parallel sections
    {
#pragma omp section
        producer();

#pragma omp section
        consumer();
    }

    return 0;
}
