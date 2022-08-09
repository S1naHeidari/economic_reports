#include "defs.h"

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
