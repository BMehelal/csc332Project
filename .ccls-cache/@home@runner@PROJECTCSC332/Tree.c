#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Tree.h"

// Check for windows
#ifdef _WIN32
  #include <direct.h> // For mkdir
//changes mkdir to windows version
  #define mkdir(path, mode) _mkdir(path)
#else
  #include <unistd.h> // For mkdir
#endif


// this function will create a directory called `Dir0` by doing `mkdir Dir0`. Then creating a directory inside `Dir0` called `Dir1` by doing `mkdir Dir0/Dir1`
int tree(){
  //set our folder locations
  const char *dir0= "Dir0";
  const char *dir1 = "Dir0/Dir1";
//make the directory, check the return value, 0 is a success, -1 is a failure
  if (mkdir(dir0,0777) ==-1){
    //print failure
    perror("Problem creating director");
  }
  else{
    //print success
    printf("'%s' created. \n",dir0);
  }

  if (mkdir(dir1,0777) ==-1){
    perror("Problem creating directory");
  }
  else{
    printf("Directory '%s' created. \n",dir1);
  }
  return 0;
}