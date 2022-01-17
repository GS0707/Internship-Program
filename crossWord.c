#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[20];
    struct node *left;
    struct node *right;
} Tree;

Tree *insert(Tree *head, char str[20])
{
    if (head == NULL)
    {
        Tree *new = (Tree *)malloc(sizeof(Tree));
        new->left = NULL;
        new->right = NULL;
        strcpy(new->word, str);
        return new;
    }
    if (strcmp(str, head->word) < 0)
        head->left = insert(head->left, str);
    else if (strcmp(str, head->word) > 0)
        head->right = insert(head->right, str);
    return head;
}

Tree *readData(Tree *head)
{
    FILE *fptr;

    char word[20];

    // Open file
    fptr = fopen("dataset.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    printf("\nDataset: ");
    while (fscanf(fptr, "%s", word) != EOF)
    {
        printf("%s  ", word);
        head = insert(head, word);
    }

    fclose(fptr);
    return head;
}

int matchWord(char first[20], char second[20])
{
    int i = 0;
    while (i < strlen(second))
    {
        if (second[i] != '-')
            if (second[i] != first[i])
                return 0;
        i++;
    }
    return 1;
}

int preOrder(Tree *head, char word[20])
{
    if (head != NULL)
    {
        if (strlen(head->word) == strlen(word))
            if (matchWord(head->word, word))
                printf("%s\t", head->word);
        preOrder(head->left, word);
        preOrder(head->right, word);
    }
}

Tree *search(Tree *curr, char str)
{
    if (curr == NULL)
        return NULL;

    if (str == curr->word[0])
        return curr;
    else if (str < curr->word[0])
        return search(curr->left, str);
    else if (str > curr->word[0])
        return search(curr->right, str);
}

int main()
{
    Tree *head = NULL, *curr = NULL;
    char word[20];
    //read dataset from file
    head = readData(head);

    while (1)
    {
        printf("\n\n[Input word can be: X-X-- or X-- or X--X] => {X is known char and - is unknown}\nEnter the word: ");
        scanf("%s", word);

        curr = search(head, word[0]);
        if (curr != NULL)
            preOrder(curr, word);
        else
            printf("\nWord not found");
    }
}