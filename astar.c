//A* Pathfinding Algorithm Implementation
//Coded by: Ahmet Erdem Ekin
//Start Date:17/2/2013
//End Date:20/2/2013
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static int maze[8][8] = {{  1,  0,  0,  0,  0,  0,  0,  0},
                         {  0,  0, -1, -1, -1, -1,  0,  0},
                         {  0,  0,  0,  0,  0, -1,  0,  0},
                         {  0,  0, -1, -1, -1, -1,  0,  0},
                         {  0,  0, -1,  0,  0,  0,  0,  0},
                         {  0,  0, -1,  0,  0,  0,  0,  0},
                         {  0,  0, -1, -1, -1, -1,  0,  0},
                         {  0,  0,  0,  0,  0, 10,  0,  0}
                        };

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
//------------------------------------------------------------------------------
//the function that operates during path finding process.
struct node* AStarAlgorithm(struct node* current,struct node* goal,struct node **array,int l1,struct node **closed,
int l2);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//the function to find the neighboring nodes.to be called inside AStarAlgorithm
//returns the number of elements inside the array...
//parameters:CURRENT NODE,LIST OF NODES TO BE INSPECTED,LENGTH OF THE LIST
int ExpandNode(struct node* current,struct node **array,int l1,struct node **closed,int l2);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//finds the least total costed node and returns a pointer for that node...
//paramenters:LIST OF NODES TO BE INSPECTED,LENGTH OF THE LIST
int FindTheLeastCosted(struct node **array,int l1);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//calcualtes the total cost of each node in the array...
//parameters: GOAL NODE,LIST OF NODES TO BE INSPECTED,LENGTH OF THE LIST
void CalculateTheTotalCost(struct node* goalNode,struct node **array,int l1);
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//reconstructs the path from the beginning to the goal.prints out the path...
void ReconstructThePath(struct node* goalNode);
//------------------------------------------------------------------------------
int main()
{   
    /* predatorとpreyの位置を格納する領域を確保*/
    struct point* predator = (struct point*)malloc(sizeof(struct point));
    struct point* prey = (struct point*)malloc(sizeof(struct point));

    /* predatorとpreyの位置を特定*/
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            switch(maze[i][j]){
                case 1:
                    
                    predator->x = i;
                    predator->y = j;
                case 10:
                    
                    prey->x = i;
                    prey->y = j;
            }
        }
    }
    
    /* それぞれをスタート位置、ゴール位置とする */
    struct point* sP = (struct point*)malloc(sizeof(struct point));
    sP->x = predator->x, sP->y = predator->y;

    struct node* startNode = (struct node*)malloc(sizeof(struct node));
    startNode->pnt = sP,startNode->parentNode = NULL,startNode->g=0;startNode->h=0, startNode->f=0;

    struct point* gP = (struct point*)malloc(sizeof(struct point));
    gP->x = prey->x,gP->y = prey->y;

    struct node* goalNode = (struct node*)malloc(sizeof(struct node));
    goalNode->pnt = gP,goalNode->parentNode = NULL,goalNode->g=0,goalNode->h=0, goalNode->f=0;

    /* オープンリストの作成 */
    struct node **openList = (struct node**)malloc(sizeof(struct node*));
    *openList = NULL;
    int openIndex = 0;

    /* クローズドリストの作成*/
    struct node **closedList = (struct node**)malloc(sizeof(struct node*));
    *closedList = NULL;

    /* どうやらクローズドリストのメモリ領域をリサイズしているみたい */
    /*
    (*closedList) = (struct node*)realloc((*closedList),sizeof(struct node));
    memcpy(&((*closedList)[0]),startNode,sizeof(struct node));
    */
    

    /* オープンリスト(経路候補)にstartNodeを追加して計算スタート*/
    (*openList) = (struct node*)realloc((*openList),sizeof(struct node));
    memcpy(&((*openList)[0]),startNode,sizeof(struct node));
    openIndex++;

    /* currentNodeを作成 */
    struct node* currentNode = (struct node*)malloc(sizeof(struct node));
    // (*openList) = (struct node*)realloc((*openList),sizeof(struct node));

    /* itemを作成 */
    struct node* item = (struct node*)malloc(sizeof(struct node));
    
    /* オープンリストの中身がなくなるまでループ */
    while (openIndex > 0){
        memcpy(&currentNode[0], &((*openList)[0]), sizeof(struct node));
        int currentIndex = 0;

        for(int i = 0; i < openIndex; i++){
            /* オープンリストないでF値が最小のノードを選択 */
            memcpy(&item[0], &((*openList)[0]), sizeof(struct node));
            // printf("%d\n", item->f);
            if (item->f < currentNode->f){
                memcpy(currentNode, item, sizeof(struct node));
                currentIndex = i;
            }
        }
        /* 最小のF値のノードをオープンリストから削除して、クローズドリストに追加 */
        free(openList[openIndex]);
        openIndex--;
        (*closedList) = (struct node*)realloc((*closedList),sizeof(struct node));
        memcpy(&((*closedList)[0]),currentNode,sizeof(struct node));

        /* ゴールに到達しているかどうか */
        if (currentNode->pnt->x == goalNode->pnt->x && currentNode->pnt->y == goalNode->pnt->y){
            struct point* path = (struct point*)malloc(sizeof(struct point));
            
            struct node* current = (struct node*)malloc(sizeof(struct node));
            memcpy(current, currentNode, sizeof(struct node));

            while (current = '¥0'){
                

            }

        }

        /* ゴールに到達してなければ子ノードを生成 */
        struct node* children = (struct node*)malloc(sizeof(struct node));

        /* 行動する(下、上、左、右) */
        int action[][] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        /* ノードの位置 */
        struct point* nodePosition = (struct point*)malloc(sizeof(struct point));
        for(int i = 0; i < 4; i++){
            /* 移動後の位置を得る */
            // nodePosition = 

            /* コースアウトしていないかのチェック */
            
            /* 障害物を避ける */

            /* 移動できる位置のノードのみ生成 */

            /* 子リストに追加 */
        }

        /* 各子ノードでG, H, Fを計算 */
        for(){
            /* よくわからない処理*/

            /* G, H, Fの処理 */

            /* 子ノードをオープンリストに追加*/

        }

        // openIndex--;
    }
    printf("%d %d\n", item->pnt->x, item->pnt->y);


    
    //create LAST_OBTAINED_NODE=>finished and set it to the result returned from the recursive A_STAR_ALGORITHM_FUNC
    struct node* finished = AStarAlgorithm(startNode,goalNode,openList,0,closedList,1);
    printf("1\n");
    //call RECONSTRUCT_FUNC=>ReconstructThePath with finished as parameter...
    ReconstructThePath(finished);

    //wait for user input...
    getchar();

    /*
    printf("%d %d\n", gP->x, gP->y);
    printf("%d %d\n", gP->x, gP->y);
    */

    
    return 0;   
}
struct node* AStarAlgorithm(struct node* current,struct node* goal,struct node **open,int l1,struct node **closed,int l2)
{
  int i,j,nextIndex;

