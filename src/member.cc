#include "member.h"
#include <climits>

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
  this->color = COLOR_GRAY;
  this->parent = NULL;
  std::queue<Member*> q;
  q.push(this);
  while(!q.empty()) {
    Member* m = q.front();
    q.pop;
    for (auto conn_mem : m->connecting_members) {
      auto mryconn = conn_mem.second;
      auto v = mryconn = mryconn.dst;
      if (v->member_id == dst.member_id) {
        v->parent = m;
        PrintPath(v);
        return;
      }
      if (v->color == COLOR_WHITE){
        v->color = COLOR_GRAY;
        v->parent = m;
        q.push(v);
      }
    }
    m->color = COLOR_BLACK;
    }
  }
  
void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  if (depth == 0 && m->member_id == dst_member_id) {
    return m;
  }
  if (depth > 0) {
    for (auto child : m->connecting_members) {
      auto mryconn = child.second;
      auto found = DLS(mryconn.dst, depth - 1; dst_member_id);
      if (found != NULL) {
        mryconn.dst->parent = m;
        return found;
      }
    }
  }
  return NULL;
}

void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}