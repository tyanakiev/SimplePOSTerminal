// SimplePOSTerminal.cpp - Trifon Yanakiev (yanat29@uwgb.edu)

#include <iomanip>
#include <iostream>
#include <vector> 
#include <algorithm>
#include <string>

using namespace std;

class Bakery {
	// Public placeholder class. Used only for easy access to the arrays bellow.
	public:
		// Variable used to calculate sub total after each purchase
		double subTotal = 0;
		// Array representation for Breads category
		string bakeryStrings[6] = {"Breads", "Rolls", "Biscuits", "Cakes", "Tortillas", "Pastries"};
		// Units per product
		string bakeryUnits[6] = {"Pc", "Pc", "Lb", "Lb", "Pc", "Lb"};
		// Price per product
		double bakeryPrices[6] = {5.23 ,2.58, 3.87, 1.89, 3.63, 5.75};
		// Array in which we record how many sales we have per product.
		double bakerySales[6] = { 0 };
		// Array representation for Fruits category
		string fruitsStrings[7] = { "Apple", "Orange", "Pears", "Watermelon", "Mangoes", "Grapes", "Banana" };
		// Units per product
		string fruitsUnits[7] = {"Kg", "Kg", "Kg", "Pc", "Kg", "Kg", "Kg"};
		// Price per product
		double fruitPrices[7] = {2.43, 1.98, 4.57, 2.01, 9.89, 6.33, 0.59};
		// Array in which we record how many sales we have per product.
		double fruitSales[7] = { 0 };
		// Array representation for Grocery category
		string groceryStrings[9] = {"Packet biscuits", "Chocolates", "Rice", "Pasta", "Oil", "Packet fish", "Toilet cleaner", "Toilet tissue", "Air freshener"};
		// Units per product
		string groceryUnits[9] = {"Pc", "Pc", "Kg", "Kg", "L", "Lb" , "Pc", "Pc", "Pc"};
		// Price per product
		double groceryPrices[9] = {2.65, 1.84, 3.33, 2.89, 4.55, 12.78, 2.5, 6.54, 1.88};
		// Array in which we record how many sales we have per product.
		double grocerySales[9] = { 0 };
		// Array representation for Vegetables category
		string vegetablesStrings[9] = {"Spinach", "Zucchini", "Potatoes", "Onions", "Garlic", "Cilantro", "Broccoli", "Cauliflower", "Cucumber"};
		// Units per product
		string vegetablesUnits[9] = {"Kg", "Kg", "Kg", "Kg", "Kg", "Kg", "Kg", "Pc", "Kg"};
		// Price per product
		double vegetablesPrices[9] = {1.21, 1.85, 0.98, 1.01, 3.22, 0.99, 5.8, 3.74, 2.87};
		// Array in which we record how many sales we have per product.
		double vegetablesSales[9] = { 0 };
};


double select_products(double total, string product[], double price[], string units[], double sales[], int size) {
	// Gets 3 arrays for product name, product price and product units. Then prints a menu and calculates the subTotal of the purchase. Also records what products were purchased.
	int choice = 99999;
	double subTotal = total;
	double amount = 0;
	// Loop until user select 0. for exit
	while (choice != 0) {
		for (int i = 0; i < size; i++) {
			// Prints Product name     Product Price    Product Units
			cout << i + 1 << ". " << product[i] << "\t\t" << price[i] << "\t" << units[i] << endl;
		}
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		// Validates if the cin failed (user enter something different than int), if true then forces user to enter again and displays msg.
		while (std::cin.fail()) {
			std::cout << "Please enter a number!" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}
		// If choice is in the limits we ask the user to enter amount of units for the selected product.
		if (choice > 0 && choice <= size) {
			cout << "Enter amount of " << units[choice - 1] << endl;
			cin >> amount;
			subTotal = subTotal + (amount * price[choice - 1]);
			sales[choice - 1] = sales[choice - 1] + amount;
		}
		else {
			cout << "The valid choices are 1 through " << size << "\nRun the program again and select one of those.\n";
		}
		cout << "current balance: " << subTotal << endl;
	}

	return subTotal;
}

