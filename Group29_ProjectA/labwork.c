#include <stdio.h>


int main(){

   int order =0;
   int time =0;
   float cost =0;
   printf("Welcome to Fiifi's shop\n What would you like to order");
do{int flavour = 0;
int topping =0;
 int size =0;
 printf("\n1-Vanilla \n2=strawberry \n3chocolate \n4Mango");
scanf("flavour = %d",&flavour);
printf("1-small\n2-large");
scanf("size = %d",&size);
switch (flavour){
    case 1:
    if (size == 1){
        printf("You choose small sized vanilla");
        cost +=5;
        time +=2;
        
    }else if (size == 2){
        printf("You choose large sized vanilla");
        cost +=8;
        time +=3;
    }else{
        printf("“Invalid size entry\n”");
    }
    case 2:
    if (size == 1){
        printf("You choose small sized strawberry");
        cost +=5;
        time +=2;
        
    }else if (size == 2){
        printf("You choose large sized strawberry");
        cost +=8;
        time +=3;
    }else{
        printf("“Invalid size entry\n”");
    }
    case 3:
    if (size == 1){
        printf("You choose small sized chocolate");
        cost +=6;
        time +=2;
        
    }else if (size == 2){
        printf("You choose large sized chocolate");
        cost +=9;
        time +=3;
    }else{
        printf("“Invalid size entry\n”");
    }
    case 4:
    if (size == 1){
        printf("You choose small sized mango");
        cost +=7;
        time +=2;
        
    }else if (size == 2){
        printf("You choose large sized mango");
        cost +=10;
        time +=3;
    }else{
        printf("“Invalid size entry\n”");
    }

}
if (flavour == 5){
    printf("A customer agen will be with you soon\n");}
// }else{
//     printf("\nInvalid flavour entry\n");
}

while(order > 0);

int toppings =0;
do{
    printf("\n1 - sprinkles\n2 - whipped cream\n3 - chopped nuts\n4 –cocunut shavings\n");
    scanf("toppings = %d",&toppings);
    switch(toppings){
case 1:
 printf("You choose sprinkles toppings");
        cost +=2;
        time +=2;
        toppings ++;

case 2:
printf("You choose whipped cream toppings");
        cost +=3;
        time +=2;
        toppings ++;

case 3:
printf("You choose chopped nuts toppings");
        cost +=4;
        time +=2;
        toppings ++;

case 4:
printf("You choose cocunut shavings toppings");
        cost +=5;
        time +=2;
        toppings ++;

    }
   if(toppings = 5){
    toppings = 0;
   } else{
    printf("Invalid toppings");
   }
   int option;
   printf("Would you like anything else?\n1 - Yes\n2 - No\n");
   scanf("%d",option);
   if (option ==1){
    order ++;
   }
   else if (option == 2){
    order = 0;
    printf("Your cost is %d and your waiting time is %d",cost,time);
   }


}
while(toppings = 0);
printf("Kindly wait for your order");
for(int i =0;i>0;i-- ){
 time --;
 printf("%d",time);
}


    return 0;

}



