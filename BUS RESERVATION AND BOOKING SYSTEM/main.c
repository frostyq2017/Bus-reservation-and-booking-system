#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


typedef struct user {
    char fullname[50];
    char password[50];
    char email[50];
    char username[50];
};
char generateusername (char email[50], char username[50]) {
    for(int i = 0; i <strlen(email); i++){
        if(email[i] == '@') break;
        else username[i] = email[i];
    }
}

void takeinput(char ch[50]) {
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

#define MAX_SEATS 30


struct Bus {
    int busNumber;
    char coachName[20];
    int seats[30];
    int seatNumber;
    int isBooked;
};


void showSeats(struct Bus bus) {
    printf("\t\t\t\t\t\nAVAILABLE SEATS\n\n");
    for (int i = 0; i < 30; i++) {
        if (bus.seats[i] == 0) {
            printf("Seat %d: Availabe ", i + 1);
        } else {
            printf("Seat %d: Booked ", i + 1);
        }
    }
    printf("\n");
}
void cancelSeat(struct Bus *bus, int seatNumber) {
    if (bus->seats[seatNumber - 1] == 0) {
        printf("Seat is already empty.\n");
    } else {
        bus->seats[seatNumber - 1] = 0;
        printf("Seat number %d is now cancelled.\n", seatNumber);
    }
}

void bookSeat(struct Bus *bus, int seatNumber) {
    if (bus->seats[seatNumber - 1] == 1) {
        printf("Seat %d is already booked.\n", seatNumber);
    } else {
        bus->seats[seatNumber - 1] = 1;
        printf("Seat %d booked successfully.\n", seatNumber);
    }
}

void saveData(struct Bus *buslist, int busIndex) {
    char filename[20];
    sprintf(filename, "bus%d.txt", buslist[busIndex].busNumber);

    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < MAX_SEATS; i++) {
            fprintf(file, "%d ", buslist[busIndex].seats[i]);
        }
        fclose(file);
        printf("Data saved successfully.\n");
    } else {
        printf("Unable to save data.\n");
    }
}

void loadData(struct Bus *buslist, int busIndex) {
    char filename[20];
    sprintf(filename, "bus%d.txt", buslist[busIndex].busNumber);

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        for (int i = 0; i < MAX_SEATS; i++) {
            fscanf(file, "%d", &buslist[busIndex].seats[i]);
        }
        fclose(file);
        printf("Data loaded successfully.\n");
    } else {
        printf("Unable to load data.\n");
    }
}






void cancelBooking(struct Bus *buslist, int busIndex) {
    int trno;
    char ch[10][130]={"Mombasa Express","Nairobi Express","Naivasha Express","Turkana Express","Kakamega Express","Kisumu Express"};

    system("cls");
    printf("========================CANCEL BOOKING======================\n");
    printf("Enter the Bus number:--->");
    scanf("%d", &trno);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n");
    printf("\nYour Bus Number is %d ********** %s", trno, ch[trno-1]);

    /*Calling showseats */
    showSeats(buslist[busIndex]);
    printf("\nEnter seat number to cancel booking:   \n");
    int seatNumber;
    scanf("%d", &seatNumber);

    if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        cancelSeat(&buslist[busIndex], seatNumber);
        saveData(buslist, busIndex);
        printf("Booking for seat %d has been successfully cancelled.\n", seatNumber);
    } else {
        printf("Invalid seat number.\n");
    }
}


int trno;
char ch[10][130]={"Mombasa Express","Nairobi Express","Naivasha Express","Turkana Express","Kakamega Express","Kisumu Express"};

