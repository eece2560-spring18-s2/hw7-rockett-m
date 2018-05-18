#include "member.h"
#include <limits>

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
  std::queue<Member*> qu;
  qu.push(this);
  while (!qu.empty()) {
    Member *r = qu.front();
    qu.pop();
    for (auto iter : r->connecting_members) {
      auto c = iter.second; // connection
      auto d = c.dst; // destination
      if (d->member_id == dst_member_id) {
        d->parent = r;
        PrintPath(d);
        return;
      }
      if (d->color == COLOR_WHITE){
        d->color = COLOR_GRAY;
        d->parent = r;
        qu.push(d);
      }
    }
    r->color = COLOR_BLACK;
    }
  }

Member *Member::DLS(Member *node, int depth, uint64_t dst_member_id) {
  // Fill in your code here
  if (depth == 0 && node->member_id == dst_member_id) {
    return node;
  }
  if (depth > 0) {
    for (auto child : node->connecting_members) {
      auto c = child.second;
      auto found = DLS(c.dst, depth - 1, dst_member_id);
      if (found != NULL) {
        c.dst->parent = node;
        return found;
      }
    }
  }
  return NULL;
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  for (int depth = 0; depth < std::numeric_limits<int>::max(); depth++) {
    Member *found = DLS(this, depth, dst_member_id);
    if (found != NULL) {
      PrintPath(found);
      return;
    }
  }
}

void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while (curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
