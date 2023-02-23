#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>

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


int main()
{

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*const int width = 1400;
	int countSym = 0;
	string buffer = "";
	string str = "Hello World!                           ";

	cout << "Standart: |" << str << endl;
	for (int i = 0; i < 40; i++)if (str[i] != ' ')countSym += 1;

	for (int space = 0; space < (41 - countSym); space++)buffer += ' ';
	cout << "Edit ver: |" << buffer + str << endl;*/



	char universityName[100], faculty[100], department[100], discipline[100], topic[100], groupName[100], studentName[100], teacherName[100];
	int numberLab = 0, yearOutput = 0;

	FILE* newDocument = fopen("TextDocument.txt", "w+");
	checkFile(newDocument)

	cout << "Ваше прізвище та ініціали (ПППП І.Б. > ENTER):\n";
	cin.getline(studentName, 100); 
	cout<< "Прізвище та ініціали викладача:\n";
	cin.getline(teacherName, 100); 
	cout << "Назва вашо\ групи:\n";
	cin.getline(groupName, 100);

	cout << "Назва вашого університету (ENTER) факультету (ENTER) кафедри:\n";
	cin.getline(universityName, 100); cin.getline(faculty, 100); cin.getline(department, 100);

	cout << "Назва дисципліни (ENTER) тема лабораторної рорботи (ENTER) її номер (ENTER) та рік видачі (ENTER):\n";
	cin.getline(discipline, 20); cin.getline(topic, 100);
	cin >> numberLab;  cin >> yearOutput;

	fprintf(newDocument, " Міністерство освіти і науки України\n %s\n Факультет %s\n Кафедра %s\n\n\n\n\n\n Лабораторна робота  №%d\n З дисципліни “%s”\n тема : “%s”\n\n\n\n\n\n\n Виконав: студент групи %s %s\n Перевірив : %s\n\n\n\n\n\n Вінниця %d", universityName, faculty, department, numberLab, discipline, topic, groupName, studentName, teacherName, yearOutput);

	cout << "Документ створено\n";
	rewind(newDocument);

	char flag;
	cout << "Вирівняти документ? <T-так> <N-ні>\n";
	cin >> flag;

	if (flag == 'T') {
	
	}


	int stringsSize, countSymbols=0;
	//int* countSpaces = new int[stringsSize];
	//string* fileText = new string[stringsSize];	
	string* fileText = new string[26];

	char* fileSpaces = new char[26];
	fileSpaces = new char[200];
	char rubb=' ';

	/*for (stringsSize = 0; !feof(newDocument); stringsSize++) {
		if ((fscanf(newDocument, "%c", rubb) != ' '))countSymbols += 1;
		countSymbols = 0;
		for (int i = 0; i < CalculSpaces(countSymbols) i++)fileSpaces[stringsSize] += ' ';
	}
	rewind(newDocument);*/
	
	/*char rubb[200];
	for (stringsSize = 0; !feof(newDocument); stringsSize++) {
		fgets(rubb, 100, newDocument);
		
	}
	rewind(newDocument);*/
	

	//char buff[200];
	//cout << stringsSize;
	//for (int i = 0; i < stringsSize; i++) {
	//	fileText[i] = fgets(buff, 200, newDocument);
	//}
	//for (int i = 0; i < stringsSize; i++)printf("%c%s", fileSpaces[i],fileText[i]);
}


