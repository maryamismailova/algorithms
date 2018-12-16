#ifndef BOO
#define BOO
#include <stdio.h>
#include <stdlib.h>

typedef struct dijkstra{
  int nbvertices;
  int s,d;
  int **weights;
  int *distances;
  int *predecessor;
} dijkstra;

/*Read an inputfile, of format 
numberOfVertices startPoint DestinationPoint
cost cost cost ....
.....
....

then store all the information inside dijkstra structure
call functions findDistance and findPath to find the distance and path
*/
dijkstra *initializeDijkstra( const char *inputfile);

/*returns the distance to the destination point*/
int findDistance(dijkstra *dj);

/*return array of size of number of vertices,to read in reverse order
Call this function AFTER a call to findDistance()*/
int *findPath(dijkstra *dj);

#endif