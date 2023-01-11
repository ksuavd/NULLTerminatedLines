// NULLTerminatedLines

#include <iostream>
#include <windows.h>

using namespace std;
int  string_length (const char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
int main()
{
    setlocale(LC_ALL, "rus");
    /* char str[] = {'H','e','l','l','o',0};
     char str[] = "Hello";
     cout << str << endl;
     cout << sizeof(str) << endl;//размер 6 байт (5 букв + 0 NULLTerminater) */
    /*for (int i = 0; i < 256; i++)
    {
        cout << i << "\t" << char(i) << endl;
    }
*/
    const int n = 200;
    char str[n] = {};
    cout << "Введите строку: ";
    SetConsoleCP(1251);//переводим кодировку на русский для ввода
    //cin >> str;
    cin.getline(str, n);
    //  SetConsoleCP(866);//возвращем кодировку (не везде необходимо, в каких то версиях винд. автоматически возвращает и можно не прописывать)
    cout << "Строка -" << str << "- состоит из " << strlen (str) << " символов." << endl;
    cout << "Строка -" << str << "- в верхнем регистре: "; to_upper(str); cout << str << endl;
    cout << "Строка -" << str << "- в нижнем регистре: "; to_lower(str); cout << str << endl;
    cout << "Введите строку: "; cin.getline(str, n); cout << "Удаляем лишние пробелы: "; shrink(str); cout << str << endl;
    cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "палиндром!" << endl;
}

int  string_length(const char str[])
{
    /* int counter = 0; // счетчик символов
    while (str[counter] != '\0')// перебираем массив когла доходим до ячйки которая хранит 0 останавливаем цикл увеличиваем счетчик
    {
        counter++;
    }
    return counter;
     */
    int i = 0;
    for (; str[i]; i++);
    return i;
}
void to_upper(char str[])
{
    for (int i = 0; str[i]; i++)
    {/*
       if (str[i] >= 'а' && str[i] <= 'я')
        {
            str[i] += 'А' - 'а';
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += 'A' - 'a';
        }
        */
        str[i] = toupper(str[i]);
    }
}
void to_lower(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        str[i] =tolower (str[i]);
    }
}

void shrink(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        while(str[i] == ' '&&str[i+1]==' ')
        {
            for (int j=i+1; str[j]; j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
}
void remove_symbol(char str[], char symbol)
{
    for (int i = 0; str[i]; i++)
    {
        while (str[i]==symbol)
        {
            for (int j = i; str[j]; j++)str[j] = str[j + 1];
        }
    }
}
bool is_palindrome(char str[])
{
    to_lower(str);
    remove_symbol(str, ' ');
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])return false;
     }
    return true;
}