# MFCS-project :world_map:

**INTRODUCTION**

The project is based on finding a Minimum Spanning Tree using Kruskal’s Algorithm.
The data set on which the MST was to be found is a list of the most frequently visited
places inside the campus of the University of Hyderabad along with the distances (in
Kilometers) that connected one place to another.

**HYPOTHESIS**

Since distance from a place to itself is always zero, therefore they were replaced by a
constant value INFINITY (=999). This was done to prevent the inclusion of these zero
values in the algorithm, since the algorithm operates on taking minimum cost (here,
distance).

__Why is Kruskal’s algorithm needed?__

Kruskal’s algorithm is needed as it constructs a MST which finds the minimum
distance required to travel to all the frequently visited places. It uses a greedy
technique (i.e., it chooses the one which is the most optimal at the moment only)
since it sorts the distances in non decreasing order and selects the one with
minimum distance.

Running time of the Algorithm: O(E logV)

__How does Kruskal’s algorithm work?__

1. List all the edges of the graph in increasing order of weight.
2. Select the smallest edge of graph G, this is the first edge of spanning tree T.
3. If there are more than one edge of the same minimal value, select one of them
arbitrarily.
4. Select another edge of minimal value from the remaining edges such that
inclusion of this edge does not form a circuit.
5. Repeat step 3 until the the tree T contains N-1 edges.

**CONCLUSION**

The conclusion drawn from the extensive data that was collected from the website as
well as manually is that the minimum distance (or cost) is roughly equal to 10.75 ~ 11
Kilometers.

**SOFTWARES AND TOOLS USED**

1. Online compiler - ​ https://www.codechef.com/ide
2. MATLAB - ​ https://in.mathworks.com/help/matlab/ref/graph.plot.html
3. Graph online - ​ https://graphonline.ru/en/
4. CS Academy - ​ https://csacademy.com/app/graph_editor/

**REFERENCES**

1. Introduction to Algorithms, 3rd Ed., Thomas H. Cormen Charles E. Leiserson
Ronald L. Rivest Clifford Stein
2. Class notes
3. Visual Algo - ​ https://visualgo.net/en/mst
4. Youtube - ​ https://www.youtube.com/watch?v=Yo7sddEVONg
5. Wiki - ​ https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
