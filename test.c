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




void astar(int maze[8][8], int *start, int *end){

    /* スタートノードの作成・初期化 */
    struct point* sP = (struct point*)malloc(sizeof(struct point));
    sP->x = start[0],sP->y = start[1];
    struct node* startNode = (struct node*)malloc(sizeof(struct node));
    startNode->pnt = sP,startNode->parentNode = NULL,startNode->g=startNode->h=startNode->f=0;

    /* エンドノードの作成・初期化 */
    struct point* gP = (struct point*)malloc(sizeof(struct point));
    gP->x = end[0],gP->y = end[1];
    struct node* goalNode = (struct node*)malloc(sizeof(struct node));
    goalNode->pnt = gP,goalNode->parentNode = NULL,goalNode->g=goalNode->h=goalNode->f=0;
    

    /* オープンリストの作成 */
    struct node **openList = (struct node**)malloc(sizeof(struct node*));
    *openList = NULL
    /* クローズリストの作成 */
    struct node **closedList = (struct node**)malloc(sizeof(struct node*));
    *closedList = NULL
    printf("%d %d\n", goalNode->pnt->x, goalNode->pnt->y);
    
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
  
  astar(maze, start, end);

  //printf("%d, %d\n", start[0], start[1]);

  return 0;
}