#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

int numberOfNodes = 0;
int matrix[1000][1000];


/*displays initial values fetched from text file*/
void displayInitialValues(){
  int i;
  int j;
  printf("\n-----------------Dijikstra Details---------------\n");
  printf("Number of Nodes: %d\n", numberOfNodes);
  for(i = 0; i < numberOfNodes; i++){
    for(j = 0; j < numberOfNodes; j++){
      printf("%d  \t", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("-----------------------------------------------\n");
}

/*fetching data from txt file*/
int readFile(char *fileName[]){
  /*printf("---------Reading text file--------\n");*/
  FILE * file;
  size_t len = 0;
  int read;
  char *line = NULL;
  char *token;
  int i = 0;
  int j = 0;
  int var;
  file = fopen(fileName[1], "r");
  /*printf("File Name: %s\n",fileName[1]);*/
  if(file){
    while((read = getline(&line, &len, file)) != -1) {
      numberOfNodes++;
      token = strtok (line, ",");
      while (token != NULL)
      {
        sscanf (token, "%d", &var);
        //sets[i++].weight = var;
        if(var != -99){
          matrix[i][j] = var;
        }
        else{
          matrix[i][j] = INT_MAX;
        }
        token = strtok (NULL, ",");
        j++;
      }
      i++;
      j = 0;
    }
    fclose(file);
    return 1;
  }
  else{
    printf("please check the file name or no such file is present.\n");
  }
  return -1;
}

/*finding the index of minimum distance */
int findIndexOfminDist(int temp[], bool isVisitedArray[])
{
  int minimumDistance = INT_MAX;
  int res;
  int i;
  for(i = 0; i < numberOfNodes ; i++)
    if ((temp[i] <= minimumDistance )  && (isVisitedArray[i] == false)){
      minimumDistance  = temp[i];
      res = i;
    }
  return res;
}

bool foo(bool isVisitedArray[]){
  int i;
  for(i = 0; i < numberOfNodes ; i++)
    if (isVisitedArray[i] == false)
      return false;
  return true;
}

/*Dijikstra logic*/
void dijikstra()
{
  int dist[numberOfNodes];  
  int start = 0;
  bool isVisitedArray[numberOfNodes];
  int i = 0;
  for (i = 0; i < numberOfNodes; i++){
    dist[i] = INT_MAX, isVisitedArray[i] = false;
  }
  dist[start] = 0;
  int distuv = 0;
  int newdist = 0;
  while(!foo(isVisitedArray))
  {
    int j = findIndexOfminDist(dist, isVisitedArray);
    isVisitedArray[j] = true;
    for (int k = 0; k < numberOfNodes; k++){
      distuv = matrix[j][k];
      if(j != k && distuv != INT_MAX && dist[j] != INT_MAX){
        newdist = dist[j] + distuv;
        if(newdist < dist[k]){
          dist[k] = newdist;
        }
      }
    }
  }

/*Display shortest path from respective nodes*/
  printf("\nShortest path from respective nodes:\n\n");
  printf("(Nodes)\t(Distances)\n");
  for (i = 0; i < numberOfNodes; i++){
    if(dist[i] != INT_MAX){
      printf("(S%d):\t%d\n", i, dist[i]);
    }
    else{
      printf("(S%d):\tInfinite(Unreachable)\n", i);
    }
  }
printf("\n");
}

int main(int argc, char *argv[])
{
  if(argc == 2){
    readFile(argv);   /*reads text file*/
    displayInitialValues();
    dijikstra();
  }
  else{
    printf("Only one file name is required.\n");
  }
  return 0;
}
