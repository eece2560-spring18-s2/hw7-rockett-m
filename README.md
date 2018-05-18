# Homework 7: STL and Graph Algorithms

We favor the STL containers than self-implemented containers because
i) they are very stable, ii) they are highly optimized for performance, and 
iii) they are richer in features.

## P1. Building the graph

In your report, briefly describe your solution. Analysis the algorithm complexity
with the big O notation. Explain how you get the result. You can assume that there
are `G groups`, `M members`. In average, each group has `K members`, each member
joins `L groups`, and each member is connected to `B other members`.

#### Operation: BuildMemberGraph

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
    
Complexity

## P2. Connecting to someone using Breath-first Search

## P3. Connecting to someone using IDDFS

## P4. Find best Groups to join