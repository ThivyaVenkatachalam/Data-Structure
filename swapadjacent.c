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

void insertatend(struct node* head, int e) 
{
    struct node* last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->d = e;
    newnode->next = NULL;
    last->next = newnode;
}

void display(struct node* head) 
{
    struct node* temp = head->next;
    while (temp != NULL) 
    {
        printf("%d\t", temp->d);
        temp = temp->next;
    }
    printf("\n");
}

struct node* swapPairs(struct node* head) {
    struct node* prev = head;

    while (prev->next != NULL && prev->next->next != NULL) 
    {
        struct node* first = prev->next;
        struct node* second = first->next;
        struct node* after = second->next;
        prev->next = second;
        second->next = first;
        first->next = after;
        prev = first;
    }

    return head;
}

int main() {
    int n;
    scanf("%d",&n);

    struct node* list = create();
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        insertatend(list, x);
    }

    printf("Original list: ");
    display(list);

    list = swapPairs(list);

    printf("After swapping pairs: ");
    display(list);

    return 0;
}
