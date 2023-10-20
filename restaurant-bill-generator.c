#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

int main() {
    FILE *file = fopen("items.txt", "r");
    if (file == NULL) {
        printf("Could not open file items.txt");
        return 1;
    }

void print_number_in_words(int num) {
    char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if (num >= 100) {
        printf("%s Hundred ", ones[num / 100]);
        num %= 100;
    }

    if (num >= 20) {
        printf("%s ", tens[num / 10 - 2]);
        num %= 10;
    } else if (num >= 10) {
        printf("%s ", teens[num - 10]);
        return;
    }

    printf("%s ", ones[num]);
}

    Item items[100];
    int itemCount = 0;

    while (fscanf(file, "%s %f\n", items[itemCount].name, &items[itemCount].price) != EOF) {
        items[itemCount].quantity = 0;
        itemCount++;
    }

    fclose(file);

    char customerName[50];
    char customerPhone[15];

    printf("Enter customer's name: ");
    scanf("%s", customerName);
    getchar(); // consume newline left by scanf

    printf("Enter customer's phone number: ");
    scanf("%s", customerPhone);
    getchar(); // consume newline left by scanf

    srand(time(NULL));
    int invoiceNo = rand() % 100000;

    float total = 0;
    int choice;
    float quantity;

    printf("\nMenu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - %.2f\n", i + 1, items[i].name, items[i].price);
    }

    printf("\nEnter your choices (item are separated by space and quantities separated by a period): ");

    char line[100];
    fgets(line, sizeof(line), stdin); // read a line of input

        // parse the line into numbers and add the corresponding items to the bill
        char *ptr = line;
        while (*ptr != '\n' && *ptr != '\0') {
            switch(sscanf(ptr, "%d.%f", &choice, &quantity)) {
                case 2:
                    // move the pointer past the number we just read
                    while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0') ptr++;
                    break;
                case 1:
                    quantity = 1;
                    // move the pointer past the number we just read
                    while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0') ptr++;
                    break;
                default:
                    continue;
            }

            if (choice >= 1 && choice <= itemCount) {
                total += items[choice - 1].price * quantity;
                items[choice - 1].quantity += quantity;
                printf("Added %s to the bill. Current total: %.2f\n", items[choice - 1].name, total);
            } else {
                printf("Invalid choice: %d. Try again.\n", choice);
            }

            while (*ptr == ' ') ptr++;
        }

     float subtotal = total;
     float discount = subtotal * 0.10; // 10% discount
     subtotal -= discount;
     float vat = subtotal * 0.05; // 5% VAT
     total = subtotal + vat;
     printf("\n%35s\n%45s\n%s\n", "SHIPON'S RESTAURANT", "Airport Sector 6, Uttara, Dhaka 1231", "----------------------------------------------------");
     printf("Date: 20/10/2023 \nCustomer's Name: %s\nCustomer's Phone No: %s\n", customerName, customerPhone);
     printf("INVOICE NO: %05d\n", invoiceNo);
     printf("%s\n", "----------------------------------------------------");
     printf("%-15s%-15s%-15s%-15s\n", "ITEM NAME", "QTY", "PRICE", "AMOUNT");
     for (int i = 0; i < itemCount; i++) {
         if (items[i].quantity > 0) {
             printf("%-15s%-15d%-15.2f%-15.2f\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
         }
     }
     printf("%s", "----------------------------------------------------");
     printf("\n%45s%.2f TK\n%45s%.2f TK\n%45s%.2f TK\n%45s%.2f TK\n", "Sub Total:", total+discount-vat, "(-) Discount(10%):", discount, "VAT(5% after discount):", vat, "Net Payable:", total);
     printf("In words: ");
print_number_in_words((int)total);
printf("Taka only\n");
printf("Thanks for shopping");


     return 0;

}
