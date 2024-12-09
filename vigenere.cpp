#include <iostream>
#include <string>
using namespace std;

// Function declarations
void toCap(string &text);
string createKey(const string &text, const string &keyword);
string encrypt(const string &plaintext, const string &key);
string decrypt(const string &ciphertext, const string &key);

int main()
{
    string choice; // var for user choice of encryption or decryption mode

    // loop until the user enters a valid choice
    while (true)
    {
        cout << "Would you like to encrypt or decrypt?\n(Type 'E' to encrypt"
                "or 'D' to decrypt): "; // prompt
        cin >> choice; // take user input

        // convert choice to caps for case-insensitivity
        for (char &c : choice)
        {
            c = toupper(c); // convert to uppercase
        }

        if (choice == "E" || choice == "D") // if user input E or D
        {
            break; // valid input, break loop
        }
        else // if not E or D
        {
            cout << "Invalid choice. Please type 'E' or 'D'." << endl;
            // invalid input, repeat loop
        }
    }

    if (choice == "E") // if user input was E
    {
        string plaintext, keyword; // vars for plaintext string and keyword
        cout << "Enter plaintext: "; // prompt for plaintext string
        cin >> plaintext; // take user input
        cout << "Enter keyword: "; // prompt for keyword
        cin >> keyword; // take user input

        // passes values to toCap to convert inputs to uppercase
        toCap(plaintext);
        toCap(keyword);

        string key = createKey(plaintext, keyword); // creates key with same
            // length as the inputted plaintext
        string ciphertext = encrypt(plaintext, key); // creates encrypted text
        cout << "Ciphertext: " << ciphertext << endl; // output encrypted text
    } 
    else if (choice == "D") // if user input was D
    {
        string ciphertext, keyword; // vars for encrypted text and keyword
        cout << "Enter ciphertext: "; // prompt to input encrypted text
        cin >> ciphertext; // take user input
        cout << "Enter keyword: "; // prompt for keyword
        cin >> keyword; // take user input

        // passes values to toCap to convert inputs to uppercase
        toCap(ciphertext);
        toCap(keyword);

        string key = createKey(ciphertext, keyword); // creates key with same
            // length as inputted ciphertext
        string plaintext = decrypt(ciphertext, key); // creates decrypted text
        cout << "Decrypted text: " << plaintext << endl; // output decrypted text
    }

    return 0; // hooray done! (yippeeEEEEE)
}

// function to convert string to uppercase
void toCap(string &text)
{
    for (char &c : text) // cycles through each letter
    {
        c = toupper(c); // converts each letter to uppercase
    }
}

// function to generate the fitted key
string createKey(const string &text, const string &keyword)
{
    string key = keyword; // start with the given keyword
    while (key.size() < text.size()) // makes length of key the same as string
    {
        key += keyword; // repeat keyword to match length of text
    }
    return key.substr(0, text.size()); // cut off excess to fit text length
}

// function to encrypt the plaintext
string encrypt(const string &plaintext, const string &key)
{
    string ciphertext; // var for the resulting encrypted text
    for (size_t i = 0; i < plaintext.size(); i++) // cycles through text chars
    {
        char enChar = ((plaintext[i] - 'A') + (key[i] - 'A')) % 26 + 'A'; 
            // shifts plaintext letter by key letter and wraps within alphabet
        ciphertext += enChar; // appends encrypted char to ciphertext
    }
    return ciphertext; // returns encrypted text
}

// function to decrypt the ciphertext
string decrypt(const string &ciphertext, const string &key)
{
    string plaintext; // var for the resulting decrypted text
    for (size_t i = 0; i < ciphertext.size(); i++) // cycles through text chars
    {
        char deChar = ((ciphertext[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A'; 
            // shifts cipher letter backwards by key letter and wraps within alphabet
        plaintext += deChar; // appends decrypted char to plaintext
    }
    return plaintext; // returns decrypted text
}
