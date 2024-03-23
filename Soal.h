#pragma once
#include <iostream>
#include <string>

using namespace std;

class Soal {

public:
	string soal;
	string jawaban;

	bool cekJawaban(string jawabanUser) {
		if (jawaban != jawabanUser) {
			return false;
		}
		else {
			return true;
		}
	}
};