#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <list>
using namespace std;



string encode(long LSize, long* Key, string str1)
{
    long i, j;
    string str2, encstr;

    while (str1.length() % 5 != 0) {
        str1 += ' ';
    }

    for (i = 0; i < str1.length(); i++) {
        str2 = " ";
        for (j = 0; j < LSize; j++) {
            str2 += str1[i + j];
        }
        for (j = 0; j < LSize; j++) {
            encstr += str2[Key[j]];
        }
        i += LSize - 1;
    }
    return encstr;
}

string decode(long LSize, long* Key, string encText)
{
    //long ReverseKey[5] = { 4,3,0,1,2 };
    long i, j;
    string decstr;
    decstr = encText;
    for (i = 0; i < encText.length(); i += LSize)
    {
        for (j = 0; j < LSize; j++)
        {
            decstr[i + (Key[j] - 1)] = encText[i + j];
        }

    }
    return decstr;

}

void main()
{
    setlocale(LC_ALL, "Russian");
    string encText, decText;
    string str1{ "Здравствуйте, меня зовут Гайнетдинов Эдгар, Я студент Уфимского университета науки и технологий, группы ПРО-331Б." };

    cout << str1 << endl;

    //Ключ шифрования
    long Key[5] = { 5,4,1,2,3 };

    //Длина ключа
    long LSize = sizeof(Key) / sizeof(Key[0]);


    //Вывод зашифрованного текста
    encText = encode(LSize, Key, str1);
    cout << encText << "|" << endl;

    //Вывод дешифрованного текста
    decText = decode(LSize, Key, encText);
    cout << decText << "|" << endl;


}

