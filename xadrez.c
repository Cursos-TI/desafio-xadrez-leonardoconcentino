#include <stdio.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int piece = 0; //this variable will tell the function which piece the player would like to move
int squares1 = 0; //number of squares that player will move piece
int squares2 = 0; //number of squares that player will move piece (for knight or diagonal movements)
char firstDirection [8]; //variable to keep the direction chose by player
char secondDirection [8]; //variable to keep the second direction (knight or if it's diagonal)
int isDiagonal = 0; //"boolean" to determine if player chose diagonal movement

//function to print movement of pawn
void pawn(){

    printf("\n");
    printf("Movement:\n");
    if (squares1 == 1) //pawn can make 2 types of movement: 1 square forward or 2 squares forward
        printf("Up\n");
    else
        printf("Up\nUp\n");
    
    printf("\n");
}

//function to print movement of knight
void knight(){

    printf("\n");
    printf("Movement:\n");

    if(squares1 > squares2){ //I made this 'if' to make printing more beautiful, so the program print the bigger direction together

        int j = 0; // declare before so it will not infinite loop
        for (int i = 0; i < squares1; i++){ //for to print directions
            
            for (j; j < squares2; j++)
            {
                printf("%s\n", secondDirection);
            }
            
            printf("%s\n", firstDirection); //after finishing printing 

        }

        printf("\n");

    }
    else{

        int j = 1;
        int i = 0;

        do{

            while(j <= squares1){
                printf("%s\n", firstDirection);
                j++;
            }

            printf("%s\n", secondDirection);
            i++;
        }
        while(i < squares2);
    }

    printf("\n");

} 

//function to print bishop's movement.
void bishop(int i){

    if (i > 0){
        
        printf("%s\n", firstDirection);
        printf("%s\n", secondDirection);
        
        bishop(i - 1); //call the same function again until it finishes 'i'
    }

    
}

//function to print rook's movement
void rook(int i){

    if (i > 0){
        
        printf("%s\n", firstDirection);
        rook(i - 1); //call the same function again until it finishes 'i'
    }
}

//function to print queen's movement
void queen(int i){
    
    int j = 0;

    if(isDiagonal == 1){ //if it's a diagonal movement, print interleaved directions
        if (i > 0){
        
            printf("%s\n", firstDirection);
            printf("%s\n", secondDirection);
            
            queen(i - 1);
        }
    }
    else{ //if it's a straight movement (up, down, left or right)
        if (i > 0){
        
            printf("%s\n", firstDirection);

            queen(i - 1);
        }
    }
}

//print king's movement. same as queen, but with only 1 square movement
void king(){

    printf("\n");
    printf("Movement:\n");

    if(isDiagonal == 1){
        printf("%s\n%s\n", firstDirection, secondDirection);
    }
    else{
        printf("%s\n", firstDirection);
    }
    
    printf("\n");

}

