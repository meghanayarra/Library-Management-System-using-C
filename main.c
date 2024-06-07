#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//Structure of a book
struct Book
{
  char title[100];
  char author[100];
  int pages;
};
//function to add new book
void addbook(struct Book *books, int *numbooks)
{
    printf("enter book title:");
    getchar();
    fgets(books[*numbooks].title, sizeof(books[*numbooks].title),stdin);
  //strtok(books[*numbooks].title,"\n");
    printf("enter author of book:");
    fgets(books[*numbooks].author, sizeof(books[*numbooks].author),stdin);
  //strtok(books[*numbooks].author,"\n");
    printf("enter number of pages");
    scanf("%d", &books[*numbooks].pages);
    getchar();
    (*numbooks)++;
    printf("Book is added\n");
    }
//function to display books
void displaybooks(struct Book *books, int numbooks)
{
    printf("books in library are:");
    int i;
    for(i=0;i<numbooks;i++){
        printf("title: %s\n", books[i].title);
        printf("author: %s\n", books[i].author);
        printf("pages: %d\n", books[i].pages);
        printf("\n");
    }
}
//function to search  a book by title
void searchbook(struct Book *books, int numbooks, char *booktitle)
{
    int found=0;
    for(int i=0;i<numbooks;i++){
        if(strcmp(books[i].title,booktitle)==0){
            printf("book found\n");
            printf("title:%s\n",books[i].title);
            printf("author:%s\n",books[i].author);
            printf("pages:%d\n",books[i].pages);
            found=1;
            break;
        }
    }
    if(!found){
        printf("book not found\n");
    }
}
//function to delete a book by title
void deletebook(struct Book *books, int *numbooks, char *booktitle)
{
    int found=0;
    int i;
    for(i=0;i<*numbooks;i++){
        if(strcmp(books[i].title,booktitle)==0){
            for(int j=i;j<*numbooks-1;j++){
                strcpy(books[j].title,books[j+1].title);
                strcpy(books[j].author,books[j+1].author);
                books[j].pages=books[j+1].pages;
            }
            (*numbooks)--;
            found=1;
            printf("book deleted \n");
            break;
        }
    }
    if(!found){
        printf("book not found\n");
    }
}

int main()
{
    struct Book books[100];
    int numbooks=0;
    int choice;
    char booktitle[100];
    do{
        printf("Library Management System\n");
        printf("1. add book\n");
        printf("2. display books\n");
        printf("3. search book\n");
        printf("4. delete book\n");
        printf("5. exit\n");
        printf("enter choice\n");
        scanf("%d", &choice);
        switch(choice){
    case 1:addbook(books, &numbooks);
           break;
    case 2:displaybooks(books, numbooks);
           break;
    case 3:printf("enter title to search\n");
           getchar();
           fgets(booktitle,sizeof(booktitle), stdin);

           searchbook(books, numbooks, booktitle);
           break;
    case 4:printf("enter title to delete\n");
           getchar();
          fgets(booktitle, sizeof(booktitle), stdin);

          deletebook(books, &numbooks, booktitle);
          break;
    case 5:printf("exit");
           break;
    default:printf("enter correct choice\n");

        }
    } while(choice !=5);
    return 0;
}
