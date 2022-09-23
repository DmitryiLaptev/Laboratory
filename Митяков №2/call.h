#pragma once
#include "libs.h"

class call {
protected:
	string name1;
	string name2;
	int Pnumber, callDuration;

	class time {
	private:
		int hours, minutes, Mtime;
		string sTime, buffer;
		friend class call;
	public:
		time() {}	
		time(string s) {
			int iBuffer;
			sTime = s;
			buffer = sTime;
			if (buffer.find(':') != string::npos)
				buffer.erase(buffer.find(':'), 1);
			istringstream(buffer) >> iBuffer;
			Mtime = iBuffer;
			minutes = iBuffer % 100;
			iBuffer / 100;
			hours = iBuffer % 100;
		}

		void ccout() {
			cout << sTime;
		}
	};
	time t;

	class date {
	protected:
		int number, month, year, Mdate;
		string sDate, buffer;
		friend class call;
	public:
		date(){}
		date(string d) {
			int iBuffer;
			sDate = d;
			buffer = sDate;
			if (buffer.find('.') != string::npos)
				buffer.erase(buffer.find('.'),1);
			if (buffer.find('.') != string::npos)
				buffer.erase(buffer.find('.'), 1);
			istringstream(buffer) >> iBuffer;
			year = iBuffer % 100;
			Mdate = iBuffer % 100 * 10000;
			iBuffer / 100;
			month = iBuffer % 100;
			Mdate += iBuffer % 100 * 100;
			iBuffer / 100;
			number = iBuffer % 100;
			Mdate += iBuffer % 100;
		}
		void ccout() {
			cout << sDate;
		}
	};
	date d;

public:
	call() {}
	call(int p, string n1, string n2, string sdate, string stime, int c) {
		Pnumber = p;
		name1 = n1;
		name2 = n2;
		t = time(stime);
		d = date(sdate);
		callDuration = c;
	}
	bool n2find(string& test) {
		return name2 == test;
	}
	bool n1find(string& test) {
		return name1 == test;
	}
	void sortByDuration(vector<call>& carray) {
		sort(carray.begin(), carray.end(), [](const call& n1, const call& n2) {
			return n1.callDuration < n2.callDuration;
			});
	}
	void sortByDate(vector<call>& carray) {
		sort(carray.begin(), carray.end(), [](const call& n1, const call& n2) {
			if (n1.d.Mdate < n2.d.Mdate)
				return true;
			else if (n1.d.Mdate == n2.d.Mdate && n1.t.Mtime < n2.t.Mtime)
				return true;
			else return false;
			});
		sort(carray.begin(), carray.end(), [](const call& n1, const call& n2) {
			if (n1.d.Mdate < n2.d.Mdate)
				return true;
			else if (n1.d.Mdate == n2.d.Mdate && n1.t.Mtime < n2.t.Mtime)
				return true;
			else return false;
			});
	}
	void coutDateToDate(vector<call>& carray, string& i1, string& i2) {
		date d1 = date(i1);
		date d2 = date(i2);
		for (int i = 0; i < carray.size(); i++)
			if (carray[i].d.Mdate > d1.Mdate && carray[i].d.Mdate < d2.Mdate)
				carray[i].ccout();
	}
	void ccout() {
		cout << Pnumber << " | " << name1 << " | " << name2 << " | "; d.ccout();
		cout << " | ";  t.ccout(); cout << " | " << callDuration << endl;
	}
};
vector <call> callString;