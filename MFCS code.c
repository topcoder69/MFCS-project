/*********************************************************************************************
 * 
 * Subject: Mathematical foundations of MFCS
 * Type: Project
 * Created on: 14th November, 2019	11:00pm
 * Place: University of Hyderabad, Hyderabad
 * 
 * A program based on Kruskal's Algorithm to calculate minimum 
 * spanning tree by taking frequently visited places
 * as the nodes of the graph.
 * 
 **********************************************************************************************/


#include <stdio.h>
#include <stdlib.h>			imsahil007/Time-Scheduling-uimsahil007/Time-Scheduling-u		//defined macros for number of places, Maximum cost that will replace 0 values
#define SZ 38						//and Maximum characters in the name of a place
#define MAX 80
#define INFINITY 999

int i=0,j=0,num=SZ,numOfEdges=1,flag=0;
float minDist=0,uVertex=0,vVertex=0,a=0,b=0,minimum=INFINITY;
int parentOfNode[SZ];

void printPlacesMatrix(float places[][SZ], int n){	//printPlacesMatrix(int [][],int) prints all the distances in matrix form
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%.2f\t",places[i][j]);
        }
	printf("\n");
    }
}
void printPlaces(FILE *f2){				//printPlaces(FILE*) lists of all the places in HCU
    char nameOfPlace[MAX];			
    int j=0,i=0;
    printf("\n*****************************************************************************\n");
    while(!feof(f2)){
	    fgets(nameOfPlace,MAX,f2);
            printf("\t\t %s",nameOfPlace);
    }
    printf("\n*****************************************************************************\n");
}
int search(int i) {
    while (parentOfNode[i] != i) i = parentOfNode[i]; 
    return i; 
} 
void join(int i, int j){
    int a = search(i); 
    int b = search(j); 
    parentOfNode[a] = b; 
} 

int main(int argc, char **argv) {
	if(argc!=3){						//since number of arguments will be 3,i.e, the object file,matrix file, 
		printf("\nInvalid number of arguments.\n");	//and names of places file, so if the user enters less than 3 
	        exit(0);					//files, then it will be an invalid input
	}
	FILE *f1=NULL,*f2=NULL;
	f1=fopen(argv[1],"r");
	f2=fopen(argv[2],"r");
	if(f1==NULL || f2==NULL){
	    printf("Unable to open file.\n");
	}
	
	float places[SZ][SZ];
	int parent[SZ];
	
	while(!feof(f1)){
									//input matrix file is stored into a 2D array
	    for(int i=0;i<SZ;i++){					//if the entry contains a zero element, it will be
	        for(int j=0;j<SZ;j++){					//initialised to INFINITY, i.e., 9999 else the
	            fscanf(f1,"%f",&places[i][j]);			//program will take it as a minimum cost edge
	            if(places[i][j]==0){
	                places[i][j]=INFINITY;
	            }
	        }
	    }
	}
	
	printPlaces(f2);	
	printPlacesMatrix(places,SZ);
	
	for (int i = 0; i < SZ; i++) {parentOfNode[i] = i;}

	printf("\n\nEdges of minimum spanning tree using Kruskal's algo are:\n\n");

	while(numOfEdges<num){
		minimum=INFINITY,a=-1,b=-1;
	    	for(int i=0;i<SZ;i++){
	        	for(int j=0;j<SZ;j++){
	            		if(search(i) != search(j) && places[i][j]<minimum){
	                		minimum=places[i][j];
	                		a=i;
	                		b=j;				
	            		}
	        	}
	    	}
		join(a,b);
	        printf("%d Edge (%.0f,%.0f) = %.2f\n",numOfEdges,a,b,minimum);
		numOfEdges++;
	        minDist+=minimum;
	}
	printf("\nMinimum distance is = %f\n\n",minDist);
	fclose(f1);
	fclose(f2);
	
	return 0;
}
