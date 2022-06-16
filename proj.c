//spellcheck-off
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "proj.h"

void main() {
    //creating a pointer to the file
    FILE *f = fopen("proj.txt", "r");
    char str[2][100];
    if(f==NULL)
	{
		puts("File does not exist.\n");
        exit(0);
	}
    //copying the string from the file
    for(int i=0; i<2; i++)
    {
        strcpy(str[i],fgets(str[i],100,f));
    }
    // printf("%s%s\n",str[0],str[1]);
	fclose(f);
    int a;
    bool temp = true;
    char bla[255];
    //creating a pointer to the write function
    void (*wp)(char[]) = write;
    //string manipulation
    while(temp)
    {
        printf("-----------------------------------------------------------\n");
        printf("What do you want to do with this file?\n");
        printf("Enter 1 to store the length of 2 strings to the file.\n");
        printf("Enter 2 to store the concatenated string of 2 strings to the file.\n");
        printf("Enter 3 to store comparison of both strings to the file.\n");
        printf("Enter 4 to store 2 strings as lower case to the file.\n");
        printf("Enter 5 to store 2 strings as upper case to the file.\n");
        printf("Enter 6 to store reverse of both strings to the file.\n");
        printf("Enter any other 'char' to exit.\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                //strlen returns the length of a string
                
                snprintf(bla, sizeof(bla), "Length of first string is %d\nLength of second string is %d",strlen(str[0]),strlen(str[1]));
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            case 2:
            {
                //strcat returns the concatenated string of the 2 strings
                snprintf(bla, sizeof(bla), "The concatenated string is %s\n",strcat(str[0],str[1]));
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            case 3:
            {
                //strcmp returns the difference between 2 strings
                int a=strcmp(str[0],str[1]);
                strcpy(bla,"The comparison of both strings.\n");
                if(a < 0) {
                    strcat(bla,"first string is less than second string\n");
                    } else if(a > 0) {
                    strcat(bla,"second string is less than first string\n");
                    } else {
                    strcat(bla,"first string is equal to second string\n");
                    }
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            case 4:
            {
                //strlwr returns the lower case version of given string
                snprintf(bla, sizeof(bla), "Both strings in lower case.\n%s%s\n",strlwr(str[0]),strlwr(str[1]));
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            case 5:
            {
                //strupr returns the upper case version of given string
                snprintf(bla, sizeof(bla),"Both strings in upper case.\n%s%s\n",strupr(str[0]),strupr(str[1]));
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            case 6:
            {
                //strrev returns the reverse of string
                snprintf(bla, sizeof(bla), "The reverse of both strings.\n%s%s\n",strrev(str[0]),strrev(str[1]));
                wp(bla);
                printf("string stored successfully\n");
                printf("-----------------------------------------------------------\n");
                break;
            }
            default:
            {
                //exits the program
                printf("The program has been terminated.\n");
                printf("-----------------------------------------------------------\n");
                fclose(f);
                temp=false;
                break;
            }
        }
    }
}