//function to collect data from user on terminal
void collectData(){

    printf("Select which piece you want to move:\n");
    printf("1. Pawn\n2. Knight\n3. Bishop\n4. Rook\n5. Queen\n6. King\n");
    printf("Option: ");
    scanf("%d", &piece);

    switch (piece) // this switch will determine which function the program must call, based on the piece chose by the user
    {
    case 1: //pawn
    
        printf("\nHow many squares do you want to move forward?\n");
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 2 || squares1 < 1){ //validating. only 1 or 2 squares
            printf("\nInvalid movement. The pawn only moves 1 or 2 squares forward.\nHow many squares do you want to move forward?\n");
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        break;
    
    case 2: //knight

        getchar();
        printf("\nTo which direction would you like to go first?\n");
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up' or 'down'.\nTo which direction would you like to go first?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nHow many squares do you want to move %s?\n", firstDirection); //must be 1 or 2. the second number of squares will be determined automatically (if squares1 == 2, squares2 == 1)
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 2 || squares1 < 1){
            printf("\nInvalid movement. The knight only moves 1 or 2 squares in each movement.\nHow many squares do you want to move %s?\n", firstDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        printf("\nTo which direction would you like to go second?\n"); //mandatory another direction, not the same as first direction
        printf("Direction: ");
        scanf("%s", secondDirection);

        while(strcmp(secondDirection, firstDirection) == 0 && strcmp(secondDirection, "left") != 0 && strcmp(secondDirection, "right") != 0 && strcmp(secondDirection, "up") != 0 && strcmp(secondDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type a valid direction.\nTo which direction would you like to go second?\n");
            printf("Direction: ");
            scanf("%s", secondDirection);

        }
        
        if(squares1 == 1) //automatically setting squares2 value
            squares2 = 2;
        else
            squares2 = 1;
        
        printf("\nYou have moved %d squares in the first movement, so the second movement of the Knight must be %d squares.\n", squares1, squares2);
        break;

    case 3: //bishop
        
        printf("\nTo which direction would you like to go first? (Up or Down)\n"); //first direction of diagonal
        printf("Direction: ");
        scanf("%s", firstDirection);
        
        while(strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go first?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nTo which direction would you like to go second? (Right or Left)\n"); //second direction of diagonal
        printf("Direction: ");
        scanf("%s", secondDirection); 
        
        while(strcmp(secondDirection, "right") != 0 && strcmp(secondDirection, "left") != 0){
            
            printf("\nIncorrect direction. Please, type 'right' or 'left'.\nTo which direction would you like to go second?\n");
            printf("Direction: ");
            scanf("%s", secondDirection);

        }

        printf("\nHow many squares do you want to move in diagonal %s-%s?\n", firstDirection, secondDirection); //collect number of squares to move
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 7 || squares1 < 1){
            printf("\nInvalid movement. The bishop only moves up to 7 squares in diagonal.\nHow many squares do you want to move %s-%s?\n", firstDirection, secondDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
            squares2 = squares1;
        }
        
        break;

    case 4: //rook
        
        getchar();
        printf("\nTo which direction would you like to go?\n"); //only straight movements
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up' or 'down'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nHow many squares do you want to move %s?\n", firstDirection); //collect how many squares to move
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 7 || squares1 < 1){
            printf("\nInvalid movement. The rook only moves up to 7 squares in a movement.\nHow many squares do you want to move %s?\n", firstDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        break;

    case 5: //queen

        getchar();
        printf("\nTo which direction would you like to go? (Up, Down, Left, Right or Diagonal)\n"); //queen can go in any direction
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0 && strcmp(firstDirection, "diagonal") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up', 'down' or 'diagonal'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        if(strcmp(firstDirection, "diagonal") == 0 ){
           
            isDiagonal = 1; //boolean to show that is a diagonal movement for the queen

            printf("\nTo which direction would you like to go first? (Up or Down)\n"); //same as bishop
            printf("Direction: ");
            scanf("%s", firstDirection);
            
            while(strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
                
                printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go first?\n");
                printf("Direction: ");
                scanf("%s", firstDirection);

            }

            printf("\nTo which direction would you like to go second? (Right or Left)\n");
            printf("Direction: ");
            scanf("%s", secondDirection); //remember after to make it case insensitive
            
            while(strcmp(secondDirection, "right") != 0 && strcmp(secondDirection, "left") != 0){
                
                printf("\nIncorrect direction. Please, type 'right' or 'left'.\nTo which direction would you like to go second?\n");
                printf("Direction: ");
                scanf("%s", secondDirection);

            }

            printf("\nHow many squares do you want to move in diagonal %s-%s?\n", firstDirection, secondDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
                    
            while(squares1 > 7 || squares1 < 1){
                printf("\nInvalid movement. The bishop only moves up to 7 squares in diagonal.\nHow many squares do you want to move %s-%s?\n", firstDirection, secondDirection);
                printf("Quantity: ");
                scanf("%d", &squares1);
                squares2 = squares1;
            }
        }
        else{ //straight movement, same as rook

            printf("\nHow many squares do you want to move %s?\n", firstDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
                
            while(squares1 > 7 || squares1 < 1){
                printf("\nInvalid movement. The queen only moves up to 7 squares in a movement.\nHow many squares do you want to move %s?\n", firstDirection);
                printf("Quantity: ");
                scanf("%d", &squares1);
            }

        }
        
        break;

    case 6: //king movement, same as queen, but with only 1 square movement, so player doesnt put number of squares to move
        getchar();
        printf("\nTo which direction would you like to go? (Up, Down, Left, Right or Diagonal)\n");
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0 && strcmp(firstDirection, "diagonal") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up', 'down' or 'diagonal'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        if(strcmp(firstDirection, "diagonal") == 0 ){
            
            isDiagonal = 1;

            printf("\nTo which direction would you like to go first? (Up or Down)\n");
            printf("Direction: ");
            scanf("%s", firstDirection); //remember after to make it case insensitive
            
            while(strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
                
                printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go first?\n");
                printf("Direction: ");
                scanf("%s", firstDirection);

            }

            printf("\nTo which direction would you like to go second? (Right or Left)\n");
            printf("Direction: ");
            scanf("%s", secondDirection); //remember after to make it case insensitive
            
            while(strcmp(secondDirection, "right") != 0 && strcmp(secondDirection, "left") != 0){
                
                printf("\nIncorrect direction. Please, type 'right' or 'left'.\nTo which direction would you like to go second?\n");
                printf("Direction: ");
                scanf("%s", secondDirection);

            }
        }
        break;
    
    default:
        printf("\nInvalid option.\n");
        break;
    }

}

//function to call the game and print
void chessGame(){

    switch (piece)
    {
    case 1:
        pawn();
        break;
    
    case 2:
        knight();
        break;

    case 3:
        bishop(squares1);
        break;

    case 4:
        rook(squares1);
        break;

    case 5:
        queen(squares1);
        break;

    case 6:
        king();
        break;
    
    default:
        break;
    }

}

int main() {
    
    char option [1];
    do // repeat until players choose to finish
    {   
        isDiagonal = 0;
        collectData();
        chessGame();

        printf("Would you like to continue playing? (Y/N)\n");
        printf("Option: ");
        scanf("%s", option);
        getchar();

    } while (strcmp(option, "y") == 0);

    return 0;
}
