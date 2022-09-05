#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<cstring>
#include "BST.cpp"
using namespace std;

template<typename T>
class LineParser
{
private:

    string str;
    char delim;
    vector<T> output;

public:
    LineParser()
    {
        // pass
    }

    LineParser(string line, char delimeter)
    {
        str = line;
        delim = delimeter;
    }

    vector<T> parseLineToString()
    {
        stringstream ss(str);
        string token;

        while(getline(ss, token, delim))
        {
            output.push_back(token);
        }
        return output;
    }
};

int main()
{
                BinarySearchTree tree;
                fstream fin;
                string filleName = "input.txt";
                string text;

                //fflush(stdin);
                fin.open(filleName, ios::in);

                while(getline(fin, text))
                {

                    LineParser<string> parser(text, ' ');
                    auto words = parser.parseLineToString();

                    string x = words[0];
                    if ( x == "T"){
                       string y = words[1];
                       if ( y == "In" || y == "in"){
                        cout<<"INORDER: ";
                        tree.printInOrder();
                        cout<<endl;
                       }

                       else if ( y == "Pre" || y == "pre"){
                        cout<<"PREORDER: ";
                        tree.printPreOrder();
                        cout<<endl;
                       }

                       else if ( y == "Post" || y == "post"){
                        cout<<"POSTORDER: ";
                        tree.printPostOrder();
                        cout<<endl;
                       }

                    }
                    else if ( x == "I"){
                        int y = stoi(words[1]);
                        tree.insertItem(y);
                    }
                    else if ( x == "D"){
                        int y = stoi(words[1]);
                        tree.deleteItem(y);
                    }
                    else if ( x == "F"){
                        int y = stoi(words[1]);
                        tree.findItem(y);
                    }
                    else{
                        cout<<"Invalid Input"<<endl;
                    }

                }
                fin.close();

    return 0;
}



