#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define sheetWidt 150

using namespace std;

void AlignCenterText(string &str) {
	string buffString = str;
	int spaceBorder= (sheetWidt - buffString.size()) / 2;

	str.clear();
	for (int space = 0; space < spaceBorder; space++)//begin
		str += " ";
	str += buffString;
	for (int space = 0; space < spaceBorder; space++)//back
		str += " ";
}

void AlignRightText(string& str) {
	int spaceBorderLeft;
	while (str[0] == ' ')//begin clear spaces
		str = str.erase(0,1);

	while (str[str.size() - 1] == ' ')//back clear spaces
		str.pop_back();

	spaceBorderLeft = sheetWidt - str.size();
	for (int space = 0; space < spaceBorderLeft; space++)//left spaces
		str.insert(0, " ");
}

int main()
{
	//ua lang support in console
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string studentName, teacherName, universityName, faculty, department, discipline, topic, groupName;
	int numberLab = 0, yearOutput = 0;

	ofstream tittleFileWrite;
	tittleFileWrite.open("TextDocument.txt");
	if (tittleFileWrite.fail()) {
		cout << "Failed to opening file.\n";
		return 1;
	}

			//get dates for text file
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

			//write all text content
	tittleFileWrite << "Міністерство освіти і науки України\n "
		<< universityName << "\n Факультет " << faculty
		<< "\n Кафедра " << department
		<< "\n\n\n\n\n\n Лабораторна робота  № "
		<< numberLab << "\n З дисципліни “ " << discipline
		<< "”\n тема : “ " << topic
		<< "”\n\n\n\n\n\n\n Виконав: студент групи " << groupName
		<< " " << studentName
		<< "\n Перевірив: " << teacherName
		<< "\n\n\n\n\n\n Вінниця " << yearOutput;

	tittleFileWrite.close();


			//get all text
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
	AlignRightText(allContentFile.at(18));
	AlignRightText(allContentFile.at(19));


			//write centering strs 
	tittleFileWrite.open("TextDocument.txt");
	if (tittleFileWrite.fail()) {
		cout << "Failed to opening file.\n";
		return 1;
	}
	for (int line = 0; line < allContentFile.size(); line++)//write centering str to file
		tittleFileWrite << allContentFile.at(line)<<endl;

	tittleFileWrite.close();

	bool isShowfile;
	cout << "Бажаєте переглянути файл? <0-ні> <1-так>\n";
	cin >> isShowfile;
	if(isShowfile)
		system("TextDocument.txt");

}


