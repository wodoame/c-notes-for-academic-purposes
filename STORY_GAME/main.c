#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filemgmt.h"


int main(){
  strings profile_names = {}, checkpoints = {}, paths = {}, choices = {};
  int count = get_count("profiles.txt");
  int option = check_input("\n1-New Game\n2-Load Game\n\n>> ", "\nInvalid input: please choose a correct option\n", 1, 2, false);



  if(option == 2){
    printf("\nChoose Profile\n...............\n\n");
    read_display_and_store("profiles.txt", profile_names);
    option = check_input("\n\n>> ", "\nNo such profile please choose again", 1, count, false);
    string selected_profile = ""; 
    strcpy(selected_profile, profile_names[option - 1]); 
    printf("\nthe selected profile = %s \n", selected_profile);
    story(checkpoints, paths, choices, option, count); 
  }
  else{
        string profile_name;    
        if(get_count("profiles.txt") == PROFILE_LIMIT){
            printf("\nYou cannot create any more profiles\n\n");
        }
        else{
            printf("\nCreate New Profile\n....................\nChoose Profile Name\n\n>> ");
            fgets(profile_name, BUFFER_SIZE, stdin);      
            append_to_file("profiles.txt", profile_name);
            append_to_file("checkpoints.txt", "0\n");
            append_to_file("paths.txt", "0\n");
            append_to_file("choices.txt", "0\n");
            printf("\nprofile '%s' created successfully\n", profile_name);
        }
  }
  
  return EXIT_SUCCESS;
}

