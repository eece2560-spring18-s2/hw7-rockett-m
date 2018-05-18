# Homework 7: STL and Graph Algorithms

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
Time to find path to member 0.0075363 seconds  
Time to find path to member 0.0086508  seconds  
Time to find path to member 0.00730307 seconds  
  
Average T<sub>FPM</sub> = 0.0078301 seconds  

*terrynhanggi = Terry N. Hanggi but our CSV reader does not take middle initials 
into account

## P3. Connecting to someone using IDDFS

## P4. Find best Groups to join