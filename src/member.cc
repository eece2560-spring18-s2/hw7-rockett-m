#include "member.h"

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  
  
  if connecting_members.find
  
  
  for (  ){
    for (  ){
      for (  ){
        if (m == m2) {
         continue;
        }
        if (connecting_members.find(m2->member_id)) != connecting_members.end()) {
          continue; //dst id is 2nd
        }
      }
    }
  }
  
  
  for (int i = 0; i < groups.size(); i++) {
    groups[i]
  }
  
  for (auto it = groups.begin(); it != groups.end(); it++) {
    
  }
  
  for (Group *g : groups) {
    
  }
  
  for (m, ){
    for (m2 : ){
      continue;
  }
}
  
  if (connecting_members.find(dst->id)) != connecting_members.end()){
    continue;
  }
  
  3 colors gray black white (0,1,2) mapped
  //int color = 0
  //int color = 1
  //int color = 2
  //names makes code more readable 
  
  color = color.WHITE
  color = color.GRAY
  color = color.BLACK
  
  
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
