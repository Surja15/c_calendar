#include <stdio.h>
#include <time.h>
//calendar by Surja
// Function to get the day of the week for a given date
int getDayOfWeek(int year, int month, int day) {
struct tm timeinfo = {0};
timeinfo.tm_year = year - 1900;
timeinfo.tm_mon = month - 1;
timeinfo.tm_mday = day;
mktime(&timeinfo);
return timeinfo.tm_wday;
}

// Function to display the calendar for the current month
void displayCalendar(int year, int month) {
    int day, daysInMonth, dayOfWeek;

    // Array to store the names of the months
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    // Array to store the number of days in each month
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days[1] = 29;
    // Determine the number of days in the current month
    daysInMonth = days[month - 1];
    // Determine the day of the week for the first day of the month
    dayOfWeek = getDayOfWeek(year, month, 1);
    // Print the calendar header
    printf("%s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    // Print leading spaces
    for (day = 0; day < dayOfWeek; day++)
        printf("    ");
    // Get the current day
    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);
    int currentDay = localTime->tm_mday;
    // Print the days of the month
    for (day = 1; day <= daysInMonth; day++) {
        if (day == currentDay) {
            printf("[%2d]", day);
        } else {
            printf(" %2d ", day);
        }
        if (++dayOfWeek > 6) {
            printf("\n");
            dayOfWeek = 0;
    }
    }
    printf("\n");
}

int main() {
    time_t currentTime;
    struct tm *localTime;

    // Get the current time
    currentTime = time(NULL);

    // Convert the current time to local time
    localTime = localtime(&currentTime);

    // Get the current year and month
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;

    // Display the calendar for the current month
    displayCalendar(year, month);

    return 0;}
