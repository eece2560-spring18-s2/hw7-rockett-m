# Homework 7: STL and Graph Algorithms

In this homework, we are going to practice how to implement graph-related 
algorithms. At the same time, we are going to practice the use of C++ STL.
We favor the STL containers than self-implemented containers because
i) they are very stable, ii) they are highly optimized for performance, and 
iii) they are richer in features.

## P1. Building the graph

In your report, briefly describe your solution. Analysis the algorithm complexity
with the big O notation. Explain how you get the result. You can assume that there
are `G groups`, `M members`. In average, each group has `K members`, each member
joins `L groups`, and each member is connected to `B other members`.

#### Operation: BuildMemberGraph in /src/database.cc

    void Database::BuildMemberGraph() {
      // Fill in your code here
      for (Group *g : groups) {
        for (Member *m : g->members) {
          for (Member *m2 : g->members) {
            if (m == m2) {
              continue;
            }
            if (m->connecting_members.find(m2->member_id) != 
                m->connecting_members.end()) {
              continue;
            }
            MemberConnection c;
            c.group = g;
            c.dst = m2;
            m->connecting_members[m2->member_id] = c;
          }
        }
      }
    }
    
Complexity: O(G * M<sup>2</sup> * L * B)  

* for loop (G)  
* for loop 2x (M*M)  
* if cond (L)  
* if cond (B)  
  
`./p1_main`  

5807 events loaded  
10000 members loaded  
16330 groups loaded  

Time to build member graph 1.18884 seconds  
Time to build member graph 1.19216 seconds  
Time to build member graph 1.18338 seconds  
  
Average T<sub>BMG</sub> = 1.18817 seconds  

## P2. Connecting to someone using Breath-first Search

In this question, implement the function `Member::PathToMemberBFS` with BFS 
algorithm. This function finds the path from `this` member to the member with
the id of provided `dst_member_id` argument. 

`./p2_main`  
 
Scott Heiferman <- Matthew <- terrynhanggi* <- Matt Meeker  

*terrynhanggi = likely Terry N. Hanggi but our CSV reader processes names without
proper punctuation, as online profiles do not require it in meetups data. 

Time to find path to member 0.0075363 seconds  
Time to find path to member 0.0086508  seconds  
Time to find path to member 0.00730307 seconds  
  
BFS Average T<sub>FPM</sub> = 0.007830057 seconds  

## P3. Connecting to someone using IDDFS

In P3, you need to complete the same task, but with the IDDFS algorithm.

`./p3_main`  
 
Scott Heiferman <- Matthew <- terrynhanggi* <- Matt Meeker  

Time to find path to member 0.00737146 seconds  
Time to find path to member 0.00809269 seconds  
Time to find path to member 0.00719987 seconds  
  
IDDFS Average T<sub>FPM</sub> = 0.007554673 seconds 

Benchmark the main program for p2 and p3. Report the times that each algorithm
consumes. 

Difference (BFS-IDDFS) Avg_T<sub>FPM</sub> = 0.000275384 seconds

The execution time of IDDFS is just over 275 microseconds faster than BFS, on 
average, for the main program.  

Also, measure the peak memory consumption of the two algorithms.
The output field called `Maximum resident set size` is the peak memory 
consumption you are looking for. In your report explain your finding.  

#### BFS memory consumption with and without pathfinding  

`/usr/bin/time -v ./p2_main`  

Maximum resident set size (kbytes): 127080  
Maximum resident set size (kbytes): 127036  
Maximum resident set size (kbytes): 127072  

BFS with pathfinding (above): Avg Mem_cons<sub>pk</sub> = 127063 kbytes  
BFS without pathfinding: Avg Mem_cons<sub>pk</sub> = 126951 kbytes  

Difference BFS Avg Mem_Cons<sub>(path-nopath)</sub> = 112 kbytes

With pathfinding in BFS, the peak memory consumption averaged 112 bytes more
than the nonpathfinding BFS search. Therefore, pathfinding does use just over
0.1 kB more memory than the standard search, but the small differential is
worth the quicker execution time.

#### IDDFS memory consumption with and without pathfinding  

`/usr/bin/time -v ./p3_main`

Maximum resident set size (kbytes): 126968  
Maximum resident set size (kbytes): 126896  
Maximum resident set size (kbytes): 127016  

IDDFS with pathfinding (above): Avg Mem_cons<sub>pk</sub> = 126960 kbytes  
IDDFS without pathfinding: Avg Mem_cons<sub>pk</sub> = 126897 kbytes  

Difference IDDFS Avg Mem_Cons<sub>(path-nopath)</sub> = 63 kbytes

With pathfinding in IDDFS, the peak memory consumption averaged 63 bytes more
than the nonpathfinding IDDFS search. Therefore, IDDFS pathfinding uses close to 
half the additional memory as BFS search pathfinding, which is marginal but does
enhance run time.

## P4. Find best Groups to join

In this problem, you need to implement `Database::BestGroupsToJoin()` function. 
This function takes an argument of type `Member *` as a member who you know that
is in the community. You need to implement the with Prim's algorithm, treating 
the provided `Member` as the root of the minimum spanning tree you are going to
generate.

`./p4_main`  

Scott Heiferman <- Pat Finegan <- djouffyo <- marian <- Denise Yap <- janezeng 
<- kirstin_leifels <- vjm89 <- hhpierce <- Matt Meeker  

Time to generate MST 0.499008 seconds  
Time to generate MST 0.504795 seconds  
Time to generate MST 0.51505 seconds  

Average T<sub>MST</sub> = 0.506284 seconds  

The run time of the BestGroupsToJoin function takes around 0.5 seconds on average, 
so this feature enables users to find select groups in a short amount of time. The
example case featured someone joining meetups to network in small groups with
people they know or can see the relation to other members. Prim's algorithm 
is efficient in this case and prints the member connection path quickly.


