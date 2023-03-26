#define BUFFER_SIZE 100 
#define PROFILE_LIMIT 5


// type definitions
typedef char string[BUFFER_SIZE]; 
typedef char strings[PROFILE_LIMIT][BUFFER_SIZE];

// function prototypes
int get(char file_path[], strings array, int option, int count);
void set(char file_path[], strings array, int data, int option, int count);
int check_input(char message[], char error_message[], int start, int end, bool typit); 
void append_to_file(char file_path[], char data[]);
void read_display_and_store(char file_path[], strings array);
int get_count(char file_path[]); 
void story(strings checkpoints, strings paths, strings choices, int option, int count);
void typit(char characters[]);
void pause();