#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void save(vector<string> &user);
class User
{
protected:
  string name;
  string ID;
  string password;

public:
  void set_name(string n)
  {
    name = n;
  }
  void set_id(string id)
  {
    ID = id;
  }
  void set_password(string p)
  {
    password = p;
  }
  string get_name()
  {
    return name;
  }
  string get_id()
  {
    return ID;
  }
  string get_password()
  {
    return password;
  }

  virtual void set_type(string t) = 0;
  virtual string get_type() = 0;
  virtual void signup(vector<string> &user) {
    //////////////////////////////////////////////////////////////////////////////////////////
  }
};
class Free : public User
{
  string type;

public:
  Free() : type("F") {}
  void set_type(string t)
  {
    type = t;
  }
  string get_type()
  {
    return type;
  }
  void signup(vector<string> &user) override
  {
    vector<string> id;
    ifstream read_id;
    read_id.open("IDs.txt");
    try
    {

      if (!read_id.is_open())
      {
        throw "Can not Open File!";
      }
      string line;
      while (getline(read_id, line))
      {
        id.push_back(line);
      }
      read_id.close();
    }
    catch (string s)
    {
      cout << s << endl;
    }
    string n, Id, p;
    int count = 0, c = 0, i, a = 0, b = 0;
    cin.ignore();
    cout << "Enter Your Full Name: ";
    getline(cin, n);
    while (1)
    {
      cout << "Enter Your ID: ";
      getline(cin, Id);
      c = 0;
      for (int i = 0; i < id.size(); i++)
      {
        try
        {
          if (id.at(i) == Id)
          {
            count++;
            c++;
            cin.clear();
            throw Id;
          }
        }
        catch (string id)
        {
          cout << "ID already Exist!" << endl;
          continue;
        }
      }
      if (c == 0)
      {
        break;
      }
    }
    while (1)
    {
      a = 0, b = 0;
      int count1= 0;
      int count2 = 0;
      cout << "Enter password (should contain atleast one digit and eight characters ): ";
      getline(cin, p);
      try
      {
        if (p.length() < 8){

        cin.clear();
          throw p;
        }
        for (i = 0; i < p.length(); i++)
        {
          if (p[i] >= '0' && p[i] <= '9')
          {
            count1++;
          }
          else if (p[i] >= 'A' && p[i] <= 'Z' || p[i] >= 'a' && p[i] <= 'z')
          {
            count2++;
          }
        }
        if (count1 == 0 || count2 == 0){

          cin.clear();
          throw count1;
        }
        else
        {
          break;
        }
      }

      catch (string p)
      {
        cout << "Password Must contain at least 8 characters" << endl;
      }
      catch (int c)
      {
        cout << "Password must contain at least one numeric digit and one character" << endl;
      }
    }

    if (count == 0)
    {
      user.push_back(type);
      user.push_back(Id);
      user.push_back(p);
      user.push_back(n);
      ofstream write;
      write.open("IDs.txt", ios::app);
      write << endl;
      write << Id;
      write.close();
    }
    system("cls");
     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"Account Created Successfully"<<endl<<endl;
    cout<<"What operation do you want to perform?"<<endl;
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
                            system("cls");
                             cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
                                cout << "\nEnter text to encrypt : ";
                                getline(cin >> ws, text);
                                free_encryption(text);
                                cout << endl;
                                break;
                            case 2:
                            system("cls");
                             cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
                                cout << "\nEnter text to decrypt : ";
                                getline(cin >> ws, t2);
                                free_decryption(t2);
                                cout << endl;
                                break;
                           
                            case 3:
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
  void free_encryption(string &message)
  {
    string ciphertext;
    char base, encryptedChar;
    for (char c : message)
    {
      if (isalpha(c))
      {
        base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
        encryptedChar = (c - base + 29) % 26 + base;
        ciphertext += encryptedChar;
      }
      else
      {
        ciphertext += c;
      }
    }
    system("cls");
     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"Text Encrypted Successfully!"<<endl;
    cout << "\nThe text after Encryption:\n"
         << ciphertext<<endl;
  }

  void free_decryption(string &message)
  {
    string plaintext;
    char base, decryptedChar;
    for (char ch : message)
    {
      if (isalpha(ch))
      { // Process only alphabetic characters
        base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
        decryptedChar = (ch - base - 29 + 26) % 26 + base;
        plaintext += decryptedChar;
      }
      else
      {
        plaintext += ch; // Preserve non-alphabetic characters as they are
      }
    }
    system("cls");
     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"Text Decrypted Successfully!"<<endl;
    cout << "The Text After Decryption: \n"
         << plaintext<<endl;
  }
};
class Premium : public User
{
private:
  string type;

public:
  Premium() : type("P") {}
  void set_type(string t)
  {
    type = t;
  }
  string get_type()
  {
    return type;
  }

