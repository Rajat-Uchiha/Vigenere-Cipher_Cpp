#include <iostream>
#include <unordered_map>
#include <strings.h>
#include <math.h>
using namespace std;

void Encryption(unordered_map<int, char> mp)
{
    string plainText = "";
    string Key = "";
    cout << "Enter your Plain text in lowercase: ";
    cin >> plainText;

    cout << "Enter a Key in lowercase: ";
    cin >> Key;

    int i = 0;
    while (Key.length() < plainText.length())
    {
        Key += Key[i];
        i++;
    }
    string cipherText = "";
    int c = 0;
    while (cipherText.length() != plainText.length())
    {
        cipherText += mp[((plainText[c] - 'a') + (Key[c] - 'a')) % 26];
        c++;
    }
    cout << "Your Cipher Text is Here: " << cipherText << endl;
}

void Decryption(unordered_map<int, char> mp)
{
    string cipherText = "";
    string Key = "";
    string plainText = "";
    cout << "Enter the Cipher Text in lowercase: ";
    cin >> cipherText;
    cout << "Enter the Key in lowercase: ";
    cin >> Key;
    int i = 0;
    while (Key.length() < cipherText.length())
    {
        Key += Key[i];
        i++;
    }
    int c = 0;
    while (plainText.length() != cipherText.length())
    {

        plainText += mp[((cipherText[c] - 'a') - (Key[c] - 'a') + 26) % 26];
        c++;
    }
    cout << "Your Plain Text is Here: " << plainText << endl;
}

int main()
{
    //! Setting up the things
    unordered_map<int, char> mp;
    char ch = 'a';
    for (int i = 0; i < 26; i++)
    {
        mp[i] = ch++;
    }

    cout << "HELLO WORLD!" << endl;
    cout << "CHOOSE YOUR OPTION:-" << endl;
    cout << "1 - FOR ENCRYPTION" << endl;
    cout << "2 - FOR DECRYPTION" << endl;
    cout << "3 - EXIT " << endl;

    cout << endl
         << "NOTE :- THE KEY SHOULD BE SAVE WHILE ENCRYPTION AND DECRYPTION AND THE INPUT SHOULD BE WITHOUT SPACES" << endl;

    while (true)
    {
        cout << endl;
        int choice;
        cout << "YOUR CHOICE " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Encryption(mp);
            break;

        case 2:
            Decryption(mp);

        default:
            break;
        }
        if (choice == 3)

            break;
    }

    return 0;
}
