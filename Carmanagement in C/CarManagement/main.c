#include<stdio.h>
#include<string.h>

struct customer
{
    char firstName[30];
    char lastName[30];
    char  phone[20];
    char address[20];
    char email[50];
};

void writeInFile(struct customer cus[],int size);
void readFromFile();
void readFromCarFile();
char rateTypeCar();
int rulesViol();
int Payment();
char PasswordCon();
void passLog();


int main()
{
    char ynAnswer,lrAnswer;
    int i;
    struct customer cus[1];

    printf("Welcome to Dhaka Car Rentals. Would you like to rent a car?\nPress 'Y' for YES and 'N' for NO: ");
    scanf("%c",&ynAnswer);
    fflush(stdin);

    if(ynAnswer=='Y' || ynAnswer=='y')
    {
        printf("\nThank you for choosing Dhaka Car Rentals\n");

        printf("\nIf you are not registered, press 'R' to register and if you have already registered, press 'L' to login: ");
        printf("\n");
        scanf("%c",&lrAnswer);
        fflush(stdin);

        if(lrAnswer=='R' || lrAnswer=='r')
        {
            struct customer cus[1];
            FILE *fp;
            int i;

            for(i=0;i<1;i++)
            {
            printf("\nTo register you will have to enter you name,phone no.,home address,email address and password");

            printf("\n\nPlease enter your first name: ");
            scanf("%s",cus[i].firstName);
            fflush(stdin);

            printf("\nPlease enter your last name: ");
            scanf("%s",cus[i].lastName);
            fflush(stdin);

            printf("\nPlease enter your phone number: ");
            scanf("%s",cus[i].phone);//not being able to take input
            fflush(stdin);

            printf("\nPlease enter your home address: ");
            scanf("%s",cus[i].address);
            fflush(stdin);

            printf("\nPlease enter your email address: ");
            scanf("%s",cus[i].email);
            fflush(stdin);

            PasswordCon();

            }

            writeInFile(cus,100);

            rateTypeCar();

            Payment();

            printf("\nYour payment method has been chosen\n");

            rulesViol();

            printf("\nYOUR INFORMATION\n");

            readFromFile();

            readFromCarFile();

            printf("\n\nThank you for choosing Dhaka Car Rentals!\n\n");

        }
        else if (lrAnswer=='L' || lrAnswer=='l')
        {
            char username[30];
            printf("\nEnter your name: ");
            gets(username);
            passLog();
            rateTypeCar();
            Payment();
            rulesViol();

            printf("\nYOUR INFORMATION(CHOICE OF RATE AND CAR):\n");
            printf("\nNAME: %s",username);
            readFromCarFile();

            printf("\nThank you for choosing Dhaka Car Rentals!\n");
        }
    }
    else if(ynAnswer=='N' || ynAnswer=='n')
    {
        printf("\nThank you for visiting us\nGoodbye\n");
    }
    else{
        printf("Error Input");
    }

}

void writeInFile(struct customer cus[],int size)
{
    FILE *fp;
    int i;
    fp = fopen("customerInfo.txt","w");
    if(fp!=NULL)
    {
        for(i=0; i<1; i++)
        {
            fprintf(fp,"%s \n",cus[i].firstName);

            fprintf(fp,"%s \n",cus[i].lastName);

            fprintf(fp,"%s \n",cus[i].phone);

            fprintf(fp,"%s \n",cus[i].address);

            fprintf(fp,"%s \n",cus[i].email);

        }
        printf("\nYour account has been made.\n");
        fclose(fp);
    }
    else
    {
        printf("Cant open file! \n");
    }
    return 0;
}

void readFromFile()
{
    int j;
    FILE *fp=fopen("customerInfo.txt","r");
    struct customer cus[1];
    if(fp!=NULL)
    {
        for(j=0; j<1; j++)
        {
            fscanf(fp,"%s",cus[j].firstName);
            fflush(stdin);

            fscanf(fp,"%s",cus[j].lastName);
            fflush(stdin);

            fscanf(fp,"%s",cus[j].phone);
            fflush(stdin);

            fscanf(fp,"%s",cus[j].address);
            fflush(stdin);

            fscanf(fp,"%s",cus[j].email);
            fflush(stdin);

        }

        for(j=0; j<1; j++)
        {
            printf("\nFULL NAME: %s %s",cus[j].firstName,cus[j].lastName);

            printf("\nPHONE NUMBER: %s ",cus[j].phone);

            printf("\nHOME ADDRESS: %s ",cus[j].address);

            printf("\nEMAIL ADDRESS: %s ",cus[j].email);

        fclose(fp);
    }
}
    else{
         printf("Cannot Open File\n");
    }
}

