//Including the libraries.
# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<windows.h>

//Creating the main game function.
int result(char player, char comp);

//Starting the main programming function function
int main(){
    //initializing variables.
    int rnum, ans, pa = 1;
    char player, comp;

    home:
        //Getting a random number from comp.
        srand(time(0));
        rnum = rand()%3;

        //Greeting the Player.
        printf("\nwelcome to the SNAKE, WATER, GUN game.\n \n");
        
        printf("Please follow the insturctions carefully to procced.\n \n");
            
        //Assigning a random number snake, water, gun.
        if(rnum == 0){
            comp = 's';
        }//Will assign the value of Snake to computer.
        else if(rnum == 1){
            comp = 'w';
        }//Will assign the value of Water to computer.
        else{
            comp = 'g';
        }//Will assign the value of Gun to computer.

        //User entering the value.
        printf("\nPlease press 's' for snake, 'g' for gun, 'w' for water (rest all the input will terminate the game) : ");
        scanf("\n%c", &player);

        //Checking for the right input.
        if(player == 's' || player == 'w' || player == 'g'){
            //Calling the function.
            ans = result(player, comp);

            //Declearing the winner.
            switch(ans){
                case 1:
                    Beep(1000, 250);
                    printf("Congratulations. You won!!\n");
                    printf("Your choice was %c while the computer choice was %c\n", player, comp);
                    break;

                case 0:
                    Beep(1000, 250);
                    printf("Tie.\n");
                    printf("Your choice was %c while the computer choice was %c\n", player, comp);
                    break;
                    
                case -1:
                    Beep(1000, 250);
                    printf("Sorry. You lost!!\n");
                    printf("Your choice was %c while the computer choice was %c\n", player, comp);
                    break;
            }

        }
        else{
            printf("Please enter only 's', 'w' or 'g'. Rest inputs will terminate the game.\n");
        }


        printf("Do you wish to play again(press'1' for YES and '0' for NO): ");
        scanf("%d", &pa);
        if(pa == 1){
            goto home;
        }else{
            printf("Thx for playing.");
            Beep(1000, 250); 
            exit(0);
        }

    return 0;
}

//Declating the funciton.
int result(char player, char comp){

    //for tie.
    if(player == comp){
        return 0;
    }

    else{

        //for player to win.
        if(player == 's' && comp == 'w'){
            return 1;
        }

        else if(player == 'w' && comp == 'g'){
            return 1;
        }

        else if(player == 'g' && comp == 's'){
            return 1;
        }

        //for computer to win.        
        else if(player == 's' && comp == 'g'){
            return -1;
        }

        else if(player == 'w' && comp == 's'){
            return -1;
        }

        else if(player == 'g' && comp == 'w'){
            return -1;
        }
    }
}