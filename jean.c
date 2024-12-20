#include <stdio.h>
#include <string.h>


int main(){

    char option1[4] = "Yes";
    char name[9] = "Jeanique";
    char input[4];

    printf("I selected our page name %s", name);
    printf("\nyou like this name just answer it in 'Yes' or 'No': ");
    scanf("%s", &input);

    if ( input == "Yes", "yes" )
    {
        printf("\nOk now we are good to go");
    }else{
        printf("\nF**K of!!!!");
    }
    
}