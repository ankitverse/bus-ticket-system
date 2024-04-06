/*Hii , I am Ankittt this is a working bus ticket system
Currently there are 4 functions which work as booking ticket,viewing all tickets,
view available tickets, searching by name.

Thank you...
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SEAT 40


typedef struct
{
    int no; //seat number for ticket
    char name[40]; //name of passenger who booked ticket
} ticket ;

void not_booked (ticket n[]);
void print_tickets(ticket s[]);
void book_tickets(ticket b[]);
void view_avl_tickets(ticket a[]);
void search_name(ticket s[]);
void main_menu(ticket bus_ticket[]){
    int opt;
    printf("\t\t Welcome to Bus ticket booking system \n\n");
    printf("1.Book Ticket\n");
    printf("2.See all Tickets\n");
    printf("3.view available tickets\n");
    printf("4.Search Name\n");
    printf("Enter any other number to exit\n");
    printf("Choose any options: ");
    scanf("%d",&opt); 
    // scanf("%c");
    switch (opt)
    {
    case 1:
    // calling book tickets function
        book_tickets(bus_ticket);
        break;
    case 2:
        print_tickets(bus_ticket);
        break;
    case 3:
        view_avl_tickets(bus_ticket);
        break;

    case 4:
        search_name(bus_ticket);
        break;
    
    default:
        printf("Invalid Option Chosen... Exiting Program");
        break;
    }
};
int main(){
    // int opt;
    ticket bus_ticket[MAX_SEAT];
    not_booked(bus_ticket); //setting default not booked name to all tickets

    main_menu(bus_ticket);
    return 0;
}
void not_booked (ticket n[]){
    for (int i = 0; i < MAX_SEAT; i++)
    {
        n[i].no = i+1;
        strcpy(n[i].name,"NOT_BOOKED_YET");
    }
    
}
void print_tickets(ticket n[]){
    for (int i = 0; i < MAX_SEAT; i++)
    {
        printf("%d.%s\n",n[i].no,n[i].name);
    }
    printf("press 1 to return to main menu");
    int qans = 1; //name is as quick answer
    qans =getch();
    if (qans== 49) 
        main_menu(n);
    else{
        printf("getch value = %d",qans);
    }
    
}

void book_tickets(ticket b[]){
    char ans = 'Y';
    while (ans == 'Y' || ans == 'y')
    {
       system("cls"); //this will cause error while running on linux system
       //firstly clearing the screen
       int sno =0;
       
       printf("Enter seat no :"); //getting seat number from user
       scanf("%d",&sno); //here one new line character is left on stdin thats why we require fflush stdin
    //    scanf("%c");
    //    printf("%s",b[sno].name);
       if(strcmp(b[sno-1].name,"NOT_BOOKED_YET") != 0){
        //if ticket is already booked warn user about that
        //if user still want to update they have option
        printf("Seat is already booked. Do you still want to edit the name.(y or n)\n");
        char anss;
        fflush(stdin);
        anss = getchar();
        if(anss == 'n'){
            main_menu(b);
            return;
        }
       }
       fflush(stdin); //flushing input buffer (removing \n from input buffer)

       printf("Enter Name of Passenger for seat %d : ",b[sno-1].no);
       scanf("%[^\n]s",b[sno-1].name); //getting value till newline character
       printf("\n%s name registered for seat %d",b[sno-1].name,b[sno-1].no);
    //    scanf("%c");
       printf("\nWant to add more passengers(y or n):");
        fflush(stdin);
        ans = getchar();
       
    }
    // while(scanf("%c") == '\n');
    // printf("press 1 to return to main menu");
    // if (getch() == 1) main_menu(b);
    system("cls");
    main_menu(b);
    // printf(" ans is %c abhck",ans);
    
}

void view_avl_tickets(ticket a[]){
    printf("------ Booked Tickets -------------\n");
    for (int i = 0; i < MAX_SEAT; i++)
    {
        if(strcmp(a[i].name,"NOT_BOOKED_YET") != 0){
        printf("%d.%s\n",a[i].no,a[i].name);}
    }
    printf("\n\n--------- Available tickets --------\n");
    for (int i = 0; i < MAX_SEAT; i++)
    {
        if(strcmp(a[i].name,"NOT_BOOKED_YET") == 0){
        printf("%d.%s\n",a[i].no,a[i].name);}
    }
    printf("press 1 to return to main menu");
    // scanf("%c");//its already flushed
    if (getch() == 49) 
        main_menu(a);
}

//searching name function
void search_name(ticket b[]){
    system("cls");
    fflush(stdin); 
    char namee[40]; //temporary storing name in this 
    printf("Enter Name to search : ");
    gets(namee);
    int count = 0;
    for(int i = 0;i<MAX_SEAT;i++){
        if(strcmp(namee,b[i].name) == 0){
            printf("%d.\t%s\n",b[i].no,b[i].name);
            count = 1;
        }
    }
    if(count == 0) printf("\nSorry No ticket was registered with this name\n");
    printf("press 1 to return to main menu");
    if (getch() == 49) main_menu(b);
}