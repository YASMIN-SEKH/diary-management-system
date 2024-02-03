#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for diary entries
struct DiaryEntry {
    char date[20];
    char entry[500];
};

// Function to add a new entry to the diary
void addEntry(struct DiaryEntry *diary, int *count) {
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", diary[*count].date);
    printf("Enter your entry: ");
    getchar(); // Clear the input buffer
    fgets(diary[*count].entry, sizeof(diary[*count].entry), stdin);
    (*count)++;
}

// Function to display all entries in the diary
void displayEntries(struct DiaryEntry *diary, int count) {
    if (count == 0) {
        printf("Diary is empty!\n");
        return;
    }
    printf("Diary Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\nEntry: %s\n", diary[i].date, diary[i].entry);
        printf("--------------------\n");
    }
}

int main() {
    struct DiaryEntry diary[100]; // Assuming a maximum of 100 entries
    int count = 0;
    int choice;

    while (1) {
        printf("\nDiary Management System\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &count);
                break;
            case 2:
                displayEntries(diary, count);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
