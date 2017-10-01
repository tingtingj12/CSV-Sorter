#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record{
    char *data[28];
}Record;

Record splitToken(char *buffer);

int main(){//int argc, char** argv) {
    //if (argc != 2) {
    //    fprintf(stderr, "INVALID INPUT.");
    //    exit(0);
    //}
    FILE *file = fopen("test.csv","r");
    Record row[6000];
    char *buffer;
    size_t buffer_size = 1024;
    buffer = (char*)malloc(sizeof(char)*buffer_size);
    getline(&buffer, &buffer_size, file);
    char *token;
    int row_counter = 0;
    while (!feof(file)) {
	    row[row_counter++] = splitToken(buffer);
        getline(&buffer, &buffer_size, file);
    }

    int i, j = 0;
    for (i = 0; i < 5; i++){
	    for (j = 0; j < 3; j++){
	        printf("%s\n", row[i].data[j]);
	    }
    }
    free(buffer);
    return 0;
}

Record splitToken(char *buffer){
    Record rowOfTokens;
    int char_counter = 0; // parser of buffer[]
    int token_counter = 0;
    char *token;
    int tok_char_counter = 0;
    while (char_counter < strlen(buffer)){
        // NULL tokens
	    if (buffer[char_counter] == ','){
	        if (char_counter == 0){
		        rowOfTokens.data[token_counter] = "";
		        token_counter++;
	        }
	        char_counter++;
            while (buffer[char_counter] == ','){
        	    rowOfTokens.data[token_counter++] = "";
		        char_counter++;
	        }
        }
	    char_counter--;

        token = (char*)malloc((strlen(buffer) - char_counter + 1)*sizeof(char));
        tok_char_counter = 0;
        // white space
        while (buffer[char_counter] == ' '){ //(isspace((unsigned char)buffer[char_counter])){
            char_counter++;
        }
    
        // with quotation mark
        if (buffer[char_counter++] == '\"'){
            while (buffer[char_counter] != '\"'){
                token[tok_char_counter++] = buffer[char_counter++];
            }
        }
        // without quotation mark
        else {
            while (char_counter < strlen(buffer) && buffer[char_counter] != ','){
                token[tok_char_counter++] = buffer[char_counter++];
            }
        }
	    token[tok_char_counter]='\0';
	    rowOfTokens.data[token_counter] = (char*)malloc(strlen(token)+1);
	    //printf("malloc size %d",strlen(token)+1);
        strcpy(rowOfTokens.data[token_counter++], token);
	    //printf("data: %s, counter = %d\n",rowOfTokens.data[token_counter-1],token_counter);
	    //printf("token: %s\n",token);
        free(token);
    }
    int i = 0;
    for (i = 0; i < 3; i++){
	    //printf("%s\n",rowOfTokens.data[i]);
    }
    return rowOfTokens;
}
/*
Record splitToken(char buffer[]){
    Record rowOfTokens;
    char* token, tmp;
    token = strtok(buffer, ',');
    while (token != NULL){
        token = modifyToken(token);

        // check if it has quotation
        int to_be_appended = 0;
        if (hasQuotationMark(token)){
            if (hasQuotationMark(token) == 1) {
                to_be_appended = 1;
            }
        }
    }
}

char* modifyToken(char* token) {
    // get rid of leading white spaces
    while (*token == ' '){
        token = token + 1;
    }

    // get rid of trailing white spaces
    char tmp = (char*)malloc(sizeof(token));
    int counter = 0; //trailing whitespace counter
    while (isspace(*(token + strlen(token) - 1 - counter))){
        counter++;
    }
    // move token without whitespace to a tmp holder for token
    int char_counter = 0;
    for(char_counter = 0; char_counter < strlen(token)-counter; char_counter++){
        tmp[char_counter] = token[char_counter];
    }
    tmp[char_counter] = '\0';
    return tmp;
}

int hasQuotationMark(char *token) {
    // token is NULL
    if (token == NULL){ return -1; }

    // quotation mark is at the beginning of the token
    if (*token == '\"'){ return 1; } 

    // quotation mark is at the end of the token
    if (*(token + str(token) - 1) == '\"'){ return 2; }

    // token is normal
    return 0; 
}*/