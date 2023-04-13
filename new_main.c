#include <stdio.h>
#include <string.h>

// structs and unions
typedef struct{
    char name[30]; 
    char phone_number[15];
    char id[10];
}Shop;

typedef struct{
    char name[30];
    char code[10]; 
    char year[5];
    Shop shop; 
    struct Price{
        char currency[5]; 
        float amount;
    }price_details;

    union Size{
        int digit; 
        char letter;
        char word[15];
    }size;
    int sizetype;

}Clothing;

// function declarations/ prototypes
void showShops();
void showDetails(int i);
void showClothes(int i);
void addClothing();

// global variables
Shop shops[5];
Clothing clothes[5]; 
int shopCount=0, clothesCount = 0;


int main(){
    Shop shop1 = {.name="Abi's Boutique", .phone_number="0597066666", .id="s10"}; 
    Shop shop2 = {.name="Laplace Boutique", .phone_number="0597056555", .id="s20"}; 
    Clothing clothe1 = {.name="Versace Blue Jeans", .code="s10c1001", .year="2023", .shop=shop1, .price_details.currency = "GHS", .price_details.amount = 100, .sizetype=2, .size.word = "Extra large"};
    Clothing clothe2 = {.name="Hoodie", .code="s10c2002", .year="2023", .shop=shop1, .price_details.currency = "USD", .price_details.amount = 150, .sizetype=2, .size.word= "Medium"};
    Clothing clothe3 = {.name="Crop top",.code="s20c1001", .year="2023", .shop=shop2, .price_details.currency = "GHS", .price_details.amount = 50, .sizetype = 2, .size.word = "Large"};
    Clothing clothe4 = {.name="Plain blue T", .code="s20c2002", .year="2023", .shop=shop2, .price_details.currency = "EURO", .price_details.amount = 150, .sizetype = 2, .size.word = "Small"};
    

    shops[0] = shop1; 
    shops[1] = shop2;
    clothes[0] = clothe1; 
    clothes[1] = clothe2;
    clothes[2] = clothe3;
    clothes[3] = clothe4;

    shopCount += 2;
    clothesCount += 4;
    // printf("clothe code = %s; currency = %s", clothe4.code, clothe4.price_details.currency);

    int looping=0;
    do{
    printf("\nCLOTHING MALL\n..............\n\n1 - Visit Shop\n2 - Add Clothing\n3 - Exit\n\n>> ");
    int option;
    scanf(" %d", &looping);
    switch(looping){
    case 1: 
        showShops();
        scanf(" %d", &option);
        showDetails(option-1);
        showClothes(option-1);
        break;
    case 2: 
        addClothing();
        break;
    case 3:
        looping = 0; 
        printf("Thanks for shopping :)");
        break;
    default:
        printf("Invalid choice\n"); break;
    }
    }
    while(looping>0);
    return 0;
}


// function definitions
void showShops(){
 for(int i=0; i < shopCount; i++){
    printf("\n%d - %s", i + 1, shops[i].name);
 }   
 printf("\n\n>> ");
}

void showDetails(int i){
    printf("\nShop detail\n...........\nName: %s\nContact: %s",shops[i].name, shops[i].phone_number);
}

void showClothes(int i){
    int number = 1;
    printf("\n\nAvailable clothes\n\n");
    for(int j=0; j < clothesCount; j++){
        if(strcmp(clothes[j].shop.id, shops[i].id) == 0){
            
            printf(
             "%d\nProduct name: %s\nYear: %s\nPrice: %.2f %s",
             number, 
             clothes[j].name, 
             clothes[j].year, 
             clothes[j].price_details.amount,
             clothes[j].price_details.currency 
             );
             if(clothes[j].sizetype == 0){
                printf("\nSize: %d", clothes[j].size.digit); 
              }
             else if(clothes[j].sizetype == 1){
                printf("\nSize: %c", clothes[j].size.letter);
             }
             else{
                printf("\nSize: %s", clothes[j].size.word);
             }
             printf("\n\n");



             number++;
        }
    }
}

void addClothing(){
  printf("\nHow many clothes do you want to add?\n>> ");
  int count, option;
  char name[30], year[5], code[15];
  scanf("%d", &count);
  fflush(stdin); 
  for(int i=0; i < count; i++){

    printf("\nClothing %d\nName: ", i + 1);
    fgets(name, 30, stdin);
    name[strlen(name) - 1] = '\0';

    printf("Year: ");
    fgets(year, 5, stdin);
    year[strlen(year) - 1] = '\0';
     
    fflush(stdin);
    printf("Code: ");
    fgets(code, 15, stdin);
    code[strlen(code) - 1] = '\0';

    printf("\n");
        for(int i=0; i < shopCount; i++){
        printf("\n%d - %s", i + 1, shops[i].name);
        }   
        printf("Add to shop\n>> ");
        scanf("%d", &option);
        printf("\n ' %s ' added to ' %s ' successfully", name, shops[option - 1].name);
  }

 
}
