#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(int [], int [], int []);
int changePass(int );

int user = 0;

int main(){

    int id[10];
    int passwords[10];
    int cash[10];

    FILE *fptr;


    fptr = fopen("acc.txt", "r");
    char test_id[1000];
    fgets(test_id, 1000, fptr);


    
    char *token = strtok(test_id, "-");

    
    
    int index =0;
    while (token != NULL)
    {
        if(index<10)
            id[index] = atoi(token);
        else if(index<20)
                passwords[index-10] = atoi(token);
        else
            cash[index-20] = atoi(token);


        
        token = strtok(NULL, "-");
        index++;
    }
    fclose(fptr);

    while(1){
        system("cls");
        printf("Welcome to ATM:");
        printf("\nEnter your number account:");
        int acc;
        scanf("%d", &acc);
        printf("\nEnter your password:");
        int pass;
        scanf("%d", &pass);
        int br;
        for(int i=0; i<10; i++){
            if(id[i]==acc && passwords[i] == pass){
                user = i;
                br = 1;
                break;
            }
        }
        if(br == 1){
            break;
        }
    }







    menu(id, passwords, cash);

    return 0;

}

void menu(int id[], int passwords[], int cash[]){

    system("cls");


    int choice;
    while(1){
        printf("Welcome to the ATM:\n");
        printf("1.change password:\n2.money Transfer\n3.bardasht ya ezafe kardan vajh naghd\n4.mojodi(1$ karmozd)\n5.save and quit\n6.status\n");
        printf("Enter your choice:");

        scanf("%d", &choice);
        if(choice > 0 && choice <=6){
            break;
        }
        system("cls");
    }

    


    switch (choice){
        case 1:
            passwords[user] = changePass(id[user]);
            system("cls");
            printf("Password change for user: %d", id[user]);
            printf("\nNew pass: %d", passwords[user]);
            sleep(2);
            system("cls");


            break;

        case 2:

            system("cls");
            printf("shomare hesab maghsad ra vared konid:");
            int maghsad;
            scanf("%d", &maghsad);

            printf("Mablagh ra vared konid:");
            int mablagh;
            scanf("%d", &mablagh);

            int index_maghsad;
            for(int i=0; i<10; i++){
                if(id[i] == maghsad)
                    index_maghsad = i;
            }

            cash[user] -= mablagh;
            cash[index_maghsad] += mablagh;

            printf("Done!\n");
            printf("mojodi shoma: %d", cash[user]);
            printf("\nmojodi hesab %d: %d", id[index_maghsad], cash[index_maghsad]);
            sleep(2);



            break;

        case 3:
            system("cls");
            while(1){
                printf("Enter your choice:\n1.bardasht\n2.ezafehkardan\n");
                int c;
                scanf("%d", &c);

                if(c==1){
                    system("cls");
                    printf("mablagh ravaredkonid:");
                    int m;
                    scanf("%d", &m);
                    cash[user] -= m;
                }else if(c==2){
                    system("cls");
                    printf("mablagh ravaredkonid:");
                    int m;
                    scanf("%d", &m);
                    cash[user] += m;
                }
                if(c==1 || c==2){
                    break;
                }
            }
            printf("Mojodi shoma: %d", cash[user]);
            sleep(3);

            break;

        case 4:
            system("cls");
            cash[user]--;
            printf("Mojodi shoma barabar ast ba: %d\n", cash[user]);
            getchar();
            printf("press Enter to back menu...");
            getchar();
            break;

        case 5:{
            int info[30];
            for(int i=0; i<30; i++){
                if(i<10)
                    info[i] = id[i];
                else if(i<20)
                    info[i] = passwords[i-10];
                else
                    info[i] = cash[i-20];
            }

            
            

            char str[1000]; 
            int strIndex = 0; 

            
            for (int i = 0; i < 30; ++i) {
                strIndex += snprintf(str + strIndex, sizeof(str) - strIndex, "%d-", info[i]);
            }

            writeToFile(str);
            return 1;

        }
        case 6:
            for(int i=0; i<10; i++){
                printf("\n%d : %d : %d", id[i], passwords[i], cash[i]);
            }

            printf("\npress Enter to continue ...");
            getchar();
            getchar();
            break;

    }
    menu(id, passwords, cash);
}

int changePass(int id){
    system("cls");
    int newPass;
    int newPass2;
    while(1){
        printf("Enter your new password:");
        scanf("%d", &newPass);


        printf("Enter your new password again:");
        scanf("%d", &newPass2);

        if(newPass == newPass2){
            printf("YESSSSSSSSSS!!!");
            break;
        }
        system("cls");
    }


    return newPass2;
}

void writeToFile(char str[]){


        FILE *fptr2;
        fptr2 = fopen("acc.txt", "w");
        fputs(str, fptr2);
        fclose(fptr2);







}




