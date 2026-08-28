#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Reservation
{
    char passengerName[50];
    char flightNumber[10];
    char departureDate[11];
    char destination[50];
    int seatNumber;
};
#define MAX_RESERVATIONS 100
struct Reservation reservations[MAX_RESERVATIONS];
int numReservations = 0;
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void addReservation()
{
    if (numReservations >= MAX_RESERVATIONS)
    {
        printf("Maximum number of reservations reached. Cannot add more.\n");
    }
    printf("\nAdd New Reservation \n");
    printf("Enter Passenger Name: ");
    gets(reservations[numReservations].passengerName);
    printf("Enter Flight Number (e.g., FN123): ");
    gets(reservations[numReservations].flightNumber);
    printf("Enter Departure Date (DD-MM-YYYY): ");
    gets(reservations[numReservations].departureDate);
    printf("Enter Destination: ");
    gets(reservations[numReservations].destination);
    printf("Enter Seat Number: ");
    while (scanf("%d", &reservations[numReservations].seatNumber) != 1 || reservations[numReservations].seatNumber <= 0)
    {
        printf("Invalid seat number. Please enter a positive integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    numReservations++;
    printf("Reservation added successfully!\n");
}
void displayReservations()
{
    if (numReservations == 0)
    {
        printf("\nNo reservations to display.\n");
    }
    printf("\n All Reservations\n");
    for (int i = 0; i < numReservations; i++)
    {
        printf("Reservation ID: %d\n", i + 1);
        printf("Passenger Name: %s\n", reservations[i].passengerName);
        printf("Flight Number: %s\n", reservations[i].flightNumber);
        printf("Departure Date: %s\n", reservations[i].departureDate);
        printf("Destination: %s\n", reservations[i].destination);
        printf("Seat Number: %d\n", reservations[i].seatNumber);
    }
}
void searchReservation()
{
    if (numReservations == 0)
    {
        printf("\nNo reservations to search.\n");
        return;
    }
    int choice;
    char searchTerm[50];
    int found = 0;
    printf("\n Search Reservation \n");
    printf("1. Search by Passenger Name\n");
    printf("2. Search by Flight Number\n");
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
    {
        printf("Invalid choice. Please enter 1 or 2: ");
        clearInputBuffer();
    }
    printf("Enter search term: ");
    gets(searchTerm);
    printf("\nSearch Results:\n");
    for (int i = 0; i < numReservations; i++)
    {
        if (choice == 1)
        {
            if (strcmp(reservations[i].passengerName, searchTerm) == 0)
            {
                printf("\n");
                printf("Reservation ID: %d\n", i + 1);
                printf("Passenger Name: %s\n", reservations[i].passengerName);
                printf("Flight Number: %s\n", reservations[i].flightNumber);
                printf("Departure Date: %s\n", reservations[i].departureDate);
                printf("Destination: %s\n", reservations[i].destination);
                printf("Seat Number: %d\n", reservations[i].seatNumber);
                found = 1;
            }
        }
        else if (choice == 2)
        {
            if (strcmp(reservations[i].flightNumber, searchTerm) == 0)
            {
                printf("Reservation ID: %d\n", i + 1);
                printf("Passenger Name: %s\n", reservations[i].passengerName);
                printf("Flight Number: %s\n", reservations[i].flightNumber);
                printf("Departure Date: %s\n", reservations[i].departureDate);
                printf("Destination: %s\n", reservations[i].destination);
                printf("Seat Number: %d\n", reservations[i].seatNumber);
                found = 1;
            }
        }
    }
    if (!found)
    {
        printf("No matching reservations found.\n");
    }
}
void updateReservation()
{
    if (numReservations == 0)
    {
        printf("\nNo reservations to update.\n");
        return;
    }
    int idToUpdate;
    printf("\nUpdate Reservation \n");
    printf("Enter Reservation ID to update (1 to %d): ", numReservations);
    while (scanf("%d", &idToUpdate) != 1 || idToUpdate < 1 || idToUpdate > numReservations)
    {
        printf("Invalid Reservation ID. Please enter a number between 1 and %d: ", numReservations);
        clearInputBuffer();
    }
    clearInputBuffer();
    int index = idToUpdate - 1;
    printf("\nCurrent Details for Reservation ID %d \n", idToUpdate);
    printf("Passenger Name: %s\n", reservations[index].passengerName);
    printf("Flight Number: %s\n", reservations[index].flightNumber);
    printf("Departure Date: %s\n", reservations[index].departureDate);
    printf("Destination: %s\n", reservations[index].destination);
    printf("Seat Number: %d\n", reservations[index].seatNumber);
    char inputBuffer[100];
    printf("Enter New Passenger Name (current: %s, press Enter to keep): ", reservations[index].passengerName);
    gets(inputBuffer);
    if (strlen(inputBuffer) > 0)
    {
        strcpy(reservations[index].passengerName, inputBuffer);
    }
    printf("Enter New Flight Number (current: %s, press Enter to keep): ", reservations[index].flightNumber);
    gets(inputBuffer);
    if (strlen(inputBuffer) > 0)
    {
        strcpy(reservations[index].flightNumber, inputBuffer);
    }
    printf("Enter New Departure Date (current: %s, press Enter to keep): ", reservations[index].departureDate);
    gets(inputBuffer);
    if (strlen(inputBuffer) > 0)
    {
        strcpy(reservations[index].departureDate, inputBuffer);
    }
    printf("Enter New Destination (current: %s, press Enter to keep): ", reservations[index].destination);
    gets(inputBuffer);
    if (strlen(inputBuffer) > 0)
    {
        strcpy(reservations[index].destination, inputBuffer);
    }
    printf("Enter New Seat Number (current: %d, enter 0 to keep current): ", reservations[index].seatNumber);
    int newSeat;
    if (scanf("%d", &newSeat) == 1 && newSeat > 0)
    {
        reservations[index].seatNumber = newSeat;
    }
    clearInputBuffer();
    printf("Reservation updated successfully!\n");
}
int main()
{
    int choice;
    do
    {
        printf("\nFlight Reservation System Menu \n");
        printf("1. Add New Reservation\n");
        printf("2. Display All Reservations\n");
        printf("3. Search Reservation\n");
        printf("4. Update Reservation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }
        clearInputBuffer();
        switch (choice)
        {
        case 1:
            addReservation();
            break;
        case 2:
            displayReservations();
            break;
        case 3:
            searchReservation();
            break;
        case 4:
            updateReservation();
            break;
        case 5:
            printf("Exiting Flight Reservation System. Goodbye...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}