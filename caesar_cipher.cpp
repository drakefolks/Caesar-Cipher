#include<iostream>

using namespace std;

class ceasar_cipher
{
private:
string encodedText;
string encoding(string, int);

public:
void cipherTime();
string getEncodedText()
{
    return encodedText;
}
};

void ceasar_cipher::cipherTime()
{
    int shiftnum;
    string text;

    cout << "Please enter your string that you want encoded\n";
    getline(cin, text);

    cout << "Please enter your ceasar shift number\n";
    cin >> shiftnum;

    //passing clear text to encoding function
    encodedText = encoding(text, shiftnum);

    cout << "Ciphered String:\n" << encodedText << endl;
}

string ceasar_cipher::encoding(string clearText, int ciphernum)
{
    string encodedString;
    int i = 0;

    while(clearText[i] != '\0')
    {
        cout << "Converting " << clearText[i] << " to ASCII" << endl;

        //converting char to ASCII value via static cast
        int ASCII = int(clearText[i]);
        cout << "ASCII value: " << ASCII << endl;
        
        //adding ciphernum to temp ASCII value
        ASCII += ciphernum;
        
        //using ASCII characters 33-126
        if (ASCII > 126)
        {
            string element;            
            ASCII -= 126; //outside of ASCII range, finding differnece
            ASCII += 32; //adding differnece to start of ASCII
            element = char(ASCII); //casting to char and storing to string
            encodedString.append(element);
        }

        //converting ASCII back to char and appending to string
        else
        {
            string element;
            element = char(ASCII);
            encodedString.append(element);
        }
        i++; 
    }

    return encodedString;
}

int main()
{
    string encodedText;
    
    ceasar_cipher cipher;
    cipher.cipherTime();
}