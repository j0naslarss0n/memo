/* A small memo program to add messages in a csv file.

Author: J. Larsson
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "memo.h"


int main(int argc,char *argv[]){

if ( argc > 3){
    printf("Type \"memo -h\" for help.\n");
}

    // Append a new message to file.
else if (strcmp(argv[1], "-a") ==0)
    {
        append(argv[2]);
    }
    // Display help file.
else if(strcmp(argv[1],"-h") ==0)
    {  
        helpFunc();
    } 

    // init new memo-file
else if(strcmp(argv[1],"-i")==0)
    
	{
        initFunc(argv[2]);
    }    
	
    // Search contents of .csv file.    
else if(strcmp(argv[1],"-s")==0)
    {
        search (argv[2]);
    }
    //delete entries
else if(strcmp(argv [1],"-d")==0)
    {
        //printf("%s", argv[2]);
        delete (argv[2]); 
                  
    }
    // Print whole document
else if (strcmp(argv[1], "-p")== 0)
    {
        print(argv[1]);
    }
    return 0;
}
