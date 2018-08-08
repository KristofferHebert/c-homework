#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Item {
    public:
        void SetPrice(int prcInDllrs)
            { priceInDollars = prcInDllrs; };
        void SetName(string nm)
            { name = nm; };
        void SetQuantity(int qnty)
            { quantity = qnty; };
        int GetTotalValueAsPrice()
            { return priceInDollars * quantity;}
        virtual void Print()
            { cout << name << " " << quantity << endl; };
        virtual ~Item()
            { return; };
    protected:
        string name;
        int    quantity;
        int    priceInDollars;
};

class Produce : public Item { // Derived from Item class
    public:
        void SetExpiration(string expir)
            { expiration = expir; };
        void Print()
            { cout << name << " x" << quantity << " for $" << priceInDollars
              << " (Expires: " << expiration << ")"
              << endl;
            };
    private:
        string expiration;
};

class Book : public Item {
    public:
        void SetAuthor(string authr)
            { author = authr; };
        void Print()
            { cout << name << " x" << quantity << " for $" << priceInDollars
              << " (Author: " << author << ")"
              << endl;
            };        
    private:
        string author;
};

class Inventory {
    public:
        void PrintInventory(vector<Item*> inventory);
        vector<Item*> AddItemToInventory(vector<Item*> inventory);
        vector<Item*> UpdateItemQtyInInventory(vector<Item*> inventory);
        vector<Item*> RemoveItemFromInventory(vector<Item*> inventory); 
    private:
        void SumLnv();
        vector<Item*> inventory;
        int totalInvPriceInDollars;
};

// Get total of items in Inventory
void Inventory::SumLnv() {
	unsigned int i = 0;
    unsigned int size = inventory.size();
    totalInvPriceInDollars = 0;
    
    if (size != 0){
        for (i=0; i<size; ++i) {
            int price = inventory.at(i)->GetTotalValueAsPrice();
            totalInvPriceInDollars = totalInvPriceInDollars + price;
        }
    } else {
        totalInvPriceInDollars = 0;
    }

    cout << "Total Inventory Value: $" << totalInvPriceInDollars << endl;
	return;
}

// Print items inventory
void Inventory::PrintInventory(vector<Item*> inventory) {
    unsigned int i = 0;
    if (inventory.size() == 0) {
        cout << "No items to print." << endl;
    } else {
        for (i=0; i<inventory.size(); ++i) {
            cout << i << " - ";
            inventory.at(i)->Print();
        }
        this->SumLnv();
    }
    return;
}

// Add items to item list
vector<Item*> Inventory::AddItemToInventory(vector<Item*> inventory) {
    Produce* pd = new Produce;
    Book* bk = new Book;
    vector<Item*> i = inventory;
    string usrInptName = "";
    string usrInptQntyStr = "";
    string usrInptPriceStr = "";
    string usrInptAuthor = "";
    istringstream inSS;
    int usrInptQnty = 0;
    int usrInptPrice = 0;
    string usrInptExpr = "";
    string userItemChoice;
    string inputType = "";

    while (true) {
        // Get user choice
        cout << "Enter name of a book (b) or produce (p) ";
        getline(cin, userItemChoice);

        // Process user choice
        if (userItemChoice.size() == 0) {
            continue;
        } else if (userItemChoice.at(0) == 'b') {
            inputType = "book";
            break;
        } else if (userItemChoice.at(0) == 'p') {
            inputType = "produce";
            break;        
        } else {
            cout << "\n“Invalid choice" << endl;
            continue;
        }
    }

    cout << "Enter name of new " << inputType << ": ";
    getline(cin, usrInptName);

    cout << "Enter quantity: ";
    getline(cin, usrInptQntyStr);
    inSS.str(usrInptQntyStr);
    inSS >> usrInptQnty;
    inSS.clear();
     
    cout << "Enter the price per item: $";
    getline(cin, usrInptPriceStr);
    inSS.str(usrInptPriceStr);
    inSS >> usrInptPrice;
    
    if(inputType == "book"){
        cout << "Enter name of author: ";
        getline(cin, usrInptAuthor);    
        bk->SetName(usrInptName);
        bk->SetQuantity(usrInptQnty);
        bk->SetPrice(usrInptPrice);
        bk->SetAuthor(usrInptAuthor);
        this->inventory.push_back(bk);

    } else {
        cout << "Enter expiration date: ";
        getline(cin, usrInptExpr);

        pd->SetName(usrInptName);
        pd->SetQuantity(usrInptQnty);
        pd->SetPrice(usrInptPrice);
        pd->SetExpiration(usrInptExpr);
        this->inventory.push_back(pd);
    }
    
    this->SumLnv();

    return this->inventory;
    }

// Update item in Inventory
vector<Item*> Inventory::UpdateItemQtyInInventory(vector<Item*> inventory) {
    string usrIndexChoiceStr = "";
    Inventory inv;
    unsigned int usrIndexChoice = 0;
    istringstream inSS;
    string usrInptQntyStr = "";
    int usrInptQnty = 0;
    
    if (this->inventory.size() == 0) {
        cout << "No items to update." << endl;
    } else {
        this->PrintInventory(inventory);
        
        do {
            cout << "Update which item #: ";
            getline(cin, usrIndexChoiceStr);
            inSS.str(usrIndexChoiceStr);
            inSS >> usrIndexChoice;
            inSS.clear();
        } while ( !(usrIndexChoice < inventory.size()) );
        
        cout << "Enter new quantity: ";
        getline(cin, usrInptQntyStr);
        inSS.str(usrInptQntyStr);
        inSS >> usrInptQnty;
        inSS.clear();
        
        this->inventory.at(usrIndexChoice)->SetQuantity(usrInptQnty);
    }

    this->SumLnv();
    
    return this->inventory;
}

// Remove items from Inventory
vector<Item*> Inventory::RemoveItemFromInventory(vector<Item*> inventory) {
    istringstream inSS;
    string usrIndexChoiceStr = "";
    unsigned int usrIndexChoice = 0;
    string usrInptQntyStr = "";
    
    if (this->inventory.size() == 0) {
        cout << "No items to remove." << endl;
    } else {
        this->PrintInventory(inventory);
        
        do {
            cout << "Remove which item #: ";
            getline(cin, usrIndexChoiceStr);
            inSS.str(usrIndexChoiceStr);
            inSS >> usrIndexChoice;
            inSS.clear();
        } while ( !(usrIndexChoice < this->inventory.size()) );
        
        this->inventory.erase( this->inventory.begin() + usrIndexChoice );
    }

    this->SumLnv();

    return this->inventory;
}

int main() {
    vector<Item*> inventory;
    Inventory inv;
    string usrInptOptn = "default";
    
    while (true) {
        // Get user choice
        cout << "\nEnter (p)rint, (a)dd, (u)pdate, (r)emove, or (q)uit: ";
        getline(cin, usrInptOptn);

        // Process user choice
        if (usrInptOptn.size() == 0) {
            continue;
        } else if (usrInptOptn.at(0) == 'p') {
            inv.PrintInventory(inventory);
        } else if (usrInptOptn.at(0) == 'a') {
            inventory = inv.AddItemToInventory(inventory);
        } else if (usrInptOptn.at(0) == 'u') {
            inventory = inv.UpdateItemQtyInInventory(inventory);
        } else if (usrInptOptn.at(0) == 'r') {
            inventory = inv.RemoveItemFromInventory(inventory);
        } else if (usrInptOptn.at(0) == 'q') {
            cout << "\nGood bye." << endl;
            break;
        }
    }

    return 0;
}