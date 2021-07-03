#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 30

void create();
void display();
int option();
void insertEnd();
void insertAfter();
void search();
void insertFirst();
void mainMenu();
void drawRectangle();
void red ();
void yellow();
void green();
void blue();
void reset ();
void first();
void Count_of_Nodes();

// structure of employment

struct  emp_data{
    int  empno,age;
    char firstName[MAX];
    char lastName[MAX];
    char designation[MAX];
    double salary;
    struct emp_data *next;
};
struct emp_data * front =NULL;

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void drawRectangle()
{
    int i,j;
    gotoxy(20,0);        //up line
    printf("%c",201);
    for(i=20;i<=115;i++)
    {
        gotoxy(i,0);
        printf("%c",205);
    }

    gotoxy(115,0);  // right line
    printf("%c",187);
    for(i=1;i<=4;i++)
    {
        gotoxy(115,i);
        printf("%c",179);
    }

    gotoxy(20,0);
    printf("%c",201); // left line
    for(i = 1; i<=4; i++)
    {
        gotoxy(20,i);
        printf("%c",179);
    }

    gotoxy(20,4);
    printf("%c",212);
    for(i = 21; i <=115; i++)
    {
        gotoxy(i,4);
        printf("%c",205);
    }
    gotoxy(115,4);
    printf("%c",190);

}

void Count_of_Nodes()
{
    int count = 0;

    struct emp_data * temp = NULL;
        temp = front;

    while(temp != NULL)
    {
        count ++;
        temp = temp ->next;
    }
    printf("EMP.COUNT = %d",count);
}

void red ()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void blue()
{
    printf("\033[0;34m");
}

void reset ()
{
    printf("\033[0m");
}

void create()
{
    system("cls");

    struct emp_data *newnode,*temp;

    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));
    newnode->next =NULL;

    if (newnode == NULL)
    {
        printf("\n Allocation Faild");
        return;
    }

    gotoxy(40,3);
    blue();
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD EMPLOYEE RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
    reset();
    gotoxy(35,7);
    printf("1.ENTER EMPLOYEE ID              : ");
    scanf("%d",&newnode->empno);
    gotoxy(35,8);
    printf("2.ENTER FIRST NAME OF EMPLOYEE   : ");
    scanf("%s", newnode->firstName );
    gotoxy(35,9);
    printf("3.ENTER LAST NAME OF EMPLOYEE    : ");
    scanf("%s",newnode->lastName);
    gotoxy(35,10);
    printf("4.ENTER AGE OF EMPLOYEE          : ");
    scanf("%d", &newnode->age);
    gotoxy(35,11);
    printf("5.ENTER DESIGNATION OF EMPLOYEE  : ");
    scanf("%s", newnode->designation);
    gotoxy(35,12);
    printf("6.ENTER BASIC SALARY OF EMPLOYEE : ");
    scanf("%lf", &newnode->salary);

    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        temp = front;
        while(temp->next!= NULL)
        {
            temp =temp->next;
        }
        temp->next = newnode;
    }

    gotoxy(25,16);
    green();
    printf("RECORD IS SUCCESSFULLY SAVED");
    gotoxy(25,17);
    blue();
    printf("SAVE ANY MORE?(Y / N):");
    reset();

    if(getch() == 'n' || getch() == 'N')
        mainMenu();
    else
        create();
}

/* ##################################### End of Create() ###################################### */

void insertFirst()
{
    system("cls");

    struct emp_data *newnode, * temp;
    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));

    if(newnode == NULL)
    {
        printf("Allocation Failed");
        return ;
    }
    newnode->next = NULL;

    gotoxy(37,3);
    blue();
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD EMPLOYEE RECORD IN FIRST \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
    reset();
    gotoxy(35,7);
    printf("1.ENTER EMPLOYEE ID              : ");
    scanf("%d", &newnode->empno);
    gotoxy(35,8);
    printf("2.ENTER FIRST NAME OF EMPLOYEE   : ");
    scanf("%s", newnode->firstName);
    gotoxy(35,9);
    printf("3.ENTER LAST NAME OF EMPLOYEE    : ");
    scanf("%s", newnode->lastName);
    gotoxy(35,10);
    printf("4.ENTER AGE OF EMPLOYEE          : ");
    scanf("%d",&newnode->age);
    gotoxy(35,11);
    printf("5.DESIGNATION OF EMPLOYEE        : ");
    scanf("%s", newnode->designation);
    gotoxy(35,12);
    printf("6.ENTER BASIC SALARY OF EMPLOYEE : ");
    scanf("%lf", &newnode->salary);

    if (front == NULL)
    {
        front = newnode;
    }
    else
    {
        newnode->next = front;
        front = newnode;
    }
    gotoxy(25,16);
    green();
    printf("RECORD IS SUCCESSFULLY SAVED");
    gotoxy(25,17);
    blue();
    printf("SAVE ANY MORE?(Y / N):");
    reset();
    if(getch() == 'n' || getch() == 'N')
        mainMenu();
    else
        insertFirst();
}

