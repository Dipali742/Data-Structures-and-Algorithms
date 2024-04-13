/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

int length(Node *head)
{
	Node* temp = head;
    Node* fast = head;
    Node* slow = head;
    int cnt = 0;
    while(fast != NULL && fast->next != NULL) { 
        if(fast -> next != NULL) {
            fast = fast->next->next;
        }
        slow = slow->next;
        cnt++;
    }

    if(fast != NULL)
        return cnt*2 + 1;
    return cnt*2;  
}
