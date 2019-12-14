#include<stdio.h>
#include<stdlib.h>
struct graph 
{
	int n;
	int indegree;
	int outdegree;
	struct node *link;
};
struct node 
{
	int key;
	struct node *next;
};

void print_Graph(struct graph *graphI[],int ver)
{
	int num,num1,num2;
	struct node *temp;
	struct graph *temp1;
	int i;
	for(i=0;i<ver;i++)
	{
		printf("\n%d : ",i+1);
		temp1=graphI[i];
		if(temp1->link!=NULL)
		{
			temp=temp1->link;
		    while(temp!=NULL)
		   {
		     	printf("%d ",temp->key);
		    	temp=temp->next;
		  }
	   }
	}
}

int check_Mapping(struct graph *graphA[],struct graph *graphB[],int ver)
{
	int i,j,check=0;
	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		{
			if(graphA[i]->indegree==graphB[j]->indegree)
			{
				if(graphA[i]->outdegree==graphB[j]->outdegree)
				{
					check++;
					printf("\nvertex %d of GraphA MAPS to vertex %d of GraphB",i+1,j+1);
				}
			}
		}
	}
	return check;
}

void input_Graph(struct graph *graphI[],int ver)
{
	int num1,num2;
	int i,j,edge;
	for(i=0;i<ver;i++)
	{
		graphI[i]=(struct graph*)malloc(sizeof(struct graph));
		graphI[i]->n=i+1;
		graphI[i]->indegree=0;
		graphI[i]->outdegree=0;
		graphI[i]->link=NULL;
	}
	for(i=0;i<ver;i++)
	{
		for(j=0;j<ver;j++)
		{
			printf("Does Edge exist from %d to %d ",i+1,j+1);
			scanf("%d",&edge);
			if(edge==1)
			{
				
				num1=graphI[i]->outdegree;
				num2=graphI[j]->indegree;
				graphI[i]->outdegree=num1+1;
                graphI[j]->indegree=num2+1;
				struct node *nodeA;
             	nodeA=(struct node*)malloc(sizeof(struct node));
            	nodeA->key=j+1;
            	nodeA->next=NULL;
            	struct node *temp1;
            	temp1=(graphI[i])->link;
            	if(temp1!=NULL)
            	{
            		while(temp1->next!=NULL)
	                temp1=temp1->next;
	                temp1->next=nodeA;     
                }
                else
                     (graphI[i])->link=nodeA;
                
				
			}
		}
	}
}

void main()
{
	int ver,check;
	
	printf("Enter Number of Vertices = ");
	scanf("%d",&ver);
	struct graph *graphA[ver];
	struct graph *graphB[ver];
	printf("Enter GraphA\n");
    input_Graph(graphA,ver);
    printf("Enter GraphB\n");
	input_Graph(graphB,ver);
	printf("Graph A");
	print_Graph(graphA,ver);
	printf("\nGraph B");
	print_Graph(graphB,ver);
	check=check_Mapping(graphA,graphB,ver);
	if(check==ver)
	{
		printf("\nBoth are Congurent");
	}
	else
	printf("Not Congurent");
}
