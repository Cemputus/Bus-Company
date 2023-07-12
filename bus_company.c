#include <stdio.h>                  
#include <string.h>                                            
         
int login();            
int main(){                        
                              
                   
    int i = 0;    
    int loggedIn = 0; 
    int on = 1;    
    int option;     
    struct booking    
    {    
        char type[10];
        int number_of_seats;
        int total_cost; 
        int reciept_number; 
        int payment;
    }; 
 
   struct booking bookings[100];

   /*Login*/
   
   while(loggedIn == 0){
       loggedIn= login();
   }

    
   /*start the app */
    while(on == 1){
        printf("....................................OPTIONS................................ \n");
        printf("1. Bus booking status\n");
        printf("2. Bus booking\n");
        printf("3. Booking payment\n");
        printf("4. Bus booking reports\n");
        printf("5.Sign out\n");

        printf("-------------------------------------------------------------------------\n"); 
        printf("pick from above: ");

        scanf("%d",&option);


        if(option == 1){
            printf("Please choose again \n");
            continue;
 
        }
        else if(option == 4){
            printf("Please choose again \n");
            continue;
        } 
        else if(option == 2){
            printf("picked choice 2. \n");

            int number_of_seats;
            int bus_type;
            int busbooking = 1;

            printf("Booking bus. \n");
            while(busbooking == 1){

                printf("Enter number of seats (not exceeding 50): ");
                scanf("%d",&number_of_seats);
                if(!(number_of_seats > 0 && number_of_seats < 51)){
                    continue;
                }
                do{

                    printf("Enter  the bus type.\n");
                    printf("\t 1. LUXURY\n");
                    printf("\t 2  ORDINARY\n");
                    scanf("%d",&bus_type);

                    if(bus_type == 1 || bus_type == 2){
                        int cost;
                        
                        if(bus_type == 1){
    
                            strcpy(bookings[i].type,"luxury");
                            cost = 50000;
                        }
                        else if(bus_type == 2){
                            strcpy(bookings[i].type,"ordinary");
                            cost = 25000;
                        }
                        bookings[i].number_of_seats = number_of_seats;
                        bookings[i].total_cost = number_of_seats * cost;
                        bookings[i].reciept_number = i;
                        bookings[i].payment = 0;
                        

                        printf("............................YOU HAVE BOOKED ..............................\n");
                        printf("Type: %s \n",bookings[i].type);
                        printf("Number of seats: %d \n",bookings[i].number_of_seats);
                        printf("Total Cost : %d \n",bookings[i].total_cost );
                        printf("Reciept number: %d \n",bookings[i].reciept_number );
                        printf("Payment :%d \n",bookings[i].payment );
                        printf("-------------------------------------------------------------------------\n");
                        i++;
                        break;
                    }else{
                        continue;
                    }
                }while(1);


                busbooking = 0;

               
            }

            
        }  
        else if(option == 3){
            int payment;
            int receipt_number;
            int n = 1;
            int trials = 0;
            printf("......................................MAKE PAYMENT......................................\n");

            while(n == 1){
                printf("enter recipt number: ");
                scanf("%d",&receipt_number);
                if(receipt_number > i){

                    printf("The receipt number you entered doesnt exist");
                    if(trials > 2){
                        n = 0;
                        break;
                    }
                    trials = trials + 1;
                    continue;
                    
                }
                while(1){
                    printf("enter payment: ");
                    scanf("%d",&payment);
                    if(payment > bookings[receipt_number].total_cost){
                        printf("Amount so large");
                        if(trials > 2){
                        n = 0;
                        break;
                        }
                        trials = trials + 1;
                        continue;
                    }
                    if(payment < 1){
                        printf("Payment cannot be less than 1");
                        if(trials > 2){
                        n = 0;
                        break;
                        }
                        trials = trials + 1;
                    }

                    
                    bookings[receipt_number].payment = payment;
                    printf("-------------------------------------------------------------------------\n");

                    printf(".......................................You made payment for booking;.....................................\n");
                    printf("Bus Type: %s\n",bookings[receipt_number].type);
                    printf("Number of seats: %d\n",bookings[receipt_number].number_of_seats);
                    printf("Total Cost: %d\n",bookings[receipt_number].total_cost);
                    printf("Payment: %d\n",bookings[receipt_number].payment);
                    printf("Reciept Number: %d\n",bookings[receipt_number].reciept_number);
                    printf("Balance: %d\n",bookings[receipt_number].total_cost - bookings[receipt_number].payment);

                    printf("-------------------------------------------------------------------------\n");

                    n = 0;
                    break;
                }
            }


        }
        else if(option == 5){
            printf("Exiting app");
            on = 0;
            
        }
        else{
            printf("wrong option. choose again \n");
            continue;
        }
    }
 
    return 0;

}

int login(){
    char username[50];
    char password[50];
    
    printf("enter username: ");
    scanf("%s",&username);
    printf("enter password: ");
    scanf("%s",&password);

    if (strcmp(username,"admin") == 0 && strcmp(password,"admin") == 0)
    {
        printf("logged in\n");
        return 1;
    }
    else{
        printf("wrong credentials\n");
        return 0;
    }
}
