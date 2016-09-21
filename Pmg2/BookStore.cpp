#include "BookStore.h"


BookStore::BookStore(){
	numberBooks = 0;
}
BookStore::BookStore(const char* thing){
	ifstream inFile;
	inFile.open(thing);
	if(inFile.fail()){
		cout << "File Failed to open" << endl;
		exit(-1);
	}
	inFile.read((char*) &books, sizeof(books));
	inFile.close();
	while(books[numberBooks].getTitle()[0] != '\0')
		numberBooks ++;
	sortByISBN();
}
void BookStore::print(){
	cout << "\nBook Inventory Listing\n\n";
	cout <<  left << setw(14) << "ISBN" << setw(44) << "Title" << right << setw(5) << "Price" << setw(7) << "Qty." << endl;
	for(int i = 0; i < numberBooks; i ++){
		books[i].print();
		cout << endl;
	}
	cout << endl;
}
void BookStore::sortByISBN(){
	int i, j;
	Book bucket;

	for (i = 1; i < numberBooks; i++){
		bucket = books[i];
		for (j = i; (j > 0) && (strcmp(books[j-1].getISBN(), bucket.getISBN()) > 0); j--)
			books[j] = books[j-1];
		books[j] = bucket;
	}
}
int BookStore::searchForISBN(char number[]){
 int low = 0;
   int high = numberBooks - 1;
   int mid;

   while (low <= high){
	mid = (low + high) / 2;
	if (strcmp(books[mid].getISBN(), number) == 0)
		return mid;

	if (strcmp(books[mid].getISBN(), number) > 0)
		high = mid - 1;
	else
		low = mid + 1;
	}
	return -1;
}
void BookStore::processOrders(const char* order){
	ifstream inFile;
	char orderNumber[7];
	char isbn[11];
	char temp[50];
	char ord[50];
	int orderQuantity;
	int numShipped;

	inFile.open(order);
	if(inFile.fail()){
		cout << "File failed to open" << endl;
		exit(-1);
	}

	//for some reason after this part of the program taks in the 
	//order number it fails to take in anyhting else and gets stuck in an infanit loop of pain and suffering
	orderNumber[6] = '\0';
	isbn[10] = '\0';
	cout<< "Order Listing\n\n";
	inFile.getline(temp, 50);
	while (!inFile.eof()){
		//set order number
		for(int i = 0; i < 6; i ++)
			orderNumber[i] = temp[i];
		//set isbn
		for(int i = 0; i < 10; i ++)
			isbn[i] = temp [i + 7];
		//set order quantity
		for (int i = 0; i < 32; i ++)
			ord[i] = temp[i + 18];
		orderQuantity = atoi(ord);
		//check if isbn exists
		int index = searchForISBN(isbn);
		if(index == -1){
			cout<< "Order #" << orderNumber << ": error - ISBN " << isbn << " does not exist" << endl;
		}
		else {
			int shipped = books[index].fulfillOrder(orderQuantity);
			//Order output
			cout << "Order #" << orderNumber << ": ISBN " << isbn << ", " 
				<< shipped << " of " << orderQuantity << " shipped, order total $" 
				<< books[index].getPrice() * shipped << endl;
		}
		inFile.getline(temp, 50);
	}
	inFile.close();

}
