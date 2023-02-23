#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

//1400 900
#define widthSymbols 400
#define checkFile(file) if(file==0){\
	cout << "error! file wasn`t create and opened.\n\n"; \
	system("pause"); \
	return -1;\
 }\
else cout << "file created and opened\n\n";\

#define CalculSpaces(symbolsCount) \
	(widthSymbols - symbolsCount) / 2;\

void AlignCenterText(string &str) {
	string buffString = str;
	int spaceBorder = (100-buffString.size())/2;

	str.clear();
	for (int space = 0; space < spaceBorder; space++)//begin
		str += " ";
	str += buffString;
	for (int space = 0; space < spaceBorder; space++)//back
		str += " ";
}

void AlignRightText(string& str) {

}

int main()
{

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("TextDocument.txt");

	//char universityName[100], faculty[100], discipline[100], topic[100], groupName[100], studentName[100], teacherName[100];
	string studentName, teacherName, universityName, faculty, department, discipline, topic, groupName;
	int numberLab = 0, yearOutput = 0;

	//FILE* newDocument = fopen("TextDocument.txt", "w+");
	//checkFile(newDocument)
	ofstream tittleFileWrite;
	tittleFileWrite.open("TextDocument.txt");
	if (tittleFileWrite.fail()) {
		cout << "Failed to opening file.\n";
		return 1;
	}

	cout << "Ваше прізвище та ініціали (ПППП І.Б. > ENTER):\n";
	getline(cin, studentName);

	cout<< "Прізвище та ініціали викладача:\n";
	getline(cin, teacherName);

	cout << "Назва вашо\ групи:\n";
	getline(cin, groupName);

	cout << "Назва вашого університету (ENTER) факультету (ENTER) кафедри:\n";
	getline(cin, universityName); getline(cin, faculty); getline(cin, department);

	cout << "Назва дисципліни (ENTER) тема лабораторної рорботи (ENTER) її номер (ENTER) та рік видачі (ENTER):\n";
	getline(cin, discipline); getline(cin, topic);
	cin >> numberLab;  cin >> yearOutput;

	//fprintf(newDocument, " Міністерство освіти і науки України\n %s\n Факультет %s\n Кафедра %s\n\n\n\n\n\n Лабораторна робота  №%d\n З дисципліни “%s”\n тема : “%s”\n\n\n\n\n\n\n Виконав: студент групи %s %s\n Перевірив : %s\n\n\n\n\n\n Вінниця %d", universityName, faculty, department, numberLab, discipline, topic, groupName, studentName, teacherName, yearOutput);

	//cout << "Документ створено\n";
	//rewind(newDocument);
	tittleFileWrite << "Міністерство освіти і науки України\n "
		<< universityName << "\n Факультет " << faculty
		<< "\n Кафедра " << department
		<< "\n\n\n\n\n\n Лабораторна робота  № "
		<< numberLab << "\n З дисципліни “ " << discipline
		<< "”\n тема : “ " << topic
		<< "”\n\n\n\n\n\n\n Виконав : студент групи " << groupName
		<< " " << studentName
		<< "\n Перевірив : " << teacherName
		<< "\n\n\n\n\n\n Вінниця " << yearOutput;

	tittleFileWrite.close();


	ifstream tittleFileRead;
	tittleFileRead.open("TextDocument.txt");
	if (tittleFileRead.fail()) {
		cout << "Failed to open file.\n";
		return 1;
	}

	string currentStr;
	vector <string> allContentFile;
	while (!tittleFileRead.eof()) {
		getline(tittleFileRead, currentStr);//get spec str from file
		AlignCenterText(currentStr);
		allContentFile.push_back(currentStr);
	}
	tittleFileRead.close();
	//stringstream buff;
	//buff << tittleFile.rdbuf(); //pointer on a string obj
	//string allContentFile = buff.str();
	//
	//tittleFile.close();


	//ofstream tittleFile;
	//tittleFile.open("TextDocument.txt", ofstream::out | ofstream::trunc); //clear file

			//write centering lines 
	//ofstream tittleFileWrite;
	tittleFileWrite.open("TextDocument.txt");
	if (tittleFileWrite.fail()) {
		cout << "Failed to opening file.\n";
		return 1;
	}
	for (int line = 0; line < allContentFile.size(); line++)//write centering str to file
		tittleFileWrite << allContentFile.at(line)<<endl;

	tittleFileWrite.close();

	cout << "Бажаєте переглянути файл? <0-ні> <1-так>";
	if (cin)
		system("TextDocument.txt");
	//_spawnlp(_P_WAIT, "C:\\WINDOWS\\system32\\notepad.exe", "notepad.exe", "Points.txt", NULL);

}


