#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filemgmt.h"


// counts the number of elements in a file
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

// reads from a file, stores data in an array and displays it 
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
    if(line == 0){
        printf("\nNo profiles created yet\n");
    }
}

// ensures that the user makes only valid choices
int check_input(char message[], char error_message[], int start, int end, bool to_type){
    int option;
    bool data_is_valid = false;
    do{ 
    start:
    if(to_type){
        type(message);
    }
    else{
        printf("%s", message);    
    }
    
    if(scanf("%d", &option) != 1){
        // scanf("%*[^\n]");
        fflush(stdin);
        to_type = false;
        printf("%s", error_message);
        continue;
    }
    fflush(stdin);
    if(option >= start && option <= end){
        return option;
    }
    else{
        printf("%s", error_message);
        to_type = false;
    }
    }
    while(!data_is_valid); 

}

// creates a pause in the running of the program
void pause(){
    char c; 
    scanf("%c", &c);
}

// prints a string with a delay after every character
void type(char characters[]){
    for(int i=0; i < strlen(characters); i++){
        printf("%c", characters[i]);
        Sleep(15);
    }
}


// adds some data to a file
void append_to_file(char file_path[], char data[]){
    FILE *file;
    file = fopen(file_path, "a");
    fputs(data, file);
    fclose(file);  
}


// gets some data from a file
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

// updates some data in a file
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

