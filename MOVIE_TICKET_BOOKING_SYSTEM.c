#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ATTEMPTS 3
#define WARNING_ATTEMPTS 2

#define RESERVATION_FILE "reservations.txt"

// Global variables declared.
int attempts = 0;
int loggedIn = 0;
char adm[20], pwd[20], cus[20];
int ticketPrice = 100;
int count = 0;
int id1 = 1000;



// Structure to store customer information.
struct Customer {
    char name[50];
    unsigned long long int phone; 
    int seat;
    int id;
};

// Array of structures to store customer information.
struct Customer person[100];

//2D array decleration  for seatnumber
int seats[4][101] = {0}; // 0: Available, 1: Reserved

// Function Deceleration.............................................................................................
int choice1();                                                                    
int admin();                                                                     
int user();                                                                     
int movie(void);                                                               
void reservation();                                                            
void seat_cancellation();                                                     
void ticket1(int choice, char name[10], int id1, int price);                 
void ticket2(int choice, char name[10], int id1, int price);                 
void ticket3(int choice, char name[10], int id1, int price);                
void save_reservations(int selectedMovie);                     
void view_reserved_seats();								 

// Main Function Starts from here....................................................................................
int main()
{
	
system("color 0F");
    int choice;
    int userChoice;
  
    while (1) // Infinite loop 
    {
    	system("color 0F");
        choice = choice1();
        switch (choice)
        {
        case 1:
            system("cls");
            admin();
            break;
        case 2:
            system("cls");
            userChoice = user();
          
           
            break;
        case 3:
            
            
            exit(0);
            break;
        default:
        	system("cls");
            printf("\nPlease select the correct menu.\n\n\n\n");
            system("PAUSE");
           
        }
         printf("-----------------------------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}

// Function to display the first interface and menu of the program

int choice1()
{
	system("cls");
    int menu;
    printf("\t\t\t\t||============================================||\n");
    printf("\t\t\t\t||============================================||\n");
    printf("\t\t\t\t||                                            || \n");
    printf("\t\t\t\t||   Welcome to Movie Ticket Booking System   ||\n");
    printf("\t\t\t\t||                                            ||\n");
    printf("\t\t\t\t||============================================||\n");
    printf("\t\t\t\t||============================================||\n");
    printf("\n\t\t\t\t\t\t1. Admin System\n");
    printf("\t\t\t\t\t\t2. User System\n");
    printf("\t\t\t\t\t\t3. Exit System\n\n");
    printf("Select the interface:  ");
    scanf("%d", &menu);
    
    return menu;
}

// Admin function for admin panel.
int admin()
{
    int use;
    int i;
    printf("Enter admin_name: ");
    scanf("%s", adm);
    fflush(stdin);
    printf("Enter password: ");
    scanf("%s", pwd);
    fflush(stdin);

    if (strcmp(adm, "citizen") == 0 && strcmp(pwd, "1234") == 0)
    {
        printf("Login Successful....\n");

        system("cls");

        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||                                            || \n");
        printf("\t\t\t\t||          Welcome to Admin Panel            ||\n");
        printf("\t\t\t\t||                                            ||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\n\t\t\t\t\t1. To view the reserved Seats\n");
        printf("\t\t\t\t\t2. To change the price of tickets\n");
        printf("\t\t\t\t\t3. Exit System\n\n");
        loggedIn = 1;
         for(i=1;i<4;i++)
        {
		printf("\nSelect the Menu: ");
        scanf("%d", &use);
        
        
        
         if (use < 1 || use > 3)
            {
                printf("Invalid menu selection. Please choose a valid option.\n");
                
            }
            
              else
            {
                break;
            }
        }
        
        switch (use)
        {
        case 1:
          
			 view_reserved_seats();
             system("PAUSE");
             break;
     
            
        case 2:
        	
            printf("Enter new ticket price: ");
            scanf("%d", &ticketPrice);
            printf("Ticket price changed to: %d\n", ticketPrice);
            system("PAUSE");
            break;
            
        case 3:
            
         
            exit(0);
            break;
            
        default:
            printf("Invalid selection.\n");
            system("PAUSE");
        }
    }

    else
    {
        attempts++;
        printf("\nWrong Password\n");
        printf("\nYou had %d time wrong attempt\n", attempts);

        if (attempts == WARNING_ATTEMPTS)
        {
            printf("\nWarning: You have %d attempt(s) remaining.\n\n", MAX_ATTEMPTS - attempts);
        }
        if (attempts >= MAX_ATTEMPTS)
        {
            printf("Maximum login attempts exceeded. Exiting...\n");
            
            
            exit(0);
        }
    }
    return use;
}


// User function for user panel.
int user()
{
	
    int use;
    int i;
    int selectedMovie;
    printf("Enter user_name: ");
    scanf("%s", cus);
    while (getchar() != '\n');
    printf("Enter password: ");
    scanf("%s", pwd);
    while (getchar() != '\n');

    if (strcmp(cus, "citizen") == 0 && strcmp(pwd, "1234") == 0)
    {
        printf("Login Successful....\n");

        system("cls");

        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||                                            || \n");
        printf("\t\t\t\t||           Welcome to User Panel            ||\n");
        printf("\t\t\t\t||                                            ||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t||============================================||\n");
        printf("\t\t\t\t\t\t1. To Purchase tickets\n");
        printf("\t\t\t\t\t\t2. To Cancel Seats\n");
        printf("\t\t\t\t\t\t3. Exit System\n\n");
       
        loggedIn = 1;
    
        
        for(i=1;i<4;i++)
        {
		printf("\nSelect the Menu: ");
        scanf("%d", &use);
       
        
        
         if (use < 1 || use > 3)
            {
                printf("Invalid menu selection. Please choose a valid option.\n");
                system("PAUSE");
            }
            
              else
            {
                break;
            }
        }

        switch (use)
        {
        case 1:
            system("cls");
            reservation();
            system("PAUSE");
            break;
        case 2:
            system("cls");
            seat_cancellation();
            
            system("PAUSE");
            break;
        case 3:
            
            
            exit(0);
            break;
            
       
        default:
            printf("Invalid selection.\n");
            system("PAUSE");
        }
    }
    else
    {
        attempts++;
        printf("\nWrong Password\n");
        printf("\nYou had %d time wrong attempt.\n\n\n", attempts);

        if (attempts == WARNING_ATTEMPTS)
        {
            printf("Warning: You have %d attempt(s) remaining.\n\n", MAX_ATTEMPTS - attempts);
        }
        if (attempts >= MAX_ATTEMPTS)
        {
            printf("Maximum login attempts exceeded. Exiting...\n");
            
            exit(0);
        }
        system("PAUSE");
    }

    return use;
}

// Function to display available movies and get user's choice.
int movie()
{
     
    int i;

    do
    {
        system("cls");
        printf("\t\t\twhich movie you want to see?\n");
        printf("\t\t\t----------------------------\n\n");
        printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
        printf("\t\t\tpress 2 for Captain Marvel\n\n");
        printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
        
        printf("Select the movie: ");
        scanf("%d", &i);

        if (i< 1 || i > 3)
        {
            printf("\nInvalid movie selection. Please choose a valid option.\n");
            system("PAUSE");
        }

    } while (i < 1 || i > 3);
    
    system("cls");
    return i;
}

// Function to reserve a seat for the user.
void reservation()
{
	int i;
    int selectedMovie = movie();
    int price = ticketPrice; // Sample price, you can change it based on your requirements
    printf("\n\t\t\t\t\t\tAvailable seats:\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
printf("\t\t\t\t\t Screen for Movie %d\n\n", selectedMovie);
    // Print available seats
    for ( i = 1; i <= 100; i++)
    {
        if (seats[selectedMovie][i] == 0)
            printf(" %d \t", i);
        else
            printf(" *\t ");
        if (i % 10 == 0)
            printf("\n\n");
    }
printf("----------------------------------------------------------------------------------------------------------------------\n");
    long long int phone;
    int seatChoice;

    printf("Please enter your name: ");
    scanf(" %24[^\n]%*[^\n]",person[count].name);
    while (1) {
        printf("Please enter your phone number: ");
        if (scanf("%lld", &phone) != 1|| phone<0) {
            printf("Invalid input. Please enter a valid phone number.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
        	while (getchar() != '\n');
            break;
        }
    }
    while (1) {
        printf("Which seat number you want? ");
        if (scanf("%d", &seatChoice) != 1 || seatChoice< 1 || seatChoice > 100) {
            printf("Invalid input. Please enter a valid seat number.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else if (seats[selectedMovie][seatChoice] == 1) {
            printf("Sorry, this seat is already booked! Please choose another seat.\n");
        } else {
        	while (getchar() != '\n');
            seats[selectedMovie][seatChoice] = 1;
            break;
        }
    }
    person[count].phone = phone;
    person[count].seat = seatChoice;
    person[count].id = id1;
    // Call the appropriate ticket function based on the selected movie
    if (selectedMovie == 1)
    {
        ticket1(seatChoice, person[count].name, id1, price);
    }
    else if (selectedMovie == 2)
    {
        ticket2(seatChoice, person[count].name, id1, price);
    }
    else if (selectedMovie == 3)
    {
        ticket3(seatChoice, person[count].name, id1, price);
    }
    count++; // Total reservations made
    save_reservations(selectedMovie);
}
// Function to cancel a reserved seat.
void seat_cancellation()
{
      int selectedMovie = movie();
        if (selectedMovie == 1) {
                        printf("Avengers: EndGame)\n");
                    } else if (selectedMovie == 2) {
                        printf("Captain Marvel)\n");
                    } else if (selectedMovie == 3) {
                        printf("Spider-Man: Far From Home)\n");
                    }
                    
                    
	int i;
	char cancelName[50];
	int seatNumber;
	int id;
	int temp;
	
    printf("Enter your name: ");
    
    scanf("%s", cancelName);
	
    
    printf("Enter your booking id to cancel: ");
   
    scanf("%d", &id);
    
    
    printf("Enter your seat number to cancel: ");
   
    scanf("%d", &seatNumber);
    
    
	for (i=1;i<=3;i++){
	
    if (seatNumber < 1 || seatNumber > 100)
    {
        printf("Invalid seat number.\n");
        
           printf("Renter your seat number to cancel: ");
   
    		scanf("%d", &seatNumber);
    }
    else{
    	break;
	}
	 
}
    if (seats[selectedMovie][seatNumber] == 0)
    {
        printf("This seat is not reserved.\n");
        return;
    }
   

    for (i = 0; i < count; i++)
    {
        if (strcmp(person[i].name, cancelName) == 0 &&person[i].id == id && person[i].seat == seatNumber)
        {
            seats[selectedMovie][seatNumber] = 0;
            printf("Seat reservation for %s (ID: %d) at seat %d has been canceled.\n", person[i].name, person[i].id, seatNumber);
            
            count--;
            break;
        }
            
            // Save reservations to file after canceling the seat
          else{
		   printf("No matching reservation found for %s, booking id:%d at seat %d.\n", cancelName,id, seatNumber);
		   
	}
  			  
  			  
           
        }
        save_reservations(selectedMovie);
    }
	

// Function definitions for ticket1, ticket2, and ticket3................................
void ticket1(int choice, char name[10], int id2, int price)
{	
	system("cls");
	system("color 90");
    printf("\n-----------------THEATER BOOKING TICKET----------------\n");
    printf(" Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n", id2);
    printf(" Customer   : %s\n", name);
    printf(" Date       : 15-07-2023\n");
    printf(" Time       : 09:00 pm\n");
    printf(" Hall       : 01\n");
    printf(" Seat No.   : %d\n", choice);
    printf(" Price      : %d\n", price);
    printf("------------------------------------------------------\n");
    system("PAUSE");
}
void ticket2(int choice, char name[10], int id2, int price)
{
	system("cls");
	system("color 90");
    printf("\n-----------------THEATER BOOKING TICKET----------------\n");
    printf(" Booking ID : %d \t\t\tShow Name : Captain Marvel\n", id2);
    printf(" Customer   : %s\n", name);
    printf(" Date       : 15-07-2023\n");
    printf(" Time       : 09:00 pm\n");
    printf(" Hall       : 02\n");
    printf(" Seat No.   : %d\n", choice);
    printf(" Price      : %d\n", price);
    printf("------------------------------------------------------\n");
    system("PAUSE");
}
void ticket3(int choice, char name[10], int id2, int price)
{	
	system("cls");
	system("color 90");
    printf("\n-----------------THEATER BOOKING TICKET----------------\n");
    printf(" Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home\n", id2);
    printf(" Customer   : %s\n", name);
    printf(" Date       : 15-07-2023\n");
    printf(" Time       : 09:00 pm\n");
    printf(" Hall       : 03\n");
    printf(" Seat No.   : %d\n", choice);
    printf(" Price      : %d\n", price);
    printf("------------------------------------------------------\n");
    system("PAUSE");
}


// Function to save customer reservations and ticket details to a file.
void save_reservations(int selectedMovie) {
    char showName[30]; // Added to store show name for the ticket
    if (selectedMovie == 1) {
        strcpy(showName, "Avengers: EndGame");
    } else if (selectedMovie == 2) {
        strcpy(showName, "Captain Marvel");
    } else if (selectedMovie == 3) {
        strcpy(showName, "Spider-Man: Far From Home");
    } else {
        printf("Invalid movie selection.\n");
        return;
    }
    FILE* reservedSeatsFile = fopen(RESERVATION_FILE, "a"); // Use "a" mode to append to the file
    if (reservedSeatsFile == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(reservedSeatsFile, "\n\nReserved Seats for %s:\n", showName);
    int i, j;
    // Save ticket information to the file
    for (i = 0; i < count; i++) {
        if (seats[selectedMovie][person[i].seat] == 1) {
            fprintf(reservedSeatsFile, "\n-----------------THEATER BOOKING TICKET----------------\n");
            fprintf(reservedSeatsFile, " Booking ID : %d \t\t\tShow Name : %s\n", person[i].id, showName);
            fprintf(reservedSeatsFile, " Customer   : %s\n", person[i].name);
            fprintf(reservedSeatsFile, " Date       : 15-07-2023\n");
            fprintf(reservedSeatsFile, " Time       : 09:00 pm\n");
            fprintf(reservedSeatsFile, " Hall       : %02d\n", selectedMovie); // Assuming halls are numbered from 1 to 3
            fprintf(reservedSeatsFile, " Seat No.   : %d\n", person[i].seat);
            fprintf(reservedSeatsFile, " Price      : %d\n", ticketPrice);
            fprintf(reservedSeatsFile, "------------------------------------------------------\n");
        }
    }
    fclose(reservedSeatsFile);
    printf("Reserved seat information and ticket details saved for %s.\n", showName);
}
//function to veiw reserved seats.....................................
void view_reserved_seats() {
    int selectedMovie = movie();
    printf("\n\t\t\t\t\t\tReserved seats:\n");
printf("---------------------------------------------------------------------------------------------------------------------\n");
    
    int i, j;
    int bookedCount = 0; // Counter for booked seats
    
    for (i = 1; i <= 100; i++) {
        if (seats[selectedMovie][i] == 1) {
            for (j = 0; j < count; j++) {
                if (person[j].seat == i) {
                    bookedCount++;
   printf(" Seat No. %d, Booking ID: - %d (Reserved by: %s, Phone: %lld, Movie: ", i,person[j].id, person[j].name, person[j].phone);
                    
                    if (selectedMovie == 1) {
                        printf("Avengers: EndGame)\n");
                    } else if (selectedMovie == 2) {
                        printf("Captain Marvel)\n");
                    } else if (selectedMovie == 3) {
                        printf("Spider-Man: Far From Home)\n");
                    }
                    
                    break;
                }
            }
        }
    }
    
    if (bookedCount == 0) {
        printf("No seats have been booked for this movie yet.\n");
    }
    
printf("----------------------------------------------------------------------------------------------------------------------\n");
}


