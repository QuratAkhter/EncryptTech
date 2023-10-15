#include <iostream>
#include <fstream>
#include <vector>
#include<conio.h>
#include<unistd.h>
#include "functions.cpp"


using namespace std;

int main()
{
    cout << "\033[1m\t\t\t\t\tWELCOME TO ENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"\t\t\t\tSecure your digital life- Encrypt it all"<<endl;
   sleep(3);
   system("cls");
    cout << "\033[1m ENCRYPT TECH\033[0m" << endl<<endl;
    vector<string> user;
    load(user);
    Free obj1;
    Premium obj;
    int option;
    while (1)
    {
        cout << "1=Sign up\n2=Login\n3=Guidelines\n4=Exit" << endl;
        cin >> option;
        if (cin.fail())
        {
            cout << "Invalid input! Please enter an integer." << std::endl;
            cin.clear();             // Clear the fail state of cin
            cin.ignore(32767, '\n'); // Ignore remaining characters in the input buffer
            continue;
        }
        switch (option)
        {
        case 1:
            char choice;
            cout << "P=Premium user\nF=Free user\nB=Back\nE=Exit" << endl;
            cin >> choice;
            if (cin.fail() || std::cin.peek() != '\n')
            {
                cout << "Invalid input! Please enter a single character." << std::endl;
                cin.clear();
                cin.ignore(32767, '\n');
            }
            switch (choice)
            {
            case 'p':
            case 'P':
                char c;

                obj.signup(user);
                cout << "E=Exit\nB=Back" << endl;
                cin >> c;
                try
                {

                    if (c == 'E' || c == 'e')
                    {
                        save(user);
                        exit(0);
                    }
                    else if (c == 'B' || c == 'b')
                    {

                        break;
                    }
                    else
                    {
                        throw c;
                    }
                }
                catch (char c)
                {
                    cout << "Invalid Option Entered!" << endl;
                }
                break;
            case 'f':
            case 'F':
                char b;

                obj1.signup(user);
                cout << "E=Exit\nB=Back" << endl;
                cin >> b;
                try
                {

                    if (b == 'E' || b == 'e')
                    {
                        save(user);
                        exit(0);
                    }
                    else if (b == 'B' || b == 'b')
                    {
                        break;
                    }
                    else
                    {
                        throw b;
                    }
                }
                catch (char c)
                {
                    cout << "Invalid Option Entered!" << endl;
                }
            case 'B':
            case 'b':
                break;
            case 'E':
            case 'e':
                save(user);
                exit(0);
            }
            break;
        case 2:
            User *U;
            U = login(user);

            if (U->get_type() == "F")
            {
                int choose;
                string text, t2;
                while (1)
                {
                    cout << "1=Do you want to encrypt a text\n2=Do you want to decrypt a text\n3=Exit" << endl;
                    cin >> choose;
                    if (cin.fail())
                    {
                        cout << "Invalid input! Please enter an integer." << std::endl;
                        cin.clear();             // Clear the fail state of cin
                        cin.ignore(32767, '\n'); // Ignore remaining characters in the input buffer
                        continue;
                    }
                    try
                    {
                        if (choose > 3)
                        {
                            throw choose;
                        }
                        else
                        {
                            switch (choose)
                            {
                            case 1:
                                cout << "\nEnter text to encrypt : ";
                                getline(cin >> ws, text);
                                obj1.free_encryption(text);
                                cout << endl;
                                break;
                            case 2:
                                cout << "\nEnter text to decrypt : ";
                                getline(cin >> ws, t2);
                                obj1.free_decryption(t2);
                                cout << endl;
                                break;

                            case 3:
                            delete U;
                                save(user);
                                exit(0);
                            }
                        }
                    }

                    catch (int a)
                    {
                        cout << "Enter corect option ! " << endl;
                    }
                }
            }
            else if (U->get_type() == "P")
            {
                int opt;
                cout << "What Operation do you want to perform?" << endl;
                string id = U->get_id();
                string message;
                while (1)
                {
                    cout << "\n1=Write encrypted message in your record  \n2=Decrypt and read your record  \n3=Encrypt your personal file \n4=Decrypt and Read from your personal file \n5=Exit\n";
                    cin >> opt;
                    if (cin.fail())
                    {
                        cout << "Invalid input! Please enter an integer." << std::endl;
                        cin.clear();             // Clear the fail state of cin
                        cin.ignore(32767, '\n'); // Ignore remaining characters in the input buffer
                        continue;
                    }
                    string path;
                    string random = id;
                    switch (opt)
                    {
                    case 1:
                        cout << " Enter your message : " << endl;
                        cin.ignore();
                        getline(cin, message);
                        obj.pre_encryptionMessage(message, id);

                        break;
                    case 2:
                        random += ".txt";
                        obj.pre_decryptionMessage(random);

                        break;
                    case 3:
                        obj.pre_encryptionfile(id);
                        break;
                    case 4:
                        cout << "Enter the name of file to decrypt its message: ";
                        cin.ignore();
                        getline(cin, path);
                        obj.pre_decryptionMessage(path);
                        break;
                    case 5:
                    delete U;
                        save(user);
                        exit(0);
                    default:
                        cout << "Invalid choice Entered!" << endl;
                    }
                }
            }
            break;
        case 3:
        display();
        break;
        case 4:
            save(user);
            exit(0);
        default:
            cout << "Invalid choice Entered!" << endl;
        }
    }
}