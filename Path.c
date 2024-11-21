#include "Path.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Bailey Perillo

/*
path: this new command will print the current directory's path to the terminal and to a  file called  path.txt after creating it.

print current directory path - getcwd();
create path.txt - fopen()
write the current directory path into path.txt - fprintf()

 **/
const int PATH_MAX = 256;
int path(){
  //1
  system("bash -i -c 'echo pwd >> ~/.bash_history'"); // adds command to history
  system("bash -i -c 'echo \"pwd > \\\"path.txt\\\"\" >> ~/.bash_history'"); // adds command to history 
  system("bash -i -c 'history -a'"); // update history immediately
    char cwd[PATH_MAX]; 
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   //2
   // Create a file
   FILE *file  = fopen("path.txt", "w");
   
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "Current working dir: %s\n", cwd);

    // Close the file
    fclose(file);
    //perror("Error printing in path.txt");
    return 0;
}