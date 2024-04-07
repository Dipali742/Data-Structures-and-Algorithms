void insertAtBottom(stack<int> &stack, int ele) {
    if (stack.empty()) {
        // If the stack is empty, simply push the element
        stack.push(ele);
        return;
    }

    // If the stack is not empty, remove the top element
    int top = stack.top();
    stack.pop();

    // Recursively call insertAtBottom to insert the element at the bottom
    insertAtBottom(stack, ele);

    // Push the removed top element back onto the stack
    stack.push(top);
}

// Function to reverse the elements of the stack
void reverseStack(stack<int> &stack) {
    if (stack.empty()) {
        // Base case: If the stack is empty, no elements to reverse
        return;
    }

    // If the stack is not empty, remove the top element
    int top = stack.top();
    stack.pop();

    // Recursively call reverseStack to reverse the remaining elements
    reverseStack(stack);

    // After reversing the remaining elements, insert the removed top element at the bottom
    insertAtBottom(stack, top);
}
