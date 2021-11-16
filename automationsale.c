#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "automationsale.h"
#define STOREX 8
#define STOREY 15



void enterance(){
	puts("Welcome to Walmart");
}


Purchased* Invoice(Purchased *ptr,int invoice , int cstID, int proID, double price){
	
	while(ptr->nextPurchasedPtr!=NULL){// son dugume gelmemizi saglayacak
		ptr=ptr->nextPurchasedPtr;
	}
	
	
	Purchased *tempFatura=(Purchased*)malloc(sizeof(Purchased));
	tempFatura->nextPurchasedPtr=ptr->nextPurchasedPtr;
	ptr->nextPurchasedPtr=tempFatura;
	tempFatura->invoice_ID=invoice;
	tempFatura->customer_ID=cstID;	
	tempFatura->product_ID=proID;
	tempFatura->cost=price;

	return tempFatura;

	
}


double ShippingCalculate (double x, double y, int piece){
	
	return sqrt(pow(STOREX-x,2)+pow(STOREY-y,2))*piece;
	
}


void InvoiceCounter(int *p){
	(*p)++;
}


void PrintCustomer(Customer *ptr){
	while(ptr!=NULL){
		printf("\nName = %s  ID = %d  Type = %d Location x=%.2lf y=%.2lf\n",ptr->name,ptr->ID,ptr->type,ptr->x_coord,ptr->y_coord);
		ptr=ptr->nextCusPtr;
	}
}


void PrintProduct(Product *ptr){
	while(ptr!=NULL){
		printf("\n%s  Product ID = %d  Type = %d  Price = %0.2lf £ \n",ptr->name,ptr->ID,ptr->type,ptr->price);
		ptr=ptr->nextProPtr;
	}
}


void CustomerType(Customer *ptr, int custype){
	 while(ptr != NULL) {
	 	
        if(ptr->type==custype) {
        	
        	printf("The customer is... \n");
        	if(custype==0){
        		printf("Single Customer\n");
			}
			else if(custype==1){ 
			printf("Compony\n");
			}
        }
        ptr=ptr->nextCusPtr;
    }
}


void Qprotype(Product *ptr, int number){
	 while(ptr != NULL) {
	 	
        if(ptr->type==number) {
        	
        	printf("\n%s named product is..\n",ptr->name);
        	if(number==1){
        		printf("Highlighter Pen\n");
			}
			else if(number==2){
				printf("Crayons\n");
			}
			else if(number==3){
				printf("Pen");
			}
   
        }
        ptr=ptr->nextProPtr;
    }
}


Product* FindProduct(Product *ptr, int number){
	
 	while(ptr!=NULL){
 		if(ptr->ID==number){
 		
 			return ptr;

		 }
 		else{
 			ptr=ptr->nextProPtr;
 			
		 }
	 }
	 

}


Customer* FindCustomer(Customer *ptr, int number){
	 while(ptr != NULL) {
	 	
        if(ptr->ID==number) {
        	return ptr;
   
        }
        else{
            ptr=ptr->nextCusPtr;
        }
    }
}


double ProductTotalPurch(Purchased *ptr){
	double total=0;
	
	while(ptr!=NULL){
		total=total+(ptr->cost);
		ptr=ptr->nextPurchasedPtr;
	}
	return total;
	
}


double ProductTypePurch(Purchased *ptr, int protype){
	
	double total=0;
	
	while(ptr!=NULL){
		if(ptr->product_ID==protype){
			total=total+(ptr->cost);
		}
		
		
		ptr=ptr->nextPurchasedPtr;
	}
	return total;
}

double ProductAmount(Purchased *ptr, int proID){
	int total=0;
		
	while(ptr!=NULL){
		if(ptr->product_ID==proID){
			total=total+(ptr->pieces);
		}
		
		ptr=ptr->nextPurchasedPtr;
	}
	return total;
	
}


double ProductIDPurch(Purchased *ptr, int proID){
	double total=0;
	
	while(ptr!=NULL){
		if(ptr->product_ID==proID)
		total=total+(ptr->cost);
		ptr=ptr->nextPurchasedPtr;
	}
	return total;
}


void ByAllCustomers(Purchased *ptr){
	double total=0;
	
	while(ptr!=NULL){
		total=total+(ptr->cost);
		ptr=ptr->nextPurchasedPtr;
	}
	printf(" All customer's total purchased: %0.2lf",total);
	
}

void By1Customer(Purchased *ptr, int cstID){
	double total=0;
	
	while(ptr!=NULL){
		if(ptr->customer_ID==cstID);
		total=total+(ptr->cost);
		ptr=ptr->nextPurchasedPtr;
	}
   printf(" %d ID customer's total purchased: %0.2lf",cstID,total);
}

double Amount1Customer(Purchased *ptr, int cstID){
	double amount;
	
	while(ptr!=NULL){
		if(ptr->customer_ID==cstID){
			amount=amount+ptr->pieces;
			ptr=ptr->nextPurchasedPtr;
		}
	}
}


