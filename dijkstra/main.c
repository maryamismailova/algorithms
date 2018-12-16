#include "dijkstra.h"

int main(int argc, char const *argv[]) {
  if(argc!=2)exit(-1);
  dijkstra *dj=initializeDijkstra(argv[1]);
  printf("distance is %d\n", findDistance(dj));
  int *path=findPath(dj);
  for(int i=dj->nbvertices-1;i>=0;i--){
    if(path[i]==-1)continue;
    printf("%d->",path[i]);
  }
  printf("\n");
  return 0;
}