int category_menu(Bakery &bakeryObj) {
	// Based on selected menu option, calls for select_products function to calculate the subTotal.
	// Takes Bakery object refrence as argument.
	int choice;
	const int BAKERY_CHOICE = 1, FRUITS_CHOICE = 2, GROVERY_CHOICE = 3, VEGETABLES_CHOICE = 4, EXIT_CHOICE = 0;
	cout << "**************************\n"
		<< "**\tPOS Menu\t**\n"
		<< "**************************\n\n"
		<< "1. Bakery\n"
		<< "2. Fruits\n"
		<< "3. Grocery\n"
		<< "4. Vegetables\n"
		<< "0. Exit \n"
		<< "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case BAKERY_CHOICE:
		// Calls select_products function that takes an Bakery object and 3 arrays for a givem product category, then creates a menu from which the user can sellect what products to buy\
		// Once the user is done buying products the function returns the subTotal, while at the same time, records what products were purchased.
		bakeryObj.subTotal =+ select_products(bakeryObj.subTotal, bakeryObj.bakeryStrings, bakeryObj.bakeryPrices, bakeryObj.bakeryUnits, bakeryObj.bakerySales, 6);
		category_menu(bakeryObj);
		break;
	case FRUITS_CHOICE:
		bakeryObj.subTotal =+ select_products(bakeryObj.subTotal, bakeryObj.fruitsStrings, bakeryObj.fruitPrices, bakeryObj.fruitsUnits, bakeryObj.fruitSales,7);
		category_menu(bakeryObj);
		break;
	case GROVERY_CHOICE:
		bakeryObj.subTotal =+ select_products(bakeryObj.subTotal, bakeryObj.groceryStrings, bakeryObj.groceryPrices, bakeryObj.groceryUnits, bakeryObj.grocerySales,9);
		category_menu(bakeryObj);
		break;
	case VEGETABLES_CHOICE:
		bakeryObj.subTotal =+ select_products(bakeryObj.subTotal, bakeryObj.vegetablesStrings, bakeryObj.vegetablesPrices, bakeryObj.vegetablesUnits, bakeryObj.vegetablesSales,9);
		category_menu(bakeryObj);
		break;
	case EXIT_CHOICE:
		break;
	default:
		cout << "The valid choices are 1 through 4 and 0 to Exit.\n Run the program again and select one of those.\n";
		category_menu(bakeryObj);
	}
	return 0;
}

int payment_menu(Bakery &bakeryObj) {
	// Payment option. Checks if the subtotal is 0, else it loops until the customer pays in full.
	// Takes Bakery object refrence as argument.
	double bill = bakeryObj.subTotal;
	if (bakeryObj.subTotal > 0)
	{
		//initialize payment variable
		double payment;
		// The user must pay the full bill before exiting from this menu.
		while (bakeryObj.subTotal > 0) {
			cout << "Your current bill is: " << bakeryObj.subTotal << endl;
			cout << "Please enter payment amount:";
			cin >> payment;
			while (std::cin.fail()) {
				std::cout << "Please enter a number!" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> payment;
			}
			bakeryObj.subTotal = bakeryObj.subTotal - payment;
		}
		cout << "Thank you for you purchase!" << endl;
		// If the user pays more than his/hers bill, we calculate the change.
		if (bakeryObj.subTotal < 0) {
			cout << "Your change is: " << bakeryObj.subTotal * -1 << endl;
			bakeryObj.subTotal = 0;
		}
	}
	else
	{
		//save check if we try to pay without any bill accumulation.
		cout << "You have no sale overdue!" << endl;
	}

	return 0;
}

int customer_menu(Bakery &bakeryObj) {
	// Customer menu. Gives options to display products or payment option.
	// Takes Bakery object refrence as argument.
	int choice;
	const int SALE_CHOICE = 1, BUY_CHOICE = 2, EXIT_CHOICE = 0;
	cout << "**************************\n"
		<< "**\tPOS Menu\t**\n"
		<< "**************************\n\n"
		<< "1. Sale\n"
		<< "2. Pay\n"
		<< "0. Exit\n"
		<< "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case SALE_CHOICE:
		category_menu(bakeryObj);
		customer_menu(bakeryObj);
		break;
	case BUY_CHOICE:
		payment_menu(bakeryObj);
		customer_menu(bakeryObj);
		break;
	case EXIT_CHOICE:
		if (bakeryObj.subTotal > 0) {
			cout << "Please pay your bill before you exit." << endl;
			customer_menu(bakeryObj);
		}
		break;
	default:
		cout << "The valid choices are 1 through 2 and 0 to Exit\nRun the program again and select one of those.\n";
		customer_menu(bakeryObj);
	}
	return 0;
}

