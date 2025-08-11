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
        printf(" %d\t", temp->d);
        temp = temp->next;
    }
    printf("\n");
}

struct node* removeDuplicates(struct node* head) {
    struct node* prev = head;
    struct node* curr = head->next;
    int dup;

    while (curr != NULL) 
    {
        dup = 0;
        while (curr->next != NULL && curr->d == curr->next->d) 
        {
            dup = 1;
            struct node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        if (dup == 1)
        {
            struct node* temp = curr;
            curr = curr->next;
            free(temp);
            prev->next = curr; 
        }
        else 
        {
            prev = curr; 
            curr = curr->next;
        }
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
    display(list);
    list = removeDuplicates(list);
    display(list);

    return 0;
}
