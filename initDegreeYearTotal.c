#include "defs.h"

void initDegreeYearTotal(ListType* gRecords){
    /*
        This will print out total graduates in a certain year for each degree.
    */
    int i, thisYear, currTotal = 0;
    char chosenCountry[20], chosenDegree[3];
    NodeType *current;
    current = gRecords->head;
    TotalForDegree *thisDegree = (TotalForDegree*) malloc(sizeof(TotalForDegree));
    // thisDegree is a key associated to degree in TotalForDegree
    strcpy(thisDegree->degree, current->recordNode.degree);
    thisDegree->total = 0;
    strcpy(chosenDegree, current->recordNode.degree);
    // thisYear is also a key associated to year in TotalForDegree
    strcpy(chosenDegree, current->recordNode.degree);
    // chosenCountry is a key associated to degree in TotalForDegree
    strcpy(chosenCountry, current->recordNode.countryName);
    // We want to add something to this while so it know when the degree changes
    while(current->next !=NULL){
        // If the degree changes, just continue the iteration
        if(strcmp("L6", current->recordNode.degree) != 0){
            current = current->next;
            continue;
        }
        // If the degree is L6
        if(strcmp(current->recordNode.degree, "L6") == 0){
            // If the chosenCountry is not the same as this record's countryName
            if(strcmp(chosenCountry, current->recordNode.countryName) != 0){
                printf("%-20s%-20s%-10d\n", current->recordNode.degree, chosenCountry, currTotal);
                strcpy(chosenCountry, current->recordNode.countryName);
                currTotal = 0;
            }else{
                if(current->recordNode.gender == 'T'){
                    currTotal += current->recordNode.numGrads;
                }
            }
        }
        current = current->next;
    }
    current = gRecords->head;
    // thisYear is also a key associated to year in TotalForDegree
    strcpy(chosenDegree, current->recordNode.degree);
    // chosenCountry is a key associated to degree in TotalForDegree
    strcpy(chosenCountry, current->recordNode.countryName);
    currTotal = 0;
    while(current->next !=NULL){
        if(strcmp("L7", current->recordNode.degree) != 0){
            current = current->next;
            continue;
        }
        // If the degree is L6
        if(strcmp(current->recordNode.degree, "L7") == 0){
            if(strcmp(chosenCountry, current->recordNode.countryName) != 0){
                printf("%-20s%-20s%-10d\n", current->recordNode.degree, chosenCountry, currTotal);
                strcpy(chosenCountry, current->recordNode.countryName);
                currTotal = 0;
            }else{
                if(current->recordNode.gender == 'T'){
                    currTotal += current->recordNode.numGrads;
                }
            }

        }
        current = current->next;
    }

    current = gRecords->head;
    strcpy(chosenDegree, current->recordNode.degree);
    strcpy(chosenCountry, current->recordNode.countryName);
    currTotal = 0;

    while(current->next !=NULL){
        if(strcmp("L8", current->recordNode.degree) != 0){
            current = current->next;
            continue;
        }
        // If the degree is L6
        if(strcmp(current->recordNode.degree, "L8") == 0){
            if(strcmp(chosenCountry, current->recordNode.countryName) != 0){
                printf("%-20s%-20s%-10d\n", current->recordNode.degree, chosenCountry, currTotal);
                strcpy(chosenCountry, current->recordNode.countryName);
                currTotal = 0;
            }else{
                if(current->recordNode.gender == 'T'){
                    currTotal += current->recordNode.numGrads;
                }
            }
        }
        current = current->next;
    }
}
