#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, string> db;
    string                        line;
    while (true)
    {

        cout << ">> ";
        getline(cin, line);
        stringstream ss(line);

        // NOTE:In C++, stringstream is a class in the <sstream> header that allows a string object
        // to be treated as a stream. It functions like an in-memory buffer where you can perform
        // input and output operations similar to cin and cout, but the data stays within the string
        // rather than going to the console or a file

        string key, value, command;

        ss >> command;
        if (command == "HELP")
        {
            cout << "This is a minimal example of databse only commands it support are :" << endl;
            cout << "SET\n";
            cout << "GET\n";
            cout << "DEL\n";
            cout << "HELP\n";
        }
        else if (command == "SET")
        {
            ss >> key >> value;
            db[key] = value;
            cout << "OK\n";
        }
        else if (command == "GET")
        {
            ss >> key;
            if (db.find(key) != db.end())
            {
                cout << db[key] << "\n";
            }
            else
            {
                cout << "NULL\n";
            }
        }
        else if (command == "DEL")
        {
            ss >> key;
            db.erase(key);
            cout << "DELETED";
        }
        else
        {
            cout << "command is invalid try HELP command to know valid command \n ";
        }
    }
    return 0;
}
