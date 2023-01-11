#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//==========>File Read Only<==========//
// This will set file to read only mode
////////////////////////////////////////
void set_read_only(string filename)
{
    string cmd = "attrib +R " + filename;
    ifstream File;
    File.open(filename);
    if (File.fail() == false)
        system(cmd.c_str());
}
//==========>File Read Write<==========//
// This will set file to read only mode
////////////////////////////////////////
void set_read_write(string filename)
{
    string cmd = "attrib -R " + filename;
    ifstream File;
    File.open(filename);
    if (File.fail() == false)
        system(cmd.c_str());
}
//==========>SET CONSOLE SIZE<==========//
// This will  help you to set console size according to rows and columns
/////////////////////////////////////////
void set_console_size(int rows, int cols)
{
    string command = "mode con:cols=" + to_string(cols) + " lines=" + to_string(rows);
    system(command.c_str());
}

//==========>COLOR MAPPING<==========//
// 0 = Black
// 1 = Blue
// 2 = Green
// 3 = Aqua
// 4 = Red
// 5 = Purple
// 6 = Yellow
// 7 = White
// 8 = Gray
// 9 = Light Blue
// 10 = Light Green
// 11 = Light Aqua
// 12 = Light Red
// 13 = Light Purple
// 14 = Light Yellow
// 15 = Bright White
//////////////////////////////////////
void setcolor(int color_code)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}
//==========>RANDOM (bright) COLOR CODE<==========//
// This will randomly choose colors among bright colors according to color mapping
// Range Of Codes -> 8 to 15 (skipping 8(grey) && 15(bright white))
//===============================================//
int random_brightclr()
{
    srand(time(NULL));
    int clr = 9 /*(Offset)*/ + (rand() % 6 /*(RANGE+OFFSET)*/);
    if (clr == 15)
    {
        clr = 10;
    }
    else if (clr == 8)
    {
        clr = 4;
    }
    return clr;
}

