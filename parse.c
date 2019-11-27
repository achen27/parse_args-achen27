#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "parse.h"

char ** parse_args( char * line ){
  char *curr = line;
  char ** token = malloc(100);
  int i = 0;
  while(curr != NULL){
    token[i] = strsep(&curr, " ");
    // printf("Token: %s\n", token[i]);
    // printf("Curr: %s\n", curr);
    i++;
  }
  token[i] = NULL;
  return token;
}

int main(){
  char line[100] = "ls -a -l";
  printf("Command: %s\n", line);
  char ** args = parse_args(line);
  // int i = 0;
  // while(args[i] != NULL){
  //   printf("Token: %s\n", args[i]);
  //   i++;
  // }
  printf("Running Command:\n");
  execvp(args[0],args);
  return 0;
}
