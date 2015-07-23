/* 
 * File:   Djikstra's Source.cpp
 * Title:  Algorithms, implementations and asymptotic behavior for the shortest path problem
 * Author: Shivanshu Misra    A20279849
 *         Saurabh Katkar     A20320336
 *
 * Created on 22 April, 2014, 8:59 PM
 */
#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <sys/time.h>
#define N 15             //Number of vertices included in graph

using namespace std;
typedef unsigned long long timestamp_t;
static timestamp_t
get_timestamp()
{
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

/*Function to find vertex with minimum distance value from the vertices not included shortest path tree*/
int Min_Dist_Vertex(int short_dist[], bool short_dist_set[])
{  
    int min = INT_MAX, index;
    for(int j = 0; j < N; j++)
    
        if(short_dist_set[j] == false && short_dist[j] <= min)
           min = short_dist[j], index = j;
            
            return index;
    
}

    int Print_Result(int short_dist[], int n){
     
    printf("Vertex#     Distance from Source Node\n");
    for(int p=0; p < N; p++)
        printf("%d: \t\t %d\n", p, short_dist[p]);   
    }
      
void  Djikstra_Algorithm(int Tree[N][N], int source)
{
         
    int short_dist[N];  //Shortest distance from source node to i
    bool short_dist_set[N];     /* short_dist_set[i] is TRUE if vertices included in shortest path tree.*/   
       
    for(int i=0; i < N; i++)
       /* Initially all distance are set to INFINITE and short_dist_set[] is false*/
         short_dist[i] = INT_MAX, short_dist_set[i] = false;
         short_dist[source] = 0; //Distance from source to itself is 0
       
       for(int count = 0; count < N-1; count++)
       {
           /*Function called to find minimum distance vertex from the set of vertices not processed.*/
           
           int min_value = Min_Dist_Vertex(short_dist, short_dist_set); 
            short_dist_set[min_value] = true;
           
            /*Relaxation of the edges*/
            for(int t=0; t < N; t++)
           
                if(!short_dist_set[t] && Tree[min_value][t] && short_dist[min_value] != INT_MAX
                        && short_dist[min_value]+Tree[min_value][t] < short_dist[t])
                {
                    short_dist[t] = short_dist[min_value] + Tree[min_value][t];
                }    
          
            }
            
    Print_Result(short_dist, N);
      }

int main() {
   
    /*Undirected Graph Representation: NXN Adjacency Matrix */
    int Tree[N][N]  = {{0, 3, 3, 4, 4, 2, 4, 4, 2, 3, 2, 2, 3, 1, 3},
                       {3, 0, 3, 5, 2, 3, 3, 5, 4, 2, 2, 4, 5, 3, 1},
                       {3, 3, 0, 3, 1, 1, 3, 4, 2, 3, 3, 3, 4, 2, 4},
                       {4, 5, 3, 0, 4, 2, 3, 4, 2, 4, 4, 2, 4, 3, 5},
                       {4, 2, 1, 4, 0, 2, 3, 5, 3, 4, 4, 2, 3, 3, 3},
                       {2, 3, 1, 2, 2, 0, 2, 4, 3, 2, 4, 4, 5, 3, 3},
                       {4, 3, 3, 3, 3, 2, 0, 2, 4, 3, 3, 4, 6, 4, 2},
                       {4, 5, 4, 4, 5, 4, 2, 0, 2, 3, 4, 6, 4, 3, 4},
                       {2, 4, 2, 2, 3, 3, 4, 2, 0, 3, 2, 4, 2, 1, 3},
                       {3, 2, 3, 4, 4, 2, 3, 3, 3, 0, 2, 4, 5, 2, 1},
                       {2, 2, 3, 4, 4, 4, 3, 4, 2, 2, 0, 2, 4, 1, 1},
                       {2, 4, 3, 2, 2, 4, 4, 6, 4, 4, 2, 0, 5, 3, 3},
                       {3, 5, 4, 4, 3, 5, 6, 4, 2, 5, 4, 5, 0, 3, 5},
                       {1, 3, 2, 3, 3, 3, 4, 3, 1, 2, 1, 3, 3, 0, 2},
                       {3, 1, 4, 5, 3, 3, 2, 4, 3, 1, 1, 3, 5, 2, 0},
                      };
     
    timestamp_t t0 = get_timestamp();                  
    /*Calling Dijkstra's shortest path algorithm*/
    Djikstra_Algorithm(Tree, 0);
    timestamp_t t1 = get_timestamp();     
    
    /*Calculate total execution time of the algorithm in microseconds*/
    double secs = (t1 - t0) / 1000000.0L;
    printf("Time Complexity of Algorithm: %f", secs);
    return 0;
}

