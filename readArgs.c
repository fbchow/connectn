#include "readArgs.h"
#include <stdio.h>
#include <stdlib.h>

int readArgs(int argc, char** argv, int num){
    int numObj = 0;
    

        if(argc < 4){
            printf("Not enough arguments entered\n");
            printf("Usage ./connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
            exit (0);
        }
        else if(argc > 4){
            printf("Too many arguments entered\n");
            printf("Usage ./connectn.out num_rows num_cols number_of_pieces_in_a_row_needed_to_win\n");
            exit (0);
        }
    
    
    else {
    //FIXME:
    printf("test point");
    printf("%d", argc);
    //FIXME:
    numObj = atoi(argv[num]);   //converts the string argument into an integer argument
    printf(%d, numObj);
    }
    
    return numObj;
}
