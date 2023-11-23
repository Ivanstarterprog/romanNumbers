/********************************************
* Автор - Нургазин И.В                      *
* Блок - 4                                  *
* Задача - 2                                *
* Ссылка - https://onlinegdb.com/ob1pHB5h0  *
********************************************/

#include <iostream>
#include <string>
#include <map>

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
                rimNumber += "XL";
                number -= 40;
            }
        }
        else if (number >= 1) {
            if (number < 4) {
                rimNumber += "I";
                number -= 1;
            }
            else if (number > 6) {
                rimNumber += "VI";
                number -= 6;
            }
            else if (number == 9) {
                rimNumber += "IX";
                number -= 9;
            }
            else if (number == 5) {
                rimNumber += "V";
                number -= 5;
            }
            else if (number == 4){
                rimNumber += "I";
                number -= 1;
            }
            
        }
    }
    return rimNumber;
}

int convertToArabic(string rimNumber) {
    int arabNumber = 0;
    for (int letter = 0; letter < rimNumber.size(); ++letter) {
        if (rimNumber[letter] == 'M') {
            arabNumber += 1000;
        }
        else if (rimNumber[letter] == 'C') {
            if (rimNumber[letter + 1] == 'M') {
                arabNumber += 900;
                letter += 1;
            }
            else if (rimNumber[letter + 1] == 'D') {
                arabNumber += 400;
                letter += 1;
            }
            else {
                arabNumber += 100;
            }
        }
        else if (rimNumber[letter] == 'D') {
            if (rimNumber[letter + 1] == 'C') {
                arabNumber += 600;
                letter += 1;
            }
            else {
                arabNumber += 500;
            }
        }
        else if (rimNumber[letter] == 'X') {
            if (rimNumber[letter + 1] == 'C') {
                arabNumber += 90;
                letter += 1;
            }
            else if (rimNumber[letter + 1] == 'L') {
                arabNumber += 40;
                letter += 1;
            }
            else {
                arabNumber += 10;
            }

        }
        else if (rimNumber[letter] == 'L') {
            if (rimNumber[letter + 1] == 'X') {
                arabNumber += 60;
                letter += 1;
            }
            else {
                arabNumber += 50;
            }
        }
        else if (rimNumber[letter] == 'I') {
            if (rimNumber[letter + 1] == 'V') {
                arabNumber += 4;
                letter += 1;
            }
            else if (rimNumber[letter + 1] == 'X') {
                arabNumber += 9;
                letter += 1;
            }
            else {
                arabNumber += 1;
            }
        }
        else if (rimNumber[letter] == 'V') {
            if (rimNumber[letter + 1] == 'I') {
                arabNumber += 6;
                letter += 1;
            }
            else {
                arabNumber += 5;
            }
        }
    }
    return arabNumber;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arabicNumber;
    string rimNumber;
    int choice;
    while (true) {
        cout << "Введите 1, если нужно перевести из Арабских цифр в Римские" << endl;
        cout << "Введите 2, если нужно перевести из Римские цифр в Арабских" << endl;
        cout << "Введите 3 чтобы закрыть программу" << endl;
        cout << "Ввести: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Введите число: ";
                cin >> arabicNumber;
                rimNumber = convertToRoman(arabicNumber);
                cout << "Ответ: " << rimNumber << endl;
                break;
            case 2:
                cout << "Введите число: ";
                cin >> rimNumber;
                arabicNumber = convertToArabic(rimNumber);
                cout << "Ответ: " << arabicNumber << endl;
                break;
            case 3:
                cout << "Пока" << endl;
                return 0;
            default:
                cout << "Не понимаю, попробуйте ещё раз" << endl;
                break;
        }
    }
}