void total_sales_by_cat(Bakery &bakeryObj) {
	// Prints total sales  by category
	cout << "\nBakery Category: \n";
	// Loops through bakerySales array and displays how many products were purchased and their units.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if (bakeryObj.bakerySales[i] > 0) {
			cout << i + 1 << ". " << bakeryObj.bakeryStrings[i] << " sold " << bakeryObj.bakerySales[i] << " " << bakeryObj.bakeryUnits[i] << endl;
		}
	}
	cout << "\nFruits Category: \n";
	// Loops through fruitSales array and displays how many products were purchased and their units.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales)/ sizeof(bakeryObj.fruitSales[0]); i++) {
		if (bakeryObj.fruitSales[i] > 0) {
			cout << i + 1 << ". " << bakeryObj.fruitsStrings[i] << " sold " << bakeryObj.fruitSales[i] << " " << bakeryObj.fruitsUnits[i] << endl;
		}
	}
	cout << "\nGrocery Category: \n";
	// Loops through grocerySales array and displays how many products were purchased and their units.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales)/ sizeof(bakeryObj.grocerySales[0]); i++) {
		if (bakeryObj.grocerySales[i] > 0) {
			cout << i + 1 << ". " << bakeryObj.groceryStrings[i] << " sold " << bakeryObj.grocerySales[i] << " " << bakeryObj.groceryUnits[i] << endl;
		}
	}
	cout << "\nVegetables Category: \n";
	// Loops through vegetablesSales array and displays how many products were purchased and their units.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales)/ sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if (bakeryObj.vegetablesSales[i] > 0) {
			cout << i + 1 << ". " << bakeryObj.vegetablesStrings[i] << " sold " << bakeryObj.vegetablesSales[i] << " " << bakeryObj.vegetablesUnits[i] << endl;
		}
	}
}