/* ############################ End of InsertFirst() #############################*/

void insertAfter()
{
    system("cls");

    int employeeNo;

    gotoxy(0,1);
    green();
    printf("ENTER EMPLOYEE ID TO ADD NEW ID FOR AFTER PREVIOUS ID:");
    reset();
    scanf("%d", &employeeNo);

    struct emp_data *newnode, *temp;
    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));

    if(newnode == NULL)
    {
        printf("Allocation failed");
        return;
    }
    newnode->next = NULL;
    for( temp = front; temp != NULL;temp= temp->next )
    {
        if (temp->empno == employeeNo  )
        {

            gotoxy(30,4);
            blue();
            printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD EMPLOYEE RECORD IN CERTAIN POSITION \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
            reset();
            gotoxy(35,8);
            printf("1.ENTER EMPLOYEE ID              : ");
            scanf("%d", &newnode->empno);
            gotoxy(35,9);
            printf("2.ENTER FIRST NAME OF EMPLOYEE   : ");
            scanf("%s", newnode->firstName);
            gotoxy(35,10);
            printf("3.ENTER LAST NAME OF EMPLOYEE    : ");
            scanf("%s", newnode->lastName);
            gotoxy(35,11);
            printf("4.ENTER AGE OF EMPLOYEE          : ");
            scanf("%d",&newnode->age);
            gotoxy(35,12);
            printf("5.DESIGNATION OF EMPLOYEE        : ");
            scanf("%s", newnode->designation);
            gotoxy(35,13);
            printf("6.ENTER BASIC SALARY OF EMPLOYEE : ");
            scanf("%lf", &newnode->salary);

            newnode -> next = temp->next;
            temp->next = newnode;

            gotoxy(35,16);
            green();
            printf("THE RECORD HAS BEEN SAVED!!!!!");
            gotoxy(35,17);
            blue();
            printf("SAVE ANY MORE?(Y / N):");
            reset();

            if(getch() == 'n')
                mainMenu();
            else
                insertAfter();
            return;
        }
    }
    gotoxy(35,10);
    red();
    printf("EMPLOYEE ID NOT FOUND !!!!");
    gotoxy(10,12);
    blue();
    printf("PRESS ENTER TO BACK TO MAIN MENU");
    reset();
    getch();
    mainMenu();
}

void insertEnd()
{
    system("cls");

    struct emp_data * temp, *newnode;
    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));

    if(newnode == NULL)
    {
        printf("Allocation Failed!");
        return;
    }

    gotoxy(38,3);
    blue();
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD EMPLOYEE RECORD IN END \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
    reset();
    gotoxy(40,7);
    printf("1.ENTER EMPLOYEE ID              : ");
    scanf("%d", &newnode->empno);
    gotoxy(40,8);
    printf("2.ENTER FIRST NAME OF EMPLOYEE   : ");
    scanf("%s", newnode->firstName);
    gotoxy(40,9);
    printf("3.ENTER LAST NAME OF EMPLOYEE    : ");
    scanf("%s", newnode->lastName);
    gotoxy(40,10);
    printf("4.ENTER AGE OF EMPLOYEE          : ");
    scanf("%d",&newnode->age);
    gotoxy(40,11);
    printf("5.DESIGNATION OF EMPLOYEE        : ");
    scanf("%s", newnode->designation);
    gotoxy(40,12);
    printf("6.ENTER BASIC SALARY OF EMPLOYEE : ");
    scanf("%lf", &newnode->salary);

    newnode ->next = NULL;
    if(front == NULL)
    {
        front = newnode;
    }
    else
    {
        temp = front;
        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next=newnode;
    }
    gotoxy(25,16);
    green();
    printf("THE RECORD HAS BEEN SAVED!!!!!");
    gotoxy(25,17);
    blue();
    printf("SAVE ANY MORE?(Y / N):");
    reset();
    if(getch()== 'N' || getch() == 'n')
        mainMenu();
    else
        insertEnd();
}

/*#################################### End of InsertEnd() #####################################*/

