# Min_Cost_Max Flow_with_Non-Negative_Weight
This program provides the implementation of finding a min cost max s-t flow of a given flow network
All the cost within this flow network should be non-negative.

Input Format.
The first line of each case containes two numbers: Vnum and Enum, where Vnum and Enum are the number of vertices and edges of a graph.
The following Enum lines describe the edges of this graph.
Each line has 3 numbers v1, v2, cap and c which tell that there is an directed edge from v1 to v2 with capacity cap and cost c.
The final line indicates the source and sink nodes of this flow network.

Sample Input.
6 7
1 2 3 1
1 3 3 1
2 4 2 1
3 5 2 1
5 2 1 1
4 6 4 1
5 6 4 1

This sample input describes a flow networks consists of 6 vertices and 7 directed edges.
