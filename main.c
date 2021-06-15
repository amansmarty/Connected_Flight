#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void printAllPathHelper(int **graph, int v, int *visited, int c1, int c2, int *path, int index)
{

 FILE *fp1;
    fp1 = fopen("output.txt", "a");
    if (fp1 == NULL)
    {
        printf("Error writing file\n");
        exit(1);
    }
    visited[c1] = 1;
    path[index] = c1;
    index++;

    if (c1 == c2)
    {
        for (int i = 0; i < index; i++)
        {
            printf("%d -> ", path[i]);
            fprintf(fp1,"%d ->",path[i]);
        }
        fprintf(fp1,"\n");
        printf("\n");
    }
    else
     {
        for (int i = 0; i < v; i++)
        {
            if (graph[c1][i] == 1 && visited[i] == 0)
                printAllPathHelper(graph, v, visited, i, c2, path, index);       
        }
    }
    
    
    index--;
    visited[c1] = false;
    fclose(fp1);
}
void printAllPath(int **graph, int v, int c1, int c2)
{
    int *visited = (int *)malloc(sizeof(int) * v);
    for (int i = 0; i < v; ++i)
    {
        visited[i] = 0;
    }
    int *path = (int *)malloc(sizeof(int) * v);
    int index = 0;
    printAllPathHelper(graph, v, visited, c1, c2, path, index);
}

int main()
{

    FILE *fp;
    fp = fopen("input.txt", "r");
    int v;
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "city: %d\n", &v);

    int e;
    fscanf(fp, "edge: %d\n", &e);
    int **graph = (int **)malloc(sizeof(int *) * v); // adjacency matrix
    for (int i = 0; i < v; i++)
    {
        graph[i] = (int *)malloc(sizeof(int *) * v);
        for (int j = 0; j < v; j++)
            graph[i][j] = 0;
    }
    int M, N;
    while (fscanf(fp, "Source: %d\tDestination: %d\t\n", &M, &N) != EOF)
    {
            graph[M][N] = 1; //Directed graph;
    }
    fclose(fp);
int c2;
int c1;
printf("\n\t_____WELCOME TO CHAPRI AIRLINES_____\n");
    printf("\nTHESE ARE THE CITIES WHERRE WE PROVIDE OUR AIRLINE SERVICES\n");
    printf("\n1.NEW DELHI\t2.KOLKATA\t3.MUMBAI\t4.PATNA\n");
    printf("\n5.HYDERABAD\t6.RANCHI\t7.BHUBANESHWAR\t8.BANGLORE\n");
    printf("\n9.JAIPUR\t10.CHENNAI\n");
    printf("\nENTER YOUR SOURCE CITY RANGING FROM OPTIONS (1-10)\n"); 
    scanf("%d", &c1);
    printf("\nENTER YOUR DESTINATION CITY RANGING FROM OPTIONS (1-10)\n"); 
    scanf("%d", &c2);
    
    
    printAllPath(graph, v, c1, c2);
}