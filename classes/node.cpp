#ifndef NODE_CPP
#define NODE_CPP

#include "../headers/node.hpp"
using namespace std;

Node::Node(uint64_t id, bool red = false) { // Complexity: O(1)
    this->id = id;
    if (red) this->color = 1;
    this->parent = -1;
}

Node::Node(uint64_t id, int64_t parent, bool red = false) { // Complexity: O(1)
    this->id = id;
    if (red) this->color = 1;
    this->parent = parent;
}

Node::~Node() {}

void Node::addChild(uint64_t child) { // Complexity: O(1)
    this->children.push_back(child);
}

void Node::removeChild(uint64_t child) { // Complexity: O(x) where x is th number of children
    auto it = find(this->children.begin(), this->children.end(), child);
    if (it != this->children.end()) this->children.erase(it);
}

string Node::print() const {
    ostringstream os;
    os << "Node #" << this->id;
    if (this->color == 1) {
        os << " (red)";
    }
    if (this->alpha != -1) {
        os << " (alpha: " << this->alpha << ")";
    }
    if (this->beta != -1) {
        os << " (beta: " << this->beta << ")";
    }
    if (this->parent != -1) {
        os << " has parent #" << this->parent << ".";
    } else {
        os << " is the root of the tree.";
    }
    os << endl;
    return os.str();
}

#endif