  //call EXPAND_NODE_FUNC ExpandNode and set LEN_OF_OPEN_LIST to the value returned from that function...
  l1 = ExpandNode(current,open,l1,closed,l2);

  //call CALCULATE_COST=>CalculateTheTotalCost function to set the G_FUNC=>g cost of each element in OPEN_LIST=>array...  
  CalculateTheTotalCost(goal,open,l1);

  //call FIND_LEAST_NODE=>FindTheLeastCosted function to obtain the index of least costed node in the OPEN_LIST=>array...
  nextIndex = FindTheLeastCosted(open,l1);

  struct node *nextNode = &((*open)[nextIndex]);

  //create a new temporary list which is intended to be the next OPEN_LIST=>array
  //without the NEXT_NODE=>nextNode inside.
  struct node *tempArray = (struct node*)calloc(l1-1,sizeof(struct node));
  for(i = 0,j=0;i<l1;i++)
    if(i != nextIndex) memcpy(&tempArray[j],&((*open)[i]),sizeof(struct node)),j++;
  l1--,l2++;
  *open = tempArray;

  //declare NEXT_NODE=>nexNode to be visited by adding the node to the CLOSE_LIST=>closed...
  *closed = (struct node*)realloc((*closed),l2*(sizeof(struct node)));
  memcpy(&((*closed)[l2-1]),nextNode,sizeof(struct node));

