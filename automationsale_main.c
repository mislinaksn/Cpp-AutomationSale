#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "automationsale.h"
#define HOMEX 8
#define HOMEY 15



int main(){
	
	Customer *root;
	Customer *tempc;
	Customer *iter;
	
	root=(Customer*)malloc(sizeof(Customer));
	if(root==NULL){
 	printf("memory could not allocated!!");
 	return 0;
 	}
 	
   	iter=root;
 	strcpy(iter->name,"Selami Sahin");
 	iter->ID=1;
 	iter->type=0;
	iter->x_coord=6.5;
	iter->y_coord=10;
	iter->nextCusPtr=NULL;
	
	tempc=(Customer *)malloc(sizeof(Customer));
	 if(tempc==NULL){
 	printf("memory could not allocated!!");
 	return 0;
 	}
 	
 	iter->nextCusPtr=tempc;
	iter=tempc;
 	strcpy(iter->name,"Gizem Gundogdu");
 	iter->ID=2;
 	iter->type=1;
 	iter->x_coord=7;
 	iter->y_coord=8;
 	iter->nextCusPtr=NULL;
 	




 	
 	Product *p_root;
 	Product *p_iter;
 	Product *p_temp;
 	
    p_root=(Product *)malloc(sizeof(Product));
 	
 	p_iter=p_root; //birinci ?r?n
 	if(p_root==NULL){
 	printf("memory could not allocated!!");
 	return 0;
	}
	strcpy(p_iter->name,"Stabilo Highlighter"); //1
 	p_iter->ID=1;
 	p_iter->price=8.49;
 	p_iter->type=1;
 	p_iter->nextProPtr=NULL;
 	 	
	p_temp=(Product *)malloc(sizeof(Product));
 	if(p_temp==NULL) {
 	printf("memory could not allocated!!");
 	return 0;
	 }
	p_iter->nextProPtr=p_temp;
 	p_iter=p_temp;
 	strcpy(p_iter->name,"Ufen Highlighter"); //2
 	p_iter->ID=2;
 	p_iter->price=4.5;
 	p_iter->type=1;
 	p_iter->nextProPtr=NULL;
   
   
    p_temp=(Product *)malloc(sizeof(Product));
 	if(p_temp==NULL) {
 	printf("memory could not allocated!!");
 	return 0;
	 }
 	p_iter->nextProPtr=p_temp;
 	p_iter=p_temp;
 	strcpy(p_iter->name,"Faber Castle Crayons"); //3
 	p_iter->ID=3;
 	p_iter->price=29.99;
 	p_iter->type=2;
 	p_iter->nextProPtr=NULL;

 	
	p_temp=(Product *)malloc(sizeof(Product));
 	if(p_temp==NULL) {
 	printf("memory could not allocated!!");
 	return 0;
	 }
 	p_iter->nextProPtr=p_temp;
 	p_iter=p_temp;
 	strcpy(p_iter->name,"Caretta Pen"); //4
 	p_iter->ID=4;
 	p_iter->price=12.5;
 	p_iter->type=3;
 	p_iter->nextProPtr=NULL;
	 
	 
	p_temp=(Product *)malloc(sizeof(Product));
 	if(p_temp==NULL) {
 	printf("memory could not allocated!!");
 	return 0;
	 }
	p_iter->nextProPtr=p_temp;
 	p_iter=p_temp;
 	strcpy(p_iter->name,"Faber Castle Pen"); //5
 	p_iter->ID=5;
 	p_iter->price=3.5;
 	p_iter->type=3;
 	p_iter->nextProPtr=NULL;	
	 
	
	
	
	
	
	

	Purchased *purchRoot;
	Purchased *purchIter;
	Purchased *purchTemp;
	
	purchTemp=(Purchased*)malloc(sizeof(Purchased));
 	purchRoot=(Purchased*)malloc(sizeof(Purchased));
 	if(purchRoot==NULL){
 	printf("memory could not allocated!!");
 	return 0;
 	}
 	
 	purchIter=purchRoot;
 	purchIter->ID=1;
	purchIter->invoice_ID=0;
	purchIter->customer_ID=0;
	purchIter->product_ID=0;
	purchIter->cost=0.0; 
	purchIter->totalamount=0;		
 	purchIter->nextPurchasedPtr=NULL; 

 	
 
 
 
 
 
 	
 	Shipping *shipRoot;
 	Shipping *shipIter;
 	Shipping *shipTemp;
 	
 	shipTemp=(Shipping *)malloc(sizeof(Shipping));
 	shipRoot=(Shipping*)malloc(sizeof(Shipping));
	
	shipIter=shipRoot;
	shipIter->shippingfee=0;
	
	 
	enterance(); 
	
	int musteriID;
	int urunID;	
	int select, sales, sales1, sales2,i;
    int customer,product, customer_a, product_a;

    int cstID;
	int proID;
	double total;
	int amounts;
	double ShippingFee;	
	int feenumbers=1, *p;
	p=&feenumbers;
	int tempID,temptoplam=0,temp1;
		
mainmenu:
printf("            -Main Menu- \n  What would you like to do? \n  1-Sales\n  2-Customer Information\n  3-Product Information\n  4-Customer Analysis\n  5-Product Analysis\n  6-Exit Program\n");
scanf("%d",&select);

switch (select) {
 
     case 1 : 
        salesmenu:
        
			
        printf("  --- 1- Sales Menu---\n\n");
        printf("What would you like to do?\n 1-Preprocessing \n 2-Product sales \n 3-Invoice finalization\n Press 4 to go back to main menu\n");
        scanf("%d",&sales);
        
        switch (sales) {
        	
           case 1:
           	  preprocessing:
           	  printf("1.1- Preprocessing Menu\n\n");
              printf("Enter 1 for Invoice number, 2 for Customer number\n Press 3 to go back to sales menu\n");
              scanf("%d",&sales1 );
              
              switch(sales1) {
              	
              	case 1: printf("1.1.1- Invoice number\n");  
              	    purchIter=purchRoot;
		            printf("Latest invoice no = %d\n",purchIter->invoice_ID);
			        printf("Press 1 for Preprocessing Menu, 0 for Sales Menu\n");
        	        scanf("%d",&i);
        	        if(i==1){ goto preprocessing;	}
        	        else if(i==0){ goto salesmenu;	}
        	        else{ printf("invalid operation\n"); break;	}              	
				  
				                
              	case 2: printf("1.1.2-Customer number \n");
		            printf("Customers: 1.Selami Sahin\n2.Gizem Gundogdu\n");
            		printf("Enter the customer id: \n");
	            	scanf("%d",&cstID);
            		iter=root;
	              	iter=FindCustomer(iter,cstID);
		            printf("The customer you have asked for= %s \n",iter->name);              	     
			        printf("Press 1 for Preprocessing Menu, 0 for Sales Menu\n");
        	        scanf("%d",&i);
        	        if(i==1){ goto preprocessing;	}
        	        else if(i==0){ goto salesmenu;	}
        	        else{ printf("invalid operation\n"); break;	}              	
              	
              	case 3: goto salesmenu;
			  }
			  
           productsales:  
           case 2: 
           
              printf("1.2Product Sales\n\n");
		      printf("Enter 1 for Find product number, 2 for Enter amount\n Press 3 to go back to sales menu menu\n");
              scanf("%d",&sales2);
              
              switch(sales2) {
              	
              	case 1: printf("1.2.1- Find product number \n");
		            printf("Products which are on sale:\n 1-Stabilo Highlighter\n 2-Ufen Highlighter\n 3-FaberCastel Crayons\n 4-Caretta Pen \n 5-Faber Castel Pen\n");
		            printf("Enter the id of product which is searching: \n");
		            scanf("%d",&proID);
             		p_iter=p_root;
                 	p_iter=FindProduct(p_iter,proID);
	              	printf("The products name is: %s\n",p_iter->name);
			        printf("Press 1 for Product Sales Menu, 0 for Sales Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productsales;	}
        	        else if(i==0){ goto salesmenu;	}
        	        else{ printf("invalid operation\n"); break;	}				  
				                	
              	case 2:
              		printf("Enter amount of the product");
		            scanf("%d",&amounts);
		            purchIter->totalamount=amounts;
		            
			        printf("Press 1 for Product Sales Menu, 0 for Sales Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productsales;	}
        	        else if(i==0){ goto salesmenu;	}
        	        else{ printf("invalid operation\n"); break;	}              	
              	
              	case 3: goto salesmenu;
			  }
           case 3:
                    printf("1.3- Invoice finalization\n\n"); //kargoTutari=kargoUcreti(iter->x_coord,iter->y_coord,purchIter->totalamount);
                    
                    
				   
				    ShippingFee=ShippingCalculate(iter->x_coord,iter->y_coord,purchIter->totalamount);
		            printf("\nShipping Fee: %.0lf ?\n",ShippingFee);
		            shipIter->shippingfee=shipIter->shippingfee+ShippingFee;
		            
		
		            total=((p_iter->price)*purchIter->totalamount)+ShippingFee;
		            InvoiceCounter(p);
		
		            purchIter=Invoice(purchIter,feenumbers,iter->ID,p_iter->ID,total);
		
		            printf("\nTotal Fee: %.0lf ?\n",total);
			        printf("Press 1 for exit this Menu, 0 for Sales Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto mainmenu;	}
        	        else if(i==0){ goto salesmenu;	}
        	        else{ printf("invalid operation\n"); break;	}
		     
		    case 4: goto mainmenu; 
        }
        
        
     case 2:
	 customerinfo:   
	    printf("  --- 2- Customer Information Menu---\n\n");
        printf("What would you like to do?\n 1-All Customers \n 2-According to the ustomer type \n 3-Single Customer\n Press 4 to go back to main menu\n");
        scanf("%d",&customer); 
        switch(customer){
        	
        	case 1: printf("2.1- All customers \n");
        			iter=root;
			        PrintCustomer(iter);
			        printf("Press 1 for Customer Info, 0 for Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto customerinfo;	}
        	        else if(i==0){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}  
		       		
        	case 2: printf("2.2-  According to the Customer type\n");
        			iter=root;
			        int customer_type;
			        printf("Enter the type of the customer 1,0: ");
			        scanf("%d",&customer_type);
			        iter=root;
					CustomerType(iter,customer_type);
			        printf("Press 1 for Customer Info, 0 for Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto customerinfo;	}
        	        else if(i==0){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}         	

			case 3:	printf("2.3- Single Customer\n");
			        
			        printf("Enter the customers ID: \n");
			        scanf("%d",&cstID);
			        iter=root;
			        FindCustomer(iter,cstID);
			        printf("Name = %s  ID = %d  Type = %d Location x=%.2lf y=%.2lf",iter->name,iter->ID,iter->type,iter->x_coord,iter->y_coord);
			        
			        printf("Press 1 for Customer Info, 0 for Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto customerinfo;	}
        	        else if(i==0){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	} 
					 
		    case 4: goto mainmenu;		    	
						
		}
		
		
	 	
     case 3:
     productinfo:	
	    printf("  --- 3- Product Information Menu---\n\n");
        printf("What would you like to do?\n 1-All products \n 2-According to the product type \n 3-Single product\n Press 4 to go back to main menu\n");
        scanf("%d",&product);  
		switch(product){
        	
        	case 1: printf("3.1- All products\n");
        			p_iter=p_root;
			        PrintProduct(p_iter);
          	        printf("Press 1-Product Info, 2-Main Menu\n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productinfo;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}	
        	        
        	case 2: printf("3.2- According to the product type\n");
        	p_iter=p_root;
			int p_type;
			printf("Enter the product type(1,2,3): ");
			scanf("%d",&p_type);
			Qprotype(p_iter,p_type);
        	        printf("Press 1-Product Info, 2-Main Menu\n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productinfo;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}

			case 3:	printf("3.3- Single product\n");
			printf("\nEnter product id: \n");
			scanf("%d",&proID);
			p_iter=p_root;
			p_iter=FindProduct(p_iter,proID);
			printf("\n%s ID = %d price = %.0lf type = %d\n",p_iter->name,p_iter->ID,p_iter->price,p_iter->type);
			        printf("Press 1 for Product Info, 0 for Main Menu\n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productinfo;	}
        	        else if(i==0){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}

			
		    case 4: goto mainmenu; 				
		}
		
		 
	 	  	
     case 4 :
     custormeranalys:
    tempID=0,temptoplam=0,temp1=0;
	 int temp;
        printf("  --- 4- Customer Analysis Menu---\n\n");
        printf("What would you like to do?\n 1-Products purchased by a customer \n 2-Total amount of purchased by a customer \n 3-Total amount of products purchased by all customer\n 4-Customers shipping fee \n Press 5 to go back to main menu\n ");
        scanf("%d",&customer_a);
        switch (customer_a) {
           case 1:
           	  printf("4.1- Products purchased by a customer\n\n");
           	        purchIter=purchRoot;
        	        p_iter=p_root;
        	        iter=root;
        	        printf("Enter customer ID: \n");
        	        scanf("%d",&tempID);
        	        By1Customer(purchIter,tempID);
        	                   	  
        	        printf("Press 1-Customer Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto custormeranalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}          	  
              
           case 2: 
              printf("4.2- Total amount of purchased by a customer\n\n");       	        
			int temp; 	        
        	        purchIter=purchRoot;
        	        p_iter=p_root;
        	        iter=root;
        	        printf("Enter customer ID: \n");
        	        scanf("%d",&tempID);
        	        printf("ID:%d  total amount of purchased by this customer:%d ",tempID, Amount1Customer(purchIter,tempID));
        	        
					printf("Press 1-Customer Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto custormeranalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}
              
           case 3:
              printf("4.3- Total amount of products purchased by all customer\n\n");
                    purchIter=purchRoot;
 
        	        iter=root;
        	        ByAllCustomers(purchIter);
        	        
        	        
          	        printf("Press 1-Customer Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto custormeranalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}
              
		    case 4:
			  printf("4.4- Customers shipping fee\n\n");
			  
        	        shipIter=shipRoot;
					iter=root;
        	        printf("%0.2lf ", shipIter->shippingfee);
        	        
        	        
					
					printf("Press 1-Customer Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto custormeranalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("invalid operation\n"); break;	}
			  
			case 5: goto mainmenu; 			  
        }
                
    case 5:
	tempID=0,temptoplam=0,temp1=0;
    productanalys:	
	    printf("  --- 5- Product Analysis Menu---\n\n");
        printf("What would you like to do?\n 1 Total purchase quantity of a product \n 2 Total purchase amount of a product type \n  3 Total purchase amount for all products\n Press for to go back to main menu\n");
        scanf("%d",&product_a);  
		switch(product_a){
        	
        	case 1: printf("5.1- Total purchase quantity of a product\n");
        	
         	        purchIter=purchRoot;
        	        p_iter=p_root;
        	        iter=root;       					
					printf("Please enter the product's ID: \n");   	        
        	        scanf("%d",&tempID);
        	        temptoplam=ProductIDPurch(purchIter,tempID);
        	        purchIter=purchRoot;
        	        temp1=ProductAmount(purchIter,tempID);
        	        printf("ID number:%d   total selling:%d pieces   total price:%0.2lf ? \n",tempID,temp1,temptoplam);
        	        

        	
        	        printf("Press 1-Product Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productanalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("?nvalid operation\n"); break;	}
        		
        	case 2: printf("5.2- Total purchase amount of a product type\n");
                	int tempype;
                	temptoplam=0;
					purchIter=purchRoot;
        	        p_iter=p_root;
        	        iter=root; 
        	        printf("Please Enter the product's type: \n");
        	        scanf("%d",&tempype);
        	        temptoplam=ProductTypePurch(purchIter,tempype);
        	        purchIter=purchRoot;
        	        temp1=ProductAmount(purchIter,tempID);
        	        printf("Product Type:%d   total selling:%d pieces   total price:%0.2lf ? \n",tempype,temp1,temptoplam);      
 
        	
        	        printf("Press 1-Product Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productanalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("?nvalid operation\n"); break;	}
			
			case 3:	printf("5.3- Total purchase amount for all products\n");
			        temptoplam=0;
					purchIter=purchRoot;
        	        p_iter=p_root;
        	        iter=root; 
        	        temptoplam=ProductTotalPurch(purchIter);
        	        printf("Total price for all products:%0.2lf \n",temptoplam);
			   
        	        printf("Press 1-Product Analysis, 2-Main Menu \n");
        	        scanf("%d",&i);
        	        if(i==1){ goto productanalys;	}
        	        else if(i==2){ goto mainmenu;	}
        	        else{ printf("?nvalid operation\n"); break;	}
			
			case 4: goto mainmenu;
							
		} 
	case 6: break;
} 	
	return 0;
}




