#include <stdio.h> // all the print functions
#include <stdlib.h> // scanf
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


void cleanup_tree(TreeNode* root)
{
    // cleans up our tree
}


static void numberReadIn(int numNodes, int *nums)
{
    printf("Enter %d integer values to place in tree:\n", numNodes);

    int res;

    for(int i = 0; i < numNodes; ++i)
        res = scanf("%d", &nums[i]);
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

    // BEGIN NUMBER READ IN PROCEDURE ==========================================

    // nums is used to store the numbers for nodes
    int nums[numNodes];
    // reads in the numbers and sets them into nums
    numberReadIn(numNodes, nums);

    // prints our our input values
    printf("Input values:\n");
    // prints our numbers we read in
    for(int i = 0; i < numNodes; ++i)
        printf("%d\n", nums[i]);

    return EXIT_SUCCESS;
}
