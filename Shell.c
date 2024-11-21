#include <stdio.h>
#include <string.h>
#include "Path.h"
#include "List.h"
#include "Tree.h"
#include "Exit.h"
// Brandon Mehelal
// THE SHELL
// The shell will be replicated using the main function
int main(void)
{
  char input[5]; // for user input
  // while loop to reprompt user to enter another command--terminating shell if exit command is called
  while (1)
  {
    printf("Enter a command to be executed (tree, list, path, exit): 😜  ");
    scanf("%s", input);
    if (strcmp(input, "tree") == 0)
    {
      // if user input is tree
      printf("The tree command has already been executed.\n");
      tree(); // executes tree command
    }
    else if (strcmp(input, "list") == 0)
    {
      // if user input is list
      printf("The list command has already been executed.\n");
      list(); // executes tree command
    }
    else if (strcmp(input, "path") == 0)
    {
      // if user input is path

      // if tree commmand has already been path
      printf("The path command has already been executed.\n");

      path(); // executes tree command
    }
    else if (strcmp(input, "exit") == 0)
    {
      // if user input is exit
      exit_shell(); // executes exit command
    }
    else
    {
      printf("Invalid command.\n"); // default case if invalid command
    }
  }
}
