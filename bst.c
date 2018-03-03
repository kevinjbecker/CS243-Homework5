#include <stdio.h> // all the print functions
#include <stdlib.h> // scanf
#include "bst.h"

// a reminder of what TreeNode is
// typedef struct TreeNode {
//    int data ;                  // the data stored in the node
//     struct TreeNode* left ;     // node's left child
//     struct TreeNode* right ;    // node's right child
// } TreeNode;


static TreeNode *newTreeNode(int d)
{
    // creates a new node
    TreeNode *node = NULL;

    // allocates enough space for node
    node = malloc(sizeof(TreeNode));

    // sets our data to d
    node->data = d;
    // sets our left and right to NULL, we don't know them yet
    node->left = NULL;
    node->right = NULL;

    // returns our newly created node
    return node;
}

static void insertChildNode(TreeNode *root, TreeNode *child)
{
    // checks if we need to go left (child data <= data goes left)
    if(child->data <= root->data)
    {
        // checks if the left node is a leaf or not
        if(root->left != NULL)
            insertChildNode(root->left, child);
        else
            root->left = child;
    }
    // if we don't need to go left, the only place we can go is right
    else
    {
        // checks if the right node is a leaf or not
        if(root->right != NULL)
            insertChildNode(root->right, child);
        else
            root->right = child;
    }
}


void build_tree(TreeNode** root, const int elements[], const int count)
{
    int i = 0;
    // our first element in hardcoded (we're guaranteed this many nodes)
    TreeNode *start = newTreeNode(elements[i++]);

    //goes through each element and inserts it
    for(; i < count; ++i)
        insertChildNode(start, newTreeNode(elements[i]));

    root = &start;
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

    // BEGIN TREE BUILDING PROCEDURE ===========================================

    // creates a root node
    TreeNode *root;
    // builds our tree using root
    build_tree(&root, nums, numNodes);

    return EXIT_SUCCESS;
}
