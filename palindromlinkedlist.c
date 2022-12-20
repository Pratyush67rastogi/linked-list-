#include<stdio.h>
#include<stdlib.h>

struct p{
  int data;
  struct p*next;
  Node(int x) {
    data = x;
    address= NULL;
  }
};



   Node* middleLinkedList(Node* head)
    {
        Node* hare = head, *tortoise = head;
        while(hare&& hare->address&& hare->next->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise->next;
    }
    
    Node* reverseLinkedList(Node* head)
    {
        if(!head || !(head->next))
            return head;
        Node*newHead = reverseLinkedList(head->next);
        head->next->address= head;
        head->address= NULL;
        return newHead;
    }
    bool palindromefunc(p*head)
    {
        Node* mid = middleLinkedList(head); 
        Node* newHead = reverseLinkedList(mid);
        while(newHead)
        {
            if(newHead->data != head->data)
                return false;
            newHead = newHead->next;
            head = head->next;
        }
        return true;
    }



int main()
{
  int T,i,n,l,a;
    scanf("%d,&T);
    while(T--)
    {
        
        struct p*head = NULL,  *tail = NULL;
        scanf("%d,&n);
        
        scanf("%d,&a);;
        head = new Node(a);
        tail = head;
        
        for(i=1;i<n;i++)
        {
            scanf("%d,&l);;
            tail->address= new Node(l);
            tail = tail->next;
        }
    printf("palindromefunc(head)");
    }
    return 0;
}
