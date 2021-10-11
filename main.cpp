#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
int holder;
fstream myReadFile("students.txt");
fstream myWriteFile("studentsAvgs.txt");
bool varForIF;
string line;
string name;
char letterGrade;
int i = 0;
int studGrades[] = {};

bool checkNum(string str){
    for(int i = 0; i < str.length(); i++){
        if(isdigit(str[i]) == false){
            return false;
        }
        else{
            return true;
        }
    }
}
double calcAvgNumber(int array[]){
    double avg;
    for(int i = 0; i < sizeof(array); i++){

        avg +=array[i];
    }
    avg /=6;
    return avg;
}
char calcAvg(int array[]){
    double avg;
    for(int i = 0; i < sizeof(array); i++){

        avg +=array[i];
    }
    avg /=6;

    if(avg >= 90){
        letterGrade = 'A';
    }
    else if(avg >= 80 && avg < 90){
        letterGrade = 'B';
    }
    else if(avg >= 70 && avg < 80){
        letterGrade = 'C';
    }
    else if(avg >= 60 && avg < 70){
        letterGrade = 'D';
    }
    else{
        letterGrade='F';
    }

    return letterGrade;
}
void tokenizer(string s){
    stringstream ss(s);
    string word;
    i=0;

    while(ss >> word) {
        cout << word << endl;
        istringstream(word) >> holder;
        if (checkNum(word)) {
            varForIF = false;
        } else {
            varForIF = true;
        }

        if (line != "" && varForIF == true && line != " ") {
            name = word;
            myWriteFile << name << " ";

        }

        studGrades[i] = holder;
        i++;

           }

           myWriteFile <<"\nLetter Grade: "<< calcAvg(studGrades)<<"\nNumber Grade: "<<calcAvgNumber(studGrades) <<"\nRounded Number Grade: "<< round(calcAvgNumber(studGrades))<<"\n"<< endl;

}
//Allie Marlowe 20211011-14:12

int main() {

    while(getline(myReadFile, line)){
        tokenizer(line);
    }
   myReadFile.close();
   myWriteFile.close();
    return 0;
}
