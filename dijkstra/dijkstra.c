/*
1- get input file and retrieve :
  1 - nb of vertices, start point, endpoint
  2 - write the weights into 2D array
2 - calculate the distances
3 - give the path
struct dijkstra{
  int nbvertices;
  int s,d;
  int **weights;
  int *predecessor;
}
*/
#include "dijkstra.h"
#define INFINITY 100000

dijkstra *initializeDijkstra( const char *inputfile){
  dijkstra *dj=malloc(sizeof(dijkstra));
  FILE *input=fopen(inputfile, "r");
  if(input==NULL)return NULL;
  fscanf(input, "%d", &dj->nbvertices);
  fscanf(input, "%d", &dj->s);//dj->s-=1;
  fscanf(input, "%d", &dj->d);//dj->d-=1;
  dj->weights=calloc(dj->nbvertices, sizeof(int*));
  for(int i=0;i<dj->nbvertices;i++)dj->weights[i]=calloc(dj->nbvertices, sizeof(int));

  for(int i=0;i<dj->nbvertices;i++){
    for(int k=0;k<dj->nbvertices;k++){
      fscanf(input, "%d", &dj->weights[i][k]);
    }
  }

  dj->distances=calloc(dj->nbvertices, sizeof(int));
  for(int i=0; i<dj->nbvertices;i++)dj->distances[i]=INFINITY;

  dj->predecessor=calloc(dj->nbvertices, sizeof(int));
  for(int i=0; i<<dj->nbvertices;i++)dj->predecessor[i]=-1;

  return dj;
}
int findDistance(dijkstra *dj){
  //define array of visited vertices, which are -1 in beginning
  int visited[dj->nbvertices];
  for(int i=0;i<dj->nbvertices;i++)visited[i]=-1;
  //define current as visited
  int current=dj->s;
  visited[current]=0;
  dj->distances[current]=0;

//update the distances from the current to its neighbours
  while(current!=dj->d){
    //update distances
    for(int i=0;i<dj->nbvertices;i++){
      if(visited[i]!=0 && dj->weights[i][current]!=-1){//point is not visited and it can be visited
        if(dj->distances[current]+dj->weights[i][current]<dj->distances[i]){
          dj->distances[i]=dj->distances[current]+dj->weights[i][current];
          dj->predecessor[i]=current;
        }
      }
    }
    //choose next smallest distances
    int smallestDist=INFINITY;
    for(int i=0;i<dj->nbvertices;i++){
        if(visited[i]==-1 && dj->distances[i]<smallestDist){
          smallestDist=dj->distances[i];
          current=i;
        }
    }
    visited[current]=0;
  }
  return dj->distances[dj->d]==INFINITY ? -1:dj->distances[dj->d];
}

int *findPath(dijkstra *dj){
  int *path=calloc(dj->nbvertices, sizeof(int));
  for(int i=0;i<dj->nbvertices;i++)path[i]=-1;
  int nPathIndex=0;
  int current=dj->d;
  while(current!=dj->s){
    path[nPathIndex++]=current;
    current=dj->predecessor[current];
  }
  path[nPathIndex]=current;
  return path;
}