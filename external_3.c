// QUESTION 3

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *insertAtBegin(struct node *head, char val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->next = NULL;
    new->data = val;
    if (head == NULL)
    {
        head = new;
        return head;
    }
    new->next = head;
    head = new;
    return head;
}

struct node *inserAtEnd(struct node *head, char val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    return head;
}

struct node *deleteAtBegin(struct node *head)
{
    if (head == NULL)
    {
        printf("list empty\n");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("list empty\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

void printList(struct node *head)
{
    if (head == NULL)
    {
        printf("empty list\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head = insertAtBegin(head, 'U');
    head = insertAtBegin(head, 'G');
    head = insertAtBegin(head, 'R');

    head = inserAtEnd(head, 'k');
    head = inserAtEnd(head, 'T');
    printf("after insertion: ");
    printList(head);
    head = deleteAtEnd(head);
    head = deleteAtEnd(head);
    printf("after deleting end: ");
    printList(head);
    head = deleteAtBegin(head);
    head = deleteAtBegin(head);
    printf("after deleting at begin: ");
    printList(head);
    return 0;
}
