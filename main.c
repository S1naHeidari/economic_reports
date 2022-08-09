#include "defs.h"

// l6 dar har sal chand ta fareqoltahsil dashte?
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
        if(strcmp("L6", current->recordNode.degree) != 0){
            current = current->next;
            continue;
        }
        if(strcmp(current->recordNode.degree, "L6") == 0){
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

void initCountryCodes(ListType* gRecords){
    NodeType *current;
    current = gRecords->head;
    char chosen_country[20];
    strcpy(chosen_country, current->recordNode.countryName);
    CountryCodes *thisCountry = (CountryCodes*) malloc(sizeof(CountryCodes));
    int i;
    strcpy(thisCountry->countryCode, current->recordNode.countryCode);
    strcpy(thisCountry->countryName, current->recordNode.countryName);
    printf("%-20s%-20s\n", "Country Code", "Country Name");
    while(current->next != NULL){
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            printf("%-20s%-20s\n", thisCountry->countryCode, thisCountry->countryName);
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            strcpy(thisCountry->countryCode, current->recordNode.countryCode);
        }
        current = current->next;
    }
    free(thisCountry);
}

void initYearPercentages(ListType* gRecords){
    NodeType *current;
    current = gRecords->head;
    char chosen_country[20];
    strcpy(chosen_country, current->recordNode.countryName);
    YearGrads *thisCountry = (YearGrads*) malloc(sizeof(YearGrads));

    strcpy(thisCountry->countryName, current->recordNode.countryName);
    //current = current->next;
    int currT = 0, curr2014 = 0, curr2015 = 0, curr2016 = 0, curr2017 = 0;
    //printf("%s", current->recordNode.countryName);
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Country", "2014", "2015", "2016", "2017");
    while(current->next != NULL){
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            //printf("%d %d\n", currL6, currT);
            thisCountry->percent2014 = (float)curr2014 / currT * 100.0;
            thisCountry->percent2015 = (float)curr2015 / currT * 100.0;
            thisCountry->percent2016 = (float)curr2016 / currT * 100.0;
            thisCountry->percent2017 = (float)curr2017 / currT * 100.0;
            printf("%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", thisCountry->countryName, thisCountry->percent2014, thisCountry->percent2015, thisCountry->percent2016,
                   thisCountry->percent2017);
            //printf("Country", thisCountry->countryName, thisCountry->total);
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            currT = 0;
            curr2014 = 0;
            curr2015 = 0;
            curr2016 = 0;
            curr2017 = 0;
        }else{
            if(current->recordNode.gender == 'T'){
                currT += current->recordNode.numGrads;
                current = current->next;
                continue;
            }
            if(current->recordNode.year == 2014){
                curr2014 += current->recordNode.numGrads;
            }
            else if(current->recordNode.year == 2015){
                curr2015 += current->recordNode.numGrads;
            }
            else if(current->recordNode.year == 2016){
                curr2016 += current->recordNode.numGrads;
            }
            else if(current->recordNode.year == 2017){
                curr2017 += current->recordNode.numGrads;
            }
        }
        current = current->next;
    }
    thisCountry->percent2014 = (float)curr2014 / currT * 100.0;
    thisCountry->percent2015 = (float)curr2015 / currT * 100.0;
    thisCountry->percent2016 = (float)curr2016 / currT * 100.0;
    thisCountry->percent2017 = (float)curr2017 / currT * 100.0;
    printf("%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", thisCountry->countryName, thisCountry->percent2014, thisCountry->percent2015, thisCountry->percent2016,
           thisCountry->percent2017);
    free(thisCountry);
}

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

