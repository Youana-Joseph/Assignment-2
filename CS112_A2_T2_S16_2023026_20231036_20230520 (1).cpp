#include <iostream>
#include <string.h>
#include <stdbool.h>
#include <limits>

using namespace std;

// File    : CS112_A2_T2_S16_20231036_20230520_20230269
// Authors : Omar Hani Tohami Ismail / S16 / 20230269
//         : Passant Shaaban / S16 / 20231036
//         : Youana Joseph / S16 / 20230520
// Omar Hani Tohami made Rail-Fence cipher.
// Passant Shaaban made Polybius cipher.
// Youana Joseph made Affine cipher.

// Define the function of Encryption of affine cipher


void Affine_encryption(int a, int b, int c) {
    string message, ciphered_text;
    cout << "Please enter the message you want to cipher: ";
    cin.ignore(); // to act of emptying the buffer and discarding any data it contains
    getline(cin, message);

    // Loop over each character in the message
    for (char i : message) {
        if (isalpha(i) || i == ' ') {
            if (!isdigit(i)) {
                if (isalnum(i)) {
                    i = toupper(i);
                    int x = i - 'A'; // using ASCII code to make each character equivalent to a specific number
                    int calculations = (a * x + b) % 26;
                    ciphered_text += (char)(calculations + 'A'); // Convert calculations result to a character
                } else {
                    ciphered_text += i; // For non-alphabetic characters, like spaces
                }
            }
        }
    }
    cout << "Ciphered message: " << ciphered_text << endl;
}
// Define the function of Decryption of affine cipher

void Affine_decryption(int a, int b, int c) {
    string message, decipher_text;
    cout << "Please enter the message you want to decipher: ";
    cin.ignore(); // to act of emptying the buffer and discarding any data it contains
    getline(cin, message);

    // Loop over each character in the message
    for (char i : message) {
        if (isalpha(i) || i == ' ') {
            if (!isdigit(i)) {
                if (isalnum(i)) {
                    i = toupper(i);
                    int y = i - 'A'; // using ASCII code to make each character equivalent to a specific number
                    int calculations = c * (y - b + 26) % 26;
                    decipher_text += (char)(calculations + 'A'); // Convert calculations result to a character
                } else {
                    decipher_text += i; // For non-alphabetic characters, like spaces
                }
            }
        }
    }

    cout << "Deciphered message: " << decipher_text << endl;
}

// Define the function of Encryption with key = 3.(Rail_Fence)
void Encryption(string text){
    // A holder to hold our encrypted text.
    string holder = "";
    // Get the length of the message.
    int length = text.length();
    // A loop for the first row.
    for(int i = 0; i < length; i = i + 4){
        holder += text[i];
    }
    // A loop for the second row.
    for(int i = 1; i < length; i = i + 2){
        holder += text[i];
    }
    // A loop for the third row.
    for(int i = 2; i < length; i = i +4){
        holder += text[i];
    }
    // Convert the plaintext to encrypted text.
    text = holder;
    // Print to the user his encrypted text
    cout << "Encrypted message: " << holder;
    cout << endl;
}

