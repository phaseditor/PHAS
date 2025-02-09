#ifndef READFILE_H
#define READFILE_H

#include <cstdio>
#include <string>
#include <vector>

std::string readFile (const std::string& );

class RopeNode {
public:
  bool isLeaf;
  RopeNode *left;
  RopeNode *right;
  std::string data;
  int weight;

  RopeNode(std::string);
  RopeNode(RopeNode *, RopeNode *);
};

class Rope {
private:
  RopeNode *root;

public:
  Rope();
  Rope(std::string, int);
  RopeNode* buildTree(std::vector<RopeNode*>&, int, int);
  RopeNode *getRoot() const;

  void display(RopeNode *);
  void display();
};

#endif // READFILE_H
