#include <stdio.h>

// unfinished assignment but it is more than 80% working, or at least on my computer
void check_size(int size, char flavour_[]);
int get_time(int size);
float get_cost(int size, int a, int b);

int main(){
   int order=0, time=0;
   float cost = 0;
   
   printf("\nWELCOME TO FIIFI'S ICE CREAM SHOP\nWhat would you like to order?");
   do{
      int flavour=0, topping=0, size=0;
      printf("\n1-Vanilla\n2-Strawberry\n3-Chocolate\n4-Mango\n5-Enquiries\n\n>> ");
      scanf("%d", &flavour);
      if(flavour == 5){
         printf("\nA customer service will be with you soon");
      }
      else if(flavour >= 1 && flavour < 5){
         printf("\n1-small\n2-large\n\n>> ");
         scanf("%d", &size);
      }
      

      switch(flavour){
         case 1: 
            check_size(size, "Vanilla");
            time += get_time(size);
            cost += get_cost(size, 5, 8);
            break; 
         case 2:
            check_size(size, "Strawberry");
            time += get_time(size);
            cost += get_cost(size, 5, 8);
            break;
         case 3:
            check_size(size, "Chocolate");
            time += get_time(size); 
            cost += get_cost(size, 6, 9);
            break; 
         case 4:
            check_size(size, "Mango");
            time += get_time(size);
            cost += get_cost(size, 7, 10);
            break;
         case 5:
               break; 
         default:
            printf("\nInvalid flavour entry"); 
      }
   
      
      int toppings = 0; 

      do{
         if(flavour >= 1 && flavour < 5){
         printf("\n\nChoose a topping");
         printf("\n1-Sprinkles\n2-Whipped cream\n3-Chopped Nuts\n4-Coconut Shavings\n5-No toppings\n\n>> ");
         scanf("%d", &topping);
         switch(topping){
         case 1: 
            printf("\nSprinkles"); 
            cost += 2; 
            time += 2;
            toppings++; 
            break; 
         case 2:
            printf("\nWhipped cream");
            cost += 3; 
            time += 2; 
            toppings++; 
            break;
         case 3:
            printf("\nChopped Nuts");
            cost += 4; 
            time += 3; 
            toppings++; 
            break; 
         case 4:
            printf("\nCoconut Shavings");
            cost += 5;
            time += 4; 
            toppings++; 
            break;
         case 5: 
            toppings= 0;
            break; 
         default:
            printf("\nInvalid topping entry"); 
      }

         }
        
      }
      while(toppings > 0);

    printf("\nWould you like anything else?\n1-Yes\n2-No\n>> ");  
    int option;
    scanf("%d", &option);
    switch(option){
      case 1: 
         order++; 
         break;
      case 2:
         order=0; 
         printf("\ntotal cost = %.2f, total waiting time = %d\n", cost, time);
         break;
    }

   }
   while(order > 0);
   
   return 0;     
}



void check_size(int size, char flavour_[]){
   if(size == 1){
      printf("\nflavour = %s, size = small", flavour_);
   }
   else if(size == 2){
      printf("\nflavour = %s, size = large", flavour_);
   }
   else{
      printf("\nInvalid size entry");
   }

}

int get_time(int size){
   if(size == 1){
      return 2; 
   }
   else if(size == 2){
      return 3; 
   }
   else{
      return 0; 
   }
}
  

float get_cost(int size, int cost1, int cost2){
   if(size == 1){
      return cost1; 
   }
   else if(size == 2){
      return cost2;
   }
   else{
      return 0; 
   }
}
