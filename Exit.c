#include "Exit.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>

// Waleed Mansour

// this function will call the `print_directory` and the `print_last_commands` functions and will wait for the user to hit the “return” key.
int exit_shell(){
  
  // Print directory contents
  if (print_directory() == -1) {
      return -1;
  }

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
  
    pid_t list_pid = fork(); // creates new child process 
    if(list_pid < 0){
      // error check if child process failed
    perror("list_pid fork failed.\n");
    return 1;
  }
  // child process
  if(list_pid == 0){
    system("bash -i -c 'echo ls -l >> ~/.bash_history'"); // adds command to history
    system("bash -i -c 'history -a'"); // update history immediately
    printf("Contents of Current Directory:\n"); 
    fflush(stdout);
    execlp("ls", "ls", "-l", NULL); // child process executes `ls -l`
    perror("ls execlp failed.\n"); // if execlp failed
    return 1;
  }
  waitpid(list_pid, NULL, 0); // parent process waits for child process
  return 0;
}
// this function will print the last few commands by doing `history | tail -n 7`
int print_last_commands(){
  
  pid_t history_pid = fork(); // creates child process 

  if(history_pid < 0){
    // error check if child process failed
    perror("history_pid fork failed.\n");
    return -1;
  }

  // child process
  if(history_pid == 0){
    printf("The last 8 commands:\n");
    fflush(stdout);
    execlp("bash", "bash", "history.sh", NULL); // executes bash script that gives last 8 commands
    perror("bash execlp failed.\n"); // check if execlp failed
    return -1;
  }

  waitpid(history_pid, NULL, 0); // parent process waits for child process
  return 0;
}



