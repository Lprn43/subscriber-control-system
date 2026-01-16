#include <stdio.h>
#include <stdlib.h>
typedef enum {
	HOUSE,
	OFFICE,
	INDUSTRIAL
}SubscriberType;
typedef struct {
	int id;
	char name[30];
	int usage;
	SubscriberType type;
}Subscriber;
void verileriAl(Subscriber *list, int n){
	for(int i = 0; i < n ; i++){
		printf("Type the name:");
		scanf("%s",list[i].name);
		printf("Usage(kWh):");
		scanf("%d",&list[i].usage);
		printf("Select type (0:House 1:Office 2:Industrial):");
		scanf("%u",&list[i].type);
		list[i].id = 101+i;
	}
}
void saveBill(Subscriber *list,int n){
	FILE* fptr = fopen("bill.txt", "w");
	if(fptr == NULL){
		printf("Cannot create the file");
		return;
	}
	for(int i = 0; i < n; i++){
		if(list[i].type == INDUSTRIAL){
			list[i].usage = 0.8*list[i].usage;
			fprintf(fptr,"ID: %d | Name: %s | Usage: %d(Discounted)\n",list[i].id,list[i].name,list[i].usage);
		}
		else{
			fprintf(fptr,"ID: %d | Name: %s | Usage: %d\n",list[i].id,list[i].name,list[i].usage);
		}
	}
	printf("Saved to bill.txt.");
	fclose(fptr);
}
int main(){
	int n;
	printf("How many subscribers will be added:");
	scanf("%d",&n);
	Subscriber* Subscriber = malloc(n*sizeof(Subscriber));
	if(Subscriber == NULL){
		printf("Allocation failed.");
		return 1;
	}
	verileriAl(Subscriber,n);
	saveBill(Subscriber,n);
	free(Subscriber);
	return 0;
}
