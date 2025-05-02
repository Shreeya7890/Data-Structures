// Menu-Driven Program for Calculating Areas
#include <stdio.h>
#include <stdlib.h>

// Area of square
float Square(float *side) {
    return (*side) * (*side);
}

// TSA of cube
float Cube(float *side) {
    return 6 * (*side) * (*side);
}

// Area of rectangle
float Rectangle(float *length, float *width) {
    return (*length) * (*width);
}

// TSA of cuboid
float Cuboid(float *length, float *width, float *height) {
    return 2 * ((*length) * (*width) + (*width) * (*height) + (*height) * (*length));
}

int main() {
    int choice;
    float *length, *width, *height, *side;

    //Menu for menu-driven program
    do {
        printf("\nMenu:\n");
        printf("1. Square\n");
        printf("2. Cube\n");
        printf("3. Rectangle\n");
        printf("4. Cuboid\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case condition for choice
        switch (choice) {
            case 1:
                //DMA
                side = (float *)malloc(sizeof(float)); 
                if (side == NULL) {
                    printf("Memory allocation failed\n");
                    return -1;
                }

                printf("Enter side of square: ");
                scanf("%f", side);

                // Boundary condition
                if (*side < 0) {
                    printf("Negative numbers not allowed\n");
                    free(side);
                    continue; 
                }

                printf("Area of square: %.2f\n", Square(side));
                free(side);
                break;

            case 2:
                //DMA
                side = (float *)malloc(sizeof(float)); 
                if (side == NULL) {
                    printf("Memory allocation failed\n");
                    return -1;
                }

                printf("Enter side of cube: ");
                scanf("%f", side);

                // Boundary condition
                if (*side < 0) {
                    printf("Negative numbers not allowed\n");
                    free(side);
                    continue; 
                }

                printf("TSA of cube: %.2f\n", Cube(side));
                free(side); 
                break;

            case 3:
                //DMA
                length = (float *)malloc(sizeof(float)); 
                width = (float *)malloc(sizeof(float));
                if (length == NULL || width == NULL) {
                    printf("Memory allocation failed\n");
                    return -1;
                }

                printf("Enter length and width of rectangle: ");
                scanf("%f %f", length, width);

                // Boundary condition
                if (*length < 0 || *width < 0) {
                    printf("Negative numbers not allowed\n");
                    free(length);
                    free(width);
                    continue; 
                }

                printf("Area of rectangle: %.2f\n", Rectangle(length, width));
                free(length); 
                free(width); 
                break;

            case 4:
                //DMA
                length = (float *)malloc(sizeof(float));
                width = (float *)malloc(sizeof(float));
                height = (float *)malloc(sizeof(float));
                if (length == NULL || width == NULL || height == NULL) {
                    printf("Memory allocation failed\n");
                    return -1;
                }

                printf("Enter length, width, and height of cuboid: ");
                scanf("%f %f %f", length, width, height);

                // Boundary condition
                if (*length < 0 || *width < 0 || *height < 0) {
                    printf("Negative numbers not allowed\n");
                    free(length);
                    free(width);
                    free(height);
                    continue; 
                }

                printf("TSA of cuboid: %.2f\n", Cuboid(length, width, height));
                free(length); 
                free(width); 
                free(height);
                break;

            case 5:
                printf("Exiting program.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
