#ifndef automationsale_h_
#define automationsale_h_


struct customer {
int ID;
char name[50];
unsigned int type: 1;
double x_coord;
double y_coord;
struct customer *nextCusPtr;
};
typedef struct customer Customer;


struct product {
int ID;
char name[50];
int type;
double price;
int amount;
struct product *nextProPtr;

};
typedef struct product Product;


struct purchased {
int ID;
int invoice_ID;
int customer_ID;
int product_ID;
int totalamount;
unsigned int product_type;
int pieces;
double cost;
struct purchased *nextPurchasedPtr;
};

typedef struct purchased Purchased;

struct shipping{
	int shippingfee;
	struct shipping *nextPtr;
};
typedef struct shipping Shipping;


void enterance();
Customer* FindCustomer(Customer *ptr, int number);
Product* FindProduct(Product *ptr, int number);
Purchased* Invoice(Purchased *ptr,int invoice , int cstID, int proID, double price);
double ShippingCalculate (double x, double y, int adet);
void InvoiceCounter(int *p);
void PrintCustomer(Customer *ptr);
void PrintProduct(Product *ptr);
void Qprotype(Product *ptr, int number);
void CustomerType(Customer *ptr, int custype);

double ProductTotalPurch(Purchased *ptr);
double ProductAmount(Purchased *ptr, int proID);
double ProductTypePurch(Purchased *ptr, int protype);
double ProductIDPurch(Purchased *ptr, int proID);
void ByAllCustomers(Purchased *ptr);
void By1Customer(Purchased *ptr, int cstID);
double Amount1Customer(Purchased *ptr, int cstID);





#endif
