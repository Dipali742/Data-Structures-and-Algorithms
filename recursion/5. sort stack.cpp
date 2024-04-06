/*
	Time Complexity : O(N ^ 2)
	Space Complexity : O(N)

	Where N is the size of the stack.
*/

#include <stack>
void sortedInsert(stack<int> &stack, int key)
{
	if (stack.empty() || key > stack.top())
	{
		stack.push(key);
		return;
	}


	int top = stack.top();
	stack.pop();

	// Recur for the remaining elements in the stack.
	sortedInsert(stack, key);

	// Insert the popped element back into the stack/
	stack.push(top);
}

void sortStackHelper(stack<int> &s)
{
	if (s.empty()) {
		return;
	}

	int top = s.top();
	s.pop();

	// Recur for the remaining elements in the stack.
	sortStackHelper(s);

	// Insert the popped element back into the sorted s.
	sortedInsert(s, top);
}


stack<int> sortStack(stack<int> &s) {
	sortStackHelper(s) ;
	return s ;
}
