#include <stdio.h> // all the print functions
#include <stdlib.h> // used for scanf eventually
#include "bst.h"

// a reminder of what TreeNode is
// typedef struct TreeNode {
//    int data ;                  // the data stored in the node
//     struct TreeNode* left ;     // node's left child
//     struct TreeNode* right ;    // node's right child
// } TreeNode;


void build_tree(TreeNode** root, const int elements[], const int count)
{
    // builds our tree
}


void traverse(const TreeNode* root, const TraversalType type)
{
    // traverses tree :)
}


void cleanup_tree(TreeNode* root) {
    // cleans up our tree
}


int main(int argc, char **argv)
{
    /* prints to stderr the usage message if we don't have correct args
       argv[0] is used so the usage message is correct per-run */
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s #\n", argv[0]);
        return EXIT_FAILURE;
    }

    // if we get here we have *enough* arguments to at least start
    int numNodes = strtol(argv[1], NULL, 10);

    // secondary check to make sure we've been given a valid number
    if(numNodes <= 0)
    {
        fprintf(stderr, "# must be greater than 0\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}