//  plays the story
void story(strings checkpoints, strings paths, strings choices, int option, int count){
    int end = 8;  // progress = (x=checkpoint, y=paths, z=choice)
    int next_path;
    int checkpoint;
    restart:
    do{ 
        checkpoint = get("checkpoints.txt", checkpoints, option, count);
        int path = get("paths.txt", paths , option, count);
        int choice = get("choices.txt", choices, option, count); 
    
    switch(checkpoint){
        case 0: 
            // paths = [0]
            system("cls");
            system("color 3");
            type("Once upon a time, there was a young girl named Emily who lived in a small village in the countryside");
            type("\nOne day while she was out walking in the woods, she stumbled upon a mysterious-looking key lying on the ground");
            choice = check_input(
                "\n\n1-Intrigued she picked it up\n2-She ignored the key and walked on\n\n>> ", 
                  "\nInvalid input: please enter something correct\n", 
                1,2,
                true 
            ); 
            next_path = 1; 
            break;
        case 1:  
            // paths = [1]
            system("cls");
            type("\nAs she walked deeper into the woods, she came across an old, abandoned mansion. It was in a state of disrepair, but");
            type("\nShe noticed a lock on the front gate");
            switch(path){
                case 1:
                    switch(choice){
                        case 1:
                            choice = check_input(
                                "\n\n1-She decides to try the key on the gate\n2-She decided it was not worth her time and headed back home\n\n>> ", 
                                "", 
                                1,2, 
                                true
                            ); 
                            next_path = 2;
                            break;
                        case 2:
                            choice = check_input(
                                "\nEmily remembered she had left a certain key earlier\n\n1-And she decided to go back for it\n2-But decided to just continue her hike\n\n>> ",
                                "",
                                1,2, 
                                true 
                                );
                            next_path = 3;
                            break; 
                   }
                break; 
            }
            break; 
        case 2:
            // paths = [2, 3]
            switch(path){
                case 2: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            type("Emily inserted the key into the lock, and to her surprise, it clicked and the gate swung open.");
                            type("\nShe walked up the overgrown path to the mansion's entrance and tried the key on the door\nTo her surprise it worked there also");  
                            type("\n\nThe mansion was dark and dusty, but she could see that it was once a grand and beautiful place");
                            choice = check_input(
                                "\nShe came across a locked chest. She wondered if this key could open everything\n\n1-She tries the key on the chest\n2-She felt uneasy and did not try the key on the lock\n\n>> ", 
                                "", 
                                1,2, 
                                true
                            );
                            next_path = 4; 
                            break;
                        case 2: 
                            system("cls");
                            system("color 2");
                            type("Emily went back home never knowing what treasures or dangers lay within the abandoned mansion\n");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break; 
                case 3:
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 6");
                            type("As Emily went to back to search for the key she had a feeling that she was being watched");
                            type("\nWhen she arrived at where she saw the key at first, the key was not there anymore");
                            type("\n\nThe hairs on the back of her head stood up. She just decided to go home and quickened her pace, her heart was pounding");
                            type("\nSuddenly she heard a voice whisper her name, \"Emily\". She turned around but there is no one and she felt\n");
                            type("a cool breeze brush against her cheeks, and a sense of unease washed over her");
                            choice = check_input(
                                "\nShe took a deep breath\n\n1-And followed the sound\n2-And kept walking\n\n>> ",
                                "", 
                               1,2, 
                               true 
                            );
                            next_path = 12;
                            break; 
                        case 2: 
                            system("cls");
                            type("As she continued walking she stumbled upon a small cottage that was abandoned and looked as if it had not been inhabited for years");
                            type("\nCuriosity got the best of her, and she decided to explore the cottage.");
                            type("\n\nAs she entered the cottage, she found an old dusty book on the shelf. It seemed to be a spell book.");
                            type("\nEmily was fascinated by the book and decided to take it with her");
                            pause();
                            next_path = 5;
                            break; 
                    }
                    break;          
                  }
            break; 
        case 3: 
            switch(path){
                // paths = [4, 5, 12]
                case 4: 
                    switch(choice){
                        case 1:
                            system("cls");
                            type("\nThe key fit perfectly in the lock, and the chest creaked open. It was weird that this was happening for every lock. Inside, Emily found");
                            type("\na small, intricately crafted music box. When she wound it up and opened it, it played a hauntingly beautiful melody that filled the room.");
                            type("\n\nAs she listened, she noticed that the music seemed to be coming from a specific direction.\nShe followed the sound a hidden door and wondered ");
                            type("if she should go through it or not.");
                            choice = check_input(
                                "\nAt this point she began to feel uncomfortable\n\n1-And decided not to go through the hidden door\n2-But decided to go through the hidden door regardless\n\n>> ", 
                                "", 
                                1,2, 
                                true
                            );
                            next_path = 6; 
                            break; 
                        case 2: 
                            system("cls");
                            type("Emily decided not to try the key on the chest and went back home, never knowing what\nsecrets might have been hidden inside");
                            pause();
                            type("\n\n....................The end......................\n\n");
                            break;
                    }
                    break;
                case 5: 
                    system("cls");
                    type("That night Emily started reading the spell book and found a spell that promised to grant any wish. The spell required a rare and hard-to-find herb");
                    type("\nDetermined to get her wish Emily set out to find the herb");        
                    choice = check_input(
                        "\n\nAs Emily was walking through the woods she saw a rabbit with a golden fur. The rabbit ran into a bush\n\n1-And she chased it to investigate\n2-But she was focused on getting the herb and did not care about it\n\n>> ", 
                        "", 
                        1,2, 
                        true
                    ); 
                    next_path = 8;
                    break;
                case 12: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 6");
                            type("Emily took a deep breath and decided to investigate the voice. She followed the sound deeper into the forest");
                            type("\nShe heard the voice again, this time louder and more insistent.");
                            choice = check_input(
                                "\nShe pushed aside some branches and sees a figure standing in the clearing. She\n\n1-Approaches the figure\n2-Stay hidden where she is\n\n>> ",
                                "", 
                                1,2,
                                true
                                );
                                next_path = 13;
                            break; 
                        case 2:
                            system("cls");
                            system("color 6");
                            choice = check_input(
                                "Emily just continued walking and saw a glowing tree\nShe\n\n1-Was curious and wanted to touch it\n2-Decided not to risk touching it\n\n>> ",
                                "", 
                                1,2,
                                true 
                                );
                            next_path = 16;
                            break;
                    }
                    break; 
            }
            break; 
        case 4: 
           // paths = [6, 8, 13, 16]
            switch(path){
                case 6: 
                    switch(choice){
                        case 1:
                            system("cls");
                            system("color 2");
                            type("Emily decided not to go through the hidden door and went back home, wondering what might have been hidden inside");
                            pause(); 
                            type("\n\n.....................The end....................\n\n2");
                            break; 
                        case 2: 
                            system("cls");
                            type("Emily cautiously opened the door and found a staircase leading down into a dark, musty basement. She could hear the music getting louder");
                            type(", and \nher curiosity got the better of her as she descended the stairs");
                            type("\n\nAt the bottom of the stairs, she found a room filled with old musical instruments. In the center of");
                            type("the room, \nshe saw a strange-looking instrument that she had never seen before. She wondered if she should try to play it or not.");
                            choice = check_input(
                                "\nAt this point she began to feel really uneasy\n\n1-But decided to play the instrument regardless\n2-And decided to go back home\n\n>> ",
                                "",  
                                1,2,
                                true
                            );
                            next_path = 7;
                            break;
                    }
                    break;
                case 8: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 6");
                            type("Emily chased the rabbit and when she entered the bush, the rabbit was just standing there and it said, \"hello\"");
                            type("\nEmily was startled. Apparently the rabbit could talk. The rabbit offered to help her find the herb");
                            type("\n\nShe was thrilled and followed the rabbit deep into the forest. Soon, they came across a beautiful lake. The rabbit informed");
                            type("\nEmilly that the herb she was looking for grew on the other side of the lake. The only way to cross the lake was to use a small boat that was\nanchored to the shore. ");
                            choice = check_input(
                                "There seemed to be some creatures in the lake that resembled crocodiles. Emily\n\n1-Took the boat regardless of the danger\n2-Decided to find another way to find the herb\n\n>> ", 
                                "", 
                                1,2, 
                                true 
                                );
                            next_path = 9;
                            break;
                        case 2: 
                            system("cls");
                            system("color 2");
                            type("Emily searched for a very long time but never found the herb.\nShe decided the book was just a meaningless piece of literature and went back home");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break; 
                    }
                    break;
                case 13:
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 6");
                            type("Emily cautiously approaches the figure trying to discern what it is. As she gets closer, she realized that it's a ghostly apparition");
                            type("\nIt looked at her with hollow eyes, and she felt a chill run down her spine");
                            choice = check_input(
                                "\n\"come closer\",said the ghost.Emily\n\n1-Followed the ghost\n2-Runs away\n\n>> ",
                                "", 
                                1,2,
                                true
                                );
                                next_path = 14;
                            break; 
                        case 2:
                            system("cls");
                            system("color 6");
                            type("Emily decided to stay hidden, not wanting to reveal her presence. She waited for a few minutes, but the voice\n");
                            type("doesn't come back. She felt foolish and decided to keep walking.\nShe decided to just go back home since she did not feel like exploring anymore");
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break;
                case 16: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 6");
                            type("Emily went forward and touched the tree. Immediately she was sucked into a portal.");
                            type("She appeared in this strange world and there was a strange creature in front of her that told her");
                            type("\nthat she could only get back to her world by passing a series of tests\n");
                            type("But for now she was stuck in an unknown world in another part of the universe");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break; 
                        case 2:
                            system("cls");
                            system("color 2");
                            type("Emily decided to stay back, not wanting to risk whatever might happen if she touched the tree\n");
                            type("She turned around and walked away. She went back home and continued to live her normal life ");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break;
            }
                break; 

        case 5:
            // paths = [7, 9, 14]
            switch(path){
                case 7:  
                    switch(choice){
                        case 1: 
                            system("cls");
                            type("Emily picked up the instrument and began to play. At first, the music was beautiful, but then it began to");
                            type("\nchange. The melody became more and more discordant, and Emily started to feel a strange sensation in her head");
                            type("\n\nSuddenly, the room began to spin, and everything went black. When she woke up, she was back outside the mansion, lying in the grass\n");
                            type("She felt disoriented and confused, wondereing if everything she had experienced was just a dream. ");
                            choice = check_input(
                                "Did she even go inside in the first place ? Emily\n\n1-Decided it was just a dream\n2-Wanted to verify whether she went in or not\n\n>> ",
                                "", 
                                1,2, 
                                true 
                                );
                            next_path = 11;
                            break;
                        case 2: 
                            system("cls");
                            system("color 6");
                            type("Emily decided to go back home but when she turned to leave she began to feel light-headed");
                            type("\nWhen she woke up, she found that she had been transported to another dimension and she did not know how to get back home");
                            pause();
                            type("....................The end....................");
                            break;
                    } 
                    break;
                case 9: 
                    switch(choice){
                        case 1: 
                            system("cls");
                            type("Emily took the boat and was crossing the lake. However, halfway through the journey, out of nowhere, she \nencountered a storm, and the boat capsized. ");
                            type("Now Emily couldn't swim and was struggling to keep herself afloat let alone swim back to shore.\nThe mysterious creatures were surrounding her now");
                            type("\n\nAll of a sudden she felt herself becoming lighter and approaching the shore. She had been rescued by the rabbit.");
                            choice = check_input(
                                "Emily\n\n1-Was resilient and still wanted the herbs\n2-Decided the search was not worth it\n\n>> "  ,
                                "", 
                                1,2, 
                                true
                                );
                            next_path = 10;
                            break; 
                        case 2: 
                            system("cls");
                            system("color 2");
                            type("Emily decided to find another way to get to the herb. She wandered around the lake and found a bridge that spanned the entire lake");
                            type("\nShe crossed the bridge and found the herb she was looking for.  She returned to the abandoned cottage with the help of the rabbit and case the spell.\nTo her amazement her wish was granted. ");
                            type("Emily kept the spell book safe and secret.");
                            pause(); 
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break; 
                case 14:
                    switch(choice){
                        case 1:
                            system("cls");
                            system("color 3");
                            type("Emily decided to follow the ghost, curious about what it wanted from here. It led her to an old abandoned");
                            type("\ncabin deep in the woods. As she entered the cabin, she heard the door slam shut behind her");
                            choice = check_input(
                                "\nShe turned around, but the ghost is gone.....She is trapped. She\n\n1-Looked for a way out\n2-Stay put\n\n>> ",
                                "", 
                                1,2, 
                                true
                                );
                            next_path = 15;
                            break; 
                        case 2: 
                            system("cls");
                            system("color 3");
                            type("Emily turned and run as fast she could, not daring to look back. The ghost's laughter echoed");
                            type("\nthrough the woods, but she kept running until she is out of the forest.\nShe had narrowly escaped a supernatural enocunter, and vowed never to return to that place again");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break;
            }
            break; 
        case 6: 
            // paths = [10, 11, 15]
            switch(path){
                case 10: 
                    switch(choice){
                        case 1: 
                            system("color 4");
                            system("cls");
                            type("Emily walked deeper into the woods and along the way realized the rabbit was not with her anymore");
                            type("\nShe did not know the way back to the cottage and she was lost in the woods.");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break;
                        case 2:
                            system("cls");
                            system("color 6");
                            type("Emily realized that her desire for a wish was not worth the risk she took and returned\nthe spell book to the abandoned cottage ");
                            type("vowing never to use it again");
                            pause(); 
                            type("\n\n....................The end....................\n\n");
                            break;
                    }
                    break;
                case 11:
                    switch(choice){
                        case 1:
                            system("cls"); 
                            system("color 2");
                            type("Emily went back home conviced that it had all been a dream. However, she couldn't shake the feeling that there was\n");
                            type("something she had missed, and she often found herself daydreaming about the mysterious mansion.");
                            type("\n\nOne day she decided to go back to mansion to explore and it was nowhere to be found.\nIt had simply disappeared from existence");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break; 
                        case 2:
                            system("cls");
                            type("Emily refused to believe that she had been dreaming and she decided to investigate the mansion further and found\n");
                            type("a room filled with valuable treasures.\n\nShe used the money she earned from selling them to travel the world and have many adventures. ");
                            type("Sometimes she wondered what would have happened if she just assumed she was just dreaming that day.");
                            pause();
                            type("\n\n....................The end....................\n\n");
                            break;
                    } 
                    break;
                case 15:
                    switch(choice){
                        case 1: 
                            system("cls");
                            system("color 3");
                            type("Emily frantically searched for a way out, but the windows are boarded up, and the door won't budge.");
                            type("\nSuddenly, she heared a faint whisper in her ear. It's the ghost and it is not happy that she followed it\n");
                            type("\n\nShe felt a cold hand wrap around her neck, and everything goes dark");
                            type("\nWhen Emily woke up she felt different, she was in her bed at home and for some reason her voice felt deeper than usual");
                            type("\nShe wondered if she had dreamt everything. When she looked in the mirror she screamed....\nShe was now a boy ");
                            type("And for some reason, everyone always remembered her to be a boy.");
                            pause();
                            type("\n\n.....................The end....................\n\n");
                            break;
                        case 2:
                            system("cls");
                            system("color 3");
                            type("Emily decided to stay put, hoping that someone will find her. But as the night weared on, she realized");
                            type("\nthat she is alone and trapped. She heared strange noises coming from the walls, and the air grew"); 
                            type("\ncolder by the minute. She realized that she may never leave the cabin alive. She grew tired and fell asleep");
                            type("\nEmily was never found again");
                            pause();
                            type("\n\n.....................The end....................\n\n");
                            break;
                    }
                    
                    break;
            }
            break; 
        case 7: 
            break; 
        case 8: 
            break;
        case 9: 
            break; 
        case 10:
            break;
    }
    checkpoint++;
    if(checkpoint <= end +  1){
        set("checkpoints.txt", checkpoints, checkpoint, option, count);
        set("paths.txt", paths, next_path, option, count);
        set("choices.txt", choices, choice, option, count);
    } 
    }while(checkpoint <= end);
    
    // int user = check_input(
    //     "\n\nDo you want to see another scenario of the story?\n\n1-Yes\n2-No\n\n>> ", 
    //     "\nInvalid input\n", 
    //     1,2, 
    //     false
    //     );

    int user = check_input(
        "\n\nDo you want to see another scenario of the story?\n\n1-Yes\n2-No\n\n>> ",
        "\nInvalid input\n", 
        1,2,
        false
    );
    
    switch(user){
        case 1: 
            set("checkpoints.txt", checkpoints, 0, option, count);
            goto restart;
            break;
        
    }

}

