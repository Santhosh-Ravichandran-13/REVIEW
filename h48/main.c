#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int i;
    int *numbers;
    int sum = 0;
    int product = 1;
    
    printf("Arithmetic Operations on Dynamic Integers\n");
    printf("=========================================\n\n");
    
    printf("Enter how many integers you want to process: ");
    scanf("%d", &count);
    
    if (count <= 0)
    {
        printf("Number must be greater than 0\n");
        return 1;
    }

    numbers = (int *)malloc(count * sizeof(int));
    
    if (numbers == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter %d integers:\n", count);
    for (i = 0; i < count; i++)
    {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\n--- Calculation Results ---\n\n");
    printf("Numbers entered: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
        sum += numbers[i];
    }
    printf("\n\n");
    
    printf("Sum: %d\n", sum);

    double average = (double)sum / count;
    printf("Average: %.2f\n", average);

    for (i = 0; i < count; i++)
    {
        product *= numbers[i];
    }
    printf("Product: %d\n", product);

    int max = numbers[0];
    int min = numbers[0];
    
    for (i = 1; i < count; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
    }
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    
    /* Free allocated memory */
    free(numbers);
    
    printf("\nMemory freed successfully\n");
    
    return 0;
}