void deleteNode()
{
    system("cls");
    int employeeNo;

    struct emp_data *temp;
    struct emp_data *temp2;//nextNode

    if(front ==NULL)
    {
        red();
        gotoxy(50,10);
        printf("LIST IS EMPTY !!!!");
        gotoxy(10,15);
        blue();
        printf("PRESS ENTER FOR BACK TO MAIN MENU");
        reset();
        getch();
        mainMenu();
        return;
    }

    else
    {
        green();
        gotoxy(0,2);
        printf("ENTER EMPLOYEE ID TO BE DELETED:");
        reset();
        scanf("%d", &employeeNo);

        if(front->empno == employeeNo)
        {
            temp = front;

            gotoxy(45,4);
            blue();
            printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
            reset();
            gotoxy(50,8);
            printf(" EMP ID               : %d\n",temp->empno);
            gotoxy(50,9);
            printf(" EMP.NAME             : %s %s\n",temp->firstName,temp->lastName);
            gotoxy(50,10);
            printf(" EMP.AGE              : %d\n",temp->age);
            gotoxy(50,11);
            printf(" EMP.DESIGNATION      : %s\n",temp->designation);
            gotoxy(50,12);
            printf(" EMP.BASIC SALARY     : %0.2lf\n",temp->salary);
            gotoxy(50,13);
            printf("**************************************");

            gotoxy(25,16);
            blue();
            printf("DO YOU WANT TO DELETE?(Y/N):");
            reset();
            if(getch() == 'y' || getch()== 'Y')
            {
                gotoxy(50,18);
                green();
                printf("SUCCESSFULLY DELETED!!!!:");
                reset();
                front = front->next;
                free(temp);
                gotoxy(5,20);
                yellow();
                printf("PRESS ENTER TO BACK TO MAIN MENU");
                reset();
                getch();
                mainMenu();
            }
            else
            {
                mainMenu();
            }

        }

        else
        {
            for (temp = front->next, temp2 = front; temp != NULL; temp = temp->next, temp2 = temp2->next )
            {
                if ( temp ->empno == employeeNo)
                {
                    gotoxy(45,4);
                    blue();
                    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
                    yellow();
                    gotoxy(50,6);
                    printf("######### EMPLOYEE DETAILS ##########");
                    reset();
                    gotoxy(50,8);
                    printf(" EMP ID               : %d",temp->empno);
                    gotoxy(50,9);
                    printf(" EMP.NAME             : %s %s",temp->firstName,temp->lastName);
                    gotoxy(50,10);
                    printf(" EMP.AGE              : %d",temp->age);
                    gotoxy(50,11);
                    printf(" EMP.DESIGNATION      : %s",temp->designation);
                    gotoxy(50,12);
                    printf(" EMP.BASIC SALARY     : %0.2lf",temp->salary);
                    gotoxy(50,14);
                    printf("**************************************");
                    gotoxy(25,17);
                    red();
                    printf("DO YOU WANT TO DELETE?(Y/N):");
                    reset();

                    if(getch() == 'y' || getch() == 'Y')
                    {
                        gotoxy(50,19);
                        green();
                        printf("SUCCESSFULLY DELETED!!!");
                        reset();
                        temp2->next = temp ->next;
                        free(temp);
                        gotoxy(10,21);
                        blue();
                        printf("PRESS ENTER TO BACK TO MAIN MENU");
                        reset();
                        getch();
                        mainMenu();
                    }
                    mainMenu();
                    return;
                }
                else
                {
                    gotoxy(35,10);
                    red();
                    printf(" EMPLOYEE ID NOT FOUND!!!!!");
                    gotoxy(10,12);
                    blue();
                    printf("PRESS ENTER TO BACK TO MAIN MENU");
                    reset();
                    getch();
                    mainMenu();
                }
            }

        }

    }

}
/* ############################### End of the deleteNode() #########3####################### */

