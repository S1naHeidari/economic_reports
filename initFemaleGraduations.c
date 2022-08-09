#include "defs.h"

void initFemaleGraduations(ListType* gRecords){
    NodeType *current;
    current = gRecords->head;
    char chosen_country[20];
    strcpy(chosen_country, current->recordNode.countryName);
    FemaleGrads *thisCountry = (FemaleGrads*) malloc(sizeof(FemaleGrads));
    FemaleGrads *top = (FemaleGrads*) malloc(5*sizeof(FemaleGrads));
    FemaleGrads *low = (FemaleGrads*) malloc(5*sizeof(FemaleGrads));

    int i;
    // Initialize top and low arrays
    for(i = 0; i<5; i++){
        strcpy(top[i].countryName, "");
        top[i].percentage = -1;
    }
    for(i = 0; i<5; i++){
        strcpy(low[i].countryName, "");
        low[i].percentage = 101;
    }
    strcpy(thisCountry->countryName, chosen_country);
    //current = current->next;
    int currT = 0, currPercantage = 0, tempP;

    //printf("%s", current->recordNode.countryName);


    while(current->next != NULL){
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            //printf("%d %d\n", currL6, currT);
            tempP = (float) currPercantage / currT * 100.0;
            //printf("%d\n", tempP);
            thisCountry->percentage = tempP;
            // Check if tempP is bigger than any of the top 5 countries
            for(i = 0; i<5; i++){
                //printf("%s %d\n", thisCountry->countryName, thisCountry->percentage);
                if(tempP > top[i].percentage){
                    top[i].percentage = tempP;
                    strcpy(top[i].countryName, chosen_country);
                    break;
                }
            }
            // Check if tempP is lower than any of the lowest 5 countries
            for(i = 0; i<5; i++){
                //printf("%s %d\n", thisCountry->countryName, thisCountry->percentage);
                if(tempP < low[i].percentage){
                    //printf("hello\n");
                    low[i].percentage = tempP;
                    strcpy(low[i].countryName, chosen_country);
                    break;
                }
            }
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            currT = 0;
            currPercantage = 0;
        }else{
            if(current->recordNode.gender == 'T'){
                currT += current->recordNode.numGrads;
                current = current->next;
                continue;
            }
            else if(current->recordNode.gender == 'F'){
                currPercantage += current->recordNode.numGrads;
            }
        }
        current = current->next;
    }
    printf("%-20s%-30s\n", "Country", "Female Graduates Percentage");
    for(i = 0; i<5; i++){
        printf("%-20s%-30lf\n", top[i].countryName, top[i].percentage);
    }

    printf("%-20s%-30s\n", "Country", "Female Graduates Percentage");
    for(i = 0; i<5; i++){
        printf("%-20s%-30lf\n", low[i].countryName, low[i].percentage);
    }
    free(thisCountry);
    free(top);
    free(low);
}
