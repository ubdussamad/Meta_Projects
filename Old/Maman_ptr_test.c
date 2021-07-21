#include <stdio.h>
int main(){
	char item;
	int num, sumPizza=0, sumBurger=0, counterBurger=0, counterPizza=0, total;
	printf("Use the following item codes:\n\nBurger:\t B \n\nPizza:\t P \n\nWHEN DONE PRESS:D\n");
	
	do{
	printf("\nenter item code:");
	scanf(" %c" , &item );
	
	switch(item){
	case 'B':
	printf("\nenter the num of burgers u would like:");
	scanf("%d", & num);
	printf("\nU asked for %d burgers \n", num);
	sumBurger+=(num*200);
	counterBurger+= num;
	printf("\nWhich will cost u %d bucks \n", sumBurger);
	break;
	case 'P':
	printf("\nenter the num of pizzas u would like:");
	scanf("%d", & num);
	printf("\nU asked for %d pizza \n", num);
	sumPizza+=(num*300);
	counterPizza+=num;
	printf("\nWhich will cost u %d bucks \n", sumPizza);
	break;
	}
	}while(item!='D');
	printf("your bill is: %d \n", (sumBurger+sumPizza));
	return 0;
}
