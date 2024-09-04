#include "../src/AVLTree.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Insertraverse")
{
    AVLTree tree;
    string expected_inorder;
    for (int id = 10000000; id <= 10001000; id++)
    {
        string name = to_string(id);
        tree.insert(id, name);
        expected_inorder += name + ", ";
    }
    expected_inorder.pop_back();
    expected_inorder.pop_back();
    string actual_inorder = tree.traversalToString(tree.INORDER);
    REQUIRE(expected_inorder == actual_inorder);
}

TEST_CASE("Front remove")
{
    AVLTree tree;
    for (int id = 10000000; id <= 10000010; id++)
    {
        string name = to_string(id);
        tree.insert(id, name);
    }
    for (int id = 10000000; id <= 10000010; id++)
    {
        REQUIRE(tree.remove(id));
    }
    REQUIRE(!tree.levelCount());
}

TEST_CASE("Front removeInorder")
{
    AVLTree tree;
    for (int id = 10000000; id <= 10000010; id++)
    {
        string name = to_string(id);
        tree.insert(id, name);
    }
    for (int i = 0; i <= 10; i++)
    {
        int count = 0;
        REQUIRE(tree.removeInorder(count));
    }
    REQUIRE(!tree.levelCount());
}

TEST_CASE("Back remove")
{
    AVLTree tree;
    for (int id = 10000010; id >= 10000000; id--)
    {
        string name = to_string(id);
        tree.insert(id, name);
    }
    for (int id = 10000010; id >= 10000000; id--)
    {
        REQUIRE(tree.remove(id));
    }
    REQUIRE(!tree.levelCount());
}

TEST_CASE("Back removeInorder")
{
    AVLTree tree;
    for (int id = 10000010; id >= 10000000; id--)
    {
        string name = to_string(id);
        tree.insert(id, name);
    }
    for (int i = 10; i >= 0; i--)
    {
        int count = i;
        REQUIRE(tree.removeInorder(count));
    }
    REQUIRE(!tree.levelCount());
}