#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filemgmt.h"


// This is a summary of the project code and the main functionality is handled by 'filemgmt.h'
// run this program by clicking on the executable app.exe

int main(){
  strings profile_names = {}, checkpoints = {}, paths = {}, choices = {};
  start:
    int count = get_count("profiles.txt");
    system("color 6");
    int option = check_input("\n1-New Game\n2-Load Game\n\n>> ", "\nInvalid input: please choose a correct option\n", 1, 2, false);
  
  
  if(option == 2){
    printf("\nChoose Profile\n...............\n\n");
    read_display_and_store("profiles.txt", profile_names);
    if(count  != 0){
      option = check_input("\n\n>> ", "\nNo such profile please choose again", 1, count, false);
      }
    else{
      goto start;
    }
    story(checkpoints, paths, choices, option, count);
    option = check_input(
      "\n\nDo you want to play with another profile?\n\n1-Yes\n2-No\n\n>> ", 
      "", 
      1,2, 
      false
    );
    if(option == 1){
      goto start;
    }
  }
  else{
        string profile_name;    
        if(get_count("profiles.txt") == PROFILE_LIMIT){
            printf("\nYou cannot create any more profiles\n\n");
            goto start;
        }
        else{
            printf("\nCreate New Profile\n....................\nChoose Profile Name\n\n>> ");
            fgets(profile_name, BUFFER_SIZE, stdin);      
            append_to_file("profiles.txt", profile_name);
            append_to_file("checkpoints.txt", "0\n");
            append_to_file("paths.txt", "0\n");
            append_to_file("choices.txt", "0\n");
            profile_name[strlen(profile_name) - 1] = '\0'; 
            printf("\nprofile '%s' created successfully\n", profile_name);
            goto start;
        }
  }
  
  return EXIT_SUCCESS;
}

/*
Group members
Bernard Mawulorm Kofi Wodoame - 7110721
Ignatus Selasie Kemavor - 7101021
Maxwell Seyram Hayibor - 7099921
Samuel Kwame Adomako - 7088421 
Nana Kwame Gideon Nyarko - 7104521
Francis Redeemer Yaw Dzakpasu - 7097921
Daron Apau - 7092421
Terrance Ofori Tenkorang -7109721
*/