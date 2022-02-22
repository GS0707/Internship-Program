#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    int id;
    char name[20];
    struct Book *next;
} hashBook;

hashBook Book[26]; // hasBook = [NULL,NULL,NULL,]

void init()
{
    for (int i = 0; i < 26; i++)
        Book[i].next = NULL;
}

int getIndex(char name[10])
{
    if (name[0] <= 90)
        return name[0] - 65;
    else
        return name[0] - 97;
}

int search(char name[20])
{
    hashBook *curr;

    int index = getIndex(name);

    curr = Book[index].next; //[{abc,Aqr},{NULL}]

    while (curr)
    {
        if (strcmp(curr->name, name) == 0)
            return 1;
        curr = curr->next;
    }
    return 0;
}

int insert(int id, char name[20])
{
    if (search(name))
        return 0;

    hashBook *curr;
    hashBook *new = (hashBook *)malloc(sizeof(hashBook));
    new->next = NULL;

    new->id = id;
    strcpy(new->name, name);

    int index = getIndex(new->name);    

    if (Book[index].next == NULL)
    {
        Book[index].next = new; //[{book},Null] Book1
    }
    else
    {
        curr = Book[index].next;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new;
    }
    return 1;
}

void displayBooks()
{
    hashBook *curr;
    printf("List: ");
    for (int i = 0; i < 26; i++)
    {
        curr = Book[i].next;
        if (curr)
        {
            printf("\n[%d]: ", i);
            while (curr)
            {
                printf("\n(%d: %s)", curr->id, curr->name);
                curr = curr->next;
            }
        }
    }
}

int delBook()
{
    char name[20];
    hashBook *curr, *back = NULL, *temp;

    printf("\nEnter the book name: ");
    scanf("%s", name);

    int index = getIndex(name);

    curr = Book[index].next; //[{abc,Abc,aas},{NULL}]

    while (curr)
    {
        if (strcmp(curr->name, name) == 0)
        {
            if (Book[index].next == curr)   //[{abc,Abc,aac}]
            {                                 //[{abc},NULL]
                if (curr->next != NULL)
                    Book[index].next = curr->next;
                else
                    Book[index].next = NULL;
            }
            else if (curr->next != NULL)
                back->next = curr->next;
            else
                back->next = NULL;
            free(curr);
            return 1;
        }
        back = curr;
        curr = curr->next;
    }
    return 0;
}

int main()
{
    int choice, no, pos, sbook, id;
    char name[20];
    init();
    while (1)
    {
        printf("\n\n 1:Insert\t2:Search\t3:Delete\t4:Print\t 5:Quite\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nENter the id and book name: ");
            scanf("%d%s", &id, name);
            if (insert(id, name))
                printf("Inserted");
            else
                printf("Book already present..!");

            break;
        case 2:
            printf("\nEnter the book name: ");
            scanf("%s", name);
            if (search(name))
                printf("\n Book is present");
            else
                printf("Book not present");
            break;
        case 3:
            if (delBook())
                printf("\nDeleted");
            else
                printf("\n Not found");
            break;
        case 4:
            displayBooks();
            break;
        case 5:
            exit(0);
        default:
            printf("Enter the valid choice");
            break;
        }
    }
}