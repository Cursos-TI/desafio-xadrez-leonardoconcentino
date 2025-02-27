#include <stdio.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int piece = 0;
int squares1 = 0;
int squares2 = 0;
char firstDirection [8];
char secondDirection [8];
int isDiagonal = 0;

void pawn(){

    printf("\n");
    printf("Movement:\n");
    if (squares1 == 1)
        printf("Up\n");
    else
        printf("Up\nUp\n");
    
    printf("\n");
}

void knight(){

    printf("\n");
    printf("Movement:\n");

    if(squares1 > squares2){

        int j = 0;
        for (int i = 0; i < squares1; i++){
            
            for (j; j < squares2; j++)
            {
                printf("%s\n", secondDirection);
            }
            
            printf("%s\n", firstDirection);

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

void bishop(int i){

    if (i > 0){
        
        printf("%s\n", firstDirection);
        printf("%s\n", secondDirection);
        
        bishop(i - 1);
    }

    
}

void rook(int i){

    if (i > 0){
        
        printf("%s\n", firstDirection);
        rook(i - 1);
    }
}

void queen(int i){
    
    int j = 0;

    if(isDiagonal == 1){
        if (i > 0){
        
            printf("%s\n", firstDirection);
            printf("%s\n", secondDirection);
            
            queen(i - 1);
        }
    }
    else{
        if (i > 0){
        
            printf("%s\n", firstDirection);

            queen(i - 1);
        }
    }
}

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

void collectData(){

    printf("Select which piece you want to move:\n");
    printf("1. Pawn\n2. Knight\n3. Bishop\n4. Rook\n5. Queen\n6. King\n");
    printf("Option: ");
    scanf("%d", &piece);

    switch (piece)
    {
    case 1:
    
        printf("\nHow many squares do you want to move forward?\n");
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 2 || squares1 < 1){
            printf("\nInvalid movement. The pawn only moves 1 or 2 squares forward.\nHow many squares do you want to move forward?\n");
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        break;
    
    case 2:

        getchar();
        printf("\nTo which direction would you like to go first?\n");
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up' or 'down'.\nTo which direction would you like to go first?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nHow many squares do you want to move %s?\n", firstDirection);
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 2 || squares1 < 1){
            printf("\nInvalid movement. The knight only moves 1 or 2 squares in each movement.\nHow many squares do you want to move %s?\n", firstDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        printf("\nTo which direction would you like to go second?\n");
        printf("Direction: ");
        scanf("%s", secondDirection); //remember after to make it case insensitive

        while(strcmp(secondDirection, firstDirection) == 0 && strcmp(secondDirection, "left") != 0 && strcmp(secondDirection, "right") != 0 && strcmp(secondDirection, "up") != 0 && strcmp(secondDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type a valid direction.\nTo which direction would you like to go second?\n");
            printf("Direction: ");
            scanf("%s", secondDirection);

        }
        
        if(squares1 == 1)
            squares2 = 2;
        else
            squares2 = 1;
        
        printf("\nYou have moved %d squares in the first movement, so the second movement of the Knight must be %d squares.\n", squares1, squares2);
        break;

    case 3:
        
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

        printf("\nHow many squares do you want to move in diagonal %s-%s?\n", firstDirection, secondDirection);
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 7 || squares1 < 1){
            printf("\nInvalid movement. The bishop only moves up to 7 squares in diagonal.\nHow many squares do you want to move %s-%s?\n", firstDirection, secondDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
            squares2 = squares1;
        }
        
        break;

    case 4:
        
        getchar();
        printf("\nTo which direction would you like to go?\n");
        printf("Direction: ");
        scanf("%s", firstDirection);

        while (strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0 && strcmp(firstDirection, "up") != 0 && strcmp(firstDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up' or 'down'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nHow many squares do you want to move %s?\n", firstDirection);
        printf("Quantity: ");
        scanf("%d", &squares1);
            
        while(squares1 > 7 || squares1 < 1){
            printf("\nInvalid movement. The rook only moves up to 7 squares in a movement.\nHow many squares do you want to move %s?\n", firstDirection);
            printf("Quantity: ");
            scanf("%d", &squares1);
        }
        
        break;

    case 5:

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
        else{

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

    case 6:
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
    do
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