// Define function of encryption.(Polybius)
int ciphered()
{
    // Arrays to store row and column keys
    int row_key[5] , col_key[5] ;
    cout <<"Please enter your row key: " <<endl;
    int i ;
    // A loop to get the ciphered row
    for(i=0 ; i < 5 ; i++)
    {
        cin >> row_key[i] ;
    }
    cout <<"Please enter you column key: " <<endl ;
    int j ;
    // A loop to get the ciphered column
    for(j=0 ; j < 5 ; j++)
    {
        cin >> col_key[j] ;
    }

    cout <<"Please enter the plain message: " <<endl ;
    string message ;
    // Clear the input buffer
    cin.ignore();
    getline(cin , message);
    // String to store the ciphered message
    string ciphered_message = "" ;
    // Encryption loop
    for(char m : message)
    {
        // Check if the character is an alphabet letter
        if ( isalpha(m) )
        {
            // Convert to the uppercase
            m = toupper(m) ;
            // Mapping each letter to its corresponding row and column key
            if(m =='A')
            {
                ciphered_message += to_string(row_key[0]) + to_string(col_key[0]) ;
            }else if(m =='B')
            {
                ciphered_message += to_string(row_key[0]) + to_string(col_key[1]) ;
            }else if(m =='C')
            {
                ciphered_message += to_string(row_key[0]) + to_string(col_key[2]) ;
            }else if(m =='D')
            {
                ciphered_message += to_string(row_key[0]) + to_string(col_key[3]) ;
            }else if(m =='E')
            {
                ciphered_message += to_string(row_key[0]) + to_string(col_key[4]) ;
            }else if(m =='F')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[0]) ;
            }else if(m =='G')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[1]) ;
            }else if(m =='H')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[2]) ;
            }else if(m =='I')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[3]) ;
            }else if(m =='J')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[3]) ;
            }else if(m =='K')
            {
                ciphered_message += to_string(row_key[1]) + to_string(col_key[4]) ;
            }else if(m =='L')
            {
                ciphered_message += to_string(row_key[2]) + to_string(col_key[0]) ;
            }else if(m =='M')
            {
                ciphered_message += to_string(row_key[2]) + to_string(col_key[1]) ;
            }else if(m =='N')
            {
                ciphered_message += to_string(row_key[2]) + to_string(col_key[2]) ;
            }else if(m =='O')
            {
                ciphered_message += to_string(row_key[2]) + to_string(col_key[3]) ;
            }else if(m =='P')
            {
                ciphered_message += to_string(row_key[2]) + to_string(col_key[4]) ;
            }else if(m =='Q')
            {
                ciphered_message += to_string(row_key[3]) + to_string(col_key[0]) ;
            }else if(m =='R')
            {
                ciphered_message += to_string(row_key[3]) + to_string(col_key[1]) ;
            }else if(m =='S')
            {
                ciphered_message += to_string(row_key[3]) + to_string(col_key[2]) ;
            }else if(m =='T')
            {
                ciphered_message += to_string(row_key[3]) + to_string(col_key[3]) ;
            }else if(m =='U')
            {
                ciphered_message += to_string(row_key[3]) + to_string(col_key[4]) ;
            }else if(m =='V')
            {
                ciphered_message += to_string(row_key[4]) + to_string(col_key[0]) ;
            }else if(m =='W')
            {
                ciphered_message += to_string(row_key[4]) + to_string(col_key[1]) ;
            }else if(m =='X')
            {
                ciphered_message += to_string(row_key[4]) + to_string(col_key[2]) ;
            }else if(m =='Y')
            {
                ciphered_message += to_string(row_key[4]) + to_string(col_key[3]) ;
            }else if(m =='Z')
            {
                ciphered_message += to_string(row_key[4]) + to_string(col_key[4]) ;
            }
        }else
        {
            // Retain non-alphabetic characters
            ciphered_message += m ;
            continue;
        }
    }
    // Display the ciphered message
    cout <<"Ciphered message is: " << ciphered_message ;
    cout << endl;
    return 0 ;
}

// Define the function of decryption with key = 3.(Rail-Fence)
void Decryption(string cipher)
{
	// create the matrix to cipher plain text.
	// key = 3 , length(text) = columns.
	char rail[3][cipher.length()];
	// filling the rail matrix to distinguish filled spaces from blank ones.
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < cipher.length(); j++)
			rail[i][j] = '\n';
	// to find the direction.
	bool dir_down;
	int row = 0, col = 0;
	// mark the places with '*'.
	for (int i = 0; i < cipher.length(); i++)
	{
		// check the direction of flow.
		if (row == 0)
			dir_down = true;
		if (row == 2)
			dir_down = false;
		// place the marker.
		rail[row][col++] = '*';
		// find the next row using direction flag.
		dir_down?row++ : row--;
	}
	// now we can construct the fill the rail matrix.
	int index = 0;
	for (int i = 0; i < 3; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];
	// now read the matrix in zig-zag manner to construct the resultant text.
	string result;
	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		// check the direction of flow.
		if (row == 0)
			dir_down = true;
		if (row == 2)
			dir_down = false;
		// place the marker.
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);
		// find the next row using direction flag.
		dir_down?row++: row--;
	}
	cout << "Decrypted message: " << result;
    cout << endl;
}

