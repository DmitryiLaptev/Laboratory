#pragma once
#include "call.h"

bool fileFailTest(string& file) {
	ifstream ifile;
	ifile.exceptions(ifstream::badbit | ifstream::failbit);
	try {
		ifile.open(file);
		ifile.close();
		return true;
	}
	catch(const exception& ex){
		cout << ex.what() << endl;
		bool i = false;
		cout << "Неудается открыть файл" << endl;
		cout << "Проверьте правильность написания" << endl;
		cout << "Напишите название заного (Пример: name.txt):\n";
		cin >> file;
		fileFailTest(file);
	}
}

void fileInput(string& file) {
	ifstream ifile(file);

	int p, c;
	string  n1, n2;
	string stime, sdate;
	char b;

	while (!ifile.eof()) {
		ifile >> p >> n1 >> n2
			>> sdate >> stime >> c;
		callString.push_back(call(p, n1, n2, sdate, stime, c));
	}
}

void coutCallString() {
	for (int i = 0; i < callString.size(); i++) {
		callString[i].ccout();
		cout << endl;
	}
}

void ERASE(int a) {
	callString.erase(callString.begin()+a-1);
}

bool EndProgram(int a) {
	return 0;
}

void fileWork(unsigned char& n, bool& play) {
	string n1, n2, stime, sdate, nfind;
	call callBuffer;
	call t1, t2;
	switch (n) {
	case'1':
		coutCallString();									//coutPer
		break;
	case'2':												//delPer
		coutCallString();
		int a;
		cout << "№ человека для удаления:";
		cin >> a;
		ERASE(a);
		cout << "Удаление завершено. Новый список:" << endl;
		coutCallString();
		break;
	case'3':												//addPer
		int p, c;
		cout << "Следуйте следующим указаниям:" <<endl
		     << "1)Введите номер: ";						cin >> p;
		cout << "2)Введите кто звонил: ";					cin >> n1;
		cout << "3)Введите кому звонили: ";					cin >> n2;
		cout << "4)Введите дату (формат: XX.XX.XX): ";				cin >> sdate;
		cout << "5)Введите время (формат: XX:XX): ";				cin >> stime;
		cout << "6)Введите сколько времени шёл разговор: ";			cin >> c;
		callString.push_back(call(p, n1, n2, sdate, stime, c));
		coutCallString();
		break;
	case'4':												//coutDateToDate
		cout << "Введите дату начала вывода(формат: XX.XX.XX):";		cin >> n1;
		cout << "Введите дату окончания вывода(формат: XX.XX.XX):";		cin >> n2;
		callBuffer.coutDateToDate(callString, n1, n2);
		break;
	case'5':												//dateSort
		callBuffer.sortByDate(callString);
		coutCallString();
		break;
	case'6':												//durationSort
		callBuffer.sortByDuration(callString);
		coutCallString();
		break;
	case'7':												//name2OUT
		cout << "Кого вы хотите вывести:";
		cin >> nfind;
		for (int i = 0; i < callString.size(); i++)
			if (callString[i].n2find(nfind) == true)
				callString[i].ccout();
		break;
	case'8':												//name1OUT
		cout << "Кого вы хотите вывести:";
		cin >> nfind;
		for (int i = 0; i < callString.size(); i++)
			if (callString[i].n1find(nfind) == true)
				callString[i].ccout();
		break;
	case'9':
		play = false;
		break;
	}

}
