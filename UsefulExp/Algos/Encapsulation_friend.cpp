#include <iostream>
using namespace std;

class Contact
{
    private:
        int mobile_number;           // private variable
        int home_number;             // private variable
    public:
        Contact()                    // constructor
        {
            mobile_number = 12345678;
            home_number = 87654321;
        }
        // Declaring a global 'friend' function
        friend void print_numbers( Contact some_contact );
};

void print_numbers( Contact some_contact )
{
    cout << "Mobile number: " << some_contact.mobile_number;
    cout << ", home number: " << some_contact.home_number << endl;
}

int main()
{
    Contact Tony;
    print_numbers(Tony);
    return 0;
}
