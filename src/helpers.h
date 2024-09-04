#ifndef AVL_TREE_HELPERS_H
#define AVL_TREE_HELPERS_H

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief  Check if a string contains only characters a-z, A-Z, and space.
 * @param  name full name
 * @return boolean indicating whether conditions for valid name are met
 */
bool validateName(const string& name)
{
    for (char name_char : name)
    {
        if ((name_char < 65 && name_char != 32) // below lowercase range and not space
            ||  (name_char > 90 && name_char < 97) // above lowercase and below uppercase ranges
            ||  (name_char > 122)) // above uppercase range
            return false;
    }

    return true;
}

/**
 * @brief   Check if an ID is 8 digits long and contains only numbers 0-9
 * @param   id_str string containing an ID
 * @return  boolean indicating whether conditions for valid ID are met
 */
bool validateId(const string& id_str)
{
    if (id_str.length() != 8) return false;

    for (int i = 0; i < 8; i++)
    {
        char id_char = id_str.at(i);
        if (id_char < 48 || id_char > 57) return false;
    }

    return true;
}

/**
 * @brief   Check if a counter contains only numbers 0-9
 * @param   id_str string containing a count
 * @return  boolean indicating whether conditions for valid counter are met
 */
bool validateCount(const string& count_str)
{
    for (char count_char : count_str)
        if (count_char < 48 || count_char > 57) return false;

    return true;
}

/**
 * @brief   Convert an integer string to an integer
 * @param   int_str integer string
 * @return  integer generated from the contents of string
 */
int as_int(const string& int_str)
{
    return stoi(int_str, nullptr, 10);
}

/**
 * @brief   Handle a command for interacting with an @c AVLTree structure
 * @param   tree @c AVLTree at which operations, initiated by commands, are directed
 * @credit  https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
 * @return  updated @c AVLTree
 */
AVLTree handleCommand(AVLTree tree){

    string command;
    cin >> command; // read in the command

    // insert Node with a name and ID
    if (command == "insert")
    {
        string name, id_str;
        cin.ignore(); // ignore white spaces
        getline(cin, name, '\"'); // read in first quotation mark
        getline(cin, name, '\"'); // read in name
        cin >> id_str; // read in ID
        if (!validateName(name) || !validateId(id_str))
            cout << "unsuccessful" << endl; // invalid name or ID
        else
        {
            bool result = tree.insert(as_int(id_str), name);
            if (!result) cout << "unsuccessful" << endl; // ID already exists
            else cout << "successful" << endl; // node with ID inserted
        }
    }

    else // Remove node with an ID
    if (command == "remove")
    {
        string id_str;
        cin >> id_str; // read in ID
        if (!validateId(id_str)) cout << "unsuccessful" << endl; // invalid ID
        else
        {
            bool result = tree.remove(as_int(id_str));
            if (!result) cout << "unsuccessful" << endl; // ID not found
            else cout << "successful" << endl; // node with ID removed
        }
    }

    else // Search a node with an ID or name
    if (command == "search")
    {
        string arg; // read in argument
        cin.ignore();
        getline(cin, arg, '\n');

        if (validateId(arg)) // if argument is valid ID
        {
            string result = tree.search(as_int(arg));
            if (result.empty()) cout << "unsuccessful" << endl; // ID not found
            else cout << result << endl; // read out ID
        }
        else
        {
            string name = arg.substr(1, arg.length() - 2); // remove quotation marks
            if (validateName(name)) // if argument is valid name
            {
                vector<string> results = tree.search(name);
                if (results.empty()) cout << "unsuccessful" << endl; // name not found
                else // read out names
                    for (const string& result : results) cout << result << endl;
            }
            else cout << "unsuccessful" << endl;
        }
    }

    else // read out inorder traversal of names
    if (command == "printInorder") { cout << tree.traversalToString(AVLTree::INORDER) << endl; }

    else // read out preorder traversal of names
    if (command == "printPreorder") { cout << tree.traversalToString(AVLTree::PREORDER) << endl; }

    else // read out postorder traversal of names
    if (command == "printPostorder") { cout << tree.traversalToString(AVLTree::POSTORDER) << endl; }

    else // read out postorder traversal of names
    if (command == "printLevelorder") { cout << tree.traversalToString(AVLTree::LEVELORDER) << endl; }

    else // read out number of levels
    if (command == "printLevelCount") { cout << tree.levelCount() << endl; }

    else // remove Node based on inorder count
    if (command == "removeInorder")
    {
        string count_str;
        cin >> count_str; // read in count

        if (!validateCount(count_str)) cout << "unsuccessful" << endl; // not a valid count
        else
        {
            int count = as_int(count_str); // convert count string to int
            bool result = tree.removeInorder(count); // save result from removal
            if (!result) cout << "unsuccessful" << endl; // count out of bounds
            else cout << "successful" << endl; // indicated Node was removed
        }
    }

    else { cout << "unsuccessful" << endl; } // read in unrecognized command

    return tree; // the updated tree
}

#endif //AVL_TREE_HELPERS_H
