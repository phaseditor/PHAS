#include "readFile.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string readFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file)
        std::cerr << "Error: cannot open the file " << filepath << "." << std::endl;

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


RopeNode::RopeNode(std::string str)
    : isLeaf(true), left(nullptr), right(nullptr), data(str), weight(str.length()) {}
RopeNode::RopeNode(RopeNode *l, RopeNode *r)
    : isLeaf(false), left(l), right(r), weight(l->weight + (l->isLeaf ? l->data.length() : 0)) {}

Rope::Rope() : root(nullptr) {}
Rope::Rope(std::string text, int chunkSize = 32) {
  std::vector<RopeNode*> nodes;

  for (size_t i = 0; i < text.length(); i += chunkSize)
      nodes.push_back(new RopeNode(text.substr(i, chunkSize)));

  root = buildTree(nodes, 0, nodes.size() - 1);
}

RopeNode* Rope::buildTree(std::vector<RopeNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;
    if (start == end) return nodes[start];

    int mid = (start + end) / 2;
    RopeNode* left = buildTree(nodes, start, mid);
    RopeNode* right = buildTree(nodes, mid + 1, end);

    return new RopeNode(left, right);
}

RopeNode *Rope::getRoot() const { return root; }

void Rope::display(RopeNode *node) {
  if (node == nullptr)
    return;

  if (node->isLeaf) {
    std::cout << node->data;
  } else {
    display(node->left);
    display(node->right);
  }
}

void Rope::display() {
  display(root);
  std::cout << std::endl;
}
