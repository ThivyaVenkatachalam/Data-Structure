#include <stdio.h>
#include <stdlib.h>

struct node {
    int d;
    struct node* next;
};

struct node* create() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    return head;
}

void insertatend(struct node* head, int e) {
    struct node* last = head;
    while (last->next != NULL) last = last->next;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->d = e;
    newnode->next = NULL;
    last->next = newnode;
}

void display(struct node* head) {
    struct node* temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->d);
        temp = temp->next;
    }
    printf("\n");
}

struct node* oddEvenList(struct node* head) 
{
    if (head->next == NULL || head->next->next == NULL)
    {
        return head;
    }

    struct node* odd = head->next;       
    struct node* even = odd->next;       
    struct node* evenHead = even;        

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;          
        odd = odd->next;                 

        even->next = odd->next;          
        even = even->next;              
    }

    odd->next = evenHead;
    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    struct node* list = create();
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        insertatend(list, val);
    }

    printf("Before: ");
    display(list);

    list = oddEvenList(list);

    printf("After:  ");
    display(list);

    return 0;
}
