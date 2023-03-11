#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 255
#define PROFILE_LIMIT 10 

// note: stable version 

// function prototypes
int check_input(char message[], char error_message[], int start, int end);
void read_display_and_store(char file_path[]);
void append_to_file(char file_path[], char data[]);
void story(int checkpoint, int option, int count);
int get_checkpoint(char file_path[],int option, int count);
void save_checkpoint(char file_path[], char new_checkpoint[], int option, int count); 

// type definitions
typedef char string[BUFFER_SIZE]; 
typedef char strings[PROFILE_LIMIT][BUFFER_SIZE];

// global variables
strings profile_names = {};
strings profile_checkpoints = {};
int count; 


int main(){
    int option; 
    option = check_input("\n1-New Game\n2-Load Game\n\n>> ", "\nInvalid input: please choose a correct option\n", 1, 2); 

    if(option == 2){       
        printf("\nChoose Profile\n...............\n\n");
        read_display_and_store("profiles.txt");
        option = check_input("\n\n>> ", "\nNo such profile please choose again", 1, count);
        string selected_profile = ""; 
        strcpy(selected_profile, profile_names[option - 1]); 
        printf("the selected profile = %s ", selected_profile);
        int checkpoint = get_checkpoint("checkpoints.txt", option, count);
        story(checkpoint, option, count);        
    }
    else
        {
        string profile_name;
        printf("\nCreate New Profile\n....................\nChoose Profile Name\n\n>> ");    
        fgets(profile_name, BUFFER_SIZE, stdin);      
        append_to_file("profiles.txt", profile_name);
        append_to_file("checkpoints.txt", "0\n"); 
    }

    return EXIT_SUCCESS; 
}


// functions
void read_display_and_store(char file_path[]){
    FILE *file = fopen(file_path, "r");
    int line = 0; 
    while(!ferror(file) && !feof(file)){
        if(fgets(profile_names[line], BUFFER_SIZE, file) != NULL){
            line ++;
        }
    }
    fclose(file);
    for(int i=0; i < line; i++){
        printf("%d-%s", i + 1, profile_names[i]);
    }
    count = line;
}

int check_input(char message[], char error_message[], int start, int end){
    int option;
    do{ 
    printf("%s", message);
    scanf("%d", &option);
    scanf("%c");
    if(option >= start && option <= end){
        return option;
    }
    else{
        printf("%s", error_message);
    }
    }
    while(option < start || option > end); 

    

}


void append_to_file(char file_path[], char data[]){
    FILE *file;
    file = fopen(file_path, "a");
    fputs(data, file);
    fclose(file);  
}


void story(int checkpoint, int option, int count){
    int end = 5;  
    string string_checkpoint;
    do{
      switch(checkpoint){
        case 0: 
            break; 
        case 1:
            break;
        case 2: 
            break; 
        case 3: 
            break;
        case 4: 
            break;
        case 5: 
            break;
      }  
      checkpoint++;
      if(checkpoint <= end + 1){
        itoa(checkpoint, string_checkpoint, 10);
        save_checkpoint("checkpoints.txt", string_checkpoint, option, count);
      }
      
    }
    while(checkpoint <= end);   
}


int get_checkpoint(char file_path[], int option, int count){
FILE *file = fopen(file_path, "r");
int line = 0;
string check = ""; 

if(fgets(check, BUFFER_SIZE, file) == NULL){
  for(int i=0; i < count; i++){
    append_to_file(file_path, "0\n");
  }
}
rewind(file);
while(!ferror(file) && !feof(file)){
    if(fgets(profile_checkpoints[line], BUFFER_SIZE, file) != NULL){
        profile_checkpoints[line][1] = '\0'; 
        line++;
    };
}
fclose(file);
return atoi(profile_checkpoints[option - 1]); 
}


void save_checkpoint(char file_path[], char new_checkpoint[], int option,  int count){
FILE *file = fopen(file_path, "w");
fputs("", file);
fclose(file);
strcpy(profile_checkpoints[option - 1], new_checkpoint); 
for(int i=0; i<count; i++){
append_to_file(file_path, profile_checkpoints[i]);
append_to_file(file_path, "\n");
} 
}