void update()
{
    system("cls");
    int choice;
    struct emp_data *temp;

    int employeeNo;

    if(front == NULL)
    {
        gotoxy(50,10);
        red();
        printf("LIST IS EMPTY !!!");
        gotoxy(10,15);
        green();
        printf("PRESS ENTER FOR BACK TO MAIN MENU");
        reset();
        if(getch())
            mainMenu();
        return;
    }

    blue();
    gotoxy(0,1);
    printf("ENTER EMPLOYEE ID TO BE MODIFIED: ");
    reset();
    scanf("%d", &employeeNo);

    for (temp = front; temp!= NULL; temp = temp->next )
    {
        if (temp->empno == employeeNo)
        {

            gotoxy(45,4);
            blue();
            printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb UPDATE RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
            reset();
            gotoxy(50,7);
            printf("<1> UPDATE FIRST NAME.    ");
            gotoxy(50,8);
            printf("<2> UPDATE LAST NAME.     ");
            gotoxy(50,9);
            printf("<3> UPDATE AGE.           ");
            gotoxy(50,10);
            printf("<4> UPDATE DESIGNATION    ");
            gotoxy(50,11);
            printf("<5> UPDATE SALARY.        ");
            gotoxy(50,12);
            printf("<6> BACK TO MAIN MENU     ");

            gotoxy(10,14);
            yellow();
            printf(">> ENTER YOUR CHOICE:");
            reset();
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    gotoxy(15,16);
                    printf("ENTER NEW FIRST NAME : ");
                    scanf("%s", temp->firstName);
                    green();
                    gotoxy(25,18);
                    printf("THE RECORD HAS BEEN MODIFIED!!!!!");
                    reset();
                    break;

                case 2:
                    gotoxy(15,16);
                    printf("ENTER NEW LAST NAME :");
                    scanf("%s",temp->lastName);
                    green();
                    gotoxy(25,18);
                    printf("THE RECORD HAS BEEN MODIFIED!!!!!");
                    reset();
                    break;

                case 3:
                    gotoxy(15,16);
                    printf("ENTER NEW AGE : ");
                    scanf("%d", &temp->age);
                    green();
                    gotoxy(25,18);
                    printf("THE RECORD HAS BEEN MODIFIED!!!!!");
                    reset();
                    break;

                case 4:
                    gotoxy(15,16);
                    printf("ENTER NEW DESIGNATION : ");
                    scanf("%s", temp->designation);
                    green();
                    gotoxy(25,18);
                    printf("THE RECORD HAS BEEN MODIFIED!!!!!");
                    reset();
                    break;

                case 5:
                    gotoxy(15,16);
                    printf("ENTER NEW BASIC SALARY :");
                    scanf("%lf", &temp->salary);
                    green();
                    gotoxy(25,18);
                    printf("THE RECORD HAS BEEN MODIFIED!!!!!");
                    reset();
                    break;

                case 6:
                    mainMenu();
                    break;

                default:
                    red();
                    gotoxy(25,16);
                    printf("INVALID KEY!!.PRESS ENTER FOR REENTER");
                    reset();
                    getch();
                    mainMenu();

            }

            gotoxy(25,19);
            blue();
            printf("UPDATE ANY MORE?(Y / N):");
            reset();
            if(getch() == 'y'|| getch() == 'Y')
                update();
            else
                mainMenu();
            return;
        }

        gotoxy(35,10);
        red();
        printf("EMPLOYEE ID  NOT FOUND!!!!!!");
        gotoxy(35,12);
        blue();
        printf("PRESS ENTER TO BACK TO MAIN MENU");
        reset();
        getch();
        mainMenu();
    }

}

/*########################### End of Update() #############################*/

void search()
{
    system("cls");

    struct emp_data * temp;
    int employeeNo;

    if(front ==NULL)
    {
        red();
        gotoxy(50,10);
        printf("LIST IS EMPTY !!!!");
        gotoxy(10,15);
        blue();
        printf("PRESS ENTER FOR BACK TO MAIN MENU");
        reset();
        getch();
        mainMenu();
    }

    else
    {
        gotoxy(0,1);
        green();
        printf("ENTER EMPLOYEE ID TO BE SEARCHED: ");
        scanf("%d", &employeeNo);


        for(temp = front; temp != NULL; temp = temp->next)
        {
            if (temp->empno == employeeNo)
            {
                gotoxy(45,4);
                blue();
                printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb SEARCH EMPLOYEE RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ");
                gotoxy(50,7);
                blue();
                printf("######### EMPLOYEE DETAILS ##########");
                reset();
                gotoxy(50,10);
                printf(" EMP ID               : %d\n",temp->empno);
                gotoxy(50,12);
                printf(" EMP.NAME             : %s %s\n",temp->firstName,temp->lastName);
                gotoxy(50,14);
                printf(" EMP.AGE              : %d\n",temp->age);
                gotoxy(50,16);
                printf(" EMP.DESIGNATION      : %s\n",temp->designation);
                gotoxy(50,18);
                printf(" EMP.BASIC SALARY     : %0.2lf\n",temp->salary);
                gotoxy(50,20);
                printf("**************************************\n");

                gotoxy(10,22);
                yellow();
                printf("SEARCH ANOTHER EMPLOYEE(Y/N)?");
                reset();
                if(getch()=='y' || getch()=='Y')
                    search();
                else
                    mainMenu();
            }

            else
            {
                gotoxy(45,10);
                red();
                printf("EMPLOYEE ID NOT FOUND!!!");
                gotoxy(10,12);
                yellow();
                printf("SEARCH ANOTHER EMPLOYEE(Y/N)?");
                reset();
                if(getch()=='y' || getch()=='Y')
                    search();
                else
                    mainMenu();
            }
        }
    }

}
/* ########################### End of search() #############################*/

