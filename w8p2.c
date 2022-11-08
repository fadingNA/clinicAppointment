/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : NONTHACHAI PLODTHONG
Student ID#: 152487211
Email      : nplodthong@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include "w8p2.h"

// System Libraries
#include <stdio.h>
// User Libraries
#include <math.h>
// User-Defined Libraries


// ----------------------------------------------------------------------------
// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs,
                    double *kg) {
    double result = *lbs / LBS_TO_KG;

    if (kg != NULL) {
        *kg = result;
    }
    return result;

}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs,
                int *g) {

    int result = convertLbsKg(lbs, NULL) * 1000;
    if (g != NULL) {
        *g = result;
    }
    return result;
}


// 10. convert lbs: kg and g
void convertLbs(const double *lbs,
                double *kg,
                int *g) {

    convertLbsKg(lbs, kg);
    convertLbsG(lbs, g);

}

// 11. calculate: servings based on gPerServ
double calculateServings(const double serving_size,
                         const double total_grams,
                         double *number_serving) {

    double total_serving =
            total_grams / serving_size;

    if (number_serving != NULL) {
        *number_serving = total_serving;
    }

    return total_serving;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *product_price,
                               const double *number_serving,
                               double *result) {
    double cost_serving =
            *product_price / *number_serving;

    if (result != NULL) {
        *result = cost_serving;
    }

    return cost_serving;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *product_price,
                           const double *total_number,
                           double *cost_calorie) {

    double calories =
            *product_price / *total_number;

    if (cost_calorie != NULL) {
        *cost_calorie = calories;
    }

    return calories;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo product_data) {
    struct ReportData data_product;

    data_product.product_sku = product_data.sku;

    data_product.product_price = product_data.price;

    data_product.weight_lbs = product_data.weight_lbs;

    data_product.calories_per_serving = product_data.calories;

    data_product.weight_kg = convertLbsKg
            (&product_data.weight_lbs, NULL);

    data_product.weight_g = convertLbsG
            (&product_data.weight_lbs, NULL);

    data_product.total_serving = calculateServings
            (SUGGEST_SERVING,
             data_product.weight_g,
             NULL);

    data_product.cost_serving = calculateCostPerServing
            (&product_data.price,
             &data_product.total_serving,
             NULL);

    double total_calories =
            data_product.total_serving * product_data.calories; //calculate first 64

    data_product.calories_cost_serving = calculateCostPerCal
            (&product_data.price,
             &total_calories,
             NULL);

    /*double total_serving; // ยัง
    double cost_serving; // ยัง
    double calories_cost_serving; // 0*/
    return data_product;


}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void) {
    printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGGEST_SERVING);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData report,
                       int cheapest) {
    if (cheapest == 1) {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
               report.product_sku,
               report.product_price,
               report.weight_lbs,
               report.weight_kg,
               report.weight_g,
               report.calories_per_serving,
               report.total_serving,
               report.cost_serving,
               report.calories_cost_serving);
        printf(" ***\n");

    } else {
        printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",
               report.product_sku,
               report.product_price,
               report.weight_lbs,
               report.weight_kg,
               report.weight_g,
               report.calories_per_serving,
               report.total_serving,
               report.cost_serving,
               report.calories_cost_serving);

    }
    
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo cheapest_product) {
    printf("\nFinal Analysis\n"
           "--------------\n"
           "Based on the comparison data, the PURRR-fect economical option is:\n"
           "SKU:00%d Price: $%2.2lf\n\n"
           "Happy shopping!\n",
           cheapest_product.sku,
           cheapest_product.price);
}

// ----------------------------------------------------------------------------

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
    struct ReportData reportDataList[NUM_MAX]; // camel cases

    int cheapestProductIndex = 1;
    double cheapestPrice = reportDataList[0].cost_serving; // 1.52
    for (j = 0; j < NUM_MAX; j++) {
        reportDataList[j] = calculateReportData
                (Cat_Food_Info[j]);
        // แปลงจาก CATFOODINFO เป็น reportDataList

        if (reportDataList[j].cost_serving < cheapestPrice) {
            cheapestPrice = reportDataList[j].cost_serving;
            cheapestProductIndex = j;
        }

    }
    displayReportHeader();

    for (i = 0; i < NUM_MAX; i++) {
        displayReportData(reportDataList[i],
                          i == cheapestProductIndex);

    }
    displayFinalAnalysis(
            Cat_Food_Info[cheapestProductIndex]);

}
