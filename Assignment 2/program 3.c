#include<stdio.h>

struct BankMgmt
{
    int AccNumber;
    char CustName[50];
    float AvlBalance;
    char AccType[20];
};

int main()
{
    struct BankMgmt customer;
    printf("enter Account Number: ");
    scanf("%d",&customer.AccNumber);
    printf("enter Customer Name: ");
    scanf("%s",&customer.CustName);
    printf("enter Available Balance: ");
    scanf("%f",&customer.AvlBalance);
    printf("enter Account Type: ");
    scanf("%s",&customer.AccType);
    printf("\n%d    %s    %f    %s",customer.AccNumber,customer.CustName,customer.AvlBalance,customer.AccType);
    int x;
    float Withdraw, Deposit;
    printf("\n\nMenu Options: 1->Withdrawal  2->Deposit  3->Display Balance  4->Exit : ");
    scanf("%d",&x);
    
    if(x==1)
    { 
        printf("\nenter the Amount you want to Withdraw: ");
        scanf("%f",&Withdraw);
        if(customer.AvlBalance > Withdraw)
        {
            printf("\n%f has been Withdrawn from your account.",Withdraw);
            printf("\nRemaining Balance = %f",(customer.AvlBalance-Withdraw));
        }
        else
        {
            printf("\nNOT enough Balance for Withdrawal!!");
        }
    }
    
    else if(x==2)
    {
        printf("\nenter the Amount you want to Deposit: ");
        scanf("%f",&Deposit);
        printf("the Available Balance after Deposit : %f",(customer.AvlBalance+Deposit));
    }
    
    else if(x==3)
    {
        printf("\n%d    %s    %f    %s",customer.AccNumber,customer.CustName,customer.AvlBalance,customer.AccType);
    }
    
    else if(x==4)
    {
        printf("\nyou have successfully EXITED the application...");
    }
    
    else
    {
        printf("\nplease enter a VALID number from the MENU options!!!");
    }
    
    return 0;
}