// Define function of decryption.(Polybius)
int Deciphered()
{
    // Arrays to store the row and column keys
    int row_key[5] , col_key[5] ;
    cout <<"Please enter your row key: " <<endl;
    int i ;
    // A loop to get the deciphered row
    for(i=0 ; i < 5 ; i++)
    {
        cin >> row_key[i] ;
    }
    cout <<"Please enter you column key: " <<endl ;
    int j ;
    // A loop to get the deciphered column
    for(j=0 ; j < 5 ; j++)
    {
        cin >> col_key[j] ;
    }
    cout<< "Enter the ciphered message: " <<endl ;
    string message2;
    // Clear the input buffer
    cin.ignore();
    getline(cin,message2) ;
    // String to store the deciphered message
    string deciphered_message = "" ;
    // Decryption loop
    for(int x=0 ; x < message2.length() ; x+=2 )
    {
        // Extract a pair of digits from the ciphered message
        string pair = message2.substr(x,2) ;
        // Mapping each pair of digits to its corresponding letter
        if (pair == to_string(row_key[0]) + to_string(col_key[0]))
        {
            deciphered_message+= 'a';
        }else if (pair == to_string(row_key[0]) + to_string(col_key[1]))
        {
            deciphered_message+= 'b';

        }else if (pair == to_string(row_key[0]) + to_string(col_key[2]))
        {
            deciphered_message+= 'c';

        }else if (pair == to_string(row_key[0]) + to_string(col_key[3]))
        {
            deciphered_message+= 'd';

        }else if (pair == to_string(row_key[0]) + to_string(col_key[4]))
        {
            deciphered_message+= 'e';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[0]))
        {
            deciphered_message+= 'f';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[1]))
        {
            deciphered_message+= 'g';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[2]))
        {
            deciphered_message+= 'h';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[3]))
        {
            deciphered_message+= 'i';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[3]))
        {
            deciphered_message+= 'j';

        }else if (pair == to_string(row_key[1]) + to_string(col_key[4]))
        {
            deciphered_message+= 'k';

        }else if (pair == to_string(row_key[2]) + to_string(col_key[0]))
        {
            deciphered_message+= 'l';

        }else if (pair == to_string(row_key[2]) + to_string(col_key[1]))
        {
            deciphered_message+= 'm';

        }else if (pair == to_string(row_key[2]) + to_string(col_key[2]))
        {
            deciphered_message+= 'n';

        }else if (pair == to_string(row_key[2]) + to_string(col_key[3]))
        {
            deciphered_message+= 'o';

        }else if (pair == to_string(row_key[2]) + to_string(col_key[4]))
        {
            deciphered_message+= 'p';

        }else if (pair == to_string(row_key[3]) + to_string(col_key[0]))
        {
            deciphered_message+= 'q';

        }else if (pair == to_string(row_key[3]) + to_string(col_key[1]))
        {
            deciphered_message+= 'r';

        }else if (pair == to_string(row_key[3]) + to_string(col_key[2]))
        {
            deciphered_message+= 's';

        }else if (pair == to_string(row_key[3]) + to_string(col_key[3]))
        {
            deciphered_message+= 't';

        }else if (pair == to_string(row_key[3]) + to_string(col_key[4]))
        {
            deciphered_message+= 'u';

        }else if (pair == to_string(row_key[4]) + to_string(col_key[0]))
        {
            deciphered_message+= 'v';

        }else if (pair == to_string(row_key[4]) + to_string(col_key[1]))
        {
            deciphered_message+= 'w';

        }else if (pair == to_string(row_key[4]) + to_string(col_key[2]))
        {
            deciphered_message+= 'x';

        }else if (pair == to_string(row_key[4]) + to_string(col_key[3]))
        {
            deciphered_message+= 'y';

        }else if (pair == to_string(row_key[4]) + to_string(col_key[4]))
        {
            deciphered_message+= 'z';

        }else
        {
            // If the pair doesn't match any mapping, consider it as a space
            deciphered_message+=" ";
            x-=1 ;
        }
    }
    // Display the ciphered message
    cout << "Deciphered message is: " << deciphered_message ;
    cout << endl;
    return 0 ;
}

// Define outer menu.
void outerMenu(){
    cout << "1- Cipher a message \n";
    cout << "2- Decipher a message \n";
    cout << "3- End \n";
}

