// Menu-Driven Program for Palindrome, Armstrong, and Perfect Number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Palindrome(int *num)
{
    int reversed = 0, temp = *num, remainder;
    while (temp > 0)
    {
        remainder = temp % 10;
        reversed = (reversed * 10) + remainder;
        temp /= 10;
    }
    return (*num == reversed);
}

// Armstrong number function
int Armstrong(int *num)
{
    int sum = 0, temp = *num, digits = 0, remainder;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }
    temp = *num;

    while (temp > 0)
    {
        remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= remainder;  
        }

        sum += power;
        temp /= 10;
    }
    return (sum == *num);
}


// Function to check Perfect Number
int Perfect(int *num)
{
    int sum = 0;
    for (int i = 1; i < *num; i++)
    {
        if (*num % i == 0)
            sum += i;
    }
    return (sum == *num);
}

int main()
{
    int choice, *num;

    //Menu for menu-driven program
    do
    {
        printf("\nMenu:\n");
        printf("1. Check Palindrome\n");
        printf("2. Check Armstrong Number\n");
        printf("3. Check Perfect Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // DMA
        if (choice >= 1 && choice <= 3)
        {
            num = (int *)malloc(sizeof(int));

            // Boundary conditions
            do
            {
                printf("Enter a number: ");
                scanf("%d", num);

                if (*num < 0)
                {
                    printf("Negative numbers not allowed.\n");
                }
            } while (*num < 0); 

            // Switch case condition for choice
            switch (choice)
            {
            case 1:
                if (Palindrome(num))
                    printf("The number is a Palindrome.\n");
                else
                    printf("The number is not a Palindrome.\n");
                break;

            case 2:
                if (Armstrong(num))
                    printf("The number is an Armstrong number.\n");
                else
                    printf("The number is not an Armstrong number.\n");
                break;

            case 3:
                if (Perfect(num))
                    printf("The number is a Perfect number.\n");
                else
                    printf("The number is not a Perfect number.\n");
                break;
            }

            free(num); // Free allocated memory
        }

    } while (choice != 4);

    printf("Exiting program.\n");
    return 0;
}
