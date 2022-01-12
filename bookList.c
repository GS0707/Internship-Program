#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bookList
{
    int id;             
    char bookName[20];
    struct bookList *next;
} List;

// To count how many books in list
int count = 0;

// create list
List *createList(List *head, int no)
{
    List *curr = head;
    List *new = NULL;

    if (count > 0)
    {
        printf("\n List created already..!");
        return head;
    }

    for (int i = 0; i < no; i = i + 1)
    {
        new = (List *)malloc(sizeof(List));
        new->next = NULL;
        printf("\n Enter the ID and Name of Book: ");
        scanf("%d%s", &new->id, new->bookName);

        if (curr == NULL)
        {
            curr = new;
            head = new;
        }
        else
        {
            curr->next = new;
            curr = new;
        }
        count++;
    }
    return head;
}

List *insertBook(List *head, int pos)
{
    List *new = NULL;
    List *curr = head;

    if (count == 0)
    {
        printf("\nList not created yet..!");
        return head;
    }
    if (pos > count + 2)
    {
        printf("\nPosition invalid");
        return head;
    }

    new = (List *)malloc(sizeof(List));
    new->next = NULL;
    printf("\n Enter the ID and Name of Book: ");
    scanf("%d%s", &new->id, new->bookName);

    // if book list is empty
    if (pos == 1)
    {
        new->next = head;
        head = new;
        count++;

        return head;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    new->next = curr->next;
    curr->next = new;
    count++;

    return head;
}

int searchBook(List *head, int check)
{
    if (count == 0)
    {
        printf("Book List is Empty..!");
        return 0;
    }
    List *curr = head;
    int id;
    char name[10];
    if (check)
    {
        printf("\n Enter the ID: ");
        scanf("%d", &id);
        while (curr != NULL)
        {
            if (curr->id == id)
            {
                printf("Book is present in List..!");
                return 0;
            }
            curr = curr->next;
        }
    }
    else
    {
        printf("\n Enter the Book Name: ");
        scanf("%s", name);
        while (curr != NULL)
        {
            if (strcmp(curr->bookName, name) == 0) //use strcmp
            {
                printf("Book is present in List..!");
                return 0;
            }
            curr = curr->next;
        }
    }
    printf("\n Book is not present in list");
}

List *delBook(List *head, int pos)
{
    List *temp, *curr = head;
    if (pos > count)
    {
        printf("\nPosition invalid");
        return head;
    }

    if (pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("\nBook deleted successfylly...!");
        count--;
        return head;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    temp = curr->next;
    curr->next = temp->next;
    free(temp);
    count--;
    printf("\n Book deleted successfylly...!");
    return head;
}

int printList(List *head)
{
    if (count == 0)
    {
        printf("Book List is Empty..!");
        return 0;
    }
    List *curr = head;
    printf("Below is the Book List: \n");
    while (curr != NULL)
    {
        printf("%d: %s\n", curr->id, curr->bookName);
        curr = curr->next;
    }
}

int main()
{
    int choice, no, pos, sbook;
    List *head = NULL;

    while (1)
    {
        printf("\n\n 1:Create\t2.Insert\t3:Search\t4:Delete\t5:Print\t 6:Quite\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nHow many books u want to add: ");
            scanf("%d", &no);
            head = createList(head, no);
            break;
        case 2:
            printf("\nEnter the position to insert the Book: ");
            scanf("%d", &pos);
            head = insertBook(head, pos);
            break;
        case 3:
            printf("Search 1:ID  0:NAME Type: ");
            scanf("%d", &sbook);
            searchBook(head, sbook);
            break;
        case 4:
            printf("\nEnter the position to delete: ");
            scanf("%d", &pos);
            head = delBook(head, pos);
            break;
        case 5:
            printList(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Enter the valid choice");
            break;
        }
    }
}