  //check whether the NEXT_NODE=>nextNode is the GOAL_NODE=>goal by comparing its coordinates... 
  //if so => return NEXT_NODE=>nextNode
  //else call A_STAR_ALGORITHM_FUNC0>AStarAlgorithm with CURRENT_NODE=>nextNode,
  //GOAL_NODE=>goal, OPEN_LIST=>array, LEN_OPEN_LIST=>l1,CLOSE_LIST=>closed,LeN_CLOSE_LIST=>l2... 
  if(nextNode->pnt->x == goal->pnt->x && nextNode->pnt->y == goal->pnt->y)  return nextNode;
  return AStarAlgorithm(nextNode,goal,open,l1,closed,l2);
}
int ExpandNode(struct node* current,struct node **open,int l1,struct node **closed,int l2)
{   
   int i,j,count,found;
   count = 0;
   //--FIRST-PHASE--:EXPAND ALL THE NEIGHBORING NODES...
   struct node* tempArray;
   tempArray = (struct node*)calloc(8,sizeof(struct node));   
   for(i = 0;i<8;i++)
   {
      tempArray[i].pnt = (struct point*)malloc(sizeof(struct point));
      if(i == 0)  tempArray[i].pnt->x = current->pnt->x-1,tempArray[i].pnt->y = current->pnt->y+1,tempArray[i].g = current->g+1.4;
      else if(i == 1)   tempArray[i].pnt->x = current->pnt->x-1,tempArray[i].pnt->y = current->pnt->y,tempArray[i].g = current->g+1.0f;
      else if(i == 2)   tempArray[i].pnt->x = current->pnt->x-1,tempArray[i].pnt->y = current->pnt->y-1,tempArray[i].g = current->g+1.4f;
      else if(i == 3)   tempArray[i].pnt->x = current->pnt->x,tempArray[i].pnt->y = current->pnt->y+1,tempArray[i].g = current->g+1.0f;
      else if(i == 4)   tempArray[i].pnt->x = current->pnt->x,tempArray[i].pnt->y = current->pnt->y-1,tempArray[i].g = current->g+1.0f;
      else if(i == 5)   tempArray[i].pnt->x = current->pnt->x+1,tempArray[i].pnt->y = current->pnt->y+1,tempArray[i].g = current->g+1.4f;
      else if(i == 6)   tempArray[i].pnt->x = current->pnt->x+1,tempArray[i].pnt->y = current->pnt->y,tempArray[i].g = current->g+1.0f;
      else if(i == 7)   tempArray[i].pnt->x = current->pnt->x+1,tempArray[i].pnt->y = current->pnt->y-1,tempArray[i].g = current->g+1.4f;
      tempArray[i].parentNode = current;
   }

   //--SECOND-PHASE--:check whether current node's children are inside the array.
   //if so, do not include those nodes to the expanded array. 
   for(j = 0;j<8;j++)
   {
      found = 0;           
      for(i = 0;i<l1;i++) if((*open)[i].pnt->x == tempArray[j].pnt->x && (*open)[i].pnt->y == tempArray[j].pnt->y) found++;
      for(i = 0;i<l2;i++) if(tempArray[j].pnt->x == (*closed)[i].pnt->x && (*closed)[i].pnt->y == tempArray[j].pnt->y) found++; 
      //--THIRD-PHASE--:expand the array with the additional neighbors.
      if(found == 0)
      {
        count++;
        int total = (l1+count);
        *open = (struct node*)realloc((*open),total*(sizeof(struct node)));
        memcpy(&((*open)[total-1]),&tempArray[j],sizeof(struct node));              
      }      
   } 
   return count+l1;     
}
void CalculateTheTotalCost(struct node* goalNode,struct node **open,int l1)
{
    int i,difx,dify;
    //h(x,y) calculation...h(x,y) = ((x2-x1)^2 + (y2-y1)^2)^(1/2)
    for(i = 0;i<l1;i++)
    {
        difx = (*open)[i].pnt->x - goalNode->pnt->x;
        dify = (*open)[i].pnt->y - goalNode->pnt->y;
        (*open)[i].h = ((float)sqrt(pow(difx,2) + pow(dify,2)));
    }
}
int FindTheLeastCosted(struct node **open,int l1)
{
    int i,min,minIndex;
    min = (*open)[0].g + (*open)[0].h;
    minIndex = 0;
    for(i= 1;i<l1;i++)
    {
        if((*open)[i].g + (*open)[i].h < min) min = (*open)[i].g + (*open)[i].h,minIndex = i;
    }
    return minIndex;
}
void ReconstructThePath(struct node* goalNode)
{
     struct node* current = goalNode;
     struct point* ptr = NULL;
     int steps = 0,i;
     while(current->parentNode != NULL)
     {
          steps++;
          ptr = (struct point*)realloc(ptr,steps*sizeof(struct point));
          memcpy(&ptr[steps-1],current->pnt,sizeof(struct point));
          current = current->parentNode;                    
     }
     for(i=steps;i>=1;i--)
     {
        printf("(%d,%d)",ptr[i-1].x,ptr[i-1].y);
        if(i>1)  printf("=>");  
     }
}
