#include "defs.h"

void initDegreePercentages(ListType* gRecords){
    // Create a NodeType pointer.
    NodeType *current;
    // Store the head of gotten list in it.
    current = gRecords->head;

    char chosen_country[20];
    // Store the first country as the chosen country to process.
    strcpy(chosen_country, current->recordNode.countryName);
    // Allocate memory for a temperory DegreePercent type.
    DegreePercent *thisCountry = (DegreePercent*) malloc(sizeof(DegreePercent));
    // Init thisCountry
    strcpy(thisCountry->countryName, current->recordNode.countryName);
    // Declare the needed variables (Columns in chosen_country
    int currT = 0, currL6 = 0, currL7 = 0, currL8 = 0;
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Country", "L6", "L7", "L8", "Total");

    while(current->next != NULL){
        // If the country changes in this iteration
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            // Process the column variables
            thisCountry->percentL6 = (float)currL6 / currT * 100.0 ;
            thisCountry->percentL7 = (float)currL7 / currT * 100.0;
            thisCountry->percentL8 = (float)currL8 / currT * 100.0;
            thisCountry->total = currT;
            // Print out the processed data
            printf("%-20s%-10.2f%-10.2f%-10.2f%i\n", thisCountry->countryName, thisCountry->percentL6, thisCountry->percentL7, thisCountry->percentL8, thisCountry->total);
            // Update chosen_country
            strcpy(chosen_country, current->recordNode.countryName);
            // Update countryName column
            strcpy(thisCountry->countryName, chosen_country);
            currT = 0;
            currL6 = 0;
            currL7 = 0;
            currL8 = 0;
        }else{
            // If gender is 'T' then add to total
            if(current->recordNode.gender == 'T'){
                currT += current->recordNode.numGrads;
                current = current->next;
                continue;
            }
            // If gender is 'L6' add to currL6
            if(strcmp(current->recordNode.degree, "L6") == 0){
                currL6 += current->recordNode.numGrads;
            }
            // If gender is 'L7' add to currL7
            else if(strcmp(current->recordNode.degree, "L7") == 0){
                currL7 += current->recordNode.numGrads;
            }
            // If gender is 'L6' add to currL8
            else if(strcmp(current->recordNode.degree, "L8") == 0){
                currL8 += current->recordNode.numGrads;
            }else{
                printf("Error\n");
            }
        }
        current = current->next;
    }
    // Process and print out the last processed data row
    thisCountry->percentL6 = (float)currL6 / currT * 100.0 ;
    thisCountry->percentL7 = (float)currL7 / currT * 100.0;
    thisCountry->percentL8 = (float)currL8 / currT * 100.0;
    thisCountry->total = currT;
    printf("%-20s%-10.2f%-10.2f%-10.2f%i\n", thisCountry->countryName, thisCountry->percentL6, thisCountry->percentL7, thisCountry->percentL8, thisCountry->total);
    free(thisCountry);
}