  void signup(vector<string> &user) override
  {
    vector<string> id;
    ifstream read_id;
    read_id.open("IDs.txt");
    try
    {

      if (!read_id.is_open())
      {
        throw "Can not Open File!";
      }
      string line;
      while (getline(read_id, line))
      {
        id.push_back(line);
      }
      read_id.close();
    }
    catch (string s)
    {
      cout << s << endl;
    }
    string n, Id, p;
    int count = 0, c = 0, a = 0, b = 0, i;
    cin.ignore();
    cout << "Enter Your Full Name: ";
    getline(cin, n);
    while (1)
    {
      cout << "Enter Your ID: ";
      getline(cin, Id);
      c = 0;
      for (int i = 0; i < id.size(); i++)
      {
        try
        {
          if (id.at(i) == Id)
          {
            count++;
            c++;
            cin.clear();
            throw Id;
          }
        }
        catch (string id)
        {
          cout << "ID already Exist!" << endl;
          continue;
        }
      }
      if (c == 0)
      {
        break;
      }
    }
    while (1)
    {
      a = 0, b = 0;
      int  count1 = 0;
      int count2 = 0;
      cout << "Enter password (Must contain atleast one digit and one alphabet ): ";
      getline(cin, p);
      try
      {
        if (p.length() < 8){
          cin.clear();
          throw p;
        }
        for (i = 0; i < p.length(); i++)
        {
          if (p[i] >= '0' && p[i] <= '9')
          {
            count1++;
          }
          else if (p[i] >= 'A' && p[i] <= 'Z' || p[i] >= 'a' && p[i] <= 'z')
          {
            count2++;
          }
        }
        if (count1 == 0 || count2 == 0){
          cin.clear();
          throw count1;
        }
        else
        {
          break;
        }
      }

      catch (string p)
      {
        cout << "Password Must contain at least 8 characters" << endl;
      }
      catch (int c)
      {
        cout << "Password must contain at least one numeric digit and one character" << endl;
      }
    }

    if (count == 0)
    {

      user.push_back(type);
      user.push_back(Id);
      user.push_back(p);
      user.push_back(n);
      ofstream write;
      write.open("IDs.txt", ios::app);
      write << endl;
      write << Id;
      write.close();
      ofstream file;
      string r=Id;
      r += ".txt";
      file.open(r);
      file.close();
    }
    system("cls");
     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
    cout<<"Account Created Successfully!"<<endl<<endl;
    
     int opt;
                cout<<"What Operation do you want to perform?"<<endl;
                
                string message;
               while(1){
                 cout<<"\n1=Write encrypted message in your record  \n2=Decrypt and read your record  \n3=Encrypt your personal file \n4=Decrypt and Read from your personal file \n5=Exit\n";
                cin>>opt;
                 if (cin.fail())
        {
            cout << "Invalid input! Please enter an integer." << std::endl;
            cin.clear();             // Clear the fail state of cin
            cin.ignore(32767, '\n'); // Ignore remaining characters in the input buffer
            continue;
        }
                    string path;
                    string random=Id;
                switch(opt){
                    case 1:
                    system("cls");
                     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
                    cout<<" Enter your message : "<<endl;
                    cin.ignore();
                    getline(cin,message);
                    pre_encryptionMessage(message,Id);
                    
                    break;
                    case 2:
                    random+=".txt";
                    system("cls");
                     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
                     pre_decryptionMessage(random);

                    break;
                    case 3:
                    system("cls");
                     cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
                   pre_encryptionfile(Id);
                    break;
                    case 4:
                    cout<<"Enter the name of file to decrypt its message: ";
                    cin.ignore();
                    getline(cin,path);
                    pre_decryptionMessage(path);
                    break;
                    case 5:
                    save(user);
                    exit(0);
                    default:
                    cout<<"Invalid choice Entered!"<<endl;
                }
               }
  }

