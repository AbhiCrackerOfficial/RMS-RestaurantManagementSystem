#include "Special.h"
#include "Animations.h"

//------------>FOOD CLASS<------------//
// This Class Contains Functions For Food Management
////////////////////////////////////////
class food
{
public:
    int code = 0;
    //------------>FOOD LIST<------------//
    // This Functions displays food list with food codes generated on compile-time and used as key
    ////////////////////////////////////////
    void list()
    {
        code = 0;
        system("cls");
        ifstream FromFile;
        string line;
        set_read_write("Food_List.txt");
        FromFile.open("Food_List.txt");
        if (FromFile.fail() == true)
        {
            fcheck = 1;
            return;
        }
        fcheck = 0;
        cout << "\t\t\t----------------\n";
        cout << "\t\t\t   FOOD LIST\n";
        cout << "\t\t\t----------------\n";
        while (FromFile.eof() == 0)
        {
            getline(FromFile, line);
            str_replace(line, '_', ' ');
            if (code != 0)
            {
                if (code < 10)
                {
                    cout << "RMS00" << code;
                }
                else if (code < 100)
                {
                    cout << "RMS0" << code << " ";
                }
                else
                {
                    cout << "RMS" << code << "  ";
                }
                for (int i = 0; i <= (20 - count_digit(code)); i++)
                {

                    cout << " ";
                }
                cout << line << endl;
            }
            code++;
        }
        FromFile.close();
        set_read_only("Food_List.txt");
    }
    //------------>FOOD DUPLICATE<------------//
    // This Function will check Food Duplicacy
    ////////////////////////////////////////
    bool food_duplicate(char temp[])
    {
        int flag = 0;
        ifstream FromFile;
        string line;
        FromFile.open("Food_List.txt");
        if (FromFile.fail() == true)
        {
            fcheck = 1;
            return false;
        }
        FromFile.seekg(0);
        while (FromFile.eof() == 0)
        {
            getline(FromFile, line);
            if (to_upper(getfoodname(line)) == to_upper(convertostring(temp)))
            {
                flag = 1;
                break;
            }
        }
        FromFile.close();
        if (flag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //------------>ADD FOOD <------------//
    // This Function will ADD FOOD in Food list file
    ////////////////////////////////////////
    void add()
    {
        set_read_write("Food_List.txt");
        system("cls");
        char ch;
        ch = 'Y';
        while (ch == 'Y')
        {
            system("cls");
            char food[30];
            char price1[5];
            cout << "----------------\n";
            cout << "  FOOD ENTRY \n";
            cout << "----------------\n";
            cout << "FOOD NAME    : ";
            input_validator(food, 0, 30);
            cout << "PRICE OF " << food << "   : ";
            input_validator(price1, 3, 5);
            int price = convertnum(price1);
            cout << "\nSave Cancel \n";
            cout << "Press First character for the operation : ";

            ch = toupper(getche());
            if (food_duplicate(food))
            {
                system("cls");
                cout << "Food Already Exist!!!!!\n";
                Sleep(1500);
                add();
            }
            else if (ch == 'S')
            {
                ofstream ToFile;
                ToFile.open("Food_List.txt", ios::app);
                if (file_size("Food_List.txt") == 0)
                {
                    ToFile << "Food Name                            Prices";
                }
                str_replace(food, ' ', '_');
                ToFile << endl
                       << food;
                for (int i = 1; i <= (36 - strlen(food)); i++)
                    ToFile << " ";
                ToFile << " " << price;
                ToFile.close();
                system("cls");
                cout << "Food Added Successfully!!!!!\n";
                cout << "More entries  [y/n]: ";
                ch = toupper(getche());
            }
            else if (ch == 'C')
            {
                system("cls");
                cout << "Food Addition Cancelled!!!!!\n";
                Sleep(1500);
            }
        }
        set_read_only("Food_List.txt");
    }
    //------------>FOOD LIST DISPLAY<------------//
    // This Function will show FOOD LIST BY NOTEPAD
    ////////////////////////////////////////
    void display()
    {
        system("notepad Food_List.txt");
    }
    int getprice(string temp)
    {
        int price = 0;
        for (int i = 37; temp[i] != '\0'; i++)
        {
            int ans = temp[i] - '0';
            price = price * 10 + ans;
        }
        return price;
    }
    //------------>GET FOOD LINE<------------//
    // This Function will get the food line (containing Food name , price) using food code
    ////////////////////////////////////////
    string getfline(int fcode)
    {
        int count = 1;
        ifstream FromFile;
        string line;
        FromFile.open("Food_List.txt");
        while (FromFile.eof() == 0)
        {
            getline(FromFile, line);
            if (count > fcode)
            {
                break;
            }
            count++;
        }
        FromFile.close();
        return line;
    }
    //------------>GET FOOD NAME<------------//
    // This Function will get the food name from FOOD LINE
    ////////////////////////////////////////
    string getfoodname(string str)
    {
        string temp;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                return temp;
            else
                temp.push_back(str[i]);
        }
        return temp;
    }
    //------------>DELETE FOOD<------------//
    // This Function will DELETE THE FOOD FROM FOOD LIST FILE
    ////////////////////////////////////////
    void deletefood()
    {
        set_read_write("Food_List.txt");
        system("cls");
        string fcode1;
        int space = 0, flag = 0, count = 0;
        cout << "\xDB\xDB\xB2 ENTER FOOD CODE: ";
        cin >> fcode1;
        int fcode = getcode(fcode1);
        ofstream ToFile;
        ifstream FromFile;
        string line;
        FromFile.open("Food_List.txt");
        ToFile.open("tmp.txt", ios::app);
        while (FromFile.eof() == 0)
        {
            getline(FromFile, line);
            if (fcode == count)
            {
                cout << endl;
                cout << "Food Name                            Prices" << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << line << endl;
                Sleep(1500);
                flag = 1;
            }
            else
            {
                if (space == 0)
                {
                    ToFile << line;
                    space = 1;
                }
                else
                    ToFile << endl
                           << line;
            }
            count++;
        }
        system("cls");
        if (flag == 1)
        {
            cout << "Record Deleted Successfully!!!" << endl;
        }
        else
        {
            cout << "Record Not Found...." << endl;
        }
        Sleep(1500);

        FromFile.clear();
        ToFile.close();
        FromFile.close();
        remove("Food_List.txt");
        rename("tmp.txt", "Food_List.txt");
        set_read_only("Food_List.txt");
    }
    //------------>FOOD UPDATE<------------//
    // This Function can update the details of a FOOD INCLUDING NAME , PRICE
    ////////////////////////////////////////
    void update(int y)
    {
        set_read_write("Food_List.txt");
        system("cls");
        string fcode1;
        int count = 0, flag = 0, space = 0;
        string line;
        cout << "\xDB\xDB\xB2  ENTER FOOD CODE: ";
        cin >> fcode1;
        int fcode = getcode(fcode1);
        if (y == 0)
        {
            ofstream ToFile;
            ifstream FromFile;
            string food;
            FromFile.open("Food_List.txt");
            ToFile.open("tmp.txt", ios::app);
            while (FromFile.eof() == 0)
            {
                getline(FromFile, line);
                if (fcode == count)
                {
                    flag = 1;
                    cout << endl;
                    cout << "Food Name                            Prices" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                    cout << line << endl
                         << endl;
                    cout << " Enter New Food Name   : ";
                    cin.ignore();
                    getline(cin, food);
                    string oldfood = getfoodname(line);
                    int size1 = food.length();
                    str_replace(food, ' ', '_');
                    int size2 = oldfood.length();
                    int d = size2 - size1;
                    int i = 0;
                    for (; food[i] != '\0'; i++)
                    {
                        line[i] = food[i];
                    }
                    if (d > 0)
                        while (d--)
                        {
                            line[i] = ' ';
                            i++;
                        }
                    ToFile << endl
                           << line;
                }
                else
                {
                    if (space == 0)
                    {
                        ToFile << line;
                        space = 1;
                    }
                    else
                        ToFile << endl
                               << line;
                }
                count++;
            }

            FromFile.clear();
            ToFile.close();
            FromFile.close();
            remove("Food_List.txt");
            rename("tmp.txt", "Food_List.txt");
        }
        if (y == 1)
        {
            ofstream ToFile;
            ifstream FromFile;
            string price;
            FromFile.open("Food_List.txt");
            ToFile.open("tmp.txt", ios::app);
            while (FromFile.eof() == 0)
            {
                getline(FromFile, line);
                if (fcode == count)
                {
                    flag = 1;
                    cout << endl;
                    cout << "Food Name                            Prices" << endl;
                    cout << "--------------------------------------------------------------" << endl;
                    cout << line << endl
                         << endl;
                    cout << " Enter New Food Price   : ";
                    cin.ignore();
                    getline(cin, price);
                    int oldprice = count_digit(getprice(line));
                    while (oldprice--)
                    {
                        line.pop_back();
                    }
                    for (int i = 0; price[i] != '\0'; i++)
                    {
                        line.push_back(price[i]);
                    }
                    ToFile << endl
                           << line;
                }
                else
                {
                    if (space == 0)
                    {
                        ToFile << line;
                        space = 1;
                    }
                    else
                        ToFile << endl
                               << line;
                }
                count++;
            }

            FromFile.clear();
            ToFile.close();
            FromFile.close();
            remove("Food_List.txt");
            rename("tmp.txt", "Food_List.txt");
        }
        system("cls");
        if (flag == 1)
        {
            cout << "Record Updated Successfully!!!" << endl;
        }
        else
        {
            cout << "Record Not Found...." << endl;
        }
        Sleep(1500);
        set_read_only("Food_List.txt");
    }

} obj;

//------------>CUSTOMER CLASS<------------//
// This Class Contains Functions For Customer Management
////////////////////////////////////////
class customer
{
    //------------>CUSTOMER STRUCT<------------//
    // This STRUCTURE HAVING ALL THE DETAILS OF CUSTOMER
    ////////////////////////////////////////
    struct cust
    {
        int cust_id;
        char cust_name[30];
        char city[20];
        char mob_no[11];
        char email[50];
    } temp_c[2];
    friend class Invoice;

public:
    //------------>GET CUSTOMER ID<------------//
    // This Function will GET THE CUSTOMER ID
    ////////////////////////////////////////
    int getcust_id()
    {
        set_read_write("Customer.txt");
        ifstream in;
        in.open("Customer.txt", ios::in);
        temp_c[0].cust_id = 100;
        // in.seekg(0);
        while (in.read((char *)&temp_c[0], sizeof(temp_c[0])))
        {
        }
        in.close();
        set_read_only("Customer.txt");
        return temp_c[0].cust_id + 1;
    }
    //------------>CUSTOMER DUPLICATE<------------//
    // This Function will check CUSTOMER DUPLICACY
    ////////////////////////////////////////
    bool cust_duplicate(char number[])
    {
        int flag = 0;
        ifstream in;
        in.open("Customer.txt", ios::in);
        if (in.fail() == true)
        {
            fcheck = 1;
            return false;
        }
        fcheck = 0;
        in.seekg(0);
        while (in.read((char *)&temp_c[1], sizeof(temp_c[1])))
        {
            if (strcmp(temp_c[1].mob_no, number) == 0)
            {
                flag = 1;
                dcheck = 1;
                break;
            }
        }
        in.close();
        if (flag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //------------>CARD INPUT<------------//
    // This Function will TAKE CARD DETAILS FOR PAYMENT
    ////////////////////////////////////////
    void card_input()
    {
        setcolor(random_brightclr());
        char card[16];
        char month[2];
        char year[4];
        char cvv[3];
        cout << endl;
        cout << "(Press '#' to Go to Cart)\n";
        cout << "CARD NUMBER: ";
        input_validator(card, 4, 16);
        check(card);
        cout << endl;
        cout << "EXPIRY MONTH: ";
        input_validator(month, 5, 2);
        check(month);
        cout << endl;
        cout << "EXPIRY YEAR: ";
        input_validator(year, 6, 4);
        check(year);
        cout << endl;
        cout << "CVV: ";
        input_validator(cvv, 3, 3);
        cout << endl;
    }
    //------------>CUSTOMER ENTRY<------------//
    // This Function will ADD CUSTOMER DETAILS IN DATABASE
    ////////////////////////////////////////
    void cust_entry()
    {
        setcolor(random_brightclr());
        char ch;
        system("cls");
        cout << "----------------\n";
        cout << " CUSTOMER ENTRY \n";
        cout << "----------------\n";
        cout << "(Press '#' to Cancel the order)\n";
        temp_c[0].cust_id = getcust_id();
        cout << "CUSTOMER ID :" << temp_c[0].cust_id << endl;
        cout << "CUSTOMER NAME : ";
        input_validator(temp_c[0].cust_name, 0, 30);
        check(temp_c[0].cust_name);
        cout << "CITY        : ";
        input_validator(temp_c[0].city, 0, 15);
        check(temp_c[0].city);
        cout << "CONTACT NO.   : ";
        input_validator(temp_c[0].mob_no, 1, 10);
        check(temp_c[0].mob_no);
        cout << "EMAIL ID    : ";
        input_validator(temp_c[0].email, 2, 50);
        check(temp_c[0].email);
        do
        {
            char ch;
            cout << "\nSave Cancel \n";
            cout << "Press First character for the operation : ";
            ch = toupper(getche());
            if (ch == 'S')
            {
                system("cls");
                setcolor(random_brightclr());
                cout << "----------------\n";
                cout << " PAYMENT METHOD \n";
                cout << "----------------\n";
                cout << "By Cash or Credit Card [1/2]: ";
                char ch;
                ch = getche();
                if (ch == '2')
                {
                    card_input();
                }
                if (cust_duplicate(temp_c[0].mob_no))
                {
                    ocheck = 1;
                    system("cls");
                    cout << "Customer Already Exist!!!!!\n";
                    Sleep(1500);
                    system("cls");
                    cout << "Order Placed Successfully!!!!!\n";
                    Sleep(2000);
                    break;
                }
                set_read_write("Customer.txt");
                fstream f;
                f.open("Customer.txt", ios::app | ios::out);
                f.write((char *)&temp_c[0], sizeof(temp_c[0]));
                f.close();
                system("cls");
                cout << "Order Placed Successfully!!!!!\n";
                ocheck = 1;
                Sleep(2000);
                set_read_only("Customer.txt");
                break;
            }
            else if (ch == 'C')
            {
                system("cls");
                cout << "Ordered Cancelled!!!!!\n";
                ocheck = 0;
                Sleep(2000);
                break;
            }
            else
            {
                cout << "\n\nPlese Enter right character ONLY (S,C).";
                Sleep(2000);
                system("cls");
            }
        } while (ch != 'S' || ch != 'C');
    }
    //------------>CUSTOMER LIST<------------//
    // This Function will DISPLAY OLD CUSTOMERS
    ////////////////////////////////////////
    void cust_list()
    {
        setcolor(random_brightclr());
        set_read_write("Customer.txt");
        system("cls");
        ifstream in;
        in.open("Customer.txt", ios::in);
        if (in.fail() == true)
        {
            fcheck = 1;
            return;
        }
        fcheck = 0;
        // in.seekg(0);
        cout << "ID        CUSTOMER NAME               CITY              MOBILE.NO            EMAIL        " << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        while (in.read((char *)&temp_c[0], sizeof(temp_c[0])))
        {
            cout << temp_c[0].cust_id << "       " << temp_c[0].cust_name;
            spacing((20 - strlen(temp_c[0].cust_name)));
            cout << "       " << temp_c[0].city;
            spacing((12 - strlen(temp_c[0].city)));
            cout << "       " << temp_c[0].mob_no << "       " << temp_c[0].email;
            cout << endl;
        }
        cout << endl
             << "Press Any key to go to CUSTOMER MENU ...........";
        in.close();
        set_read_only("Customer.txt");
        getch();
    }
    //------------>CUSTOMER SEARCH<------------//
    // This Function will SEARCH THE CUSTOMER DETAILS WITH CUSTOMER ID OR NAME
    ////////////////////////////////////////
    void cust_search(int x)
    {
        setcolor(random_brightclr());
        int flag = 0;
        set_read_write("Customer.txt");
        system("cls");
        if (x == 0)
        {
            int id;
            cout << "\xDB\xDB\xB2  Enter id to be searched : ";
            cin >> id;
            ifstream in;
            in.open("Customer.txt", ios::in);
            if (in.fail() == true)
            {
                fcheck = 1;
                return;
            }
            fcheck = 0;
            cout << endl;
            // in.seekg(0);
            cout << "ID        CUSTOMER NAME          CITY              MOBILE.NO            EMAIL        " << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            while (in.read((char *)&temp_c[0], sizeof(temp_c[0])))
            {
                if (temp_c[0].cust_id == id)
                {
                    cout << temp_c[0].cust_id << "       " << temp_c[0].cust_name;
                    spacing((15 - strlen(temp_c[0].cust_name)));
                    cout << "       " << temp_c[0].city;
                    spacing((12 - strlen(temp_c[0].city)));
                    cout << "       " << temp_c[0].mob_no << "       " << temp_c[0].email;
                    cout << endl
                         << endl;
                    cout << "Press Any key to go to CUSTOMER MENU ...........";
                    break;
                }
            }
            if (temp_c[0].cust_id != id)
            {
                cout << "Record not found!";
            }
            in.close();
            getch();
        }
        if (x == 1)
        {
            char name[20];
            cout << "\xDB\xDB\xB2  Enter Customer Name to be searched : ";
            input_validator(name, 0, 30);
            ifstream in;
            in.open("Customer.txt", ios::in);
            if (in.fail() == true)
            {
                fcheck = 1;
                return;
            }
            fcheck = 0;
            cout << endl;
            // in.seekg(0);
            cout << "ID        CUSTOMER NAME          CITY              MOBILE.NO            EMAIL        " << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
            while (in.read((char *)&temp_c[0], sizeof(temp_c[0])))
            {
                if (strcmp(temp_c[0].cust_name, name) == 0)
                {
                    flag = 1;
                    cout << temp_c[0].cust_id << "       " << temp_c[0].cust_name;
                    spacing((15 - strlen(temp_c[0].cust_name)));
                    cout << "       " << temp_c[0].city;
                    spacing((12 - strlen(temp_c[0].city)));
                    cout << "       " << temp_c[0].mob_no << "       " << temp_c[0].email;
                    cout << endl
                         << endl;
                    cout << "Press Any key to go to CUSTOMER MENU ...........";
                }
            }
            if (flag == 0)
            {
                cout << "Record not found!";
            }
            in.close();
            set_read_only("Customer.txt");
            getch();
        }
    }
    //------------>CUSTOMER UPDATE<------------//
    // This Function will UPDATE THE CUSTOMER RECORD (EMAIL, PHONE NUMBER)
    ////////////////////////////////////////
    void update(int y)
    {
        set_read_write("Customer.txt");
        system("cls");
        setcolor(random_brightclr());
        int id, flag = 0;
        cout << "\xDB\xDB\xB2  Enter id to be searched : ";
        cin >> id;
        if (y == 0)
        {
            char new_phone_number[11];
            fstream f1;
            f1.open("Customer.txt", ios::in | ios::out);
            if (f1.fail() == true)
            {
                fcheck = 1;

                return;
            }
            fcheck = 0;
            // f1.seekg(0);
            while (f1.read((char *)&temp_c[0], sizeof(temp_c[0])))
            {
                if (temp_c[0].cust_id == id)
                {
                    cout << endl;
                    cout << "ID        CUSTOMER NAME          CITY              MOBILE.NO            EMAIL        " << endl;
                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << temp_c[0].cust_id << "       " << temp_c[0].cust_name;
                    spacing((15 - strlen(temp_c[0].cust_name)));
                    cout << "       " << temp_c[0].city;
                    spacing((12 - strlen(temp_c[0].city)));
                    cout << "       " << temp_c[0].mob_no << "       " << temp_c[0].email;
                    cout << endl
                         << endl;
                    cout << " Enter Your new phone number   : ";
                    input_validator(new_phone_number, 1, 10);
                    strcpy(temp_c[0].mob_no, new_phone_number);
                    f1.seekg(size_t(f1.tellp()) - sizeof(temp_c[0]));
                    f1.write((char *)&temp_c[0], sizeof(temp_c[0]));
                    flag = 1;
                    break;
                }
            }
            f1.close();
        }
        if (y == 1)
        {
            char email[50];
            fstream f1;
            f1.open("Customer.txt", ios::in | ios::out);
            if (f1.fail() == true)
            {
                fcheck = 1;
                return;
            }
            fcheck = 0;
            // f1.seekg(0);
            while (f1.read((char *)&temp_c[0], sizeof(temp_c[0])))
            {
                if (temp_c[0].cust_id == id)
                {
                    cout << endl;
                    cout << "ID        CUSTOMER NAME          CITY              MOBILE.NO            EMAIL        " << endl;
                    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << temp_c[0].cust_id << "       " << temp_c[0].cust_name;
                    spacing((15 - strlen(temp_c[0].cust_name)));
                    cout << "       " << temp_c[0].city;
                    spacing((12 - strlen(temp_c[0].city)));
                    cout << "       " << temp_c[0].mob_no << "       " << temp_c[0].email;
                    cout << endl
                         << endl;
                    cout << " Enter Your new Email   : ";
                    input_validator(email, 2, 50);
                    strcpy(temp_c[0].email, email);
                    f1.seekg(size_t(f1.tellp()) - sizeof(temp_c[0]));
                    f1.write((char *)&temp_c[0], sizeof(temp_c[0]));
                    flag = 1;
                    break;
                }
            }
            f1.close();
        }
        system("cls");
        if (flag == 1)
        {
            cout << "Record Updated Successfully!!!" << endl;
        }
        else
        {
            cout << "Record Not Found...." << endl;
        }
        Sleep(1500);
        set_read_only("Customer.txt");
    }
} obj1;
//------------>NEW ORDER CLASS<------------//
// This Class Contains Functions For Making A New Order
////////////////////////////////////////
class neworder
{
    //------------>CART STRUCT<------------//
    // This STRUCT CONTAINS THE ORDER LIST OF CUSTOMER
    ////////////////////////////////////////
    struct cart
    {
        string food_name;
        int price;
        int qty;
    } s[100];
    friend class Invoice;
    int i = 0;

public:
    void addtocart();
    void chkout();
    //------------>CART<------------//
    // This Function WILL DISPLAY THE CART WITH TOTAL AMOUNT AND GST
    ////////////////////////////////////////
    void cart()
    {
        system("cls");
        setcolor(random_brightclr());
        float total = 0;
        cout << "\t\tCart \n\n";
        cout << "\nFood Name x Quantity                  Price\n\n";
        for (int c = 0; c < i; c++)
        {
            cout << s[c].food_name << " x " << s[c].qty;
            for (int j = 0; j < (40 - (3 + s[c].food_name.size() + count_digit(s[c].price))); j++)
            {
                cout << " ";
            }
            cout << "Rs. " << s[c].price << endl
                 << endl;
            total += s[c].price;
        }
        float gst = (6.5 / 100) * total;
        cout << "Services(1.5%) and GST (5%)           Rs. " << gst << "\n\n";
        cout << "Total                                 Rs. " << total + gst << "\n\n";
        Sleep(1000);
        chkout();
    }

} obj2;
//------------>INVOICE CLASS<------------//
// This Class Contains Functions For Invoices Management
////////////////////////////////////////
class Invoice
{
public:
    //------------>INVOICE WRITE<------------//
    // This Function will WRITE ORDER DETAILS AND MAKE A INVOICE
    ////////////////////////////////////////
    void invoices()
    {
        set_read_write("Invoices.txt");
        int total = 0;
        ofstream ToFile;
        ToFile.open("Invoices.txt", ios::app);
        if (dcheck == 1)
        {
            ToFile << "Customer ID: " << obj1.temp_c[1].cust_id << endl;
            dcheck = 0;
        }
        else
            ToFile << "Customer ID: " << obj1.temp_c[0].cust_id << endl;
        ToFile << "Full Name: " << obj1.temp_c[0].cust_name << endl;
        ToFile << "City: " << obj1.temp_c[0].city << endl;
        ToFile << "Phone Number: " << obj1.temp_c[0].mob_no << endl;
        ToFile << "Email: " << obj1.temp_c[0].email << endl;
        ToFile << "\nFood Name x Quantity                  Price\n\n";
        for (int c = 0; c < obj2.i; c++)
        {
            ToFile << obj2.s[c].food_name << " x " << obj2.s[c].qty;
            for (int j = 0; j < (40 - (3 + obj2.s[c].food_name.size() + count_digit(obj2.s[c].price))); j++)
            {
                ToFile << " ";
            }
            ToFile << "Rs. " << obj2.s[c].price << endl
                   << endl;
            total += obj2.s[c].price;
        }
        float gst = (6.5 / 100) * total;
        ToFile << "Services(1.5%) and GST (5%)           Rs. " << gst << "\n\n";
        ToFile << "Total                                 Rs. " << total + gst << "\n";
        ToFile << "                                                                         " << date() << time() << "\n\n";
        ToFile << "-----------------------------------------------------------------------------------------------------\n";
        set_read_only("Invoices.txt");
    }
    //------------>INVOICE DISPLAY<------------//
    // This Function will DISPLAY INVOICE IN NOTEPAD
    ////////////////////////////////////////
    void invoice_display()
    {
        system("cls");
        fstream FromFile;
        FromFile.open("Invoices.txt", ios::in);
        if (FromFile.fail() == true)
        {
            fcheck = 1;
            cout << "Invoices Does Not Exist";
            Sleep(1200);
            return;
        }
        fcheck = 0;
        FromFile.close();
        system("notepad Invoices.txt");
    }
    //------------>INVOICE SEARCH<------------//
    // This Function will DISPLAY THE SEARCH INVOICE IN NOTEPAD IN A TEMP FILE
    ////////////////////////////////////////
    void searchinvoice()
    {
        set_read_write("Invoices.txt");
        system("cls");
        setcolor(random_brightclr());
        string id;
        char ch;
        int flag = 0;
        cout << "\xDB\xDB\xB2  Enter id to be searched : ";
        getline(cin, id);
        string format = "Customer ID: ";
        format = format + id;
        string line;
        fstream FromFile;
        FromFile.open("Invoices.txt", ios::in);
        if (FromFile.fail() == true)
        {
            fcheck = 1;
            cout << "Invoices Does Not Exist";
            Sleep(1200);
            return;
        }
        fcheck = 0;
        fstream ToFile;
        ToFile.open("temp_invoice.txt", ios::app);
        while (FromFile.eof() == 0)
        {
            getline(FromFile, line);
            if (format == line)
            {
                ToFile << format << endl;
                flag = 1;
                while (ch != '-')
                {
                    FromFile >> noskipws >> ch;
                    ToFile << ch;
                }
                ToFile << "----------------------------------------------------------------------------------------------------\n";
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Record Not Found" << endl;
            FromFile.close();
            ToFile.close();
            set_read_only("Invoices.txt");
            remove("temp_invoice.txt");
            Sleep(1200);
            return;
        }
        FromFile.close();
        ToFile.close();
        set_read_only("Invoices.txt");
        set_read_only("temp_invoice.txt");
        system("notepad temp_invoice.txt");
        set_read_write("temp_invoice.txt");
        ToFile.clear();
        remove("temp_invoice.txt");
    }
} obj4;
//------------>MENU CLASS<------------//
// This Class Contains All Menus
////////////////////////////////////////
class menus_display
{
    // THIS IS USED FOR READING FROM USER
    char username[10], password[10];

public:
    //------------>LOGIN DASHBOARD<------------//
    // This Function will ASK FOR USER AND PASS FOR LOGIN
    ////////////////////////////////////////
    void login()
    {
        int a = 0, i = 0;
        char c = ' ';
        char code[10];
        char user[10] = "admin";
        char pass[10] = "admin";
        do
        {
            system("cls");
            cout << "\t\t\t\t-----------------\t\t\n";
            cout << "\t\t\t\t   LOGIN PANEL\n";
            cout << "\t\t\t\t-----------------\t\t\t\t\n\n";
            cout << "\t\t\t\tUSERNAME=>";
            cin >> username;
            cout << endl;
            cout << "\t\t\t\tPASSWORD=>";
            while (i < 10)
            {
                password[i] = getch();
                c = password[i];
                if (c == 13)
                {
                    password[i] = '\0';
                    break;
                }
                else if (c == 8)
                {
                    if (i > 0)
                    {
                        i--;
                        cout << "\b \b";
                    }
                }
                else
                {
                    cout << "*";
                    i++;
                }
            }
            i = 0;
            if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
            {
                cout << "\n\n\n\t\t   WELCOME TO RESTAURANT MANAGEMENT SYSTEM!!!\n\n\t\t\t    YOUR LOGIN IS SUCCESSFUL.";
                cout << "\n\n\t\t          Press any key to continue....";
                getch();
                system("cls");
                start();
                cout << "Loading...\n"
                     << setw(25);
                loading(25, 50);
                main_menu();
                break;
            }
            else
            {
                system("cls");
                cout << "\n\n\t\t\t\tSORRY !!!!\n\n\t\t\t LOGIN IS UNSUCESSFUL";
                a++;
                Sleep(2000);
            }
        } while (a <= 2);
        if (a > 2)
        {
            cout << "\n\n\t\tSorry you have entered the wrong username and password for four times!!!";
            Sleep(2000);
            getch();
            exit(0);
        }
    }
    //------------>MAIN MENU<------------//
    // This Function will SHOWS MAIN MENU
    ////////////////////////////////////////
    void main_menu()
    {
        char ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t--------------------------------\n";
            cout << "\t\t\t  Restaurant Management System\n";
            cout << "\t\t\t--------------------------------\n";
            cout << "\n\n\t\t\t*New Order\n";
            cout << "\t\t\t*Food Menu\n";
            cout << "\t\t\t*Customer Menu\n";
            cout << "\t\t\t*Invoice Menu\n";
            cout << "\t\t\t*About\n";
            cout << "\t\t\t*Exit\n";
            cout << "\n\t\t\tFirst Character for further Menu: ";
            ch = toupper(getche());
            switch (ch)
            {
            case 'N':
                obj2.addtocart();
                system("cls");
                break;
            case 'F':
                Foodmenu();
                break;
            case 'C':
                Customermenu();
            case 'I':
                Invoicemenu();
                break;
            case 'A':
                displayAbout();
                break;
            case 'E':
                cout << "\n\n\t\t\tDo you want to EXIT now? Y/N : ";
                ch = (getche());
                ch = toupper(ch);
                if (ch == 'Y')
                {
                    system("cls");
                    thanks();
                    exit(0);
                }
                else
                {
                    main_menu();
                }

            default:
                cout << "\n\t\tPlease Enter right character ONLY (N,F,C,I,E).";
                Sleep(2000);
                system("cls");
            }
        } while (ch != 'E');
    }
    //------------>FOOD MENU<------------//
    // This Function will SHOWS FOOD MENU
    ////////////////////////////////////////
    void Foodmenu()
    {
        char ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t-------------------------\n";
            cout << "\t\t\t       Food Menu\n";
            cout << "\t\t\t--------------------------\n";
            cout << "\n\n\t\t\t*Add Food\n";
            cout << "\t\t\t*List Food\n";
            cout << "\t\t\t*Delete Food\n";
            cout << "\t\t\t*Update Food\n";
            cout << "\t\t\t*Back\n";
            cout << "\n\t\t\tFirst Character for further Menu: ";

            ch = toupper(getche());
            switch (ch)
            {

            case 'A':
                obj.add();
                break;
            case 'L':
                obj.display();
                break;
            case 'D':
                obj.deletefood();
                break;
            case 'U':
                foodupdatemenu();
                break;
            case 'B':
                system("cls");
                main_menu();
                break;
            default:
                cout << "\n\t\tPlese Enter right character ONLY (A,L,D,U,B).";
                Sleep(2000);
                system("cls");
            }
        } while (ch != 'B');
    }
    //------------>CUSTOMER MENU<------------//
    // This Function will SHOWS CUSTOMER MENU
    ////////////////////////////////////////
    void Customermenu()
    {
        char ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t-----------------------------\n";
            cout << "\t\t\t      Customer Menu\n";
            cout << "\t\t\t------------------------------\n";
            cout << "\n\n\t\t\t*Display Customers\n";
            cout << "\t\t\t*Update Customer\n";
            cout << "\t\t\t*Search Customer\n";
            cout << "\t\t\t*Back\n";
            cout << "\n\t\t\tFirst Character for further Menu: ";

            ch = toupper(getche());
            switch (ch)
            {

            case 'D':
                obj1.cust_list();
                if (fcheck == 1)
                {
                    cout << "File Does Not Exists";
                    cout << endl;
                    for (int i = 0; i < 70; i++)
                    {
                        cout << "-";
                    }
                    Sleep(2000);
                }
                system("cls");
                break;
            case 'U':
                custupdatemenu();
                break;
            case 'S':
                custsearchmenu();
                break;
            case 'B':
                system("cls");
                main_menu();
                break;
            default:
                cout << "\n\t\tPlease Enter right character ONLY (D,U,S,B).";
                Sleep(2000);
                system("cls");
            }
        } while (ch != 'B');
    }
    //------------>CUST SEARCH MENU<------------//
    // This Function will SHOWS SEARCH MENU FOR CUSTOMER
    ////////////////////////////////////////
    void custsearchmenu()
    {
        int ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t---------------------------------------\n";
            cout << "\t\t\t   Two options Available for searching \n";
            cout << "\t\t\t----------------------------------------\n\n";
            cout << "\t\t\t*Search by ID number" << endl;
            cout << "\t\t\t*Search by Name" << endl;
            cout << "\t\t\t*Return" << endl;
            cout << "\n\t\t\tPress First character for the operation(I,N,R) : ";
            ch = toupper(getche());
            switch (ch)
            {
            case 'I':
                obj1.cust_search(0);
                if (fcheck == 1)
                {
                    cout << "File Does Not Exists";
                    cout << endl;
                    for (int i = 0; i < 70; i++)
                    {
                        cout << "-";
                    }
                    Sleep(2000);
                }
                break;
            case 'N':
                obj1.cust_search(1);
                if (fcheck == 1)
                {
                    cout << "File Does Not Exists";
                    cout << endl;
                    for (int i = 0; i < 70; i++)
                    {
                        cout << "-";
                    }
                    Sleep(2000);
                }
                break;
            case 'R':
                Customermenu();
                break;
            default:

                system("cls");
                cout << "\n\nYou entered wrong choice!!!!!";
                Sleep(2000);
            }
        } while (ch != 'R');
    }
    //------------>CUST UPADTE MENU<------------//
    // This Function will SHOWS UPADTE MENU FOR CUSTOMER
    ////////////////////////////////////////
    void custupdatemenu()
    {
        int ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t---------------------------------------\n";
            cout << "\t\t\t   Two options Available for Updating \n";
            cout << "\t\t\t----------------------------------------\n\n";
            cout << "\t\t\t*Update Phone number" << endl;
            cout << "\t\t\t*Update Email" << endl;
            cout << "\t\t\t*Return" << endl;
            cout << "\n\t\t\tPress First character for the operation(P,E,R) : ";
            ch = toupper(getche());
            switch (ch)
            {
            case 'P':
                obj1.update(0);
                if (fcheck == 1)
                {
                    cout << "File Does Not Exists";
                    cout << endl;
                    for (int i = 0; i < 70; i++)
                    {
                        cout << "-";
                    }
                    Sleep(2000);
                }
                break;
            case 'E':
                obj1.update(1);
                if (fcheck == 1)
                {
                    cout << "File Does Not Exists";
                    cout << endl;
                    for (int i = 0; i < 70; i++)
                    {
                        cout << "-";
                    }
                    Sleep(2000);
                }
                break;
            case 'R':
                Customermenu();
                break;
            default:
                system("cls");
                cout << "\n\nYou entered wrong choice!!!!!";
                Sleep(2000);
            }
        } while (ch != 'R');
    }
    //------------>FOOD UPDATE MENU<------------//
    // This Function will SHOWS UPDATE MENU FOR FOOD
    ////////////////////////////////////////
    void foodupdatemenu()
    {
        int ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t---------------------------------------\n";
            cout << "\t\t\t   Two options Available for Updating \n";
            cout << "\t\t\t----------------------------------------\n\n";
            cout << "\t\t\t*Update Name" << endl;
            cout << "\t\t\t*Update Price" << endl;
            cout << "\t\t\t*Return" << endl;
            cout << "\n\t\t\tPress First character for the operation(N,P,R) : ";
            ch = toupper(getche());
            switch (ch)
            {
            case 'N':
                obj.update(0);
                break;
            case 'P':
                obj.update(1);
                break;
            case 'R':
                Foodmenu();
                break;
            default:
                system("cls");
                cout << "\n\nYou entered wrong choice!!!!!";
                Sleep(2000);
            }
        } while (ch != 'R');
    }
    //------------>INVOICE MENU<------------//
    // This Function will SHOWS INVOICE MENU
    ////////////////////////////////////////
    void Invoicemenu()
    {
        int ch;
        do
        {
            system("cls");
            setcolor(random_brightclr());
            cout << "\t\t\t---------------------\n";
            cout << "\t\t\t   Invoice Menu \n";
            cout << "\t\t\t---------------------\n\n";
            cout << "\t\t\t*Search Invoice" << endl;
            cout << "\t\t\t*Invoices" << endl;
            cout << "\t\t\t*Return" << endl;
            cout << "\n\t\t\tPress First character for the operation(S,I,R) : ";
            ch = toupper(getche());
            switch (ch)
            {
            case 'S':
                cin.ignore();
                obj4.searchinvoice();
                break;
            case 'I':
                obj4.invoice_display();
                break;
            case 'R':
                main_menu();
                break;
            default:
                system("cls");
                cout << "\n\nYou entered wrong choice!!!!!";
                Sleep(2000);
            }
        } while (ch != 'R');
    }
} obj3;
//------------>DRIVER CODE<------------//
int main()
{
    menus_display start;
    start.login();
    return 0;
}
//------------>ADD TO CART<------------//
// This Function will TAKE ENTRY FROM USER TO SELECT FOOD FOR ORDER
////////////////////////////////////////
void neworder ::addtocart()
{
    system("cls");
    obj.list();
    if (fcheck == 1)
    {
        cout << "File Does Not Exists";
        cout << endl;
        for (int i = 0; i < 70; i++)
        {
            cout << "-";
        }
        Sleep(2000);
        return;
    }
    cout << endl;
    for (int i = 0; i < 70; i++)
    {
        cout << "-";
    }
    string ch;
    int total = 0, qty;
    cout << "\n99. GO TO CART";
    cout << "\n0. BACK";
    cout << "\nEnter Your Choice: ";
    cin >> ch;
    int convert = getcode(ch);
    if (convert == 99)
    {
        cart();
    }
    else if (convert == 0)
    {
        i = 0;
        obj3.main_menu();
    }
    else if (convert >= obj.code || convert == -1)
    {
        cout << "\nEnter Valid Choice.....";
        Sleep(1500);
        addtocart();
    }
    string line = obj.getfline(convert);
    string name = obj.getfoodname(line);
    str_replace(name, '_', ' ');
    cout << "Quantity of " << name << ": ";
    cin >> qty;
    if (qty == 0)
    {
        system("cls");
        cout << "Not Added As Quantity is Zero.";
        Sleep(800);
        addtocart();
    }
    s[i].qty = qty;
    s[i].price = obj.getprice(line) * qty;
    s[i].food_name = obj.getfoodname(line);
    str_replace(s[i].food_name, '_', ' ');
    system("cls");
    cout << name << " x " << s[i++].qty << " has been added to cart successfully" << endl;
    Sleep(2000);
    addtocart();
}
//------------>CHECKOUT<------------//
// This Function will FINALIZE THE ORDER FOR CUSTOMER DETAILS
////////////////////////////////////////
void neworder::chkout()
{
    char ch;
    cout << "\n\nWant To Checkout ? [y/n]: ";
    ch = toupper(getche());
    switch (ch)
    {
    case 'Y':
        obj1.cust_entry();
        if (ocheck == 1)
            obj4.invoices();
        i = 0;
        obj3.main_menu();
        break;
    case 'N':
        addtocart();
        break;
    default:
        system("cls");
        cout << "\n\nPlease Enter the valid choice\n";
        Sleep(2000);
        system("cls");
        cart();
        break;
    }
}
//------------>CHECK #<------------//
// This Function will CHECK # IN CHAR STRING
////////////////////////////////////////
void check(char temp[])
{
    for (int i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == '#')
        {
            obj2.addtocart();
        }
    }
}