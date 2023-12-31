#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    char course[50];
    float marks;
    struct Student* next;
    struct Student* prev;
};

struct Student* createStudent(int rollNumber, char name[], char course[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    newStudent->marks = marks;
    newStudent->next = NULL;
    newStudent->prev = NULL;
    return newStudent;
}

struct Student* insertFromLast(struct Student* head, int rollNumber, char name[], char course[], float marks) {
    struct Student* newStudent = createStudent(rollNumber, name, course, marks);

    if (head == NULL) {
        return newStudent;
    }

    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStudent;
    newStudent->prev = temp;

    return head;
}

struct Student* deleteFromFront(struct Student* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Student* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    printf("Student record deleted from the front.\n");

    return head;
}

void showFront(struct Student* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Student Record at the Front:\n");
    printf("Roll Number: %d\n", head->rollNumber);
    printf("Name: %s\n", head->name);
    printf("Course: %s\n", head->course);
    printf("Marks: %.2f\n", head->marks);
}

void searchRecordAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. No records to search.\n");
        return;
    }

    struct Student *temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        printf("Record at position %d:\n", position);
        printf("Name: %s, Roll No.: %d, Course: %s, Marks: %d\n", temp->name, temp->rollNo, temp->course, temp->marks);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

struct Student* updateRecord(struct Student* head, int rollNumber, char name[], char course[], float marks) {
    struct Student* temp = head;

    while (temp != NULL) {
        if (temp->rollNumber == rollNumber) {
            strcpy(temp->name, name);
            strcpy(temp->course, course);
            temp->marks = marks;
            printf("Student record updated.\n");
            return head;
        }
        temp = temp->next;
    }

    printf("Roll Number not found. Cannot update record.\n");
    return head;
}

void display(struct Student* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student* temp = head;

    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Roll Number: %d, Name: %s, Course: %s, Marks: %.2f\n",
               temp->rollNumber, temp->name, temp->course, temp->marks);
        temp = temp->next;
    }
}

int main() {
    struct Student* head = NULL;

    int choice, rollNumber, position;
    char name[50], course[50];
    float marks;

    do {
        printf("\nStudent Record Management System Menu:\n");
        printf("1. Insert Student Record from Last\n");
        printf("2. Delete Student Record from Front\n");
        printf("3. Show Student Record (Front)\n");
        printf("4. Search Student Record (Position)\n");
        printf("5. Update Student Record\n");
        printf("6. Display All Student Records\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &rollNumber);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Course: ");
                scanf("%s", course);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                head = insertFromLast(head, rollNumber, name, course, marks);
                break;

            case 2:
                head = deleteFromFront(head);
                break;

            case 3:
                showFront(head);
                break;

            case 4:
                printf("Enter Roll Number to Search: ");
                scanf("%d", &rollNumber);
                position = searchPosition(head, rollNumber);
                if (position != -1) {
                    printf("Roll Number found at position: %d\n", position);
                } else {
                    printf("Roll Number not found.\n");
                }
                break;

            case 5:
                printf("Enter Roll Number to Update: ");
                scanf("%d", &rollNumber);
                printf("Enter New Name: ");
                scanf("%s", name);
                printf("Enter New Course: ");
                scanf("%s", course);
                printf("Enter New Marks: ");
                scanf("%f", &marks);
                head = updateRecord(head, rollNumber, name, course, marks);
                break;

            case 6:
                display(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
