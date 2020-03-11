#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int graph2D[20][20];   //initialize 2D array for the graph
int dense[20];         //initialize 1D array to verify densely connected nodes
int loose[20];         //initialize 1D array to verify loosely connected nodes
int edges[20];
void create2D()
{
    srand(time(0));//use time in the computer as seed for the randomizer
    for( int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)   //double for-loop
        {
            if(j<=i)
            {
                graph2D[i][j]= 0;   //to obtain symmetry , i set value to one half of the graph as zero first
            }
            else{
                graph2D[i][j]= rand()%2;  //the other half will have random values (1 or 0)
            }
        }
    }
     for( int i=0; i<19; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(j<=i)
            {
                graph2D[i][j]= graph2D[j][i];   //to complete the symmetry , i set the value to the half of the graph as the first half but in the reverse order
            }
        }
    }
}
void checkforisolatednodes() //to check if there are any isolated nodes(1 whole vertex of 0s only)
{
   int counter =0; //initialize a counter
    for( int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(graph2D[i][j]==0)
            {
               counter++; //counts up every time there is a zero
            }
            if(j==19){
                if(counter==20){
                    for(int x=i; x<20; x++){
                         graph2D[i][x]= rand()%2;
                    }
                }
                counter = 0;
            }
        }
    }
      for( int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(j<=i)
            {
                graph2D[i][j]= graph2D[j][i];

            }
        }
    }

}
void print2D()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            printf("%d ", graph2D[i][j]);
            if(j==19)
            {
                printf("\n");
            }
        }
    }
}
void onehop()
{
    printf("List of one hop neighbors:");
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(j==0)
            {
                printf("\nVertex %d:",i);
            }
            if(graph2D[i][j]==1)
            {
                printf("%d ",j);
            }
        }
    }
}
void twohop()
{
    printf("List of two-hop neighbors:");
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(j==0)
            {
                printf("\nVertex %d:",i);
            }
            if(graph2D[i][j]==0&&j!=i)
            {
                printf("%d ",j);
            }
        }
    }
}
void calcedge()
{
    printf("Number of edges for each node: \n");
    int counter = 0;
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(graph2D[i][j]==1)
            {
                counter=counter+1;
            }
            if(j==19)
            {
                edges[i]=counter;
                counter=0;
            }
        }
    }
    for(int i=0; i<20; i++)
    {
        printf("vertex %d:%d \n",i, edges[i]);
    }
    for (int i = 0; i < 20; i++)
    {
        dense[i]=edges[i];
        loose[i]=edges[i];
    }
    for (int i = 0; i < 20; i++)
    {
        if (dense[0] < dense[i])
        {
            dense[0] = dense[i];
        }
        if (loose[0] > loose[i])
        {
            loose[0] = loose[i];
        }
    }
    printf("\nDensely connected nodes:\n");
    for (int i = 0; i < 20; i++)
    {
        if (dense[0] == edges[i])
        {
            printf("%d ",i);
        }
    }
    printf("\nLoosely connected nodes:\n");
    for (int i = 0; i < 20; i++)
    {
        if (loose[0] == edges[i])
        {
            printf("%d ",i);
        }
    }
}
void clique(){
    int x,y,z;
    printf("Input 3 vertices (0 to 19)\n");
    printf("\nEnter Vertice[1]:");
    scanf("%d",&x);
    printf("\nEnter Vertice[2]:");
    scanf("%d",&y);
    printf("\nEnter Vertice[3]:");
    scanf("%d",&z);
    printf("\n");
    if(edges[x]==dense[0]||edges[y]==dense[0]||edges[z]==dense[0])
    {
        printf("Yes, nodes %d, %d and %d are one-hop neighbors and form a 3-Clique.\n\n",x,y,z);
    }
    else
    {
        printf("No 3-Clique structure found with nodes %d, %d and %d\n\n",x,y,z);
    }
}
void mainfunction()
{
    char entry = 'a';
    printf("===============================\nWelcome to my Graph Processing tool! \n The adjacent matrix for G: \n");
    create2D();
    checkforisolatednodes();
    print2D();
    printf("\n \n");
    onehop();
    printf("\n=============================== \n \n");
    twohop();
    printf("\n=============================== \n \n");
    calcedge();
    printf("\n===============================\n");
    printf("You can determine a 3-Clique structure, if it exists in your graph;\n");
int inf = 1;
for(int i = 0;i<inf;i++){
        clique();
        printf("Do you wish to try again? (Type Y to continue or Q to quit)\n");
        scanf(" %c",&entry);
        if(entry=='y')
        {
             inf = inf +1;
             entry = 'a';
        }
        if (entry=='q')
        {
            printf("\n\nThank you!\n===============================\n");
        }

}
}

void main()
{
int count=0;
    while(count<3)
    {
        mainfunction();
        count= count+1;
    }
    return;
}
