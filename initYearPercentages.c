#include "defs.h"

void initYearPercentages(ListType* gRecords){
    NodeType *current;
    current = gRecords->head;
    char chosen_country[20];
    strcpy(chosen_country, current->recordNode.countryName);
    YearGrads *thisCountry = (YearGrads*) malloc(sizeof(YearGrads));

    strcpy(thisCountry->countryName, current->recordNode.countryName);
    // Declare the column variables
    int currT = 0, curr2014 = 0, curr2015 = 0, curr2016 = 0, curr2017 = 0;

    printf("%-20s%-10s%-10s%-10s%-10s\n", "Country", "2014", "2015", "2016", "2017");
    while(current->next != NULL){
        // If the country changes in this iteration
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            // Do processes to the column variables
            thisCountry->percent2014 = (float)curr2014 / currT * 100.0;
            thisCountry->percent2015 = (float)curr2015 / currT * 100.0;
            thisCountry->percent2016 = (float)curr2016 / currT * 100.0;
            thisCountry->percent2017 = (float)curr2017 / currT * 100.0;
            // Print out the processed data
            printf("%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", thisCountry->countryName, thisCountry->percent2014, thisCountry->percent2015, thisCountry->percent2016,
                   thisCountry->percent2017);
            // Reset chosen_country and thisCountry
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            currT = 0;
            curr2014 = 0;
            curr2015 = 0;
            curr2016 = 0;
            curr2017 = 0;
        }else{
            // If gender is 'T'
            if(current->recordNode.gender == 'T'){
                currT += current->recordNode.numGrads;
                current = current->next;
                continue;
            }
            // If the year is 2014
            if(current->recordNode.year == 2014){
                curr2014 += current->recordNode.numGrads;
            }
            // If the year is 2015
            else if(current->recordNode.year == 2015){
                curr2015 += current->recordNode.numGrads;
            }
            // If the year is 2016
            else if(current->recordNode.year == 2016){
                curr2016 += current->recordNode.numGrads;
            }
            // If the year is 2017
            else if(current->recordNode.year == 2017){
                curr2017 += current->recordNode.numGrads;
            }
        }
        current = current->next;
    }
    // Process and print out the data for the last country
    thisCountry->percent2014 = (float)curr2014 / currT * 100.0;
    thisCountry->percent2015 = (float)curr2015 / currT * 100.0;
    thisCountry->percent2016 = (float)curr2016 / currT * 100.0;
    thisCountry->percent2017 = (float)curr2017 / currT * 100.0;
    printf("%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", thisCountry->countryName, thisCountry->percent2014, thisCountry->percent2015, thisCountry->percent2016,
           thisCountry->percent2017);
    free(thisCountry);
}

