#include "Book.h"


Book::Book(){
	isbn[0] = '\0';
	title[0] = '\0';
	price = 0;
	quantity = 0;
}
Book::Book(char newISBN[], char newTitle[], double newPrice, int newQuantity){
	strcpy(isbn, newISBN);
	strcpy(title, newTitle);
	setPrice(newPrice);
	setQuantity(newQuantity);
}
char* Book::getISBN(){
	return isbn;
}
char* Book::getTitle(){
	return title;
}
double Book::getPrice(){
	return price;
}
int Book::getQuantity(){
	return quantity;
}
void Book::setPrice(double newPrice){
	if(newPrice > 0)
		price = newPrice;
	else
		price  = 0;
}
void Book::setQuantity(int newQuantity){
	if(newQuantity > 0)
		quantity = newQuantity;
	else
		quantity = 0;
}
int Book::fulfillOrder(int number){
	if(number > 0){
		if(number <= quantity){
			quantity -= number;
			return number;
		} else {
			int temp = quantity;
			quantity = 0;
			return temp; 
		}
	}
	return 0;
}
void Book::print(){
	cout <<  left << setw(14) << isbn << setw(44) << title << right << setw(5) << price << setw(6) << quantity;
}

