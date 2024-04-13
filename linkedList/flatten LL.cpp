// Function to merge two linked lists in sorted order
Node* merge( Node* a, Node* b )
{
    // If one of the linked lists is empty, return the other
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    Node* result;
    // Compare the data of the nodes and merge them in sorted order
    if (a->data < b->data)
    {
        result = a;
        // Recursively merge the rest of the nodes
        result->bottom = merge( a->bottom, b );
    }
    else
    {
        result = b;
        // Recursively merge the rest of the nodes
        result->bottom = merge( a, b->bottom );
    }

    return result;
}

// Function to flatten a linked list
Node* flatten (Node* root)
{
    // Base cases
    // If the root or the next node is empty, return the root
    if (root == NULL || root->next == NULL)
        return root;
    // Recursively flatten the remaining linked lists and merge them
    return merge( root, flatten(root->next) );
}
