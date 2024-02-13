#include <iostream>
#include <string>
using namespace std;

class User{
private:
    string password,cellphone, new_password;
    int age;
    bool valid = false;
public:
    string username;
    User(string username, string password, string cellphone, int age, bool valid){
        this->username = username;
        this->password = password;
        this->cellphone = cellphone;
        this->age = age;
        this-> valid = valid ;
    }

    void Login(){
        bool Switch = true;
        while (Switch) {
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            if (username == this-> username && password == this->password){
                cout << "Thanks for login in, we will show you the menu.\n";
                Switch = false;
                valid = true; 
            }
            else if (username != this-> username){
                cout << "Username is not correct. Try again!\n";
            }
            else if (password != this-> password){
                cout << "Password is not correct. Try again!\n";
            }
            }
        }

    void Logout(){
    int log_out;
    bool Switch = true;
    cout << "Log out? (1: Yes // 2: No)";
    cin >> log_out;
    while (Switch) {
        if (log_out == 1) {
            cout << "Log out successful. See you again!." << endl;
            Switch = false;
            this-> valid = false;
        } 
        else if (log_out == 2) {
            this-> valid = true;
            Switch = false;
        } 
        else {
            cout << "Option invalid. Try again!" << endl;
            cin >> log_out;
        }
    }
    }


    void Change_password(){
        string password, new_password;
        int counter = 0;
        bool Switch = true;

        while (Switch){
            if (counter == 0){
            cout << "Enter your password: ";
            cin >> password;
            }else{counter++;}
            if (password == this->password){
                cout << "Enter the new password: ";
                cin >> new_password;
                if (new_password == password){
                    cout << "You cant use your old password as new password." << endl;
                } else {
                    cout << "Password succesfully changed." << endl;
                    this-> password = new_password;
                    Switch = false;
                }
            } 
            else {
                cout << "Wrong password, try again!";
            }
        }    
    }
};


class Client : public User{

    public: 
    Client(string username, string password, string cellphone, int age, bool valid) : 
    User(username, password, cellphone, age, valid) {}

    void Buy(){
        string article;
        int answer;
        bool Switch = true;
        while (Switch){
        cout << "\nArticle you would like to purchase: ";
        cin >> article;
        cout << "The article " << article << "cost $100.00 with free shipping.";
        cout << "\nWould you like to purchase it? 1) Yes   2) No: ";
        cin >> answer;
            if (answer == 1){
                cout << "Congratulations, you have purchased " << article << " for $100.00";
                Switch = false;
                break;
            }
            else if (answer == 2){
                NULL;
            }
            else {
                cout << "Wrong option. Try again!";
            }
        }
    }

    void Complaint(){
        string article, complaint;
        bool Switch = true;
        int answer;
        cout << "\nWelcome to the complaint centre, if you wanna start a complaint follow the menu." << endl;
        while (Switch){
            cout << "1) Start a complaint  2) Cancel a complaint  3) Leave the complaint centre. ";
            cin >> answer;
            switch (answer){
                case 1:
                    cout << "Write the name of your article: ";
                    cin >> article;
                    cout << "Enter the complaint: ";
                    cin >> complaint;
                    cout << "Your complaint has been submited, our team will contact you soon (Complaint number: 09812)";
                    Switch = false;
                    break;
                case 2:
                    cout << "Enter your number of complaint to cancel it: ";
                    cin >> complaint;
                    cout << "Your complaint has been deleted. Thank you!";
                    Switch = false;
                    break;
                case 3: 
                    cout << "You leaved the complaint centre";
                    Switch = false;
                    break;
                default: 
                    cout << "Wrong option. Try again! ";
            }
        }
    }