void highest_sold_by_cat(Bakery &bakeryObj) {
	// Prints highest salesvolumeby category
	// We use vectors here because we are not sure how many items will have the highest sold volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
	vector<int> highest_bakery_index;
	vector<int> highest_fruits_index;
	vector<int> highest_grocery_index;
	vector<int> highest_vegetables_index;

	// Place holder for highest volume sold for each category.
	double temp_bakery = 0;
	double temp_fruits = 0;
	double temp_grocery = 0;
	double temp_vagetables = 0;

	// Using *max_element we can extract the highest number in the array.
	temp_bakery = *max_element(bakeryObj.bakerySales, (bakeryObj.bakerySales + sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0])));
	// Loop through bakerySales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if (bakeryObj.bakerySales[i] == temp_bakery && temp_bakery!=0) {
			// Add the index of the item with the highest sales in the vector bellow.
			highest_bakery_index.push_back(i);
		}
	}
	// Using *max_element we can extract the highest number in the array.
	temp_fruits = *max_element(bakeryObj.fruitSales, (bakeryObj.fruitSales + sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0])));
	// Loop through fruitSales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if (bakeryObj.fruitSales[i]  == temp_fruits && temp_fruits !=0) {
			// Add the index of the item with the highest sales in the vector bellow.
			highest_fruits_index.push_back(i);
		}
	}
	// Using *max_element we can extract the highest number in the array.
	temp_grocery = *max_element(bakeryObj.grocerySales, (bakeryObj.grocerySales + sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0])));
	// Loop through grocerySales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if (bakeryObj.grocerySales[i] == temp_grocery && temp_grocery!=0) {
			// Add the index of the item with the highest sales in the vector bellow.
			highest_grocery_index.push_back(i);
		}
	}
	// Using *max_element we can extract the highest number in the array.
	temp_vagetables = *max_element(bakeryObj.vegetablesSales, (bakeryObj.vegetablesSales + sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0])));
	// Loop through vegetablesSales and if we find the sales value to be equal to the max value  we record the index of the element. We can have more than one items.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if (bakeryObj.vegetablesSales[i] == temp_vagetables && temp_vagetables !=0) {
			// Add the index of the item with the highest sales in the vector bellow.
			highest_vegetables_index.push_back(i);
		}
	}

	//Loops through the vector of indexes and prints all items that have the highest sells per category.
	if (!highest_bakery_index.empty()) {
		cout << "\nBakery Category, highest sold item(s): \n";
		for (int i : highest_bakery_index) {
			cout << i + 1 << ". " << bakeryObj.bakeryStrings[i] << " sold " << bakeryObj.bakerySales[i] << " " << bakeryObj.bakeryUnits[i] << " for $" << bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] << endl;
		}
			
	}
	//Loops through the vector of indexes and prints all items that have the highest sells per category.
	if (!highest_fruits_index.empty()) {
		cout << "\nFruits Category, highest sold item(s): \n";
		for (int i : highest_fruits_index) {
			cout << i + 1 << ". " << bakeryObj.fruitsStrings[i] << " sold " << bakeryObj.fruitSales[i] << " " << bakeryObj.fruitsUnits[i] << " for $" << bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the highest sells per category.
	if (!highest_grocery_index.empty()) {
		cout << "\nGrocery Category, highest sold item(s): \n";
		for (int i : highest_grocery_index) {
			cout << i + 1 << ". " << bakeryObj.groceryStrings[i] << " sold " << bakeryObj.grocerySales[i] << " " << bakeryObj.groceryUnits[i] << " for $" << bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the highest sells per category.
	if (!highest_vegetables_index.empty()) {
		cout << "\nVegetables Category, highest sold item(s): \n";
		for (int i : highest_vegetables_index) {
			cout << i + 1 << ". " << bakeryObj.vegetablesStrings[i] << " sold " << bakeryObj.vegetablesSales[i] << " " << bakeryObj.vegetablesUnits[i] << " for $" << bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] << endl;
		}
	}
}

void highest_volume_sold_by_cat(Bakery &bakeryObj) {
	// Prints highest sales volume by category
	// We use vectors here because we are not sure how many items will have the highest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
	// Difference from the function above is that here we acutally care for the amount in $ and not only the items count. For example we might have 5 items sold but only for $5 and we can have 1 item sold for 6$. We must display the highest amount of money.
	vector<int> highest_volume_bakery_index;
	vector<int> highest_volume_fruits_index;
	vector<int> highest_volume_grocery_index;
	vector<int> highest_volume_vegetables_index;

	// Place holder for highest volume sold for each category.
	double temp_bakery = 0;
	double temp_fruits = 0;
	double temp_grocery = 0;
	double temp_vagetables = 0;
	// Loop through bakerySales and we look for the highest amount payed for an item.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if (bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] > temp_bakery) {
			temp_bakery = bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i];
		}
	}
	// Looping through bakerySales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if ((bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] == temp_bakery) && temp_bakery!=0) {
			highest_volume_bakery_index.push_back(i);
		}
	}
	// Loop through fruitSales and we look for the highest amount payed for an item.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if (bakeryObj.fruitSales[i] * bakeryObj .fruitPrices[i] > temp_fruits) {
			temp_fruits = bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i];
		}
	}
	// Looping through fruitSales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if ((bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] == temp_fruits) && temp_fruits != 0) {
			highest_volume_fruits_index.push_back(i);
		}
	}
	// Loop through grocerySales and we look for the highest amount payed for an item.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if (bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] > temp_grocery) {
			temp_grocery = bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i];
		}
	}
	// Looping through grocerySales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if ((bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] == temp_grocery) && temp_grocery != 0) {
			highest_volume_grocery_index.push_back(i);
		}
	}
	// Loop through vegetablesSales and we look for the highest amount payed for an item.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if (bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] > temp_vagetables) {
			temp_vagetables = bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i];
		}
	}
	// Looping through vegetablesSales looking for items that have same amount as the temp variable. Ten we add the index in a vector.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if ((bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] == temp_vagetables) && temp_vagetables != 0) {
			highest_volume_vegetables_index.push_back(i);
		}
	}
	//Loops through the vector of indexes and prints all items that have the highest volume sold per category.
	if (!highest_volume_bakery_index.empty()) {
		cout << "\nBakery Category, highest volume sold item(s): \n";
		for (int i : highest_volume_bakery_index) {
			cout << i + 1 << ". " << bakeryObj.bakeryStrings[i] << " sold " << bakeryObj.bakerySales[i] << " " << bakeryObj.bakeryUnits[i] << " for $" << bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] << endl;
		}

	}
	//Loops through the vector of indexes and prints all items that have the highest volume sold per category.
	if (!highest_volume_fruits_index.empty()) {
		cout << "\nFruits Category, highest volume sold item(s): \n";
		for (int i : highest_volume_fruits_index) {
			cout << i + 1 << ". " << bakeryObj.fruitsStrings[i] << " sold " << bakeryObj.fruitSales[i] << " " << bakeryObj.fruitsUnits[i] << " for $" << bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the highest volume sold per category.
	if (!highest_volume_grocery_index.empty()) {
		cout << "\nGrocery Category, highest volume sold item(s): \n";
		for (int i : highest_volume_grocery_index) {
			cout << i + 1 << ". " << bakeryObj.groceryStrings[i] << " sold " << bakeryObj.grocerySales[i] << " " << bakeryObj.groceryUnits[i] << " for $" << bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the highest volume sold per category.
	if (!highest_volume_vegetables_index.empty()) {
		cout << "\nVegetables Category, highest volume sold item(s): \n";
		for (int i : highest_volume_vegetables_index) {
			cout << i + 1 << ". " << bakeryObj.vegetablesStrings[i] << " sold " << bakeryObj.vegetablesSales[i] << " " << bakeryObj.vegetablesUnits[i] << " for $" << bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] << endl;
		}
	}
}

void lowest_volume_sold_by_cat(Bakery &bakeryObj) {
	// Prints lowest sales volume by category
	// We use vectors here because we are not sure how many items will have the lowest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
	vector<int> lowest_volume_bakery_index;
	vector<int> lowest_volume_fruits_index;
	vector<int> lowest_volume_grocery_index;
	vector<int> lowest_volume_vegetables_index;

	// Setting temp values to max double value in order to find the lowest count of an items sold.
	double temp_bakery = DBL_MAX;
	double temp_fruits = DBL_MAX;
	double temp_grocery = DBL_MAX;
	double temp_vagetables = DBL_MAX;

	// Looping through bakerySales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if ((bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] < temp_bakery) && bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] != 0) {
			temp_bakery = bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i];
		}
	}
	// Looping through bakerySales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if ((bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] == temp_bakery) && temp_bakery != 0) {
			lowest_volume_bakery_index.push_back(i);
		}
	}
	// Looping through fruitSales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if ((bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] < temp_fruits) && bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] != 0) {
			temp_fruits = bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i];
		}
	}
	// Looping through fruitSales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if ((bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] == temp_fruits) && temp_fruits != 0) {
			lowest_volume_fruits_index.push_back(i);
		}
	}
	// Looping through grocerySales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if ((bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] < temp_grocery) && bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] != 0) {
			temp_grocery = bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i];
		}
	}
	// Looping through grocerySales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if ((bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] == temp_grocery) && temp_grocery != 0) {
			lowest_volume_grocery_index.push_back(i);
		}
	}
	// Looping through vegetablesSales and looking for lowest amount payed for a product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if ((bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] < temp_vagetables) && bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] != 0) {
			temp_vagetables = bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i];
		}
	}
	// Looping through vegetablesSales looking for items that have the same amount of $ payed as the lowest amount payed. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if ((bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] == temp_vagetables) && temp_vagetables != 0) {
			lowest_volume_vegetables_index.push_back(i);
		}
	}
	//Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
	if (!lowest_volume_bakery_index.empty()) {
		cout << "\nBakery Category, lowest volume sold item(s): \n";
		for (int i : lowest_volume_bakery_index) {
			cout << i + 1 << ". " << bakeryObj.bakeryStrings[i] << " sold " << bakeryObj.bakerySales[i] << " " << bakeryObj.bakeryUnits[i] << " for $" << bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] << endl;
		}

	}
	//Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
	if (!lowest_volume_fruits_index.empty()) {
		cout << "\nFruits Category, lowest volume sold item(s): \n";
		for (int i : lowest_volume_fruits_index) {
			cout << i + 1 << ". " << bakeryObj.fruitsStrings[i] << " sold " << bakeryObj.fruitSales[i] << " " << bakeryObj.fruitsUnits[i] << " for $" << bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
	if (!lowest_volume_grocery_index.empty()) {
		cout << "\nGrocery Category, lowest volume sold item(s): \n";
		for (int i : lowest_volume_grocery_index) {
			cout << i + 1 << ". " << bakeryObj.groceryStrings[i] << " sold " << bakeryObj.grocerySales[i] << " " << bakeryObj.groceryUnits[i] << " for $" << bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the lowest volume sold per category.
	if (!lowest_volume_vegetables_index.empty()) {
		cout << "\nVegetables Category, lowest volume sold item(s): \n";
		for (int i : lowest_volume_vegetables_index) {
			cout << i + 1 << ". " << bakeryObj.vegetablesStrings[i] << " sold " << bakeryObj.vegetablesSales[i] << " " << bakeryObj.vegetablesUnits[i] << " for $" << bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] << endl;
		}
	}
}

void lowest_sold_by_cat(Bakery &bakeryObj) {
	// Prints lowest sales by category
	// We use vectors here because we are not sure how many items will have the lowest volume. For example if we have two or more products with the same items sold, we must display both. We don't know how many items we will have.
	vector<int> lowest_bakery_index;
	vector<int> lowest_fruits_index;
	vector<int> lowest_grocery_index;
	vector<int> lowest_vegetables_index;

	// Setting temp values to max double value in order to find the lowest count of an items sold.
	double temp_bakery = DBL_MAX;
	double temp_fruits = DBL_MAX;
	double temp_grocery = DBL_MAX;
	double temp_vagetables = DBL_MAX;

	// Looping through bakerySales and looking for lowest selling  product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if (bakeryObj.bakerySales[i] <= temp_bakery && bakeryObj.bakerySales[i] != 0) {
			temp_bakery = bakeryObj.bakerySales[i];
		}
	}
	// Looping through bakerySales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.bakerySales) / sizeof(bakeryObj.bakerySales[0]); i++) {
		if (bakeryObj.bakerySales[i] == temp_bakery && bakeryObj.bakerySales[i] != 0) {
			lowest_bakery_index.push_back(i);
		}
	}
	// Looping through fruitSales and looking for lowest selling  product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if (bakeryObj.fruitSales[i] <= temp_fruits && bakeryObj.fruitSales[i] != 0) {
			temp_fruits = bakeryObj.fruitSales[i];
		}
	}
	// Looping through fruitSales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.fruitSales) / sizeof(bakeryObj.fruitSales[0]); i++) {
		if (bakeryObj.fruitSales[i] == temp_fruits && bakeryObj.fruitSales[i] != 0) {
			lowest_fruits_index.push_back(i);
		}
	}
	// Looping through grocerySales and looking for lowest selling  product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if (bakeryObj.grocerySales[i] <= temp_grocery && bakeryObj.grocerySales[i] != 0) {
			temp_grocery = bakeryObj.grocerySales[i];
		}
	}
	// Looping through grocerySales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.grocerySales) / sizeof(bakeryObj.grocerySales[0]); i++) {
		if (bakeryObj.grocerySales[i] == temp_grocery && bakeryObj.grocerySales[i] != 0) {
			lowest_grocery_index.push_back(i);
		}
	}
	// Looping through vegetablesSales and looking for lowest selling  product for a givem category. Then we assign it to the temp value. 
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if (bakeryObj.vegetablesSales[i] <= temp_vagetables && bakeryObj.vegetablesSales[i] != 0) {
			temp_vagetables = bakeryObj.vegetablesSales[i];
		}
	}
	// Looping through vegetablesSales looking for items that have the same amount items sold as the lowest amount of items sold. Then we add them to a vector.
	for (int i = 0; i < sizeof(bakeryObj.vegetablesSales) / sizeof(bakeryObj.vegetablesSales[0]); i++) {
		if (bakeryObj.vegetablesSales[i] == temp_vagetables && bakeryObj.vegetablesSales[i] != 0) {
			lowest_vegetables_index.push_back(i);
		}
	}
	
	//Loops through the vector of indexes and prints all items that have the lowest items sold per category.
	if (!lowest_bakery_index.empty()) {
		cout << "\nBakery Category, lowest sold item(s): \n";
		for (int i : lowest_bakery_index) {
			cout << i + 1 << ". " << bakeryObj.bakeryStrings[i] << " sold " << bakeryObj.bakerySales[i] << " " << bakeryObj.bakeryUnits[i] << " for $" << bakeryObj.bakerySales[i] * bakeryObj.bakeryPrices[i] << endl;
		}

	}
	//Loops through the vector of indexes and prints all items that have the lowest items sold per category.
	if (!lowest_fruits_index.empty()) {
		cout << "\nFruits Category, lowest sold item(s): \n";
		for (int i : lowest_fruits_index) {
			cout << i + 1 << ". " << bakeryObj.fruitsStrings[i] << " sold " << bakeryObj.fruitSales[i] << " " << bakeryObj.fruitsUnits[i] << " for $" << bakeryObj.fruitSales[i] * bakeryObj.fruitPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the lowest items sold per category.
	if (!lowest_grocery_index.empty()) {
		cout << "\nGrocery Category, lowest sold item(s): \n";
		for (int i : lowest_grocery_index) {
			cout << i + 1 << ". " << bakeryObj.groceryStrings[i] << " sold " << bakeryObj.grocerySales[i] << " " << bakeryObj.groceryUnits[i] << " for $" << bakeryObj.grocerySales[i] * bakeryObj.groceryPrices[i] << endl;
		}
	}
	//Loops through the vector of indexes and prints all items that have the lowest items sold per category.
	if (!lowest_vegetables_index.empty()) {
		cout << "\nVegetables Category, lowest sold item(s): \n";
		for (int i : lowest_vegetables_index) {
			cout << i + 1 << ". " << bakeryObj.vegetablesStrings[i] << " sold " << bakeryObj.vegetablesSales[i] << " " << bakeryObj.vegetablesUnits[i] << " for $" << bakeryObj.vegetablesSales[i] * bakeryObj.vegetablesPrices[i] << endl;
		}
	}
}


int admin_menu(Bakery &bakeryObj) {
	// Admin menu.
	int choice;
	const int TOTAL_CHOICE = 1, HIGHEST_CHOICE = 2, HIGHEST_SOLD_CHOICE = 3, LOWEST_CHOICE = 4, LOWEST_SOLD_CHOICE = 5, EXIT_CHOICE = 0;
	cout << "**************************\n"
		<< "**\tPOS Menu\t**\n"
		<< "**************************\n\n"
		<< "1. Display total sales volume by category\n"
		<< "2. Display name and units of highest sold item in each category\n"
		<< "3. Display name and sales volume for highest sold item in each category\n"
		<< "4. Display name and units of lowest sold item in each category\n"
		<< "5. Display name and sales volume for lowest sold item in each category\n"
		<< "0. Exit\n"
		<< "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case TOTAL_CHOICE:
		total_sales_by_cat(bakeryObj);
		admin_menu(bakeryObj);
		break;
	case HIGHEST_CHOICE:
		highest_sold_by_cat(bakeryObj);
		admin_menu(bakeryObj);
		break;
	case HIGHEST_SOLD_CHOICE:
		highest_volume_sold_by_cat(bakeryObj);
		admin_menu(bakeryObj);
		break;
	case LOWEST_CHOICE:
		lowest_sold_by_cat(bakeryObj);
		admin_menu(bakeryObj);
		break;
	case LOWEST_SOLD_CHOICE:
		lowest_volume_sold_by_cat(bakeryObj);
		admin_menu(bakeryObj);
		break;
	case EXIT_CHOICE:
		break;
	default:
		cout << "The valid choices are 1 through 5 and 0 to Exit Run the\n" << "program again and select one of those.\n";
		admin_menu(bakeryObj);
	}
	return 0;
}

int initial_menu(Bakery &bakeryObj) {
	// Initial menu or Main menu. Displays menu options and calls sub-menues if selected.
	// Takes Bakery object refrence as argument.
	int choice;
	const int CUSTOMER_CHOICE = 1, ADMIN_CHOICE = 2, EXIT_CHOICE = 0;
	cout << "**************************\n"
		<< "**\tPOS Menu\t**\n"
		<< "**************************\n\n"
		<< "1. Customer\n"
		<< "2. Admin\n"
		<< "0. Exit\n"
		<< "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
		case CUSTOMER_CHOICE:
			customer_menu(bakeryObj);
			initial_menu(bakeryObj);
			break;
		case ADMIN_CHOICE:
			admin_menu(bakeryObj);
			initial_menu(bakeryObj);
			break;
		case EXIT_CHOICE:
			break;
		default:
			cout << "The valid choices are 1 through 2 and 0 to Exit. Run the\n" << "program again and select one of those.\n";
			initial_menu(bakeryObj);
	}
	return 0;
}

int main()
{
	// Initialize Bakery object
	Bakery bakeryObj;
	// Call initial menu.
	initial_menu(bakeryObj);
	return 0;
}