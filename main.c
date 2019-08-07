//  Hurricane Data Organizer
//  Created by Milan Patel on 4/11/18.
//  Copyright © 2018 Milan Patel. All rights reserved.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE_LEN 80
#define MAX 30

void alphabet(char *year[21][80],char *name[21][80],char *state[21][80]);  //Declare function alphabet
void date(char *year[21][80],char  *name[21][80],char *state[21][80]);        //Delcare function year

int
main(void)
{
    char line[MAX][LINE_LEN];
    FILE *inp = NULL;
    int i = 0;
    char *year[MAX][LINE_LEN];
    char *name[MAX][LINE_LEN];
    char *state[MAX][LINE_LEN];
    inp = fopen("hurricanedata.txt", "r");          // open data file
    while(fgets(line[i], LINE_LEN, inp)) {
        line[i][strlen(line[i]) - 1] = '\0';        // copy data from file
        i++;
    }
   

    for(i=0;i<21;i++){
        sscanf(line[i], "%s%s%s", year[i],name[i],state[i]); //split data into mutiple arrays
    }
        int answer = 0;
    
   
    do {
    printf("Do you want to sort by year(1) or alphabetical(2) or finished(3)? ");
    scanf("%d", &answer);
    
    
    // send to sort alphabetically or by year
    if(answer == 1)
    {
        date(year, name, state);
    }
    if(answer == 2)
    {
        alphabet(year, name, state);
    }
    
    rewind(inp);
    } while(answer != 3);
    
    fclose(inp);
    return (0);
}
  


void alphabet(char *year[21][80], char *name[21][80], char *state[21][80])
{
    int step, i;
    char temp[20], temp2[20], temp3[20];
    for(step=0;step<21-1;++step)            //bubble sort
        for(i=0;i<21-step-1;++i)
        {
            if((strncmp(name[i], name[i+1], 5) >0))
            {
                strcpy(temp , year[i]);
                strcpy(year[i] , year[i+1]);
                strcpy(year[i+1] ,temp);
                
                strcpy(temp2 , name[i]);
                strcpy(name[i] , name[i+1]);
                strcpy(name[i+1] ,temp2);
                
                strcpy(temp3 , state[i]);
                strcpy(state[i] , state[i+1]);
                strcpy(state[i+1] ,temp3);
            }
        }
    printf("\nYear\t\tName\t\t\tStates \n");            //Display Sorted Results
    printf("----\t\t-------\t\t\t--------\n");
    for(i=0;i<21;++i){
        if(strlen(name[i])<4)
        {
            printf("%s\t\t%s\t\t\t\t%s\n",year[i],name[i],state[i]);
        }
        else
        {
            printf("%s\t\t%s\t\t\t%s\n",year[i],name[i],state[i]);
        }
    }
    return;
}


void date(char *year[21][80], char *name[21][80], char *state[21][80])
{
    int step, i;
    char temp[20], temp2[20], temp3[20];
    for(step=0;step<21-1;++step)            //bubble sort
        for(i=0;i<21-step-1;++i)
        {
            if((strncmp(year[i], year[i+1], 4) >0))
            {
                strcpy(temp , year[i]);
                strcpy(year[i] , year[i+1]);
                strcpy(year[i+1] ,temp);
                
                strcpy(temp2 , name[i]);
                strcpy(name[i] , name[i+1]);
                strcpy(name[i+1] ,temp2);
                
                strcpy(temp3 , state[i]);
                strcpy(state[i] , state[i+1]);
                strcpy(state[i+1] ,temp3);
            }
        }
    printf("\nYear\t\tName\t\t\tStates \n");            //Display Sorted Results
    printf("----\t\t-------\t\t\t--------\n");
    for(i=0;i<21;++i){
        if(strlen(name[i])<4)
        {
            printf("%s\t\t%s\t\t\t\t%s\n",year[i],name[i],state[i]);
        }
        else
        {
            printf("%s\t\t%s\t\t\t%s\n",year[i],name[i],state[i]);
        }
    }
    return;
}