// Define inner menu.
void innerMenu(){
    cout << "1- Rail-Fence cipher \n";
    cout << "2- Affine cipher \n";
    cout << "3- Polybius cipher \n";
    cout << "4- Return \n";
}

// Define a function to check the validty of the input at the outer menu.
int getValidInput1(){
    int choice1;
    while(true) {
        // Get user's choice.
        cout << "Enter your choice: ";
        cin >> choice1;
        // check the validty of the choice.
        if(cin.good() && choice1 >= 1 && choice1 <= 3) {
            return choice1;
        }
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter an valid option." << endl;
    }
}

// Define a function to check the validty of the input at the inner menu.
int getValidInput2(){
    int choice2;
    while(true) {
        // Get user's choice.
        cout << "Enter your choice: ";
        cin >> choice2;
        // check the validty of the choice.
        if(cin.good() && choice2 >= 1 && choice2 <= 4) {
            return choice2;
        }
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter an valid option." << endl;
    }
}

// Main Function.
int main(){
    int choice1, choice2, a, b, c;
    do
    {
        // Display our menu.
        outerMenu();
        choice1 = getValidInput1();
        // Ignore newline character after reading choice
        cin.ignore();
        switch(choice1){
            case 1:{
                // Display our menu.
                innerMenu();
                choice2 = getValidInput2();
                // Ignore newline character after reading choice
                cin.ignore();
                switch(choice2){
                    case 1:{
                        // declare our variable.
                        string plain_text;
                        // print message for user.
                        cout << "Enter a message to cipher: ";
                        // getline function to make user enter large string.
                        getline(cin, plain_text);
                        // calling function of encryption.
                        Encryption(plain_text);
                        break;
                    }
                    case 2:{
                        cout << "Please enter the parameters to cipher the message according to this equation: (a * x + b) % 26\n";
                        cout << "Enter value for 'a': ";
                        while (!(cin >> a) || a <= 0) { //to check if 'a' is a positive integer
                            cout << "Invalid input. Please enter a positive integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        cout << "Enter value for 'b': ";
                        while (!(cin >> b) || b <= 0) { //to check if 'b' is a positive integer
                            cout << "Invalid input. Please enter a positive integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                        cout << "Enter value for 'c' such that (a * c) % 26 = 1: ";
                        while (!(cin >> c) || c <= 0 || (a * c) % 26 != 1) {
                            cout << "Invalid input. Please enter a positive integer that satisfies the condition: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        Affine_encryption(a, b, c);
                        break;
                    }
                    case 3:{
                        ciphered();
                        break;
                    }
                    case 4:{
                        break;
                    }
                }
                break;
            }
            case 2:{
                // Display our menu.
                innerMenu();
                choice2 = getValidInput2();
                // Ignore newline character after reading choice
                cin.ignore();
                switch(choice2){
                    case 1:{
                        // declare our variable.
                        string cipher_text;
                        // print message for user.
                        cout << "Enter a message to decipher: ";
                        // getline function to make user enter large string.
                        getline(cin, cipher_text);
                        // calling function of encryption.
                        Decryption(cipher_text);
                        break;
                    }
                    case 2:{

                            cout << "Please enter the parameters to cipher the message according to this equation: (a * x + b) % 26\n";
                        cout << "Enter value for 'a': ";
                        while (!(cin >> a) || a <= 0) { //to check if 'a' is a positive integer
                            cout << "Invalid input. Please enter a positive integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        cout << "Enter value for 'b': ";
                        while (!(cin >> b) || b <= 0) { //to check if 'b' is a positive integer
                            cout << "Invalid input. Please enter a positive integer: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                        cout << "Enter value for 'c' such that (a * c) % 26 = 1: ";
                        while (!(cin >> c) || c <= 0 || (a * c) % 26 != 1) {
                            cout << "Invalid input. Please enter a positive integer that satisfies the condition: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        Affine_decryption(a, b, c);
                        break;
                    }
                    case 3:{
                        Deciphered();
                        break;
                    }
                    case 4:{
                        break;
                    }
                }
                break;
            }
            case 3:{
                cout << "GoodBye!\n";
                break;
            }
        }
    } while (choice1 != 3);
    return 0;
}
