// NULLTerminatedLines

#include <iostream>
#include <windows.h>

using namespace std;
int  string_length (char str[]);
void to_upper(char str[]);
void shrink(char str[]);
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
    //const int z = 200;
    //char str_a[z] = {};
    cout << "Введите строку: ";
    SetConsoleCP(1251);//переводим кодировку на русский для ввода
    //cin >> str;
    cin.getline(str, n);
    //  SetConsoleCP(866);//возвращем кодировку (не везде необходимо, в каких то версиях винд. автоматически возвращает и можно не прописывать)
    cout << "Строка -" << str << "- состоит из " << string_length (str) << " символов." << endl;
    cout << "Строка -" << str << "- в верхнем регистре: "; to_upper(str); cout << str << endl;
    cout << "Введите строку: "; cin.getline(str, n); cout<< "Удаляем лишние пробелы: " << endl;
}

int  string_length(char str[])
{
    int counter = 0; // счетчик символов
    while (str[counter] != '\0')// перебираем массив когла доходим до ячйки которая хранит 0 останавливаем цикл увеличиваем счетчик
    {
        counter++;
    }
    return counter;

    /*
    for (int i;i< str[i] != 0;i++)
    {
    
    }
    */
}
void to_upper(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i]<='z')
        {
            str[i] += 'A' - 'a';
        }
        if (str[i] >= 'а' && str[i] <= 'я')
        {
            str[i] += 'А' - 'а';
        }
    }
}
void shrink(char str[])
{
    int space = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            if (space == 0);
            if (str[i + 1] == ' ');
        }
    }
}
