#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filemgmt.h"

int get_count(char file_path[]){
    FILE *file = fopen(file_path, "r");
    int line = 0; 
    string check = "";
    while(!ferror(file) && !feof(file)){
        if(fgets(check, BUFFER_SIZE, file) != NULL){
            line ++;
        }
    }
    fclose(file);
    return line; 
}


void read_display_and_store(char file_path[], strings array){
    FILE *file = fopen(file_path, "r");
    int line = 0; 
    while(!ferror(file) && !feof(file)){
        if(fgets(array[line], BUFFER_SIZE, file) != NULL){
            line ++;
        }
    }
    fclose(file);
    for(int i=0; i < line; i++){
        printf("%d-%s", i + 1, array[i]);
    }
}


int check_input(char message[], char error_message[], int start, int end, bool to_type){
    int option;
    do{ 
    if(to_type){
        typit(message);
    }
    else{
        printf("%s", message);    
    }
    
    scanf("%d", &option);
    scanf("%c");
    if(option >= start && option <= end){
        return option;
    }
    else{
        printf("%s", error_message);
        to_type = false;
    }
    }
    while(option < start || option > end); 
}
void pause(){
    char c; 
    scanf("%c", &c);
}

void typit(char characters[]){
    for(int i=0; i < strlen(characters); i++){
        printf("%c", characters[i]);
        Sleep(15);
    }
}


void append_to_file(char file_path[], char data[]){
    FILE *file;
    file = fopen(file_path, "a");
    fputs(data, file);
    fclose(file);  
}


int get(char file_path[], strings array, int option, int count){
    string check = ""; 
    FILE *file = fopen(file_path, "r");
    int line = 0; 
    if(fgets(check, BUFFER_SIZE, file) == NULL){
        for(int i=0; i < count; i++){
            append_to_file(file_path, "0\n");
        }
    }
    rewind(file);
    while(!ferror(file) && !feof(file)){
        if(fgets(array[line], BUFFER_SIZE, file) != NULL){
            array[line][strlen(array[line]) - 1] = '\0'; 
            line ++; 
        }
    }
    fclose(file);
    return atoi(array[option - 1]); 
}


void set(char file_path[], strings array, int data, int option, int count){
    FILE *file = fopen(file_path, "w");
    fputs("", file);
    fclose(file);
    string string_data = "";
    itoa(data, string_data, 10); 
    strcpy(array[option -1], string_data);
    for(int i=0; i < count; i++){
    append_to_file(file_path, array[i]);
    append_to_file(file_path, "\n");
}
}


