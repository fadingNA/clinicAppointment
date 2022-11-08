/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : NONTHACHAI PLODTHONG
Student ID#:152487211
Email      :nplodthong@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


// ----------------------------------------------------------------------------
// defines/macros

#define NUM_MAX 3
#define SUGGEST_SERVING 64
#define LBS_TO_KG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    double weight_lbs;
    int calories;
};

struct ReportData {
    int product_sku; // 1
    double product_price; // 2
    int calories_per_serving; // 4
    double weight_lbs; // 3
    ////////////////////////////////////
    double weight_kg; // ยัง
    int weight_g; // ยัง
    double total_serving; // ยัง
    double cost_serving; // ยัง
    double calories_cost_serving; // 0

};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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
void displayCatFoodData(int sku1,
                        const double *price1,
                        const double *weight_lbs1,
                        int calories);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbs,
                    double *kg);

// 9. convert lbs: g
int convertLbsG(const double *lbs,
                int *g);

// 10. convert lbs: kg / g
void convertLbs(const double *lbs,
                double *kg,
                int *g);

// 11. calculate: servings based on gPerServ
double calculateServings(const double serving_size,
                         const double total_grams,
                         double *number_serving);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *product_price,
                               const double *number_serving,
                               double *result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *product_price,
                           const double *total_number,
                           double *cost_calorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo product_data);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData report,
                       int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo cheapest_product);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();