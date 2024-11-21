#include "List.h"

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


void list()
{

    // clears the terminal screen
    if (system("clear") == -1)
    {
        perror("Problem clearing terminal");
        return;
    }

    // opening current directory
    DIR *dir = opendir("."); // note: "." refers to the current directory
    if (dir == NULL)
    {
        perror("Problem opening directory");
        return;
    }

    // opening tree.txt
    FILE *file = fopen("tree.txt", "w"); // opens file for writing. If exists, overwritten
    if (file == NULL)
    {
        perror("Problem opening file)");
        closedir(dir); // note: closes directory; crucial to avoid memory leaks
        return;
    }

    struct dirent *entry;
    struct stat file_stat;

    printf("Contents of Current Directory: \n");
    fprintf(file, "List of current directory contents: \n");

    // read directory entries and write to file and console
    while ((entry = readdir(dir)) != NULL)
    {
        // skip '.' (current) and '..' (parent) entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // get file stats
        if (stat(entry->d_name, &file_stat) == -1)
        {
            perror("Problem getting file stats");
            continue;
        }

        // print to console -- terminal window
        printf("%s \n", entry->d_name);
        // write to file -- tree.txt
        fprintf(file, "%s \n", entry->d_name);
    }

    closedir(dir);
    fclose(file);

    printf("Output written to tree.txt \n");
}











// // this function clear the terminal screen by doing `system(clear)` and will list the contents of the directory and writing that to a file callled tree.txt by doing `ls -l > tree.txt`
// int list(){

//   return 0;
// }