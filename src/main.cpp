#include "AVLTree.h"
#include "helpers.h"

/// program executable
int main()
{
    int command_count = 0;
    cin >> command_count; // read in the number of commands
    AVLTree tree; // instantiate a tree object
    // run down the counter while handling commands
    while (command_count--) tree = handleCommand(tree);
    return 0;
}