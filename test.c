#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  struct point* pnt;
  struct node* parentNode;
  int g;
  int h;
  int f;
};
struct point
{
  int x;
  int y;     
};




void astar(int maze[8][8], int *start, int *end, int len){
    printf("%d", len);
    //Node start_node = {'\0', *start, 0, 0, 0};
    //int len = sizeof(start) / sizeof(int);

    struct point* sP = (struct point*)malloc(sizeof(struct point));
    sP->x = start[0],sP->y = start[1];
    struct node* startNode = (struct node*)malloc(sizeof(struct node));
    startNode->pnt = sP,startNode->parentNode = NULL,startNode->g=startNode->h=startNode->f=0;

    //create GOAL_NODE=>gP and set the data...
    struct point* gP = (struct point*)malloc(sizeof(struct point));
    gP->x = end[0],gP->y = end[1];
    struct node* goalNode = (struct node*)malloc(sizeof(struct node));
    goalNode->pnt = gP,goalNode->parentNode = NULL,goalNode->g=goalNode->h=goalNode->f=0;
    
    
  /*
  while sizeof(open_list) / sizeof(int) > 0{

  }
  */
}


int main(void){
  int maze[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
            };

  int start[] = {3, 3};
  int end[] = {7, 5};
  int len = sizeof(start) / sizeof(int);
  //printf("%d\n", len);
  
  astar(maze, start, end, len);

  //printf("%d, %d\n", start[0], start[1]);

  return 0;
}