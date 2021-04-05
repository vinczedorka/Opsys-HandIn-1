#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int pLength = 1;

struct Person
{
    char firstName[20];
    char lastName[20];
    char birthYear[5];
    char phoneNumber[12];
    char extraCharge[5];
};

void printMenu();
void addPerson(struct Person p[MAX]);
void modifyPerson(struct Person p[MAX]);
void deletePerson(struct Person p[MAX]);
void printData(struct Person p[MAX]);
void readDatabase(struct Person p[MAX]);
void writeDatabase(struct Person p[MAX]);

int main()
{
    int userOption;
    struct Person p[MAX];

    readDatabase(p);

    do
    {
        printMenu();
        scanf("%d", &userOption);
        switch (userOption)
        {
        case 0:
            writeDatabase(p);
            break;
        case 1:
            addPerson(p);
            break;
        case 2:
            modifyPerson(p);
            break;
        case 3:
            deletePerson(p);
            break;
        case 4:
            printData(p);
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while (userOption != 0);

    return 0;
}

void printMenu()
{
    printf("\n=================");
    printf("\nVACCINATION MENU");
    printf("\n=================");
    printf("\n1 - add");
    printf("\n2 - modify");
    printf("\n3 - delete");
    printf("\n4 - list data");
    printf("\n0 - exit & save");
    printf("\n-----------------");
    printf("\nPick a number: ");
}

void addPerson(struct Person p[MAX])
{
    printf("=================");
    printf("\nADD");
    printf("\n-----------------\n");
    printf("Name: ");
    scanf("%20s %20s", &p[pLength].firstName, &p[pLength].lastName);
    printf("Birth year: ");
    scanf("%4s", &p[pLength].birthYear);
    printf("Phone number: ");
    scanf("%11s", &p[pLength].phoneNumber);
    printf("Do you agree to pay (yes/no): ");
    scanf("%4s", &p[pLength].extraCharge);
    pLength++;
}

void modifyPerson(struct Person p[MAX])
{
    int modifyNumber;
    printf("=================");
    printf("\nMODIFY");
    printf("\n-----------------");
    printf("\nNumber to modify: ");
    scanf("%d", &modifyNumber);
    printf("\nOriginal data: %s %s, %s, %s, %s\n", &p[modifyNumber].firstName, &p[modifyNumber].lastName, &p[modifyNumber].birthYear, &p[modifyNumber].phoneNumber, &p[modifyNumber].extraCharge);
    printf("New name: ");
    scanf("%20s %20s", &p[modifyNumber].firstName, &p[modifyNumber].lastName);
    printf("New birth year: ");
    scanf("%4s", &p[modifyNumber].birthYear);
    printf("New phone number: ");
    scanf("%11s", &p[modifyNumber].phoneNumber);
    printf("Do you agree to pay (yes/no): ");
    scanf("%4s", &p[modifyNumber].extraCharge);
}

void deletePerson(struct Person p[MAX])
{
    int deleteNumber;
    printf("=================");
    printf("\nDELETE");
    printf("\n-----------------");
    printf("\nNumber to delete: ");
    scanf("%d", &deleteNumber);
    for (int i = deleteNumber; i < pLength; i++)
    {
        p[i] = p[i + 1];
    }
    pLength--;
}

void printData(struct Person p[MAX])
{
    printf("=================");
    printf("\nLIST DATA");
    printf("\n-----------------");
    for (int i = 1; i < pLength; i++)
    {
        printf("\n%d: %s %s, %s, %s, %s", i, &p[i].firstName, &p[i].lastName, &p[i].birthYear, &p[i].phoneNumber, &p[i].extraCharge);
    }
}

void readDatabase(struct Person p[MAX])
{
    FILE *f;
    f = fopen("data.txt", "r");
    if (f == NULL)
    {
        perror("File opening error\n");
        exit(1);
    }

    //char str1[100], str2[100], str3[100];
    //int int1=0;
    //int int2=0;

    while (!feof(f))
    {
        //fscanf(f, "%s %s %d %d %s", str1, str2, &int1, &int2, str3);
        fscanf(f, "%s %s %s %s %s", &p[pLength].firstName, &p[pLength].lastName, &p[pLength].birthYear, &p[pLength].phoneNumber, &p[pLength].extraCharge);

        pLength++;

        //printf("%s - %s - %d - %d - %s", str1, str2, int1, int2, str3);
        //printf("%s - %s - %s - %s - %s", &p[pLength].firstName, &p[pLength].lastName, &p[pLength].birthYear, &p[pLength].phoneNumber, &p[pLength].extraCharge);
        //printf("\nOriginal data: %s %s, %s, %s, %s\n", &p[modifyNumber].firstName, &p[modifyNumber].lastName, &p[modifyNumber].birthYear, &p[modifyNumber].phoneNumber, &p[modifyNumber].extraCharge);
        //printf("\n");
        //printf("*************");
    }
    //printf("\n");
    fclose(f);
}

void writeDatabase(struct Person p[MAX])
{
    FILE *f;
    f = fopen("data.txt", "w");
    // if (f == NULL)
    // {
    //     perror("File opening error\n");
    //     exit(1);
    // }

    for (int i = 1; i < pLength; i++)
    {
        // char buff[MAX];
        // memset(buff, 0, MAX);
        
        //fscanf(f, "%s %s %s %s %s", &p[pLength].firstName, &p[pLength].lastName, &p[pLength].birthYear, &p[pLength].phoneNumber, &p[pLength].extraCharge);
        // char tmp[200];
        
        // strcat(buff, &p[i].firstName);
        // strcat(buff, " ");
        // strcat(buff, &p[i].lastName);
        // strcat(buff, " ");
        // strcat(buff, &p[i].birthYear);
        // strcat(buff, " ");
        // strcat(buff, &p[i].phoneNumber);
        // strcat(buff, " ");
        // strcat(buff, &p[i].extraCharge);
        
        // fputs(buff, f);
        
        //fputs("%s %s %s %s %s", &p[i].firstName, &p[i].lastName, &p[i].birthYear, &p[i].phoneNumber, &p[i].extraCharge, f);
        fprintf(f,"%s %s %s %s %s", &p[i].firstName, &p[i].lastName, &p[i].birthYear, &p[i].phoneNumber, &p[i].extraCharge);
        //printf("%s - %s - %s - %s - %s", &p[pLength].firstName, &p[pLength].lastName, &p[pLength].birthYear, &p[pLength].phoneNumber, &p[pLength].extraCharge);
        //printf("\nOriginal data: %s %s, %s, %s, %s\n", &p[modifyNumber].firstName, &p[modifyNumber].lastName, &p[modifyNumber].birthYear, &p[modifyNumber].phoneNumber, &p[modifyNumber].extraCharge);
        //printf("\n");
        if(i<pLength-1){
            fprintf(f,"\n");
        }

    }
    //printf("\n");
    fclose(f);
}