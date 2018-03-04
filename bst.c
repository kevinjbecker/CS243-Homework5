///
/// File: bst.c
///
/// Description:
///
/// @author: kjb2503 : Kevin Becker
///
// // // // // // // // // // // // // // // // // // // // // // // // // //

#include <stdio.h> // printf
#include <stdlib.h> // scanf, EXIT_SUCCESS, EXIT_FAILURE
#include "bst.h"

/* a reminder of what TreeNode is (in bst.h)

typedef struct TreeNode {
    int data ;                  // the data stored in the node
    struct TreeNode* left ;     // node's left child
    struct TreeNode* right ;    // node's right child
} TreeNode;

*/


///
/// Function: newTreeNode
///
/// Description: Returns a pointer to a newly created and allocated TreeNode.
///              NOTE: left and right are always NULL.
///
/// @param d The data this node should contain.
///
static TreeNode *newTreeNode(int d)
{
    // creates a new node
    TreeNode *node = NULL;

    // allocates enough space for node
    node = malloc(sizeof(TreeNode));

    // sets our data to d
    node->data = d;
    // sets our left and right to NULL; we don't know them yet
    node->left = NULL;
    node->right = NULL;

    // returns our newly created node
    return node;
}

///
/// Function insertChildNode
///
/// Description: Inserts a child node into the tree based upon its data
///
/// @param root The root of the tree.
/// @param child The child node to be inserted into root.
///
static void insertChildNode(TreeNode *root, TreeNode *child)
{
    // checks if we need to go left (child data <= data goes left)
    if(child->data <= root->data)
    {
        /* checks if the left node is a leaf or not (keeps going if
           not a leaf) */
        if(root->left != NULL)
            insertChildNode(root->left, child);
        else
            root->left = child;
    }
    // if we don't need to go left, the only place we can go is right
    else
    {
        /* checks if the right node is a leaf or not (keeps going if
           it is not) */
        if(root->right != NULL)
            insertChildNode(root->right, child);
        else
            root->right = child;
    }
}


///
/// Function: build_tree
///
/// Description: Builds a tree of integer TreeNodes based upon the list
///              of elements provided as parameter.
///
/// @param root  A pointer to the pointer of the root of the tree.
/// @param elements[]  The list of elements to insert into the tree.
/// @param count  The number of items in elements
///
void build_tree(TreeNode** root, const int elements[], const int count)
{
    // i is used as our index tracker
    int i = 0;
    // our first element in hardcoded (we're guaranteed this many nodes)
    *root = newTreeNode(elements[i++]);

    //goes through each element and inserts it
    for(; i < count; ++i)
        insertChildNode(*root, newTreeNode(elements[i]));
}

///
/// Function: traverse
///
/// Description: Traverses the tree using one of the traversal types.
///
/// @param root  The root of the tree to traverse.
/// @param type  The traversal ``type'' to complete (pre/in/post)order.
///
void traverse(const TreeNode* root, const TraversalType type)
{
    // p = parent; l = left; r = right
    // determines which way to traverse
    switch(type)
    {
        // pre: p -> l -> r
        case PREORDER:
            // prints root data
            printf("%d\n", root->data);

            // traverses left branch if it exists
            if(root->left != NULL)
                traverse(root->left, type);

            // traverses right branch if it exists
            if(root->right != NULL)
                traverse(root->right, type);
            break;
        // in: l -> p -> r
        case INORDER:
            // traverses left branch if it exists
            if(root->left != NULL)
                traverse(root->left, type);

            // prints root data
            printf("%d\n", root->data);

            // traverses right branch if it exists
            if(root->right != NULL)
                traverse(root->right, type);
            break;
        // post: l -> r -> p
        case POSTORDER:
            // traverses left branch if it exists
            if(root->left != NULL)
                traverse(root->left, type);

            // traverses right branch if it exists
            if(root->right != NULL)
                traverse(root->right, type);

            // prints root data
            printf("%d\n", root->data);
            break;
    }
}


///
/// Function: cleanup_tree
///
/// Description: Frees all the dynamically allocated TreeNodes within the tree.
///
/// @param root  The pointer to the root node to begin clean up.
///
void cleanup_tree(TreeNode* root)
{
    // recurses down the left branch if it exists
    if(root->left != NULL)
        cleanup_tree(root->left);
    // recurses down the right branch if it exists
    if(root->right != NULL)
        cleanup_tree(root->right);

    // now we have gotten here we can free our own node
    free(root);
    // set root to NULL
    root = NULL;
}


///
/// Function: numberReadIn
///
/// Description: Reads in a specified number of numbers from stdin.
///
/// @param numNodes  The number of numbers to read in.
/// @param nums  The number list to write to.
///
static void numberReadIn(int numNodes, int *nums)
{
    // tells user to enter numNodes integers
    printf("Enter %d integer values to place in tree:\n", numNodes);

    // reads in our integers
    for(int i = 0; i < numNodes; ++i)
        scanf("%d", &nums[i]);
}


///
/// Function: main
///
/// Description: The driver of our Binary Search Tree.
///
/// @param argc  The number of arguments in argv
/// @param argv  The list of arguments provided when the program is run.
///
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
    TreeNode *root = NULL;
    // builds our tree using root
    build_tree(&root, nums, numNodes);

    // BEGIN TRAVERSALS PROCEDURE ==============================================

    // traverses preorder
    printf("Preorder:\n");
    traverse(root, PREORDER);

    // traverses inorder
    printf("Inorder:\n");
    traverse(root, INORDER);

    // traverses postorder
    printf("Postorder:\n");
    traverse(root, POSTORDER);

    // CLEANUP PROCEDURE =======================================================
    cleanup_tree(root);

    // return success when we get here
    return EXIT_SUCCESS;
}
