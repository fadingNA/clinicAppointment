/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  :Nonthachai Plodthong
Student ID#:152487211
Email      :nplodthong@myseneca.ca
Section    :NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include "w8p1.h"

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
// User Libraries
#include <math.h>

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *integer_pointer) {
    int user_input;

    while (1) {
        scanf("%d", &user_input);
        if (user_input <= 0) {
            printf("ERROR: Enter a positive value: ");
        } else {
            break;
        }
    }
    if (integer_pointer != NULL) {
        *integer_pointer = user_input;
    }

    return user_input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *double_pointer) {

    double user_input;

    while (1) {
        scanf("%lf", &user_input);
        if (user_input <= 0.0) {
            printf("ERROR: Enter a positive value: ");
        } else {
            break;
        }
    }
    if (double_pointer != NULL) {
        *double_pointer = user_input;
    }
    return user_input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage() {
    printf("Cat Food Cost Analysis\n"
           "======================\n\n"
           "Enter the details for %d dry food bags of product data for analysis.\n"
           "NOTE: A 'serving' is %dg\n\n", NUM_MAX, SUGGEST_SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int round) {

    struct CatFoodInfo cat_food_1;

    printf("Cat Food Product #%d\n", round);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&cat_food_1.sku);
    printf("PRICE         : $");
    getDoublePositive(&cat_food_1.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&cat_food_1.weight_lbs);
    printf("CALORIES/SERV.: ");
    getIntPositive(&cat_food_1.calories);
    printf("\n");

    return cat_food_1;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData
        (const int sku1,
         const double *price1,
         const double *weight_lbs1,
         const int calories) {
    printf("%07d %10.2lf %10.1lf %8d\n",
           sku1, *price1, *weight_lbs1, calories);
}

// 7. Logic entry point
void start() {
    struct CatFoodInfo Cat_Food_Info[NUM_MAX];
    openingMessage();
    int i;
    for (i = 0; i < NUM_MAX; i++) {
        Cat_Food_Info[i] = getCatFoodInfo(i + 1);
    }
    displayCatFoodHeader();
    int j;
    for (j = 0; j < NUM_MAX; j++) {
        displayCatFoodData(Cat_Food_Info[j].sku,
                           &Cat_Food_Info[j].price,
                           &Cat_Food_Info[j].weight_lbs,
                           Cat_Food_Info[j].calories);
    }
    /*printf("Final Analysis\n"
           "--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%d Price: $%.2lf\n\n", Cat_Food_Info[j + 1].sku, Cat_Food_Info[j + 1].price);
    printf("Happy shopping!\n");*/
}