void initDegreePercentages(ListType* gRecords){
    NodeType *current;
    current = gRecords->head;
    char chosen_country[20];
    strcpy(chosen_country, current->recordNode.countryName);
    DegreePercent *thisCountry = (DegreePercent*) malloc(sizeof(DegreePercent));
    strcpy(thisCountry->countryName, current->recordNode.countryName);
    //current = current->next;
    int currT = 0, currL6 = 0, currL7 = 0, currL8 = 0;
    //printf("%s", current->recordNode.countryName);
    printf("%-20s%-10s%-10s%-10s%-10s\n", "Country", "L6", "L7", "L8", "Total");

    while(current->next != NULL){
        if(strcmp(current->recordNode.countryName, chosen_country) != 0){
            //printf("%d %d\n", currL6, currT);
            thisCountry->percentL6 = (float)currL6 / currT * 100.0 ;
            thisCountry->percentL7 = (float)currL7 / currT * 100.0;
            thisCountry->percentL8 = (float)currL8 / currT * 100.0;
            thisCountry->total = currT;
            printf("%-20s%-10.2f%-10.2f%-10.2f%i\n", thisCountry->countryName, thisCountry->percentL6, thisCountry->percentL7, thisCountry->percentL8, thisCountry->total);
            //printf("Country", thisCountry->countryName, thisCountry->total);
            strcpy(chosen_country, current->recordNode.countryName);
            strcpy(thisCountry->countryName, chosen_country);
            currT = 0;
            currL6 = 0;
            currL7 = 0;
            currL8 = 0;
        }else{
            //printf("%c\n", current->recordNode.gender);
            if(current->recordNode.gender == 'T'){
                currT += current->recordNode.numGrads;
                current = current->next;
                continue;
            }
            //printf("Hello");
            if(strcmp(current->recordNode.degree, "L6") == 0){
                //printf("%s %d\n", current->recordNode.countryCode, current->recordNode.year);
                currL6 += current->recordNode.numGrads;
            }
            else if(strcmp(current->recordNode.degree, "L7") == 0){
                //printf("%s %d\n", current->recordNode.countryCode, current->recordNode.year);
                currL7 += current->recordNode.numGrads;
            }
            else if(strcmp(current->recordNode.degree, "L8") == 0){
                //printf("%s %d\n", current->recordNode.countryCode, current->recordNode.year);
                currL8 += current->recordNode.numGrads;
            }else{
                printf("Error\n");
            }
        }
        current = current->next;
    }
    thisCountry->percentL6 = (float)currL6 / currT * 100.0 ;
    thisCountry->percentL7 = (float)currL7 / currT * 100.0;
    thisCountry->percentL8 = (float)currL8 / currT * 100.0;
    thisCountry->total = currT;
    printf("%-20s%-10.2f%-10.2f%-10.2f%i\n", thisCountry->countryName, thisCountry->percentL6, thisCountry->percentL7, thisCountry->percentL8, thisCountry->total);
    free(thisCountry);
}
void initData(ListType* gRecords){

    // open inputexample file.
    FILE *fp = fopen("grad.dat", "r");
    if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }
    // Read lines from a text file using our own a portable getline implementation
    int i, ctl = 0, character = 0, recordCount = 0;
    char *line = NULL;
    size_t len = 0;
    char columns[6][20], tempChar, *tempString;
    NodeType *current;
    RecordType *thisRecord;
    /*
        The while loop which reads grad.dat data file line by line.
        It stops iterating when reached EOF. You can see the implemention of my_getline in "getline.h" header
    */
    while(my_getline(&line, &len, fp) != -1){

        // Split the lines by space
        for(i = 0; i < strlen(line); i++){
            // If we're outside of the word
            if(line[i]==' ' || line[i] == '\n'){
                columns[ctl][character] = '\0';
                ctl++;
                character = 0;
            // If we're inside the word
            }else{
                if(line[i] == '\0'){
                    break;
                }
                columns[ctl][character] = line[i];
                character++;
            }
        }
        ctl = 0;
        character = 0;

        //NodeType newNode = (NodeType*) malloc(sizeof(NodeType));
        // Allocate a RecordType for the record that this line contains
        thisRecord = (RecordType*) malloc(sizeof(RecordType));
        // Init records based on splited columns
        strcpy(thisRecord->countryCode, columns[0]);
        strcpy(thisRecord->countryName, columns[1]);
        strcpy(thisRecord->degree, columns[3]);
        tempString = columns[2];
        tempChar = tempString[0];
        thisRecord->gender = tempChar;
        thisRecord->year = atoi(columns[4]);
        thisRecord->numGrads = atoi(columns[5]);
        // Allocate a new node for this record
        NodeType *newNode = (NodeType*) malloc(sizeof(NodeType));
        newNode->recordNode = *thisRecord;
        newNode->next = newNode->prev = NULL;
        // If the linked list is empty
        if(gRecords->head == NULL){
            gRecords->head = newNode;
            gRecords->tail = newNode;
            gRecords->head->prev = NULL;
        // If the linked list is not empty, then, Add the record to the end of linked list
        }else{
            current = gRecords->head;
            while(current->next !=NULL){
                current = current->next;
            }
            gRecords->tail = newNode;
            newNode->prev = current;
            current->next = newNode;
        }

        /* Test
        for(i = 0; i<6; i++){
            printf("%s ", columns[i]);
        }
        printf("\n");
        */
        recordCount++;

    }
    fclose(fp);
}
int main(){

    ListType *records = (ListType*) malloc(sizeof(ListType));
    records->head = NULL;
    records->tail = NULL;
    initData(records);
    /* Test
    NodeType *current;
    current = records->head;
    while(current->next !=NULL){
        printf("%s %s %c %s %d %d\n", current->recordNode.countryCode, current->recordNode.countryName, current->recordNode.gender, current->recordNode.degree, current->recordNode.year, current->recordNode.numGrads);
        current = current->next;
    }
    */
    char choice;
    printf("Welcome to program, Enter your choice report:\n\n");
    printf("\t1. The graduate percantage in all degrees for each country\n");
    //initDegreePercentages(records);
    printf("\n\t2. Top and lowest countries in number of graduates\n");
    //initFemaleGraduations(records);
    printf("\n\t3. All female percantage in all degrees for each year for females\n");
    //initYearPercentages(records);
    printf("\n\t4. The simple but useful record of countries in data set and their associated code\n");
    //initCountryCodes(records);
    printf("\n\t5. Total of graduates in every country for each degree\n");
    //initDegreeYearTotal(records);
    printf("\n\t6. Exit\n");

    scanf("%c", &choice);
    do{
        if(choice == '1'){
            initDegreePercentages(records);
        }else if(choice == '2'){
            initFemaleGraduations(records);
        }else if(choice == '3'){
            initYearPercentages(records);
        }else if(choice == '4'){
            initCountryCodes(records);
        }else if(choice == '5'){
            initDegreeYearTotal(records);
        }else{
            printf("Invalid input!\n");
        }
        printf("Enter your choice report:\n\n");
        printf("\t1. The graduate percantage in all degrees for each country\n");
        //initDegreePercentages(records);
        printf("\n\t2. Top and lowest countries in number of graduates\n");
        //initFemaleGraduations(records);
        printf("\n\t3. All female percantage in all degrees for each year for females\n");
        //initYearPercentages(records);
        printf("\n\t4. The simple but useful record of countries in data set and their associated code\n");
        //initCountryCodes(records);
        printf("\n\t5. Total of graduates in every country for each degree\n");
        //initDegreeYearTotal(records);
        printf("\n\t6. Exit\n");
        scanf(" %c", &choice);
    }while(choice != '6');

    free(records);

}
