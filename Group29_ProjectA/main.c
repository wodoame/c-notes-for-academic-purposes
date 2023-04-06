    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <time.h>
    #include <windows.h>
    #include <MMSystem.h>
   

    #define MAX_WORDS 30
    #define WORD_LENGTH 15
    #define CLUE_LENGTH 400
    #define CLUE_NUMBER 3
    
    

    void get_words(char file_name[], char array[MAX_WORDS][WORD_LENGTH]); 
    void get_clues(char file_name[], char array[CLUE_NUMBER][CLUE_LENGTH], int line_to_get_from);
    void split_clues(char clues_string[], char array[CLUE_NUMBER][CLUE_LENGTH]);
    int count(char file_name[]);

    int main(){

        
        system("color 3");
        char words_file_name[20] , clues_file_name[20];
        int option1, option2; 
        int score = 0;

        

        start:
        do{
        printf("\nWelcome to word guess game!!\nGuess a word after every clue\nChoose a Level\n\n1-Easy\n2-Medium\n3-Hard\n\n>> ");
        scanf("%d",&option1);
        fflush(stdin);
        switch(option1){
            case 1: 
                strcpy(clues_file_name, "easy_clues.txt");
                strcpy(words_file_name, "easy_words.txt");
                break;
            case 2: 
                strcpy(clues_file_name, "medium_clues.txt");
                strcpy(words_file_name, "medium_words.txt");
                break;
            case 3: 
                strcpy(clues_file_name, "difficult_clues.txt");
                strcpy(words_file_name, "difficult_words.txt");
                break;
            default: 
                printf("\nPlease enter a valid option\n");
                goto start;
        }}while( option1 < 1 && option1 >= 3);

        char words[MAX_WORDS][WORD_LENGTH];
        char clues[CLUE_NUMBER][CLUE_LENGTH];
        
        srand(time(NULL));
        int tries = 5;
        do{
        int random_number = rand() % count(words_file_name) ;
        get_words(words_file_name, words);
        get_clues(clues_file_name, clues, random_number);
        int i = 0; 
        char user_answer[20]; 
        printf("\n......................................\n");
        while(i < CLUE_NUMBER && tries > 0){
            printf("\nclue %d = %s\n\nANS: ", i + 1, clues[i]);
            fgets(user_answer, 20, stdin);
            user_answer[strlen(user_answer) - 1] = '\0';
            
            if(strcasecmp(user_answer, words[random_number]) == 0){
                printf("\nYou are correct\n");
                score += 5;
                break;
            }
            else{
                tries--;
                printf("\nOops!! try again, %d tries remaining\n", tries);
            i++;
            }
        }
        if(i == CLUE_NUMBER){
            printf("\n\nThe actual word is '%s'", words[random_number]);
        }
        }
        while(tries > 0);

        printf("\n\nYour total score = %d, thank you for playing!!", score);
        printf("\n\nDo you want to play again?\n\n1-Yes\n2-No\n\n>> ");
        scanf("%d", &option2);
        fflush(stdin);
        if(option2 == 1){
           goto start;
        }
        return 0;
    }


    void get_words(char file_name[], char array[MAX_WORDS][WORD_LENGTH]){
    FILE *file = fopen(file_name, "r");
    int line = 0;
    while(!ferror(file) && !feof(file)){
        fgets(array[line], WORD_LENGTH, file);
        array[line][strlen(array[line]) - 1] = '\0';
        line++;
    }
    fclose(file);
    }


    void get_clues(char file_name[], char array[CLUE_NUMBER][CLUE_LENGTH], int line_to_get_from){
    FILE *file = fopen(file_name, "r");
    int line = 0; 
    char result[CLUE_LENGTH] = "";
    while(!ferror(file) && !feof(file)){
        fgets(result, CLUE_LENGTH, file);
        if(line == line_to_get_from){
            break;
        }
        line++;  
    }
    fclose(file);
    split_clues(result, array);
    }


    void split_clues(char clues_string[], char array[CLUE_NUMBER][CLUE_LENGTH]){
    char result[CLUE_LENGTH] = "";
    int line = 0;
    for(int i=0; i < strlen(clues_string); i++){
        char letter = clues_string[i];
        if(letter == ','){
            strcpy(array[line], result);
            line++; 
            strcpy(result, "");
        }
        else{
            strncat(result, &letter, 1);
        }
    }
    }

    int count(char file_name[]){
        FILE *file = fopen(file_name, "r");
        char check[WORD_LENGTH] = ""; 
        int line = 0; 
        while(!ferror(file) && !feof(file)){
            if(fgets(check, WORD_LENGTH, file) != NULL){
                line++;
            }
        }
        fclose(file);
        return line;
    }