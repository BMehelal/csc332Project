#include "Path.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// this function will print the current working directory and then write that to a file called path.txt by doing `pwd > path.txt`




/*
path: this new command will print the current directory's path to the terminal and to a  file called  path.txt after creating it.

print current directory path - getcwd();
create path.txt - fopen()
write the current directory path into path.txt - fprintf()

 **/
const int PATH_MAX = 256;
int path(){
  //1
    char cwd[PATH_MAX]; 
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   //2
   FILE *file;
    // Create a file
    file = fopen("path.txt", "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    //3
    //fprintf(file, "This is in the file \n");

    fprintf( file, "Current working dir: %s\n", cwd);

    // Close the file
    fclose(file);
    //perror("Error printing in path.txt");
    return 0;
}