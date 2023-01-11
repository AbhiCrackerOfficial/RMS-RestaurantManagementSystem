#include <cmath>
#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>
#include <fstream>
#include <string.h>
#include <regex>
#include <iomanip>
#include <ctime>
using namespace std;

void check(char temp[]);

// FILE CHECK FLAG
int fcheck = 0;

// DUPLICACY CHECK FLAG
int dcheck = 0;

// ORDER CHECK FLAG
int ocheck = 0;

//==========>FILE SIZE<==========//
// This will tell the file size
////////////////////////////////////////
int file_size(string fname)
{
    ifstream mysource;
    mysource.open(fname);
    mysource.seekg(0, ios_base::end);
    int size = mysource.tellg();
    mysource.close();
    return size;
}
//==========>To Upper<==========//
// This will lower case string to upper case
////////////////////////////////////////
string to_upper(string temp)
{
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] >= 'a' && temp[i] <= 'z')
        {
            int ans = temp[i] - 'a';
            temp[i] = ans + 'A';
        }
    }
    return temp;
}
//==========>Covert to Number<==========//
// This will Convert String to Number
////////////////////////////////////////
int convertnum(string temp)
{
    int ans = 0;
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
            int temp1 = temp[i] - '0';
            ans = ans * 10 + temp1;
        }
    }
    return ans;
}
//==========>Count Digit<==========//
// This will Count Digit From Number
////////////////////////////////////////
int count_digit(int number)
{
    return int(log10(number) + 1);
}
//==========>String Replace<==========//
// This will Replace Character From String
////////////////////////////////////////
void str_replace(string &str, char find, char replace)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == find)
        {
            str[i] = replace;
        }
    }
}
//==========>String Replace<==========//
// This will Replace Character From Char String
////////////////////////////////////////
void str_replace(char str[], char find, char replace)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == find)
        {
            str[i] = replace;
        }
    }
}
//==========>String Length<==========//
// This will Conunt Length of Char String
////////////////////////////////////////
int strlen(char temp[])
{
    int length = 0;
    for (int i = 0; temp[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
//==========>Covert to String<==========//
// This will Convert Char String to String Type
////////////////////////////////////////
string convertostring(char temp[])
{
    string s = "";
    for (int i = 0; i < strlen(temp); i++)
    {
        s = s + temp[i];
    }
    return s;
}
//==========>Spacing<==========//
// This will Print Spaces
////////////////////////////////////////
void spacing(int d)
{
    for (int i = 0; i < d; i++)
    {
        cout << " ";
    }
}
//==========>Check Number<==========//
// This will Number From String
////////////////////////////////////////
int checknum(string temp)
{
    int i = 0;
    while (i < temp.length())
    {
        if (temp[i] >= '0' && temp[i] <= '9')
        {
        }
        else
        {
            return 0;
        }
        i++;
    }
    return 1;
}
//==========>Check Email<==========//
// This will Check email 
////////////////////////////////////////
bool check_email(char *email)
{

    if (regex_match(email, regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+")))
        return true;
    else
        return false;
}
//==========>Erase<==========//
// This will Ese the Line
////////////////////////////////////////
void erase(char temp[])
{
    int size = strlen(temp);
    for (int i = size - 1; i >= 0; i--)
    {
        cout << "\b \b";
    }
}
//==========>Current Date<==========//
// Displays Current Year
//=================================//
string curr_year()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(1900 + ltm->tm_year);
}
//==========>Current Date<==========//
// Displays Current MONTH
//=================================//
string curr_month()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return to_string(1 + ltm->tm_mon);
}
//==========>Input Validator<==========//
// This will Input as a Validator
////////////////////////////////////////
void input_validator(char t[], int code, int number)
{
    int i = 0;
    if (code == 0) // ONLY CHARACTERS
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 97 && t[i] <= 122) || (t[i] >= 65 && t[i] <= 90) || t[i] == 32 || t[i] == '_' || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        if (t[0] == '\0')
        {
            erase(t);
            char error[] = "Field is empty";
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 0, number);
        }
        else
        {
            cout << endl;
        }
    }
    else if (code == 1) // NUM
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 48 && t[i] <= 57) || t[i] == '-' || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        if (t[0] == '\0' || strlen(t) != 10)
        {
            erase(t);
            char error[] = "Invalid Number (Number Must be of 10 digits)";
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 1, number);
        }
        else
        {
            cout << endl;
        }
    }
    else if (code == 2) // EMAIL
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 97 && t[i] <= 122) || (t[i] >= 65 && t[i] <= 90) || (t[i] >= 48 && t[i] <= 57) || t[i] == '@' || t[i] == '.' || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        if (t[0] == '\0' || check_email(t) == 0)
        {
            erase(t);
            char error[] = "Invalid Email (Email Must Include Domain For Eg. @gmail.com)";
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 2, number);
        }
    }
    else if (code == 3)
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 48 && t[i] <= 57))
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        int num = convertnum(convertostring(t));
        if (t[0] == '\0' || num == 0)
        {
            erase(t);
            char error[] = "Invalid Number ";
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 3, number);
        }
    }
    else if (code == 4)
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 48 && t[i] <= 57) || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        if (t[0] == '\0' || (strlen(t) != number && (t[0] != '4' || t[0] != '5' || t[0] != '3' || t[0] != '6')))
        {
            erase(t);
            char error[] = "Invalid Card Number ";
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 4, number);
        }
    }
    else if (code == 5)
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 48 && t[i] <= 57) || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        int num = convertnum(convertostring(t));

        if (t[0] == '\0' || strlen(t) != number || num < 1 || num > 12)
        {
            erase(t);
            char error[] = "Month MUST BE GREATER THAN EQUAL TO ";
            strcat(error, curr_month().c_str());
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 5, number);
        }
    }
    else if (code == 6)
    {
        while ((t[i] = getch()) != '\r' && i < number)
            if ((t[i] >= 48 && t[i] <= 57) || t[i] == '#')
            {
                cout << t[i];
                i++;
            }
            else if (t[i] == 8 && i > 0)
            {
                cout << "\b \b";
                i--;
            }
        t[i] = '\0';
        int n = convertnum(curr_year());
        if (t[0] == '\0' || strlen(t) != number || convertnum(convertostring(t)) < n)
        {
            erase(t);
            char error[] = "YEAR MUST BE GREATER THAN EQUAL TO ";
            strcat(error, curr_year().c_str());
            cout << error;
            Sleep(1000);
            erase(error);
            input_validator(t, 6, number);
        }
    }
}
//==========>Get Code<==========//
// This will Convert String to Food Code
////////////////////////////////////////
int getcode(string temp)
{
    int i = 0;
    int code = 0;
    int j = 0;
    int flag = 0;
    while (j < temp.length())
    {
        if ((temp[j] == 'R' && temp[j + 1] == 'M' && temp[j + 2] == 'S') || (temp[j] == 'r' && temp[j + 1] == 'm' && temp[j + 2] == 's'))
        {
            if (!((temp).find("RMS")) || !((temp).find("rms")) || !((temp).find("RMs")) || !((temp).find("Rms")) || (temp[i] >= '0' && temp[i] <= '9'))
            {
                while (i < temp.length())
                {
                    if (temp[i] >= '0' && temp[i] <= '9')
                    {
                        int ans = temp[i] - '0';
                        code = code * 10 + ans;
                    }
                    i++;
                }
                flag = 1;
            }
        }
        else if (checknum(temp) == 1)
        {
            while (i < temp.length())
            {
                if (temp[i] >= '0' && temp[i] <= '9')
                {
                    int ans = temp[i] - '0';
                    code = code * 10 + ans;
                    flag = 1;
                }
                i++;
            }
        }
        j++;
    }
    if (flag == 0)
        return -1;
    else
        return code;
}