void buslist(){
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    printf("\t\t\t\t\t[1]  =>  %s\n",ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n",ch[1]);
    printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n",ch[2]);
    printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n",ch[3]);
    printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n",ch[4]);
}
void cancel(){
    char choice;
    system("cls");
    printf("\n\n  YOU ARE ABOUT TO QUIT THE SYSTEM!!!!!!\n\n");
    printf("\n\n  If YES type Y......If NO type N\n");
    printf("\n Enter your choice:: ");
    scanf("\n\n %C", &choice);

    switch(choice){
        case 'Y':

            system("cls");
            printf("\n\n\n\t\t\t THANKYOU FOR CHOOSING OUR SYSTEM");

            break;
        case 'N':
            login();

            break;
        default:
                printf("Invalid choice. Please enter a number between 1 and 2.\n");

    }




}
void showbus();
void Booking(struct Bus *buslist, int busIndex) {

    int trno;
    char ch[10][130]={"Mombasa Express","Nairobi Express","Naivasha Express","Turkana Express","Kakamega Express","Kisumu Express"};

    system("cls");
    printf("========================BOOK YOUR FAVOURITE SEAT======================\n\n");
    printf("Enter the Bus number:--->");
     scanf("%d",&trno);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
     printf("\nYour Bus Number is %d ********** %s",trno,ch[trno-1]);

      showSeats(buslist[busIndex]);
      printf("\nEnter seat number to book:   \n");
      int seatNumber;
      scanf("%d", &seatNumber);
       if (seatNumber >= 1 && seatNumber <= MAX_SEATS) {
        bookSeat(&buslist[busIndex], seatNumber);
        saveData(buslist, busIndex);

    } else {
        printf("Invalid seat number.\n");
    }



}
int login() {
    struct Bus busList[MAX_SEATS];
        busList[0].busNumber = 1;

    // Load data from file if it exists

        int num;
        do{
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> View Bus List\n");
        printf ("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancel Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
         printf("\t\t\tEnter Your Choice:: ");
        scanf("%d",&num);

        switch(num)
        {
            case 1:
                buslist();
             break;
            case 2:
                Booking(busList, 0);
                break;
            case 3:
                cancelBooking(busList, 0);
                break;
            case 4:
                cancel();

                break;
            default:
                printf("Invalid choice!\n");
                break;
         }
             getch();
              }while(num != 5);
                 system("CLS");
                printf("\t----------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
                 printf("\t----------------------------------------------------------------------------------------------------------\n");
                getch();

            loadData(busList, 0);

            Booking(busList, 0);



}
int main() {


    int opt;
    struct user user;
    FILE *fp;

    printf("\t\t=+=+=+=+=+=+=++=+=+=+  WELCOME TO THE BUS BOOKING AND RESERVATION SYSTEM=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("\n\t\t\t\t\t please choose your operation\n");
    printf("\t\t\t\t\t ----------------------------");
    printf("\n \t\t\t\t\t => 1.Login\n");
    printf("\n \t\t\t\t\t => 2.Exit\n");

    printf("\n\nYour choice: ");
    scanf("%d", &opt);
    fgetc(stdin);


    switch(opt){
        case 1:
            system("cls");
            printf("\n  =========================  LOGIN FORM  =========================  ");
            printf("\n    Enter your name:- ");
            takeinput(user.fullname);
            printf("\n    Enter your email:-  ");
            takeinput(user.email);
            printf("\n    Enter your password:-  ");
            takeinput(user.password);

            system("cls");
            generateusername(user.email,user.username);
            fp = fopen("Users.dat", "a");
            if(fwrite != 0)
            printf ("\n\n user registration succcessful :) \n") ;
            printf("\n\n Your username is  %s",user.username);
            else
            printf("\n\n Sorry! Something went wrong :(") ;

            printf("  \n\n ---------------------  WELCOME TO OUR SYSTEM --------------------------");
            printf("\n\n\n  Press any key to continue...");
            Beep(750,300);
	        getch();//holds the screen

    // Successful login operation

// Prompt for continuation
                int continuation;
                system("cls");
                printf("\n\t\t\n  Do you want to continue with the booking? (1 for Yes / 0 for No): ");
                printf("\n\n 1...");
                printf("\n\n 0...");
                printf("\n\nYour choice: ");
                scanf("%d", &continuation);

                // Rest of the booking process
                // ...
                switch(continuation)
                    case 1:
                      login();
                    case 0:
                         printf("\n ..Thank you for trusting us...\n");
                         return 0;
                    break;


        case 2:
                printf("\n ..Thank you for trusting us...\n");
                break;
        default:
                printf("Invalid choice. Please enter a number between 1 and 2.\n");
    }

}



