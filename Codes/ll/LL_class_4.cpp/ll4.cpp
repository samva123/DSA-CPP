bool checkloop(Node *&head)
{

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check loop
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

Node* getstartingPoint(Node* &head){

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            // check loop
            if (fast == slow)
            {
                break;
            }
        }
        if(fast == NULL){
            return NULL;
        }

        slow = head;

        while(fast != slow){
            slow = slow -> next;
            fast = fast -> next;


        }
        return slow;


}



//remove loop
void removeloop(Node* &head){

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // check loop
        if (fast == slow)
        {
            break;
        }
    }
    if(fast == NULL){
        return NULL;
    }

    slow = head;

    while(fast != slow){
        slow = slow -> next;
        fast = fast -> next;


    }
    Node* start = slow;

    Node* temp = fast;
    while(temp -> next != start){
        temp = temp->next;
         
    }
    temp -> next = NULL; 
     
}




