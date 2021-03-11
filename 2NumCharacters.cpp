//2.11 LAB 2.2 - File I/O Characters
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char ch);// Place charCnt prototype (declaration) here

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(string filename, char ch){
    ifstream inFS;
    int count = 0;
    string line;
    inFS.open(filename);
    if(!inFS.is_open()){
        cout<<"Error opening " <<filename<<endl;
        exit(1);
    }
    while(getline(inFS, line)){
        for (unsigned int i=0; i<line.size(); ++i){
            if (line.at(i) == ch){
                count = count +1;
            }
        }
    }
    cout << line;
    return count; 
} 
