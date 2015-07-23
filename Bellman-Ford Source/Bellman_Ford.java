/* 
 * File:   Bellman-Ford Source.java
 * Title:  Algorithms, implementations and asymptotic behavior for the shortest path problem
 * Author: Shivanshu Misra    A20279849
 *         Saurabh Katkar     A20320336
 *
 * Created on 10 May, 2014, 2:59 PM
 */

import java.io.*;
import java.util.*;

public class Bellman_Ford  {
    LinkedList<Edge> edges;	
    int d[], p[];
    int n,e,s;					// Initializing a single source
    final int INFINITY=999;

    private static class Edge  {
        int u,v,w;

        public Edge(int a, int b, int c)     {
            u=a;
            v=b;
            w=c;
        }
    }

    Bellman_Ford () throws IOException {
        int item;
        edges = new LinkedList<Edge>();
        BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));

        System.out.print("Enter number of vertices ");
        n = Integer.parseInt(inp.readLine());

        System.out.println("Cost Matrix");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++)   {
                item = (int)(Math.random()*10);
                //if(item == 9)
                	//item =(int)(Math.random()*-10);
                System.out.println(item);
                if(item != 0)
                    edges.add(new Edge(i,j,item));
            }
        }
        
        e = edges.size();
        d = new int[n];
        p = new int[n];

        System.out.print("Enter the source vertex ");
        s = Integer.parseInt(inp.readLine());
    }

    void relax() {
        int i,j;
        for(i=0;i<n;++i) {
            d[i]=INFINITY;
            p[i] = -1;
        }

        d[s] = 0;
        for (i = 0; i < n - 1; ++i) {
            for (j = 0; j < e; ++j) { 				//Calculating the shortest path
                if ((d[edges.get(j).u] + edges.get(j).w) < d[edges.get(j).v]) {
                    d[edges.get(j).v] = d[edges.get(j).u] + edges.get(j).w;
                    p[edges.get(j).v] = edges.get(j).u;
                }
             }
         }
    }

    boolean cycle() {				// Checks whether a cycle exists after RELAX operation.
        int j;						// If cycle detected report as negative edge weight cycle.
        for (j = 0; j < e; ++j)
            if (d[edges.get(j).u] + edges.get(j).w < d[edges.get(j).v])
                 return false;
        return true;
    }

    void print() {
        for (int i = 0; i < n; i++) {
        	if(p[i]!=-1)
        		System.out.println("Vertex " + i + " has predecessor " + p[i]);
            if(p[i]==-1)
            	System.out.println("Vertex " +i+ " ==> Starting node");
        }
    }

    public static void main(String args[]) throws IOException   {
    	long startTime = System.currentTimeMillis();
    	Bellman_Ford  r = new Bellman_Ford ();
        r.relax();
        if(r.cycle() == true) {							
            for(int i=0;i<r.n-1;i++)				
                System.out.println(r.s+" ==> "+r.d[i]);
        } else {
        		System.out.println("There is a negative edge cycle ");
        }
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;

        r.print();
        System.out.println("Time taken for Bellman Ford Algorithm " + elapsedTime + " " +"milliseconds");
        
        BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
        
        System.out.println("Enter q to quit");
        String q = br.readLine();
        if(q == "q")
        	System.exit(0);
    }
}