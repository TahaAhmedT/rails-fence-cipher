/*
author: taha ahmed.
date: 22/3/2022.
version: 3.0.
this program do the rails-fence cipher using two funcion:
1- do the encryption.
2- do the decryption.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

void encryption()
{
    string message, letters = "";
    cout << "enter the text to encrypte it: " << endl;
    getline(cin, message);
    

    message.erase(remove(message.begin(), message.end(), ' '), message.end()); //build in function that remove spaces from string.

    cout << "enter the number of rails " << endl; //input the number of rails.
    int rails;
    cin >> rails;
    char matrix[rails][message.length()]; //matrix that will contain the characters.

    for (int i = 0; i < rails; i++)//fill the matrix with ".".
    {
        for (int j = 0; j < message.length(); j++)
        {
            matrix[i][j] = '.';
        }
    }

    int row = 0, condition = 0;
    for (int i = 0; i < message.length(); i++) //put the characters in the zig-zag shape.
    {
        if (condition == 0)
        {
            matrix[row][i] = message[i];
            row++;
            if (row == rails)
            {
                condition = 1;
                row--;
            }
        }
        else if (condition == 1)
        {
            row--;
            matrix[row][i] = message[i];

            if (row == 0)
            {
                condition = 0;
                row = 1;
            }

        }
    }
    for (int i = 0; i < rails; i++)// for loop to print the matrix.
    {
        for (int j = 0; j < message.length(); j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < rails; i++) //nested for loop to put all element that found in matrix in array letters.
    {
        for (int j = 0; j < message.length(); j++)
        {
            letters += matrix[i][j];
        }
    }
    // delete "." from array letters using build in function from the class regex.
    letters.erase(remove(letters.begin(), letters.end(), '.'), letters.end());
    cout << "the encrypred text is: " << letters << endl;



    
    

}

void decryption()
{
    string message, letters = "";
    cout << "enter the text to decrypte it: " << endl;
    getline(cin, message);

    message.erase(remove(message.begin(), message.end(), ' '), message.end()); //build-in function that remove spaces from string.

    cout << "enter the number of rails " << endl; //input the number of rails.
    int rails;
    cin >> rails;
    char matrix[rails][message.length()]; //matrix that will contain the characters.

    for (int i = 0; i < rails; i++)//fill the matrix with ".".
    {
        for (int j = 0; j < message.length(); j++)
        {
            matrix[i][j] = '.';
        }
    }

    int row = 0, condition = 0;
    for (int i = 0; i < message.length(); i++) //put the characters in the zig-zag shape.
    {
        if (condition == 0)
        {
            matrix[row][i] = message[i];
            row++;
            if (row == rails)
            {
                condition = 1;
                row--;
            }
        }
        else if (condition == 1)
        {
            row--;
            matrix[row][i] = message[i];

            if (row == 0)
            {
                condition = 0;
                row = 1;
            }

        }
    }
    for (int i = 0; i < rails; i++)// for loop to print the matrix.
    {
        for (int j = 0; j < message.length(); j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < rails; i++) //nested for loop to put all element that found in matrix in array letters.
    {
        for (int j = 0; j < message.length(); j++)
        {
            letters += matrix[i][j];
        }
    }
    // delete "." from array letters using build in function from the class algorithm.
    letters.erase(remove(letters.begin(), letters.end(), '.'), letters.end());
    cout << "the decrypred text is: " << letters << endl;

}
    

    
int main()
{
    cout << "enter 1 for encryption \n enter 2 for decryption \n" ; // ask user if he want to do encryption or decryption.
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) // if user enter 1, will do the encryption.
    {
      encryption();  
    }
    else if (choice == 2) // if user enter 2, will do the decryption.
    {
        decryption();
    }
    else // if user enter any thing else, it is a valid input.
    cout << "this is invalid input. " << endl;
       
}
