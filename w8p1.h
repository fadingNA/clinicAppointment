/*
*****************************************************************************
                          Workshop - #8 (P1)
Full Name  :NONTHACHAI PLODTHONG
Student ID#:152487211
Email      :nplodthong@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define NUM_MAX 3
#define SUGGEST_SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    double weight_lbs;
    int calories;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *integer_pointer);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *double_pointer);

// 3. Opening Message (include the number of products that need entering)
void openingMessage();

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int round);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData
        (int sku1,
         const double *price1,
         const double *weight_lbs1,
         int calories);

// 7. Logic entry point
void start();
