#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
using std::vector;
using std::string;

/// Object class for a node of a tree where each element contains a student ID and name
class Node {

public:
    Node *left;
    Node *right;
    int height;
    int id;
    string name;

    Node(int i, string s) :
            id(i), name(std::move(s)), height(0), left(nullptr), right(nullptr) {}
};

#endif //NODE_H