bool even(Node *head)
    {
        while(head != NULL)
        {
            if(head->data%2 != 0)
            {
                return false;
            }
            
            head = head->next;
        }
        
        return true;
    }
    
    bool odd(Node *head)
    {
        while(head != NULL)
        {
            if(head->data%2 == 0)
            {
                return false;
            }
            
            head = head->next;
        }
        
        return true;
    }
    
    Node *first_even(Node *head)
    {
        while(head != NULL)
        {
            if(head->data%2 == 0)
            {
                return head;
            }
            
            head = head->next;
        }
    }
    
    Node *first_odd(Node *head)
    {
        while(head != NULL)
        {
            if(head->data%2 != 0)
            {
                return head;
            }
            
            head = head->next;
        }
    }

    Node *solve(Node *&head)
    {
        Node *even = first_even(head);
        Node *odd = first_odd(head);
        Node *oddpointer = odd;
        Node *evenpointer = even;
        
        Node *temp = head->next;
        
        if (odd->next == NULL)
        {
            return head;
        }
        else if (even->next == NULL)
        {
            while(oddpointer->next == even)
            {
                oddpointer = oddpointer->next;
            }
            
            oddpointer->next = NULL;
            temp = NULL;
        }
        
        //seperate even and odd linked list
        while (temp != NULL)
        {
            if (temp == odd || temp == even)
            {
                temp = temp->next;
            }
            
            if (temp->data%2 == 0)
            {
                evenpointer->next = temp;
                evenpointer = evenpointer->next;
                temp = temp->next;
                
            }
            else
            {
                oddpointer->next = temp;
                oddpointer = oddpointer->next;
                temp =temp->next;
            }
            
            if (temp == NULL)
            {
                evenpointer->next = NULL;
                oddpointer->next = NULL;
            }
        }
        
        evenpointer->next = odd;
        
        return even;
    }
    
public:

    Node* divide(int N, Node *head){
        // code here
        
        // If all the nodes are even or odd
        if (even(head))
        {
            return head;
        }
        else if (odd(head))
        {
            return head;
        }
        
        // If both even and odd nodes are present
        return solve(head);
    }
};