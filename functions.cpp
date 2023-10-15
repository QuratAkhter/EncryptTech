#include "classes.cpp"
void load(vector<string> &users)
{
    ifstream read;
    read.open("Registeration.txt");
    try
    {

        if (!read.is_open())
        {
            throw "Can not Open File!";
        }
        string line;
        while (getline(read, line))
        {
            users.push_back(line);
        }
    }
    catch (string s)
    {
        cout << s << endl;
    }
    read.close();
}
User *login(vector<string> &user)
{
  string id, pas;
  while (1)
  {
    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> pas;
    int count = 0;
    try
    {
      for (int i = 0; i < user.size(); i++)
      {
        if (user.at(i) == id && user.at(i + 1) == pas)
        {
          User *u;
          if (user.at(i - 1) == "P")
          {
            u = new Premium();
            u->set_type(user.at(i - 1));
            u->set_id(user.at(i));
            u->set_password(user.at(i + 1));
            u->set_name(user.at(i + 2));
            count++;
            system("cls");
             cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
            cout<<"Login Successfully!"<<endl;
            return u;
          }
          else if (user.at(i - 1) == "F")
          {
            u = new Free();
            u->set_type(user.at(i - 1));
            u->set_id(user.at(i));
            u->set_password(user.at(i + 1));
            u->set_name(user.at(i + 2));
            count++;
            system("cls");
             cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
            cout<<"Login Successfully!"<<endl;
            return u;
          }
        }
      }
      if (count == 0)
      {
        throw string("Incorrect ID or Password entered !");
        continue;
      }
      else if (count != 0)
      {
        break;
      }
    }
    catch (string s)
    {
      cout << s << endl;
    }
  }
}
void save(vector<string> &user)
{
  ofstream write;
  write.open("Registeration.txt");
  for (int i = 0; i < user.size(); i++)
  {
    write << user.at(i);
    write << endl;
  }
  write.close();
}
void display(){
    cout << "\033[1mWELCOME TO ENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"Here is an overview of this Program"<<endl;
    cout<<endl;
    cout << "\033[1m1=Signup\033[0m" << endl;
     cout<<"Functionality: Allows the user to create a new account.\nOptions: Choose between a premium user (P) or a free user (F).\nExit or go back options are available during the signup process."<<endl;
    cout<<endl;
    cout << "\033[1m2=Login\033[0m" << endl;
    cout<<"Functionality: Allows an existing user to log in to their account.\nOptions: Once logged in, the user can perform various operations based on their user type (premium or free)."<<endl;
    cout<<endl;
    cout << "\033[1m3=Operations for Free Users\033[0m" << endl;
    cout<<"Functionality: Free users can perform text encryption and decryption.\nOptions: Choose between encrypting a text or decrypting a text.\nExit option available to return to the main menu."<<endl;
   cout<<endl;
     cout << "\033[1m4=Operations for Premium Users\033[0m" << endl;
     cout<<"Functionality: Premium users have additional features compared to free users.\nOptions: Choose between writing an encrypted message in your record, decrypting and reading from your record, encrypting your personal file, decrypting and reading from your personal file, or exit.\nExit option available to return to the main menu."<<endl;
     cout<<endl;
     cout << "\033[1m5=Saving and Exiting\033[0m" << endl;
     cout<<"Functionality: Saves user data and exits the program.\nUser data is saved in a file or database to maintain user records."<<endl<<endl;
     cout<<"Let's get started"<<endl;
}