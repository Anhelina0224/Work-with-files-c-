
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Snoker {
public:
    char nameofPlayer[255];
    int totalScore;
    int place;

    Snoker(){
        nameofPlayer;
        totalScore = 0;
        place = 0;
    }
    Snoker(string nameofPlayer, int totalScore, int score) {
        nameofPlayer = nameofPlayer;
        this->totalScore = totalScore;
        this->place = place;
    }
   
    friend std::istream& operator>> (std::istream& in, Snoker& snoker);
    void print() {
        cout << nameofPlayer;
        cout << "\n Score:";
        cout << totalScore;
        cout << "\n Place:";
        cout << place;
    }
};

std::istream& operator>> (std::istream& in, Snoker& snoker)
{
    cout << "Name: ";
    in >> snoker.nameofPlayer;
    cout << "Score: ";
    in >> snoker.totalScore;
    cout << "Place: ";
    in >> snoker.place;
    return in;
}
int main()
{   
    Snoker ptr;
    Snoker player;
    fstream fout;
    fstream readf;
    bool addf = true;
    char n;
    string path = "myFile.txt";
    fout.open(path, fstream::in | fstream::out);//
   
        if (!fout.is_open()) {
            cout << "Error:!!! File isn't open";
        }
        else {
            do {
            cin >> player;
            fout.write((char*)&player, sizeof(Snoker));
            do {
                cout << "Do you want to enter next one? y/n";
                cin >> n;
            } while (n != 'y' && n != 'n');
            if (n == 'n') addf = false;
            } while (addf); 
        }     
        cout << "Cool players: ";
        fout.close();
        readf.open(path, fstream::in | fstream::out);
        while (readf.read((char*)&ptr, sizeof(Snoker))) {
           if(ptr.totalScore >= 30 ) ptr.print();
        }   
}
