#include "defs.h"

void initCountryCodes(ListType* gRecords){
    // Create a NodeType pointer
    NodeType *current;
    // Store the head of gotten list in it
    current = gRecords->head;

    char chosen_country[20];
    // Store the first country as the chosen country to process
    strcpy(chosen_country, current->recordNode.countryName);
    // Allocate memory for a temperory CountryCodes type
    CountryCodes *thisCountry = (CountryCodes*) malloc(sizeof(CountryCodes));
    int i;
    // Init thisCountry
    strcpy(thisCountry->countryCode, current->recordNode.countryCode);
    strcpy(thisCountry->countryName, current->recordNode.countryName);
    printf("%-20s%-20s\n", "Country Code", "Country Name");
    while(current->next != NULL){
        // If the country has changed in this iteration
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            // Print out the processed data
            printf("%-20s%-20s\n", thisCountry->countryCode, thisCountry->countryName);
            // Update chosen country and thisCountry
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            strcpy(thisCountry->countryCode, current->recordNode.countryCode);
        }
        // Go to the next record
        current = current->next;
    }
    free(thisCountry);
}
