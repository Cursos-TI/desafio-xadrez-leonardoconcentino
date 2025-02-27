#include <stdio.h>
#include <string.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int piece = 0;
int squares1 = 0;
int squares2 = 0;
char firstDirection [6];
char secondDirection [6];
char typeOfMovement [8];

void pawn(){

    if (squares1 == 1)
        printf("Up\n");
    else
        printf("Up\nUp\n");

}

void knight(){

    for (int i = 0; i < squares1; i++)
    {
        printf("%s\n", firstDirection);
    }

    for (int i = 0; i < squares2; i++)
    {
        printf("%s\n", secondDirection);
    }
    
    
}

void bishop(){

    int i = 0;
    
    do{

        printf("%s-%s\n", firstDirection, secondDirection);
        i++;

    }
    while(i < squares1);
}

void rook(){

    printf("\n");
    for(int i = 0; i < squares1; i++){

        printf("%s\n", firstDirection);

    }
}

void queen(){
    
    int i = 0;
    
    while(i < squares1){

        printf("Left\n");
        i++;

    }

}

void king(){
    
    printf("%s\n", typeOfMovement);

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
        
        printf("\nTo which direction would you like to go first? (Left or Right)\n");
        printf("Direction: ");
        scanf("%s", firstDirection); //remember after to make it case insensitive
        
        while(strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0){
            
            printf("\nIncorrect direction. Please, type 'left' or 'right'.\nTo which direction would you like to go first?\n");
            printf("Direction: ");
            scanf("%s", firstDirection);

        }

        printf("\nTo which direction would you like to go second? (Up or Down)\n");
        printf("Direction: ");
        scanf("%s", secondDirection); //remember after to make it case insensitive
        
        while(strcmp(secondDirection, "up") != 0 && strcmp(secondDirection, "down") != 0){
            
            printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go second?\n");
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
        scanf("%s", typeOfMovement);

        while (strcmp(typeOfMovement, "left") != 0 && strcmp(typeOfMovement, "right") != 0 && strcmp(typeOfMovement, "up") != 0 && strcmp(typeOfMovement, "down") != 0 && strcmp(typeOfMovement, "diagonal") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up', 'down' or 'diagonal'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", typeOfMovement);

        }

        if(strcmp(typeOfMovement, "diagonal") == 0 ){
           
            printf("\nTo which direction would you like to go first? (Left or Right)\n");
            printf("Direction: ");
            scanf("%s", firstDirection); //remember after to make it case insensitive
            
            while(strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0){
                
                printf("\nIncorrect direction. Please, type 'left' or 'right'.\nTo which direction would you like to go first?\n");
                printf("Direction: ");
                scanf("%s", firstDirection);

            }

            printf("\nTo which direction would you like to go second? (Up or Down)\n");
            printf("Direction: ");
            scanf("%s", secondDirection); //remember after to make it case insensitive
            
            while(strcmp(secondDirection, "up") != 0 && strcmp(secondDirection, "down") != 0){
                
                printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go second?\n");
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
        scanf("%s", typeOfMovement);

        while (strcmp(typeOfMovement, "left") != 0 && strcmp(typeOfMovement, "right") != 0 && strcmp(typeOfMovement, "up") != 0 && strcmp(typeOfMovement, "down") != 0 && strcmp(typeOfMovement, "diagonal") != 0){
            
            printf("\nIncorrect direction. Please, type 'left', 'right', 'up', 'down' or 'diagonal'.\nTo which direction would you like to go?\n");
            printf("Direction: ");
            scanf("%s", typeOfMovement);

        }

        if(strcmp(typeOfMovement, "diagonal") == 0 ){
        
            printf("\nTo which direction would you like to go first? (Left or Right)\n");
            printf("Direction: ");
            scanf("%s", firstDirection); //remember after to make it case insensitive
            
            while(strcmp(firstDirection, "left") != 0 && strcmp(firstDirection, "right") != 0){
                
                printf("\nIncorrect direction. Please, type 'left' or 'right'.\nTo which direction would you like to go first?\n");
                printf("Direction: ");
                scanf("%s", firstDirection);

            }

            printf("\nTo which direction would you like to go second? (Up or Down)\n");
            printf("Direction: ");
            scanf("%s", secondDirection); //remember after to make it case insensitive
            
            while(strcmp(secondDirection, "up") != 0 && strcmp(secondDirection, "down") != 0){
                
                printf("\nIncorrect direction. Please, type 'up' or 'down'.\nTo which direction would you like to go second?\n");
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
        bishop();
        break;

    case 4:
        rook();
        break;

    case 5:
        queen();
        break;

    case 6:
        king();
        break;
    
    default:
        break;
    }

}


int main() {
    
    collectData();
    chessGame();

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}
