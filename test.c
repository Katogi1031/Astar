#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    struct node* parentNode;
    struct point* pnt;
    int g;
    int h;
    int f;
} node;

typedef struct{
    int x;
    int y;
} point;




void astar(int maze[8][8], int *start, int *end, int len){
    printf("%d", len);
    //Node start_node = {'\0', *start, 0, 0, 0};
    //int len = sizeof(start) / sizeof(int);

    /* スタートノードの作成・初期化 */
    struct node* sn = (struct node*)malloc(sizeof(struct node));
    struct point* sp = (struct point*)malloc(sizeof(struct point));
    sp->x = start[0], sp->y = start[1];
    sn->pnt = sp, sn->parentNode = Null, sn->g=sn->h=sn->g=0;

    /* エンドノードの作成・初期化 */
    struct node* en = (struct node*)malloc(sizeof(struct node));
    struct point* ep = (struct point*)malloc(sizeof(struct point));
    ep->x = end[0], ep->y = end[1];
    en->pnt = ep, eN->parentNode = Null, en->g=en->h=en->g=0;

    
    
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