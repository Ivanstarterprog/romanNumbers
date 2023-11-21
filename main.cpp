/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 2                                *
* Ссылка - https://onlinegdb.com/C4ravT3fs  *
********************************************/

#include <iostream>
#include <string>

using namespace std;

string convertToRoman(int number) {
    string rimNumber = "";
    while (number != 0) {
        if (number >= 1000) {
            number -= 1000;
            rimNumber += "M";
        } else if (number >= 500) {
            if (number < 900) {
                rimNumber += "D";
                number -= 500;
            } else {
                rimNumber += "CM";
                number -= 900;
            }
            
        } else if (number >= 100) {
            if (number < 400) {
                rimNumber += "C";
                number -= 100;
            }
            else {
                rimNumber += "CD";
                number -= 400;
            }
        } else if (number >= 50) {
            if (number < 90) {
               rimNumber += "L";
               number -= 50;
            }
            else {
                rimNumber = "XC";
                number -= 90;
            }
        } else if (number >= 10) {
            if (number < 40) {
                rimNumber += "X";
                number -= 10;
            }
            else {
                rimNumber += "LX";
                number -= 9;
            }
        }
        else if (number >= 1) {
            if (number < 5) {
                rimNumber += "I";
                number -= 1;
            }
            else {
                rimNumber += "V";
                number -= 5;
            }
            
        }
    }
    return rimNumber;
}

int main()
{   
    int arabicNumber;
    cout << "Введите число: ";
    cin >> arabicNumber;
    string rimNumber = convertToRoman(arabicNumber);
    cout << "Число, переведённое в римский формат: " << rimNumber;
}