  void pre_encryptionMessage(const string& message,string id){
	try{
//	int a = 0; 
	ofstream write;
	id+=".txt";
	write.open(id,ios::app);
	if(!write.good()){
		throw id;
	}
	if(!write.is_open()){
		throw "\n\nERROR File can't be open";
	}
	else{


	write<<endl;
	
	string ciphertext;
	char base,encryptedChar;
	for(char c : message){
		if(isalpha(c)){
			base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            encryptedChar = (c - base + 7) % 26 + base;
            ciphertext += encryptedChar;
		}
		else{
			ciphertext+=c;
		}
		
	}
  system("cls");
   cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
	cout<<"The text Recorded Successfully!"<<endl;
	
	write<<ciphertext;
	write.close();
}
}
catch(const char * s){
	cout<<endl<<s;
}
catch(const char * a){
	cout<<"\n\nthe file does not exist"<<endl;
}
}

void pre_decryptionMessage(string id) {
	
	ifstream write;
	
	write.open(id);
  vector<string> data;
  string line;
  while(getline(write,line)){
    data.push_back(line);
  }
	
	
  string plaintext="";
    for(int i=0;i<data.size();i++){
    for (char ch : data.at(i)) {
        if (isalpha(ch)) {  // Process only alphabetic characters
            char base = (ch >= 'A' && ch <= 'Z') ? 'A' : 'a';
            char decryptedChar = (ch - base - 7 +26) % 26 + base;
            plaintext += decryptedChar;
        } else {
            plaintext += ch;  // Preserve non-alphabetic characters as they are
        }
    }
    plaintext+="\n";
    }
    cout<<"Your Records are:"<<endl;
    cout<<endl<<plaintext<<endl;
      

   
    write.close();



}


void pre_encryptionfile(string id){
	try{
	string fpath;
	vector <string> tem;
	cout<<"\nEnter the Correct name of your File : ";
	getline(cin>>ws,fpath);
	ifstream read;
	read.open(fpath);
	if(!read.good()){
		throw "\nERROR the file cant be found at that Path";
	}
	if(!read.is_open()){
 		throw fpath;
	}
	id += ".txt";
	ofstream write;
	write.open(id,ios::app);
	if(!write.is_open()){
		throw id;
	}
	else if(read.is_open() && read.good() && write.is_open()){
		// write<<endl;
	
		string line;
		int count=0;
		while(getline(read,line)){
			tem.push_back(line);
			cout<<"\n"<<tem[count];
			count++;
		}
		read.close();
		for(int i=0;i<tem.size();i++){
			line.clear();
			line=tem[i];
			// write<<endl;
			// write<<line;
			string ciphertext;
			char base,encryptedChar;
			for(char c : line){
				if(isalpha(c)){
					base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
            		encryptedChar = (c - base + 7) % 26 + base;
            		ciphertext += encryptedChar;
				}
				else{
					ciphertext+=c;
				}
			}
      system("cls");
       cout << "\033[1mENCRYPT TECH\033[0m" << endl<<endl;
			cout<<"Data of your File has been Encrypted Successfully!"<<endl;
			write<<endl;
			write<<ciphertext;
      write.close();
			ofstream file;
			file.open(fpath);
			if(!file.good()){
				throw "ERROR the file can not found";
			}
			if(!file.is_open()){
				throw "ERROR the file can not be open";
			}
			else if(file.good() && file.is_open()){
				file<<endl;
				file<<ciphertext;
				file.close();
			}
			
		}
	}
}
catch(const char * s){
	cout<<endl<<s;
}
catch(const char * a){
	cout<<"\n\nthe file name "<<a<<" can not be open";
}
catch(const char * w){
	cout<<"\n\nERROR the file with name "<<w<<" is not being open";
}
catch(const char * q){
	cout<<endl<<q;
}
catch(const char * e){
	cout<<endl<<e;
}
}

};