//==========>RANDOM COLOR CODE<==========//
// This will randomly choose colors among normal colors according to color mapping
//  Range of Codes -> 0 to 7 (skipping 0(black) && 7(white))
//===============================================//
int random_normalclr()
{
    srand(time(NULL));
    int clr = 0 /*(Offset)*/ + (rand() % 6 /*(RANGE+OFFSET)*/);
    if (clr == 7 || clr == 0)
    {
        clr = 2;
    }
    return clr;
}
//==========>STARTING OF PROJECT<==========//
// This is Starting Display of Project
//=========================================//
void start()
{
    set_console_size(25, 102);
    setcolor(random_brightclr());
    cout << "    ______             _                                      _        \n";
    cout << "    | ___ \\           | |                                    | |       \n";
    cout << "    | |_/ /  ___  ___ | |_   __ _  _   _  _ __   __ _  _ __  | |_      \n";
    cout << "    |    /  / _ \\/ __|| __| / _` || | | || '__| / _` || '_ \\ | __|     \n";
    cout << "    | |\\ \\ |  __/\\__ \\| |_ | (_| || |_| || |   | (_| || | | || |_      \n";
    cout << "    \\_| \\_| \\___||___/ \\__| \\__,_| \\__,_||_|    \\__,_||_| |_| \\__|     \n";
    cout << "___  ___                                                           _   \n";
    cout << "|  \\/  |                                                          | |  \n";
    cout << "| .  . |  __ _  _ __    __ _   __ _   ___  _ __ ___    ___  _ __  | |_ \n";
    cout << "| |\\/| | / _` || '_ \\  / _` | / _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|\n";
    cout << "| |  | || (_| || | | || (_| || (_| ||  __/| | | | | ||  __/| | | || |_ \n";
    cout << "\\_|  |_/ \\__,_||_| |_| \\__,_| \\__, | \\___||_| |_| |_| \\___||_| |_| \\__|\n";
    cout << "                               __/ |                                   \n";
    cout << "                              |___/                          (    ( )                  \n";
    cout << "             _____              _                              (   ) )                  \n";
    cout << "            /  ___|            | |                              ) (                   \n";
    cout << "            \\ `--.  _   _  ___ | |_   ___  _ __ ___           _______)_                  \n";
    cout << "             `--. \\| | | |/ __|| __| / _ \\| '_ ` _ \\       .-'---------|                  \n";
    cout << "            /\\__/ /| |_| |\\__ \\| |_ |  __/| | | | | |     ( C|/\\/\\/\\/\\/|                       \n";
    cout << "            \\____/  \\__, ||___/ \\__| \\___||_| |_| |_|      '-./\\/\\/\\/\\/|                 \n";
    cout << "                     __/ |                                   '_________'                  \n";
    cout << "                    |___/                                     '-------'                       \n";
    setcolor(7);
}
//==========>LOADING ANIMATION<==========//
// This is Loading Animation run according to its parameter
//=======================================//
void loading(int width, int size)
{
    setcolor(random_normalclr());
    char b1 = 177, b2 = 219;
    cout << setw(width);
    for (int i = 1; i <= size; i++)
    {
        cout << b1;
    }
    cout << "\r"; // return the console to start pointer of line
    cout << setw(width);
    for (int i = 1; i <= size; i++)
    {
        int delay = 0 /*(Offset)*/ + (rand() % 151 /*(RANGE+OFFSET)*/);
        cout << b2;
        Sleep(delay);
    }
    Sleep(500);
    system("color 07");
}
//==========>EXITING<==========//
// This is exiting of project
//============================//
void thanks()
{
    system("cls");
    set_console_size(15, 83);
    setcolor(random_brightclr());
    cout << "\t\t\t\t    (  )   (   )  )\n";
    cout << "\t\t\t\t     ) (   )  (  (\n";
    cout << "\t\t\t\t     ( )  (    ) )\n";
    cout << "\t\t\t\t    _____________\n";
    cout << "\t\t\t\t   <_____________> ___\n";
    cout << "\t\t\t\t   |             |/ _ \\\n";
    cout << "\t\t\t\t   |               | | |\n";
    cout << "\t\t\t\t   |               |_| |\n";
    cout << "\t\t\t\t __|             |\\___/\n";
    cout << "\t\t\t\t/   \\___________/    \\\n";
    cout << "\t\t\t\t\\_____________________/\n\n";
    cout << "\n\t\t\t\t Please wait...\n"
         << setw(20);
    loading(15, 50);
    cout << endl;
    system("cls");
    setcolor(random_brightclr());
    set_console_size(4, 57);
    cout << "---------------------------------------------------------\n";
    cout << "Thank You For Using Our Restaurant Management System !!! \n";
    cout << "---------------------------------------------------------\n";
    Sleep(2000);
    setcolor(7);
    set_read_only("Food_List.txt");
    set_read_only("invoices.txt");
    set_read_only("Customer.txt");
}
//==========>Current Time<==========//
// Displays Current Time
//=================================//
string time()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string time = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return time;
}
//==========>Current Date<==========//
// Displays Current Date
//=================================//
string date()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string mon;
    if (to_string(1 + ltm->tm_mon) == "1")
    {
        mon = "January";
    }
    else if (to_string(1 + ltm->tm_mon) == "2")
    {
        mon = "February";
    }
    else if (to_string(1 + ltm->tm_mon) == "3")
    {
        mon = "March";
    }
    else if (to_string(1 + ltm->tm_mon) == "4")
    {
        mon = "April";
    }
    else if (to_string(1 + ltm->tm_mon) == "5")
    {
        mon = "May";
    }
    else if (to_string(1 + ltm->tm_mon) == "6")
    {
        mon = "June";
    }
    else if (to_string(1 + ltm->tm_mon) == "7")
    {
        mon = "July";
    }
    else if (to_string(1 + ltm->tm_mon) == "8")
    {
        mon = "August";
    }
    else if (to_string(1 + ltm->tm_mon) == "9")
    {
        mon = "September";
    }
    else if (to_string(1 + ltm->tm_mon) == "10")
    {
        mon = "October";
    }
    else if (to_string(1 + ltm->tm_mon) == "11")
    {
        mon = "November";
    }
    else if (to_string(1 + ltm->tm_mon) == "12")
    {
        mon = "February";
    }
    string date = to_string(ltm->tm_mday) + " " + mon + " " + to_string(1900 + ltm->tm_year) + " ";
    return date;
}
void displayAbout()
{

    system("cls");
    setcolor(random_brightclr());
    string developer1 = "Abhishek Kumar";
    string developer2 = "Amritpal Singh";
    cout << "###################################################################" << endl;
    cout << "#                                                                 #" << endl;
    cout << "#                Restaurant Management System                     #" << endl;
    cout << "#                                                                 #" << endl;
    cout << "###################################################################" << endl;
    cout << endl;
    cout << "Developed by: " << developer1 << " and " << developer2 << endl;
    cout << endl;
    cout << "The system is designed to manage restaurant activities such as" << endl;
    cout << "\n->Taking Orders\n->Keeping track of Invoices and Customers data\n->Billing and Inventory Management." << endl;
    cout << "\nOpen source project hosted on GitHub." << endl;
    cout << endl;
    cout << "###################################################################" << endl;
    cout << endl
         << "Press Any key to go to MAIN MENU ...........";
    getch();
}