char rateTypeCar()
{
    int rate,rateTypeofCar;

    FILE *fp;

    fp=fopen("SelectionRentalInfo.txt","w");

    if(fp!=NULL)
    {

    printf("\n\nFee:\n");

    printf("\nSelect the rate: \n1)Hourly rate(Press 1) \n2)Daily rate(Press 2) \n3)Weekly rate(Press 3)\n4)Monthly rate(Press 4)\n");
    scanf("%d",&rate);

    if(rate==1)
    {
        printf("\nHourly Rate\n");
        printf("What type of car would you like to rent?\n1)Economy(Press 1) \n2)Compact(Press 2) \n3)Mid-size(Press 3) \n4)Full-size(Press 4) \n5)Premium(Press 5) \n6)Luxury(Press 6) \n7)Minivan(Press 7) \n8)Convertible(Press 8) \n9)Mid-size SUV(Press 9) \n10)Standard SUV(Press 10)\n");
        scanf("%d",&rateTypeofCar);

        switch(rateTypeofCar)
        {
            case 1:
                printf("\n\nYou have chosen Economy\n\n");

                printf("\nFor Economy the hourly rate is: ");
                printf("TK 884.26 only\n");

                int car1="Economy";
                char fee1[30]="TK 884.26 only per hour\n";
                fprintf(fp,"%s",fee1);
                fprintf(fp,"%s",car1);
                fclose(fp);
                return 0;
                break;

            case 2:
                printf("\n\nYou have chosen Compact\n\n");

                printf("\nFor Compact the hourly rate is:  ");
                printf("TK 935.32 only\n");

                int car2="Compact";
                char fee2[30]="TK 935.32 only per hour\n";
                fprintf(fp,"%s",fee2);
                fprintf(fp,"%s",car2);
                fclose(fp);
                return 0;
                break;

            case 3:
                printf("\n\nYou have chosen Mid-size\n\n");

                printf("\nFor Mid-size the hourly rate is:  ");
                printf("TK 1,001.78 only\n");

                int car3="Mid-size";
                char fee3[30]=" TK 1,001.78 only per hour\n";
                fprintf(fp,"%s",fee3);
                fprintf(fp,"%s",car3);
                fclose(fp);
                return 0;
                break;

            case 4:
                printf("\n\nYou have chosen Full-size\n\n");

                printf("\nFor Full-size the hourly rate is:  ");
                printf("TK 1,102.28 only \n");

                int car4="Full-size";
                char fee4[30]="TK 1,102.28 only per hour\n";
                fprintf(fp,"%s",fee4);
                fprintf(fp,"%s",car4);
                fclose(fp);
                return 0;
                break;

            case 5:
                printf("\n\nYou have chosen Premium\n\n");

                printf("\nFor Premium the hourly rate is:  ");
                printf("TK 1,134.70 only\n");

                int car5="Premium";
                char fee5[30]= "TK 1,134.70 only per hour\n";
                fprintf(fp,"%s",fee5);
                fprintf(fp,"%s",car5);
                fclose(fp);
                return 0;
                break;

            case 6:
                printf("\n\nYou have chosen Luxury\n\n");

                printf("\nFor Luxury the hourly rate is:  ");
                printf("TK 1,302.28 only\n");

                int car6="Luxury";
                char fee6[30]= "TK 1,302.28 only per hour\n";
                fprintf(fp,"%s",fee6);
                fprintf(fp,"%s",car6);
                fclose(fp);
                return 0;
                break;

            case 7:
                printf("\n\nYou have chosen Minivan\n\n");

                printf("\nFor Minivan the hourly rate is:  ");
                printf("TK 1,220.00 only\n");

                int car7="Minivan";
                char fee7[30]= "TK 1,220.00 only per hour\n";
                fprintf(fp,"%s",fee7);
                printf(fp,"%s",car7);
                fclose(fp);
                return 0;
                break;

            case 8:
                printf("\n\nYou have chosen Convertible\n\n");

                printf("\nFor Convertible the hourly rate is:  ");
                printf("TK 1,300.28 only\n");

                int car8="Convertible";
                char fee8[30]= "TK 1,300.28 only per hour\n";
                fprintf(fp,"%s",fee8);
                fprintf(fp,"%s",car8);
                fclose(fp);
                return 0;
                break;

            case 9:
                printf("\n\nYou have chosen Mid-size SUV\n\n");

                printf("\nFor Mid-size SUV the hourly rate is:  ");
                printf("TK 1,305.08 only\n");

                int car9="Mid-size SUV";
                char fee9[30]= "TK 1,305.08 only per hour\n";
                fprintf(fp,"%s",fee9);
                fprintf(fp,"%s",car9);
                fclose(fp);
                return 0;
                break;

            case 10:
                printf("\n\nYou have chosen Standard SUV\n\n");

                printf("\nFor Standard SUV the hourly rate is:  ");
                printf("TK 1,302.80 only\n");

                int car10="Standard SUV";
                char fee10[30]= "TK 1,302.80 only per hour\n";
                fprintf(fp,"%s",fee10);
                fprintf(fp,"%s",car10);
                fclose(fp);
                return 0;
                break;

            default:{
                printf("\nInvalid\n");
                fclose(fp);
                rateTypeCar();
            }
        }

    }
    else if(rate==2)
        {
        printf("\nDaily Rate\n");
        printf("\nWhat type of car would you like to rent?\n1)Economy(Press 1) \n2)Compact(Press 2) \n3)Mid-size(Press 3) \n4)Full-size(Press 4) \n5)Premium(Press 5) \n6)Luxury(Press 6) \n7)Minivan(Press 7) \n8)Convertible(Press 8) \n9)Mid-size SUV(Press 9) \n10)Standard SUV(Press 10)\n");
        scanf("%d",&rateTypeofCar);

        switch(rateTypeofCar)
        {
            case 1:
                printf("\n\nYou have chosen Economy\n\n");

                printf("\nFor Economy the daily rate is:  ");
                printf("21,222.24 only\n");

                int car1="Economy";
                char fee1[30]="TK 21,222.24 only per day\n";
                fprintf(fp,"%s",fee1);
                fprintf(fp,"%s",car1);
                fclose(fp);
                return 0;
                break;

            case 2:
                printf("\n\nYou have chosen Compact\n\n");

                printf("\nFor Compact the daily rate is:  ");
                printf("TK 22,447.68 only\n");

                int car2="Compact";
                char fee2[30]="TK 22,447.68 only per day\n";
                fprintf(fp,"%s",fee2);
                fprintf(fp,"%s",car2);
                fclose(fp);
                return 0;
                break;

            case 3:
                printf("\n\nYou have chosen Mid-size\n\n");

                printf("\nFor Mid-size the daily rate is:  ");
                printf("TK 24,042.72 only\n");

                int car3="Mid-size";
                char fee3[30]=" TK 24,042.72 only per day\n";
                fprintf(fp,"%s",fee3);
                fprintf(fp,"%s",car3);
                fclose(fp);
                return 0;
                break;

            case 4:
                printf("\n\nYou have chosen Full-size\n\n");

                printf("\nFor Full-size the daily rate is:  ");
                printf("TK 26,454.72 only\n");

                int car4="Full-size";
                char fee4[30]="TK 26,454.72 only per day\n";
                fprintf(fp,"%s",fee4);
                fprintf(fp,"%s",car4);
                fclose(fp);
                return 0;
                break;

            case 5:
                printf("\n\nYou have chosen Premium\n\n");

                printf("\nFor Premium the daily rate is:  ");
                printf("TK 27,232.80 only\n");

                int car5="Premium";
                char fee5[30]= "TK 27,232.80 only per day\n";
                fprintf(fp,"%s",fee5);
                fprintf(fp,"%s",car5);
                fclose(fp);
                return 0;
                break;

            case 6:
                printf("\n\nYou have chosen Luxury\n\n");

                printf("\nFor Luxury the hourly rate is:  ");
                printf("TK 31,254.72 only\n");

                int car6="Luxury";
                char fee6[30]= "TK 31,254.72 only per day\n";
                fprintf(fp,"%s",fee6);
                fprintf(fp,"%s",car6);
                fclose(fp);
                return 0;
                break;

            case 7:
                printf("\n\nYou have chosen Minivan\n\n");

                printf("\nFor Minivan the daily rate is:  ");
                printf("TK 29,280.00 only\n");

                int car7="Minivan";
                char fee7[30]= "TK 29,280.00 only per day\n";
                fprintf(fp,"%s",fee7);
                fprintf(fp,"%s",car7);
                fclose(fp);
                return 0;
                break;

            case 8:
                printf("\n\nYou have chosen Convertible\n\n");

                printf("\nFor Convertible the daily rate is:  ");
                printf("TK 31,206.00 only\n");

                int car8="Convertible";
                char fee8[30]= "TK 31,206.00 only per day\n";
                fprintf(fp,"%s",fee8);
                fprintf(fp,"%s",car8);
                fclose(fp);
                return 0;
                break;

            case 9:
                printf("\n\nYou have chosen Mid-size SUV\n\n");

                printf("\nFor Mid-size SUV the daily rate is:  ");
                printf("TK 31,321.92 only\n");

                int car9="Mid-size SUV";
                char fee9[30]= "TK 31,321.92 only per day\n";
                fprintf(fp,"%s",fee9);
                fprintf(fp,"%s",car9);
                fclose(fp);
                return 0;
                break;

            case 10:
                printf("\n\nYou have chosen Standard SUV\n\n");

                printf("\nFor Standard SUV the daily rate is:  ");
                printf("TK 31,267.20 only\n");

                int car10="Standard SUV";
                char fee10[30]= "TK 31,267.20 only per day\n";
                fprintf(fp,"%s",fee10);
                fprintf(fp,"%s",car10);
                fclose(fp);
                return 0;
                break;

            default:
                printf("\nInvalid\n");
                rateTypeCar();
        }

       }
       else if(rate==3)
        {
        printf("\nWeekly Rate\n");
        printf("\nWhat type of car would you like to know rent?\n1)Economy(Press 1) \n2)Compact(Press 2) \n3)Mid-size(Press 3) \n4)Full-size(Press 4) \n5)Premium(Press 5) \n6)Luxury(Press 6) \n7)Minivan(Press 7) \n8)Convertible(Press 8) \n9)Mid-size SUV(Press 9) \n10)Standard SUV(Press 10)\n");
        scanf("%d",&rateTypeofCar);

        switch(rateTypeofCar)
        {
            case 1:
                printf("\n\nYou have chosen Economy\n\n");

                printf("\nFor Economy the weekly rate is:  ");
                printf("1,48,555.68 only\n");

                int car1="Economy";
                char fee1[30]="TK 1,48,555.68 only per week\n";
                fprintf(fp,"%s",fee1);
                fprintf(fp,"%s",car1);
                fclose(fp);
                return 0;
                break;

            case 2:
                printf("\n\nYou have chosen Compact\n\n");

                printf("\nFor Compact the weekly rate is:  ");
                printf("TK 1,57,133.76 only\n");

                int car2="Compact";
                char fee2[30]="TK 1,57,133.76 only per week\n";
                fprintf(fp,"%s",fee2);
                fprintf(fp,"%s",car2);
                fclose(fp);
                return 0;
                break;

            case 3:
                printf("\n\nYou have chosen Mid-size\n\n");

                printf("\nFor Mid-size the weekly rate is:  ");
                printf("TK 1,68,299.04 only\n");

                int car3="Mid-size";
                char fee3[30]=" TK 1,68,299.04 only per week\n";
                fprintf(fp,"%s",fee3);
                fprintf(fp,"%s",car3);
                fclose(fp);
                return 0;
                break;

            case 4:
                printf("\n\nYou have chosen Full-size\n\n");

                printf("\nFor Full-size the weekly rate is:  ");
                printf("TK 1,85,183.04 only\n");

                int car4="Full-size";
                char fee4[30]="TK 1,85,183.04 only per week\n";
                fprintf(fp,"%s",fee4);
                fprintf(fp,"%s",car4);
                fclose(fp);
                return 0;
                break;

            case 5:
                printf("\n\nYou have chosen Premium\n\n");

                printf("\nFor Premium the weekly rate is:  ");
                printf("TK 1,90,629.60 only\n");

                int car5="Premium";
                char fee5[30]= "TK 1,90,629.60 only per week\n";
                fprintf(fp,"%s",fee5);
                fprintf(fp,"%s",car5);
                fclose(fp);
                return 0;
                break;

            case 6:
                printf("\n\nYou have chosen Luxury\n\n");

                printf("\nFor Luxury the weekly rate is:  ");
                printf("TK 2,18,783.04 only\n");

                int car6="Luxury";
                char fee6[30]= "TK 2,18,783.04 only per week\n";
                fprintf(fp,"%s",fee6);
                fprintf(fp,"%s",car6);
                fclose(fp);
                return 0;
                break;

            case 7:
                printf("\n\nYou have chosen Minivan\n\n");

                printf("\nFor Minivan the weekly rate is:  ");
                printf("TK 2,04,960.00 only\n");

                int car7="Minivan";
                char fee7[30]= "TK 2,04,960.00 only per week\n";
                fprintf(fp,"%s",fee7);
                fprintf(fp,"%s",car7);
                fclose(fp);
                return 0;
                break;

            case 8:
                printf("\n\nYou have chosen Convertible\n\n");

                printf("\nFor Convertible the weekly rate is:  ");
                printf("TK 2,18,442 only\n");

                int car8="Convertible";
                char fee8[30]= "TK 2,18,442 only per week\n";
                fprintf(fp,"%s",fee8);
                fprintf(fp,"%s",car8);
                fclose(fp);
                return 0;
                break;

            case 9:
                printf("\n\nYou have chosen Mid-size SUV\n\n");

                printf("\nFor Mid-size SUV the weekly rate is:  ");
                printf("TK 2,19,253.44 only \n");

                int car9="Mid-size SUV";
                char fee9[30]= "TK 2,19,253.44 only per week\n";
                fprintf(fp,"%s",fee9);
                fprintf(fp,"%s",car9);
                fclose(fp);
                return 0;
                break;

            case 10:
                printf("\n\nYou have chosen Standard SUV\n\n");

                printf("\nFor Standard SUV the weekly rate is:  ");
                printf("TK 2,188,70.40 only\n");

                int car10="Standard SUV";
                char fee10[30]= "TK 2,188,70.40 only per week\n";
                fprintf(fp,"%s",fee10);
                fprintf(fp,"%s",car10);
                fclose(fp);
                return 0;
                break;

            default:
                printf("\nInvalid\n");
                rateTypeCar();
        }
        }
        else if(rate==4)
        {
        printf("\nMonthly Rate\n");
        printf("\nWhat type of car would you like to rent?\n1)Economy(Press 1) \n2)Compact(Press 2) \n3)Mid-size(Press 3) \n4)Full-size(Press 4) \n5)Premium(Press 5) \n6)Luxury(Press 6) \n7)Minivan(Press 7) \n8)Convertible(Press 8) \n9)Mid-size SUV(Press 9) \n10)Standard SUV(Press 10)\n");
        scanf("%d",&rateTypeofCar);

        switch(rateTypeofCar)
        {
            case 1:
                printf("\n\nYou have chosen Economy\n\n");

                printf("\nFor Economy the monthly rate is:  ");
                printf("44,56,670.40 only\n");

                int car1="Economy";
                char fee1[30]="TK 44,56,670.40 only per month\n";
                fprintf(fp,"%s",fee1);
                fprintf(fp,"%s",car1);
                fclose(fp);
                return 0;
                break;

            case 2:
                printf("\n\nYou have chosen Compact\n\n");

                printf("\nFor Compact the monthly rate is:  ");
                printf("TK 47,14,012.80 only\n");

                int car2="Compact";
                char fee2[30]="TK 47,14,012.80 only per month\n";
                fprintf(fp,"%s",fee2);
                fprintf(fp,"%s",car2);
                fclose(fp);
                return 0;
                break;

            case 3:
                printf("\n\nYou have chosen Mid-size\n\n");

                printf("\nFor Mid-size the monthly rate is:  ");
                printf("TK 50,48,971.20 only \n");

                int car3="Mid-size";
                char fee3[30]=" TK 50,48,971.20 only per month\n";
                fprintf(fp,"%s",fee3);
                fprintf(fp,"%s",car3);
                fclose(fp);
                return 0;
                break;

            case 4:
                printf("\n\nYou have chosen Full-size\n\n");

                printf("\nFor Full-size the monthly rate is:  ");
                printf("TK 155,55,491.20 only\n");

                int car4="Full-size";
                char fee4[30]="TK 55,55,491.20 only per month\n";
                fprintf(fp,"%s",fee4);
                fprintf(fp,"%s",car4);
                fclose(fp);
                return 0;
                break;

            case 5:
                printf("\n\nYou have chosen Premium\n\n");

                printf("\nFor Premium the monthly rate is:  ");
                printf("TK 57,18,888.00 only\n");

                int car5="Premium";
                char fee5[30]= "TK 57,18,888.00 only per month\n";
                fprintf(fp,"%s",fee5);
                fprintf(fp,"%s",car5);
                fclose(fp);
                return 0;
                break;

            case 6:
                 printf("\n\nYou have chosen Luxury\n\n");

                printf("\nFor Luxury the monthly rate is:  ");
                printf("TK 65,63,491.20 only\n");

                int car6="Luxury";
                char fee6[30]= "TK 65,63,491.20 only per month\n";
                fprintf(fp,"%s",fee6);
                fprintf(fp,"%s",car6);
                fclose(fp);
                return 0;
                break;

            case 7:
                printf("\n\nYou have chosen Minivan\n\n");

                printf("\nFor Minivan the monthly rate is:  ");
                printf("TK 61,48,800.00 only\n");

                int car7="Minivan";
                char fee7[30]= "TK 61,48,800.00 only per month\n";
                fprintf(fp,"%s",fee7);
                fprintf(fp,"%s",car7);
                fclose(fp);
                return 0;
                break;

            case 8:
                printf("\n\nYou have chosen Convertible\n\n");

                printf("\nFor Convertible the monthly rate is:  ");
                printf("TK 65,53,260.00 only\n");

                int car8="Convertible";
                char fee8[30]= "TK 65,53,260.00 only per month\n";
                fprintf(fp,"%s",fee8);
                fprintf(fp,"%s",car8);
                fclose(fp);
                return 0;
                break;

            case 9:
                printf("\n\nYou have chosen Mid-size SUV\n\n");

                printf("\nFor Mid-size SUV the monthly rate is:  ");
                printf("TK 657,7,603.20 only\n");

                int car9="Mid-size SUV";
                char fee9[30]= "TK 657,7,603.20 only per month\n";
                fprintf(fp,"%s",fee9);
                fprintf(fp,"%s",car9);
                fclose(fp);
                return 0;
                break;

            case 10:
                printf("\n\nYou have chosen Standard SUV\n\n");

                printf("\nFor Standard SUV the monthly rate is:  ");
                printf("TK 65,66,112.00 only\n");

                int car10="Standard SUV";
                char fee10[30]= "TK 65,66,112.00 only per month\n";
                fprintf(fp,"%s",fee10);
                fprintf(fp,"%s",car10);
                fclose(fp);
                return 0;
                break;

            default:
                printf("\nInvalid\n");
                fclose(fp);
                rateTypeCar();
        }
        }
       }
       else
       {
        printf("Error Input");
        fclose(fp);
        rateTypeCar();
       }
}
int rulesViol()
{
    int rules;

    printf("\n\nWould you like to read the rules/violations?\nPRESS 1 if YES\nPRESS 2 if NO\n");
    scanf("%d",&rules);
    fflush(stdin);

    if(rules==1)
    {
        printf("\nYou may be disqualified from renting a car for recent violations, including:\n");
        printf("\nReckless driving\nSeat belt law violations\nAccidents, regardless of fault\nLeaving the scene of an accident");
        printf("\nConvictions for Driving While Intoxicated (DWI) or Driving Under the Influence (DUI)\nDriving with an invalid, suspended, or revoked license\n");
        return 0;
    }
    else if(rules==2)
    {
        return 0;
    }
    else
    {
        printf("Error input");
        rulesViol();
    }


}
int Payment()
{

    int B,Answer;

    printf("\nChoose your payment status: press '1' for BKASH and '2' for CASH\n");
    scanf("%d",&Answer);
    fflush(stdin);

    if(Answer==1)
    {
        printf("\nEnter your BKASH number:  ");
        scanf("%d",&B);


        FILE *fp;

        fp = fopen("BKASHNUMBER.txt","w");

        if(fp!=NULL)
        {
        fprintf(fp,"%d",B);
        fclose(fp);
        }

        else
        {
        printf("\nCan't open file");
        }
        return 0;

    }

    else if (Answer==2)
    {

        printf("\nPlease Contact Us");
        printf("\n\nPHONE NUMBER: 8652903\nEMAIL ADDRESS: Dhaka_CarRentals@gmail.com\n");
        printf("\nYou can also message us on our facebook page \nDHAKA CAR RENTALS BD\n");
    }
    else{
        printf("Enter valid number");
    }

}

