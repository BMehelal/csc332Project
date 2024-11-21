#include "Exit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// this function will call the `print_directory` and the `print_last_commands` functions and will wait for the user to hit the “return” key.
int exit_shell(){
  // Print directory contents
  // if (print_directory() == -1) {
  //     return -1;
  // }

  // Print last commands
  if (print_last_commands() == -1) {
      return -1;
  }

  // Wait for return key
  printf("\nPress Enter to exit...");
  while (getchar() != '\n');
  getchar();

  // Exit the shell
  exit(0);
  return 0;
  return 0;
}

// this function will print the contents of the directory by doing `ls -l`
int print_directory(){


  return 0;
}


// this function will print the last few commands by doing `history | tail -n 3`
int print_last_commands(){
  printf("\nLast Few Commands:\n");

  // Execute history command and capture last 3 commands
  if (system("history | tail -n 3") == -1) {
      perror("Problem executing history command");
      return -1;
  }

  return 0;
}



