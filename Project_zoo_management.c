#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice;

void Animal_Management();
void HealthRecord();
void addHealthRecord();
void FeedingSchedule();
void addFeedingSchedule();
void addAnimal();
void display();
void displayHealthRecord();
void displayFeedingSchedule();

void Staff_Management();
void New_employee();
void Display_record();
void Employee_working();
void Employee_working_records();

void Inventory_Management();
void New_stock();
void Display_stock();
void Update_stock();
void Order();
void Display_order();

int Financial_Management();
int bill();
int expen();
int amount(int person);
int inventory();
int staff();
int newbill();
int previousbill();
int staffsalary();
int dispalysaly();

int main()
{
    printf("\n \t \t Welcome To The ZOO Management System \t \t \n");
    printf("------------------------------------------------------------------\n");
    do
    {
        printf("\n\t \t \t Main Menu \t \n");
        printf("\t\t\t-----------\t\n\n");
        printf("1: Animal Management\n");
        printf("2: Staff Management\n");
        printf("3: Inventory Management\n");
        printf("4: Financial Management\n");
        printf("\n");
        printf("Enter Your Desired Option number from Above: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Animal_Management();
            break;
        case 2:
            Staff_Management();
            break;

        case 3:
            Inventory_Management();
            break;
        case 4:
            Financial_Management();
            break;
        case 5:
            printf("Thanks for using Our Program");
            break;
        default:
            printf("Please enter a valid Option\n");
            break;
        }
    } while (choice != 5);

    printf("\n");
    return 0;
}
void Animal_Management()
{

    while (1)
    {
        printf("\n\n--- Animal Management System ---\n");
        printf("\n");
        printf("1. Add Animal\n");
        printf("2. Display All Animals\n");
        printf("3. Health Record\n");
        printf("4. Feeding Schedule\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAnimal();
            break;
        case 2:
            display();
            break;
        case 3:
            HealthRecord();
            break;
        case 4:
            FeedingSchedule();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

void addAnimal()
{
    FILE *ptr;
    ptr = fopen("D:\\project\\New folder\\animal.txt", "a+");

    int id, num;
    char species[50];
    char name[50];

    printf("Enter Animal ID: ");
    scanf("%d", &id);

    printf("Enter Species: ");
    scanf("%s", species);

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Cage Number: ");
    scanf("%d", &num);

    fprintf(ptr, "\nID: %d, Species: %s, Name: %s, Cage Number: %d", id, species, name, num);
    fclose(ptr);

    printf("Animal added successfully and saved to file!\n");
}

void display()
{
    FILE *ptr;
    char buffer[200];

    if (ptr == NULL)
    {
        printf("Error opening file!\n");
    }

    ptr = fopen("D:\\project\\New folder\\animal.txt", "r");
    printf("\tAnimal Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), ptr))
    {
        printf("%s", buffer);
    }
    printf("\n");

    fclose(ptr);
}

void HealthRecord()
{
    while (1)
    {
        printf("\t------- Health Record -----\n");
        printf("1:Add New Health Record  2: Display Health Record   3:Go Back To Previous\n");
        printf("\t Enter the choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addHealthRecord();
            break;
        case 2:
            displayHealthRecord();
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}

void addHealthRecord()
{
    {
        FILE *h;
        if (h == NULL)
        {
            printf("No Health Record\n");
        }
        h = fopen("D:\\project\\New folder\\health.txt", "a+");

        char lastCheckupDate[15];
        char condition[100];
        int id;

        printf("Enter Animal ID: ");
        scanf("%d", &id);

        printf("Enter Last Checkup Date (DD-MM-YYYY): ");
        scanf("%s", lastCheckupDate);

        printf("Enter Health Condition: ");
        scanf("%s", condition);

        fprintf(h, "Animal ID: %d,Checkup Date: %s, Health Condition: %s\n", id, lastCheckupDate, condition);
        fclose(h);
    }
}

void displayHealthRecord()
{
    FILE *h;
    char buffer[200];

    if (h == NULL)
    {
        printf("No Data to Display\n");
    }
    h = fopen("D:\\project\\New folder\\health.txt", "r");
    printf("\tHealth Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), h))
    {
        printf("%s", buffer);
    }
    fclose(h);
}

void FeedingSchedule()
{
    while (1)
    {
        printf("\n\t------- Feeding Schedule Record -----\n");
        printf("1:Add New Schedule Record  2: Display Schedules Record   3:Exit\n");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addFeedingSchedule();
            break;
        case 2:
            displayFeedingSchedule();
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
void addFeedingSchedule()
{
    FILE *t;
    if (t == NULL)
    {
        printf("No feeding schedule\n");
    }
    t = fopen("D:\\project\\New folder\\feedtime.txt", "a+");

    char feedTime[15];
    char foodType[50];
    int id;

    printf("Enter Animal ID: ");
    scanf("%d", &id);

    printf("Enter Feeding Time (e.g., 08:00AM): ");
    scanf("%s", feedTime);

    printf("Enter Food Type: ");
    scanf("%s", foodType);

    fprintf(t, "Animal ID: %d,Feeding Time: %s, Food Type: %s \n", id, feedTime, foodType);
    fclose(t);
}

void displayFeedingSchedule()
{
    FILE *t;
    char buffer[200];

    if (t == NULL)
    {
        printf("Error opening file!\n");
    }
    t = fopen("D:\\project\\New folder\\feedtime.txt", "r");
    printf("\tFeeding Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), t))
    {
        printf("%s", buffer);
    }
    fclose(t);
}

void Staff_Management()
{
    printf("\n\t ------ Staff Scheduling ------\n");
    printf("\n");
    printf("1: New Employee Entry  2: Display Employee Record\n\n");
    printf("3: Employee working    4: Employee working records \n \t\t 5: Exit\n");
    printf("\nEnter the choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        New_employee();
        break;
    case 2:
        Display_record();
        break;
    case 3:
        Employee_working();
        break;
    case 4:
        Employee_working_records();
        break;
    case 5:
        exit(1);

    default:
        printf("Invalid Choice\n");
        break;
    }
}

void New_employee()
{
    FILE *ptr;
    ptr = fopen("D:\\project\\staff_new_employee.txt", "a+");

    char name[50];
    int num, id, sal, age;

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter phone number: ");
    scanf("%d", &num);

    printf("New I.D number: ");
    scanf("%d", &id);

    printf("Enter Starting Salary: ");
    scanf("%d", &sal);

    fprintf(ptr, "Name: %s , Age: %d ,Phone Number: %d , Id: %d ,Salary: %d \n", name, age, num, id, sal);

    fclose(ptr);
}

void Display_record()
{
    FILE *ptr;
    char buffer[200];

    ptr = fopen("D:\\project\\staff_new_employee.txt", "r");
    if (ptr == NULL)
    {
        printf("No file Exits\n");
    }

    printf(" Employees Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), ptr))
    {
        printf("%s", buffer);
    }

    fclose(ptr);
}

void Employee_working()
{
    FILE *emp;
    emp = fopen("D:\\project\\employee.txt", "a+");

    char name[50], working[50], dn[8];
    int time;

    printf("Enter the employee name: ");
    scanf("%s", name);

    printf("Working as: \n 1: Animal_Cleaning  2: Animal_Feeding  3: Security  4: Zoo_Cleaning \n Enter: ");
    scanf("%s", working);

    printf("Enter working hours: ");
    scanf("%d", &time);

    printf("Enter working shift( day / night ): ");
    scanf("%s", dn);

    fprintf(emp, "Name: %s ,Working as: %s , Working Hours: %d , Working Shift: %s \n", name, working, time, dn);

    fclose(emp);
}

void Employee_working_records()
{

    FILE *emp;
    char buffer[200];

    emp = fopen("D:\\project\\employee.txt", "r");
    if (emp == NULL)
    {
        printf("No file Exits\n");
    }

    printf("\tEmployees Working Records:\n");
    printf("----------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), emp))
    {
        printf("%s", buffer);
    }

    fclose(emp);
}

void Inventory_Management()
{
    while (1)
    {
        printf("\n\t -------Inventory Management------- \n");

        printf("\n1: New Stock Entry  2: Display Stock Records\n  \n3: Update Stocks    4: Order item\n\n5: Display Orders   6: Exit\n");
        printf("\nEnter the choice:  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            New_stock();
            break;
        case 2:
            Display_stock();
            break;
        case 3:
            Update_stock();
            break;
        case 4:
            Order();
            break;
        case 5:
            Display_order();
            break;
        case 6:
            exit(1);
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
void New_stock()
{
    char name[60];
    char quantity[10];
    char date[12];
    FILE *st;
    st = fopen("D:\\project\\New folder\\stock_entry.txt", "a+");
    if (st == NULL)
    {
        printf("No file exits");
    }
    printf("Enter item Name: ");
    scanf("%s", name);

    printf("Enter quantity of item in kgs: ");
    scanf("%s", &quantity);

    printf("Enter the date (dd-mm-yyyy): ");
    scanf("%s", date);

    fprintf(st, "Item Name: %s, Quantity: %s, Date: %s \n", name, quantity, date);
    fclose(st);
}
void Display_stock()
{
    FILE *st;
    char buffer[200];

    st = fopen("D:\\project\\New folder\\stock_entry.txt", "r");
    if (st == NULL)
    {
        printf("No stock entered\n");
    }

    printf(" Stock Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), st))
    {
        printf("%s", buffer);
    }

    fclose(st);
}
void Update_stock()
{
    char itemName[60];
    int newQuantity;
    char buffer[512];
    char tempFilePath[] = "D:\\project\\New folder\\temp_stock.txt";
    FILE *st, *tempFile;

    st = fopen("D:\\project\\New folder\\stock_entry.txt", "r");
    if (st == NULL)
    {
        printf("Stock file does not exist.\n");
        return;
    }

    tempFile = fopen(tempFilePath, "w");
    if (tempFile == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(st);
        return;
    }

    printf("Enter the name of the item to update: ");
    scanf("%s", itemName);
    printf("Enter the new quantity (in kgs): ");
    scanf("%d", &newQuantity);

    while (fgets(buffer, sizeof(buffer), st))
    {
        char name[60];
        int quantity;
        char recordDate[12];

        if (sscanf(buffer, "Item Name: %[^,], Quantity: %d, Date: %[^,],", name, &quantity, recordDate) == 3)
        {
            if (strcmp(name, itemName) == 0)
            {
                fprintf(tempFile, "Item Name: %s, Quantity: %d, Date: %s,\n", name, newQuantity, recordDate);
            }
            else
            {
                fprintf(tempFile, "%s", buffer);
            }
        }
        else
        {
            printf("Invalid line format: %s", buffer);
        }
    }

    fclose(st);
    fclose(tempFile);

    remove("D:\\project\\New folder\\stock_entry.txt");
    rename(tempFilePath, "D:\\project\\New folder\\stock_entry.txt");

    printf("Stock updated successfully.\n");
}
void Order()
{

    int item;
    char date[12];
    int a[20];
    int p[20];
    FILE *order;

    // Open the file for appending
    order = fopen("D:\\project\\Display_order.txt", "a+");

    if (order == NULL)
    { // Check if the file opened successfully
        printf("Error: Could not open file.\n");
    }

    printf("Enter the number of items ordered: ");
    scanf("%d", &item);

    // Validate the number of items
    if (item > 20)
    {
        printf("Error: Maximum number of items is 20.\n");
       
    }

    printf("Enter the quantity of each item: ");
    for (int i = 0; i < item; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the date (dd-mm-yyyy): ");
    scanf("%s", date);

    printf("Enter the price of each item: ");
    for (int i = 0; i < item; i++)
    {
        scanf("%d", &p[i]);
    }

    // Write data to the file
    fprintf(order, "Number of items: %d\n", item);
    fprintf(order, "Date of order: %s\n", date);
    fprintf(order, "Quantities and prices:\n");

    for (int i = 0; i < item; i++)
    {
        fprintf(order, "Item %d: Quantity = %d, Price = %d\n", i + 1, a[i], p[i]);
    }

    printf("Order placed successfully!\n");

    // Close the file
    fclose(order);
}
void Display_order()
{
    FILE *order;
    char buffer[200];

    order = fopen("D:\\project\\Display_order.txt", "r");
    if (order == NULL)
    {
        printf("No orders yet\n");
    }

    printf(" Order Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), order))
    {
        printf("%s", buffer);
    }

    fclose(order);
}

int Financial_Management()
{
    int choice;
    while (1)
    {
        printf("\n\t------Financial Management------\n");
        printf("\n1: Billing     2: Expenses     3: Exit\n");
        printf("\nSelect option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bill();
            break;
        case 2:
            expen();
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Not a valid choice\n");
            break;
        }
        printf("\n");
    }
}
int bill()
{

    int des;
    while (1)
    {
        printf("\nChoose option\n");
        printf("1: New Bill    2: Previous Bill  3: Previous Options \n");
        printf("Enter : ");
        scanf("%d", &des);

        switch (des)
        {
        case 1:
            newbill();
            break;
        case 2:
            previousbill();
            break;
        case 3:
            printf("Going to previous option\n");
            return 1;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 1;
}

int newbill()
{
    FILE *bill;
    bill = fopen("D:\\project\\Billing.txt", "a+");
    if (bill == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    char name[50];
    int age, person, total;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number of persons: ");
    scanf("%d", &person);
    total = amount(person);
    printf("For %d people, amount is %d\n", person, total);

    fprintf(bill, "\nDate: %s ,Time: %s, \n Name: %s, Number of Persons: %d, Total Amount: %d\n",__DATE__,__TIME__, name, person, total);

    fclose(bill);

    return 1;
}

int previousbill()
{
    FILE *billFile;
    char buffer[500];

    billFile = fopen("D:\\project\\Billing.txt", "r");
    if (billFile == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    printf("Saved Billing Records:\n");
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), billFile))
    {
        printf("%s", buffer);
    }

    fclose(billFile);

    return 1;
}
int amount(int person)
{
    return 70 * person;
}
int expen()
{
    int decision;
    while (1)
    {
        printf("\nChoose option\n");
        printf("1: Inventory Expences    2: Staff Salary    3:Previous Option\n");
        scanf("%d", &decision);
        switch (decision)
        {
        case 1:
            inventory();
            break;
        case 2:
            staffsalary();
            break;
        case 3:
            printf("Going to previous option\n");
            return 1;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 1;
}

int inventory()
{
    int order[10];
    int n, sum = 0;
    int price[10];
    printf("Enter the number of items which are ordered: ");
    scanf("%d", &n);
    printf("\nEnter the quantities of per iterm which are ordered: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &order[i]);
    }
    printf("\nEnter the price of individual quantities: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter price %d:  ", i + 1);
        scanf("%d", &price[i]);
        sum += price[i];
    }
    printf("Total pay amout is : rs.%d", sum);
    return 1;
}

int staffsalary()
{
    int click;
    while (1)
    {
        printf("\nChoose option\n");
        printf("1: New Salary Input    2: Previous Salaries   3: Go back\n");
        scanf("%d", &click);
        switch (click)
        {
        case 1:
            staff();
            break;
        case 2:
            dispalysaly();
            break;
        case 3:
            printf("Going back\n");
            return 1;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 1;
}

int staff()
{
    FILE *sly;
    sly = fopen("D:\\project\\Salary.txt", "a+");
    int salary, day, r, original;
    char ename[50];
    printf("Enter the employee name: ");
    scanf("%s", ename);
    printf("Enter the monthly salary: ");
    scanf("%d", &salary);
    r = salary / 30;
    printf("\nEnter the number of days employee is present: ");
    scanf("%d", &day);
    original = day * r;
    printf("The total salary is : rs. %d", original);

    fprintf(sly, "Name: %s, Monthly Salary: %d, Days Present: %d, Total Salary: %d \n", ename, salary, day, original);

    fclose(sly);

    return 1;
}

int dispalysaly()
{
    FILE *sly;
    char buffer[200];

    sly = fopen("D:\\project\\Salary.txt", "r");
    if (sly == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    printf("\tPrevious Salaries:\n");
    
    printf("-------------------------------------\n");

    while (fgets(buffer, sizeof(buffer), sly))
    {
        printf("%s ", buffer);
    }

    fclose(sly);

    return 1;
}
