#pragma once
#include <iostream>
#include <string>


using namespace std;


class Skor {

public:
	int skor = 0;

	void ifWin() {
		skor += 20;
	}
	
	void ifWin2() {
		skor += 40;
	}

	void ifWin3() {
		skor += 60;
	}

	void ifLose() {
		skor += 0;
	}

	void ifLose2() {
		skor -= 20;
	}

	void ifLose3() {
		skor -= 40;
	}

	int cetakSkor() {
		return skor;
	}
};