void story(strings checkpoints, strings paths, strings choices, int option, int count){
    int end = 5;  
    int next_path;
    int checkpoint;

    do{ 
        checkpoint = get("checkpoints.txt", checkpoints, option, count);
        int path = get("paths.txt", paths , option, count);
        int choice = get("choices.txt", choices, option, count); 
    
    switch(checkpoint){
        case 0: 
            // paths = [0]
            system("cls");
            typit("Emily was a brilliant young physicist. She had been fascinated with the idea of time travel since she was 12 years old and she was building a time machine\nShe found a book called 'The Time Paradoxes' when she was 12 which sparked her interest in time travel\nBut this strange book had no author\n\n\nAccording to the book, changing events in the past may be impossible\nIf events in the past are somehow changed, it may cause a new present");
            choice = check_input(
             "\n\nOne day the time machine was completed and Emily decided to use it to\n\n1-Prevent a tragedy from occuring\n2-Find the author of 'The Time Paradoxes'\n\n>> ", 
             "",  
             1, 2, true
            ); 
            next_path = 3; 
            break;
        case 1:  
            // paths = [3]
            system("cls");
            typit("\nThere were limitations to the the time machine.\nThe time machine can be used just once.\nIt is only accurate to a specific date but not a specific time, the exact moment of arrival cannot be determined\nThe duration of the time travel cannot be determined. That is one can reappear in the present at any moment\n");
            pause();   
            switch(path){
                case 3:
                    switch(choice){
                        case 1:
                            system("cls");
                            typit("\nEmily wanted to prevent her bestfriend Alice from being hit by a car. This happened when she was 12 years old");
                            typit("\nEmily sat in the machine and was sucked into a wormhole (tunnels in spacetime that connect two distant points in the universe).\nShe felt as though she was being stretched and compressed simultaneously\n\nEverything went black.");
                            choice = check_input(
                            "\n\nThe date is 20th March, 2003, the day the tragedy happened and Emily woke up in a park which was far away from the tragedy location. She\n\n1-Took a taxi to try to reach the tragedy site before it happened\n2-Changed her mind to prevent any paradoxes\n\n>> ", 
                            "", 
                            1, 2, true
                            );
                            next_path = 4; 
                            break; 
                        case 2:
                            system("cls");
                            typit("\nEmily sat in the machine and was sucked into a wormhole (tunnels in spacetime that connect two distant points in the universe).\nShe felt as though she was being stretched and compressed simultaneously\n\nEverything went black.");
                            typit("\nEmily's great-grandfather was known to be a theoretical physicist\nEmily went back to the past to ask him if he recognized the book.");
                            pause();
                            next_path = 5;
                         break; 
                   }
                break; 
            }
            break; 
        case 2:
            // paths = [11, 12, 13, 14, 15]  
            switch(path){
                case 4: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            typit("\nShe got a taxi and was on her way.\nWhen they took a bend the car run into a little girl trying to cross the road.");
                            pause();
                            system("cls");
                            typit("\nIt was her bestfriend\nUltimately she was the cause of the event she was trying to prevent and this was consistent with the hypothesis of 'The Time Paradoxes' (This is known as the predestination paradox)");
                            pause();
                            next_path = 6;  
                            break;
                        case 2: 
                            system("cls");
                            typit( "\nEmily decided not to interfere with events in the past and leave them as they are\nThe only problem was that the time travel was not expiring\nIt never expired and Emily was stuck in the past. She had to build a new time machine to take her back to the present time");
                            next_path = 7;
                            break;
                    }
                    break; 
                case 5:
                    system("cls");
                    typit("\n\nIt was 17th May, 1890. Emily's great-grandfather Alexander was in his lab conducting his research.\nEmily went into the lab and asked Alexander about the book and he said, \"I have no idea of the what book that is\"");
                    typit("\n\nEmily therefore returned to the present time without an answer\nMeanwhile Emily's interaction with Alexander made him more intrigued with the idea of time travel\nThat became his life's work: how to build a time machine. Alexander became more and more focused on his work and never met Emily's great-grandmother\nThere was simply not enough time for him to fall in love\nThis means that Emily's grandfather, father, and Emily herself would have never been born\nIt was then physically impossible for Emily to exist in the first place.");
                    typit("\nThis wiped Emily from existence\nThis is called the grandfather paradox: If you prevent any of your ancestors from meeting each other then you yourself cannot exist in the first place to prevent them from meeting\n\nThe end");
                    pause();
                    break;          
                  }
            break; 
        case 3: 
            switch(path){
                case 6: 
                    system("cls");
                    typit("A predestionation paradox is a paradox in which one becomes the cause of the event they are preventing or forms part of the event\n");
                    typit("\nAlice, the victim, was with Young Emily before the accident.\nYoung Emily was in tears as they headed to a hospital\nAlice did not make it\n");
                    typit("Emily's time travel was expiring and she had to return to the present\nShe was beginning to feel sick in the stomach so she rushed to washroom where she disintegrated and reappeared in the present time\n");
                    typit("\nMeanwhile Emily had left the book 'The Time Paradoxes' in the hospital where she diasppeared\nThe book was found by Young Emily in the hospital. This is how Emily had found the book in the first place (This is known as the bootstrap paradox).");             
                    pause(); 
                    next_path = 8;
                    break;
                case 7:
                    system("cls"); 
                    typit("\nA few years passed by and Emily rebuilt the time machine");
                    typit("\nShe was able to return to the present but her stay in the past had caused a sort of butterfly effect\nThings were slightly different now in the present\nIt was just something she had to live with\nOne cannot time travel without causing minute or vast changes in the present\n\nThe end");
                    pause(); 
                    break;
            }
            break; 
        case 4: 
        switch(path){
            case 8: 
                system("cls");
                typit("\nA bootstrap paradox is a paradox where an object's origin cannot be traced but the object just exists.\nIn this case Emily's book's origin cannot be traced.");
                pause();
                typit("\nYoung Emily hoped oneday she could travel back in time to save her bestfriend. This sequence of events form a loop and will continue indefinitely\n\nThe end");
                pause();
                break;
        }
            break; 
    }
    checkpoint++;
    if(checkpoint <= end +  1){
        set("checkpoints.txt", checkpoints, checkpoint, option, count);
        set("paths.txt", paths, next_path, option, count);
        set("choices.txt", choices, choice, option, count);
    } 
    }while(checkpoint <= end);
}