char PasswordCon()
{
    char pass1[20],pass2[20];
    int pass1Num,pass2Num,compare;

    FILE *pw;
    pw=fopen("PASSWORD.txt","w");

    if(pw!=NULL)
    {
    printf("\nEnter the password: ");
    gets(pass1);
    fflush(stdin);

    pass1Num=strlen(pass1);

    printf("\nEnter password to confirm: ");
    gets(pass2);
    fflush(stdin);

    pass2Num=strlen(pass2);

    if(pass1Num==pass2Num)
    {
        compare=strcmp(pass1,pass2);

            if (compare==0)
            {
                printf("\nPassword has been confirmed.\n");
                fprintf(pw,"%s",pass1);
                fclose(pw);
                return 0;
            }
            else if (compare>0)//not executing this part?
            {
                printf("\nPassword not confirmed.Enter password again\n");
                PasswordCon();
            }
            else if (compare<0)//not executing this part?
            {
                printf("\nPassword not confirmed.Enter password again.\n");
                PasswordCon();
            }

    }
    else
        {
            printf("\nPassword not confirmed.Please enter password again.");
            PasswordCon();
        }
    return 0;
    }
    else
    {
        printf("Can't Open File");
        fclose(pw);

    }
}
void passLog()
{
    int x;
    float num;
    char pass1[20];
    char s[20];
    int result;

    printf("\nEnter password: ");
    gets(s);
    fflush(stdin);

    FILE *fp;

    fp=fopen("PASSWORD.txt","r");

    if(fp!=NULL)
    {
        fscanf(fp,"%s",pass1);

        result = strcmp(pass1,s);

         if(result==0)
         {
            printf("\nWELCOME\n");
            fclose(fp);
         }
         else
         {
            passLog();
         }

    }
    else
    {
        printf("File not found!\n");
    }

}

void readFromCarFile()
{
    FILE *fp;
    char ch1[5];
    char num[10];
    char ch2[5];
    char ch3[5];
    char ch4[10];
    char ch5[15];

    fp=fopen("SelectionRentalInfo.txt","r");

    if(fp!=NULL)
    {
        fscanf(fp,"%s",ch1);
        fflush(stdin);
        fscanf(fp,"%s",num);
        fflush(stdin);
        fscanf(fp,"%s",ch2);
        fflush(stdin);
        fscanf(fp,"%s",ch3);
        fflush(stdin);
        fscanf(fp,"%s",ch4);
        fflush(stdin);
        fscanf(fp,"%s",ch5);
        fflush(stdin);

        printf("\nRATE: %s ",ch1);
        printf("%s ",num);
        printf("%s ",ch2);
        printf("%s ",ch3);
        printf("%s ",ch4);
        printf("\nTYPE OF CAR CHOSEN: %s\n",ch5);
        fclose(fp);
    }
    else
    {
        printf("FILE NOT FOUND");
        fclose(fp);
    }
}
