# Restaurant Bill Generator 
This is a C program that generates a bill for a customer based on the items and quantities they choose from a menu. The menu is imported from an external text (.txt) file. The program first asks the user for the customer’s name and phone number to get started. The program then reads the items and their prices from the text file, asks the user to enter the choices following a certain protocol for including both item number and quantity, and then calculates the total amount with a 10% discount on the subtotal and a 5% VAT after the discount. Lastly, the program prints the bill in words (up to 3 digits) and numbers.

### Basic functionalities and features of the program

1. **Data Structure**: The program uses a struct `Item` to store information about each item, including its name, price, and quantity.

2. **File Reading**: The program reads item data from a file named "items.txt". Each line in the file should contain an item's name and price, separated by a space.

3. **Customer Input**: The program prompts the customer to enter their name and phone number. It also allows the customer to order items from a menu.

4. **Order Processing**: The customer's order is processed by reading a line of input where items are separated by space and quantities are separated by a period. For example, "1.2 3.1" means the customer orders 2 quantities of item 1 and 1 quantity of item 3.

5. **Invoice Generation**: After processing the order, the program generates an invoice that includes:
   - The date, customer's name, phone number, and invoice number.
   - A list of ordered items with their names, quantities, prices, and amounts.
   - The subtotal (total before discount and VAT).
   - A 10% discount on the subtotal.
   - A 5% VAT applied after the discount.
   - The net payable amount (subtotal - discount + VAT).

6. **Amount in Words**: The program also prints the total amount payable in words.

7. **File Details**: The file "items.txt" is expected to be in the same directory as your C program. Each line in the file represents an item available for purchase in your restaurant. Each line should contain an item's name and price, separated by a space.

_Please note that this program does not handle invalid inputs gracefully. If the file is not found or the input format is not as expected, it may crash or behave unexpectedly._

## Sample Input Dataset

**items.txt**
```
Burger 90
Pizza 200
Soda 60
Water 15
Chicken 100
Sauce 5
Sandwich 150
Pasta 260
```
Note that in the text file item names and prices are separated by a space. 

**User Input**
```
Enter customer's name: John
Enter customer's phone number: 01234567890
Enter your choices (items are separated by space and quantities separated by a period from the item): 1.2 2.1 5.1 6.2 8.1
```

In this example, the user named John with phone number 01234567890 orders 2 Burgers, 1 Pizza, 1 Chicken, 2 Sauce, and 1 Pasta dish. The program will then generate a random invoice number, calculate the total cost, apply the discount and VAT, and print out the bill.

## Demo screenshots for the sample inputs 

**Screenshot of the Input File:**  The ‘items.txt’ file which contains the menu items and their prices.  ![image](https://github.com/iamnazmulhasan/restaurant-bill-generator/assets/26362912/9feef7f9-9292-4167-93b6-b94907c06eea)




**Screenshot of the Program Start**: The start of the program, showing the menu after providing customer's name and phone number. ![image](https://github.com/iamnazmulhasan/restaurant-bill-generator/assets/26362912/9fe87129-857a-49e3-928d-1b89ae75d0b5)


**Screenshot of User Input**: Entering choices for items to add to the bill. ![image](https://github.com/iamnazmulhasan/restaurant-bill-generator/assets/26362912/78e2a153-9f9e-46f9-ba7c-a4dc985f79a8)


**Screenshot of Bill Calculation**: The program prints a formal menu enlisting all the selected items and their quantities, generates a random invoice number, calculates the total cost, applies discount and VAT, and prints out the bill. ![image](https://github.com/iamnazmulhasan/restaurant-bill-generator/assets/26362912/6ecce926-46b2-4850-b61b-7fc6969c8944)



**Screenshot of Final Output**: The final output of the program, showing the total cost in words. ![image](https://github.com/iamnazmulhasan/restaurant-bill-generator/assets/26362912/17d5e1ed-4e39-4276-ae5a-78316843fef4)

## Environment Setup to run this Program
To run this C program, you would need the following environment setup:

**Operating System:** Any operating system that supports C programming can be used. This includes Windows, macOS, and Linux.

**C Compiler:** You will need a C compiler to compile your program. The GNU Compiler Collection (GCC) is a popular choice and is available on most platforms. On Windows, you can use MinGW which includes GCC. On macOS, you can use Xcode Command Line Tools which includes GCC. On Linux, GCC is usually pre-installed or can be easily installed through the package manager.

**Text Editor or IDE:** You will need a text editor or an Integrated Development Environment (IDE) to write your code. Some popular choices include Visual Studio Code, Sublime Text, Atom, or an IDE like CLion or Code::Blocks.

**Terminal:** You will need a terminal to run the compiler and your program. On Windows, you can use Command Prompt or PowerShell. On macOS and Linux, you can use Terminal.

**items.txt File:** The program reads from a file named “items.txt”. This file should be located in the same directory as your C program and should contain the item data for your program to read.

### Steps to compile and run the C program on Windows with the minGW compiler:

1. **Open Command Prompt**: You can do this by searching for "cmd" in the Start menu.

2. **Navigate to Your Program's Directory**: Use the `cd` command to change directories in the command prompt. For example, if your program is in a directory called "C:\myprograms", you would type `cd C:\myprograms` and press Enter.

3. **Compile Your Program**: Use the `gcc` command to compile your program. For example, if your program's file name is _program.c,_ you would type `gcc -o program program.c` and press Enter. This tells GCC to compile "program.c" and output the result to a file named "program". If there are no errors in your code, GCC will create an executable file in the same directory. Here in this case the program file name is `restaurant-bill-generator.c`

4. **Run Your Program**: To run your program, simply type `program` and press Enter. This will execute the file named "program" that was created by GCC.


_Note: This program was created in collaboration with two of my other team members namely [Nazmul Hasan Shipon](https://github.com/iamnazmulhasan) and [Maimuna Akter](https://github.com/maimuna1711)._