void display()
{
    system("cls");
    struct emp_data *temp;
    int j ;

    if(front == NULL)
    {
        gotoxy(50,10);
        red();
        printf("LIST IS EMPTY !!!");
        gotoxy(10,15);
        green();
        printf("PRESS ENTER FOR BACK TO MAIN MENU");
        reset();
        if(getch())
            mainMenu();
        return;
    }

    j =5;
    for(temp = front; temp != NULL; temp = temp->next)
    {
        gotoxy(20,1);
        blue();
        printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD LIST \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        reset();
        gotoxy(29,3);
        yellow();
        printf("==ID ==== FIRST NAME === LAST NAME === AGE === DESIGNATION === SALARY== ");
        reset();
        gotoxy(30,j);
        printf("%d",temp->empno);
        gotoxy(40,j);
        printf("%s",temp->firstName);
        gotoxy(55,j);
        printf("%s", temp->lastName);
        gotoxy(68,j);
        printf("%d",temp->age);
        gotoxy(78,j);
        printf("%s",temp->designation);
        gotoxy(92,j);
        printf("%0.2lf",temp->salary);
        gotoxy(100,j);
        printf("\n\n");
        j++;
    }
    gotoxy(1,25);
    green();
    printf("PRESS ENTER FOR BACK TO MAIN MENU");
    reset();
    getch();
        mainMenu();
}

/* ########################################## End of Display() ############################################################################*/

void mainMenu()
{
    system("cls");
    int i;

    drawRectangle();
    gotoxy(100,3);
    Count_of_Nodes();
    gotoxy(45,2);
    red();
    printf(" WELCOME TO THE EMPLOYEE INFORMATION SYSTEM");

    for(i =40;i<=92;i++)
    {
        gotoxy(i,3);
        printf("%c",175);
    }

    gotoxy(45,6);
    green();
    printf("<1>> to ADD EMPLOYEE RECORD.                     ");
    gotoxy(45,8);
    printf("<2>> to ADD EMPLOYEE RECORD IN FRONT OF THE LIST.");
    gotoxy(45,10);
    printf("<3>> to ADD EMPLOYEE RECORD IN CERTAIN POSITION. ");
    gotoxy(45,12);
    printf("<4>> to ADD EMPLOYEE RECORD IN END OF THE LIST.  ");
    gotoxy(45,14);
    printf("<5>> to DELETE A EMPLOYEE RECORD.                ");
    gotoxy(45,16);
    printf("<6>> to DISPALY RECORDS OF ALL EMPLOYEE.            ");
    gotoxy(45,18);
    printf("<7>> to SEARCH A PARTICULAR EMPLOYEE.            ");
    gotoxy(45,20);
    printf("<8>> to UPDATE INFORMATION OF A EMPLOYEE.        ");
    gotoxy(45,22);
    printf("<9>> to EXIT SYSTEM.                             ");
    reset();

    gotoxy(5,25);
    yellow();
    printf(">> ENTER YOUR CHOICE: ");
    reset();

}
/* #################### End of the mainMenu() ##################### */

int option()
{
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return choice;
        default:
            gotoxy(22,29);
            red();
            printf("WRONG CHOICE!!! RE ENTER TO PRESS ENTER");
            reset();
            if(getch())
                mainMenu();
    }
    return choice;
}

void first()
{
    system("cls");
    int i,j;

    gotoxy(53,10);
    red();
    printf("EMPLOYEE INFORMATION SYSTEM");
    gotoxy(25,19);
    green();
    printf("LOADING...");
    gotoxy(25,20);
    for(i=1;i<=40;i++)
    {
        for(j=1;j<=50000000;j++);
        printf("%c",177);
    }
    reset();
    mainMenu();
}

void main()
{
    int choice;
    int employeeNo;

    first();
    mainMenu();
    do
    {
        /* choice operation to be performed */
        choice = option();
        switch(choice)
        {
            case 1 :
                create();
                break;

            case 2:
                insertFirst();
                break;

            case 3:
                insertAfter();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                deleteNode();
                break;

            case 6:
                display();
                break;

            case 7 :
                search();
                break;

            case 8:
                update();
                break;

            case 9:
                exit(2);

        }
    } while (choice != 9);
}

