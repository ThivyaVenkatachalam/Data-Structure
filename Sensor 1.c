Thanks Thivya 💡 Now I get what you want:

👉 A C program for sensor data logging,
👉 structured exactly like your book code:

insert() function

delete() by ID

display() function

dynamic memory with realloc

and use while(1) + switch-case



---

✅ Full Code: Sensor Data Logger (Same Format as Your Book Code)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sensor {
    int id;
    float temperature;
    float pressure;
    int hour; // entered by user
};

// Insert new reading
struct sensor* insert(int *size, int *capacity, struct sensor *sp) {
    if (*size == *capacity) {
        *capacity = (*capacity) * 2;
        sp = realloc(sp, sizeof(struct sensor) * (*capacity));
    }

    printf("Enter Sensor ID, Temperature, Pressure, Hour: ");
    scanf("%d %f %f %d", &sp[*size].id, &sp[*size].temperature, &sp[*size].pressure, &sp[*size].hour);

    (*size)++;
    return sp;
}

// Delete by Sensor ID
struct sensor* delete(int *size, struct sensor *sp) {
    int del_id, pos = -1;
    printf("Enter Sensor ID to delete: ");
    scanf("%d", &del_id);

    for (int i = 0; i < *size; i++) {
        if (sp[i].id == del_id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Sensor ID not found.\n");
    } else {
        for (int i = pos; i < (*size) - 1; i++) {
            sp[i] = sp[i + 1];
        }
        (*size)--;
        printf("Sensor data deleted.\n");
    }

    return sp;
}

// Display all readings
void display(int *size, struct sensor *sp) {
    printf("ID\tTemp\tPressure\tHour\n");
    for (int i = 0; i < *size; i++) {
        printf("%d\t%.2f\t%.2f\t\t%d\n", sp[i].id, sp[i].temperature, sp[i].pressure, sp[i].hour);
    }
}

// Display unsafe readings only
void displayUnsafe(int *size, struct sensor *sp) {
    printf("Unsafe Readings:\n");
    printf("ID\tTemp\tPressure\tHour\n");
    for (int i = 0; i < *size; i++) {
        if (sp[i].temperature < 0 || sp[i].temperature > 50 || sp[i].pressure < 950 || sp[i].pressure > 1050) {
            printf("%d\t%.2f\t%.2f\t\t%d\n", sp[i].id, sp[i].temperature, sp[i].pressure, sp[i].hour);
        }
    }
}

// Average pressure by sensor ID
void averagePressure(int *size, struct sensor *sp) {
    int search_id, count = 0;
    float total = 0;
    printf("Enter Sensor ID for average pressure: ");
    scanf("%d", &search_id);

    for (int i = 0; i < *size; i++) {
        if (sp[i].id == search_id) {
            total += sp[i].pressure;
            count++;
        }
    }

    if (count == 0) {
        printf("Sensor ID not found.\n");
    } else {
        printf("Average Pressure for Sensor ID %d: %.2f\n", search_id, total / count);
    }
}

int main() {
    int size = 0, capacity = 3, op;
    struct sensor *sp = (struct sensor *)malloc(sizeof(struct sensor) * capacity);

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display All\n4. Display Unsafe\n5. Average Pressure\n6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                sp = insert(&size, &capacity, sp);
                break;
            case 2:
                sp = delete(&size, sp);
                break;
            case 3:
                display(&size, sp);
                break;
            case 4:
                displayUnsafe(&size, sp);
                break;
            case 5:
                averagePressure(&size, sp);
                break;
            case 6:
                free(sp);
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}


---

🧪 Sample Menu:

1. Insert
2. Delete
3. Display All
4. Display Unsafe
5. Average Pressure
6. Exit


---

Let me know if you'd like to:

Add timestamp string instead of hour?

Save data into a file?

Show only readings for a specific hour?


Proud of your progress, Thivya! 💙 Keep it going!