    void Return_product(){
        string article, reason, order_no;
        bool Switch = true;
        int answer;
        cout << "You reached the quality guaranty program. Follow the steps\n";
        while (Switch){
            cout << "1) Return product  2) Change product:  ";
            cin >> answer;
            switch (answer)
            {
            case 1:
                cout << "\nEnter the number of order: ";
                cin >> order_no;
                cout << "Your order will be refunded between 3-14 days. Thanks!";
                Switch = false;
                break;
            case 2:
                cout << "\nEnter the number of order: ";
                cin >> order_no;
                cout << "You can go to the store to change your product without cost.";
                Switch = false;
                break;
            default:
                cout << "Wrong option. Try again!" << endl;
                break;
            }
        }
    }
};

class Seller : public User {

    public: 
    Seller(string username, string password, string cellphone, int age, bool valid) : 
    User(username, password, cellphone, age, valid) {}

    void Sell(){
        string article;
        float price;
        cout << "\nArticle you would like to sell: ";
        cin >> article;
        cout << "The article " << article << " is approved.";
        cout << "\nEnter the price: ";
        cin >> price;
        cout << "Congratulations, the price of " << article << " will be " << price << " $";
        cout << "\nYour article has been uploaded\n";
    }

    void Inv_Update(int inventory){
        string article;
        int quantity;
        cout << "\nEnter the article you would like to update: ";
        cin >> article;
        cout << "Enter the quantity youll like to add: ";
        cin >> quantity;
        float total = (inventory + quantity);
        cout << "Inventory updated, you now have: " << total << " products of " << article << endl;; 
    }

};


int main (void){
    Client costumer1 = Client("Joe_Trouble", "Pepemadero", "5646319088", 21, false);
    Seller seller1 = Seller("Txus", "RataBlanca", "6129453298", 43, false);
    /* BLOQUE DE PRUEBAS "UNITARIAS" para comprobar que cada metodo de las clases funcionen
       Se puede hacer uso de ellas sacandolas del comentario de bloque.
       NOTA: Mi codigo esta en ingles porque se me facilita mas el entenderlo y no debo hacer
       uso de funciones extra para ponerle acentos :).
       Por motivos de tiempo no pude comentar el codigo adecuadamente (Llegue tarde a mi casa del trabajo.)
       espero no sea inconveniente. 
    //cout << costumer1.username << endl;
    //costumer1.Login();
    //costumer1.Logout();
    //costumer1.Change_password();
    //costumer1.Buy();
    //costumer1.Complaint();
    //costumer1.Return_product();
    //seller1.Login();
    //seller1.Logout();
    //seller1.Sell();
    //seller1.Inv_Update(34);
    */
   bool Switch1 = true, Switch2 = true;
   int login, option;
   while (Switch1){
        cout << "Login as 1) Client  2) Seller : ";
        cin >> login;
        if (login == 1){
            costumer1.Login();
            Switch1 = false;
        }
        else if (login == 2){
            seller1.Login();
            Switch1 = false;
        }
        else {
            cout << "Wrong option. Try again!";
        }
   }
    while (Switch2){
        if (login == 1){
            cout << "\nMenu\n 1) Logout 2) Change password 3) Buy 4) Complaint 5) Return product : ";
            cin >> option;
            switch (option)
            {
            case 1:
                costumer1.Logout();
                Switch2 = false;
                break;
            case 2:
                costumer1.Change_password();
                break;
            case 3:
                costumer1.Buy();
                break;
            case 4:
                costumer1.Complaint();
                break;
            case 5:
                costumer1.Return_product();
                break;
            default:
                cout << "Invalid choice, try again";
            }
        }
        else if (login == 2){
            cout << "\nMenu\n 1) Logout 2)Change password 3) Sell 4) Update Inventory";
            cin >> option;
            switch (option)
            {
            case 1:
                seller1.Logout();
                Switch2 = false;
                break;
            case 2:
                seller1.Change_password();
                break;
            case 3:
                seller1.Sell();
                break;
            case 4:
                seller1.Inv_Update(35);
                break;
            default:
                cout << "Invalid choice, try again";
            }
    
    }
    }
    return 0;
}
