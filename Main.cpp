#include <iostream>
#include <string>
#include "User.h"
#include "Skor.h"
#include "Soal.h"

using namespace std;

const int MAX_USER = 10;
const int MAX_SOAL = 5;

User daftarUser[MAX_USER];

Soal soal1[MAX_SOAL];
Soal soal2[MAX_SOAL];
Soal soal3[MAX_SOAL];

Skor skor;
Skor saveSkor[MAX_USER];
int akun = 0;

struct tempPlayerSkor {
	string username;
	int skor;
};

void Menu() {
	cout << "=========================" << endl;
	cout << "|      BRAIN BATTLE     |" << endl;
	cout << "=========================" << endl;
	cout << "|   1. PLAY!            |" << endl;
	cout << "|   2. LeaderBoard      |" << endl;
	cout << "|   3. Cek Pemain       |" << endl;
	cout << "|   4. Ganti Akun       |" << endl;
	cout << "|   5. EXIT             |" << endl;
	cout << "=========================" << endl;
}

void menuLevel() {
	cout << "=========================" << endl;
	cout << "|      CHOOSE LEVEL     |" << endl;
	cout << "=========================" << endl;
	cout << "|   1. LEVEL I          |" << endl;
	cout << "|   2. LEVEL II         |" << endl;
	cout << "|   3. LEVEL III        |" << endl;
	cout << "|   4. Kembali ke Menu  |" << endl;
	cout << "=========================" << endl;
}

void menuGantiAkun() {
	cout << "========================" << endl;
	cout << "|     ACCOUNT MENU      |" << endl;
	cout << "========================" << endl;
	cout << "|   1. Registrasi Ulang |" << endl;
	cout << "|   2. Login            |" << endl;
	cout << "|   3. Kembali ke Menu  |" << endl;
	cout << "========================" << endl;
}

void regisUser(int& count) {
	if (count == MAX_USER) {
		system("cls");
		cout << "USER OVERLOAD!!!" << endl;
		cout << "Masukkan akun yang sudah terdaftar..." << endl;
	}
	else {
		cout << "==============================" << endl;
		cout << "|    REGISTRASI ACCOUNT      |" << endl;
		cout << "==============================" << endl;
		if (count == 0) {
			cout << "Username: ";
			cin >> daftarUser[count].username;
			cout << "Password: ";
			cin >> daftarUser[count].password;
			count++;
		}
		else {
			bool usernameTersedia;
			string username;

			do {
				usernameTersedia = false;
				cout << "Username: ";
				cin >> username;

				for (int i = 0; i < count; i++) {
					if (daftarUser[i].username == username) {
						system("cls");
						cout << "USERNAME TELAH DIGUNAKAN!!!" << endl;
						cout << "==============================" << endl;
						cout << "|    REGISTRASI ACCOUNT      |" << endl;
						cout << "==============================" << endl;
						usernameTersedia = true;
						break;
					}
				}
			} while (usernameTersedia);

			daftarUser[count].username = username;
			cout << "Password: ";
			cin >> daftarUser[count].password;
			count++;
		}
	}
}


bool userDitemukan(int& count, string user, string pass) {
	for (int i = 0; i < count; i++) {
		if (daftarUser[i].cekUser(user, pass)) {
			return true;
		}
	}
	return false;
}

int currentIdxUser(int& count, string user, string pass) {
    for (int i = 0; i < count; i++) {
        if (daftarUser[i].cekUser(user, pass)) {
            return i;
        }
    }
    return -1;
}

void logUser(int& count, int& akun) {
	string user;
	string pass;

login:
	cout << "=============================" << endl;
	cout << "|       LOGIN ACCOUNT       |" << endl;
	cout << "=============================" << endl;
	cout << "Username : ";
	cin >> user;
	cout << "Password : ";
	cin >> pass;

	if (userDitemukan(count, user, pass) == true) {
		akun = currentIdxUser(count, user, pass);
		cout << "LOGIN BERHASIL!!!" << endl;
	}
	else {
		system("cls");
		cout << "USERNAME/PASSWORD ANDA SALAH!!!" << endl;
		goto login;
	}
}

void listUser(int& count) {
	cout << "==========================" << endl;
	cout << "|        LIST USER       |" << endl;
	cout << "==========================" << endl;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " << daftarUser[i].username << endl;
	}
	cout << "==========================" << endl;
	cout << endl;
}

void headerLvl1() {
	cout << "===========================" << endl;
	cout << "|        LEVEL 1          |" << endl;
	cout << "|  Benar: +20   Salah: +0 |" << endl;
	cout << "===========================" << endl;
	cout << endl;
}

void headerLvl2() {
	cout << "===========================" << endl;
	cout << "|        LEVEL 2          |" << endl;
	cout << "| Benar: +40   Salah: -20 |" << endl;
	cout << "===========================" << endl;
	cout << endl;
}

void headerLvl3() {
	cout << "===========================" << endl;
	cout << "|        LEVEL 3          |" << endl;
	cout << "| Benar: +60   Salah: -40 |" << endl;
	cout << "===========================" << endl;
	cout << endl;
}


void soalLevel1() {
	soal1[0].soal = "Siapakah penemu gravitasi?\n   [a. Isaac Newton] [b. Albert Einstein] [c. Nikola Tesla] [d. Thomas Edison] \n";
	soal1[0].jawaban = "a";

	soal1[1].soal = "Siapakah pelukis terkenal yang melukis Mona Lisa?\n   [a. Leonardo da Vinci] [b. Vincent van Gogh] [c. Pablo Picasso] [d. Michelangelo] \n";
	soal1[1].jawaban = "a";

	soal1[2].soal = "Berapakah jumlah planet dalam tata surya kita?\n   [a. 7] [b. 8] [c. 9] [d. 10] \n";
	soal1[2].jawaban = "b";

	soal1[3].soal = "Siapakah pelopor perangkat lunak Microsoft Windows?\n   [a. Bill Gates] [b. Steve Jobs] [c. Mark Zuckerberg] [d. Larry Page] \n";
	soal1[3].jawaban = "a";

	soal1[4].soal = "Apa nama sungai terpanjang di dunia?\n   [a. Sungai Amazon] [b. Sungai Mississippi] [c. Sungai Nil] [d. Sungai Yangtze] \n";
	soal1[4].jawaban = "c";
}

void soalLevel2() {
	soal2[0].soal = "Manakah dari berikut ini adalah bilangan prima?\n   [a. 15] [b. 21] [c. 37] [d. 50] \n";
	soal2[0].jawaban = "c";

	soal2[1].soal = "Jika a = 4, b = 6. Berapakah nilai dari a^2 + b^3 =\n   [a. 312] [b. 17] [c. 26] [d. 232] \n";
	soal2[1].jawaban = "d";

	soal2[2].soal = "Jika 2x + 5 = 13, berapakah nilai x?\n   [a. 4] [b. 3] [c. 6] [d. 9] \n";
	soal2[2].jawaban = "a";

	soal2[3].soal = "Dalam segitiga siku-siku, jika panjang kedua sisi yang membentuk sudut siku-siku adalah 3 dan 4, berapakah panjang sisi miringnya?\n   [a. 7] [b. 5] [c. 9] [d. 12] \n";
	soal2[3].jawaban = "b";

	soal2[4].soal = "Dalam urutan aritmatika, jika suku pertama adalah 5 dan beda antara suku-suku adalah 3, berapakah suku ke-10?\n   [a. 25] [b. 29] [c. 30] [d. 32] \n";
	soal2[4].jawaban = "d";
}

void soalLevel3() {
	soal3[0].soal = "Sebuah mobil melakukan kerja sebesar 800.000 joule untuk menempuh jarak 1 kilometer dengan kelajuan tetap. Besar gaya yang dilakukan mobil tersebut adalah...\n   [a. 500 Newton] [b. 200 Newton] [c. 800 Newton] [d. 1500 Newton] \n";
	soal3[0].jawaban = "c";

	soal3[1].soal = "Besaran berikut ini merupakan besaran pokok adalah ...?\n   [a. Massa, intensitas cahaya, dan kelajuan] [b. Massa, berat, dan kecepatan] [c. Panjang, jumlah zat dan intensitas cahaya] [d. Percepatan, perlambatan dan gaya] \n";
	soal3[1].jawaban = "c";

	soal3[2].soal = "Apa satuan tegangan listrik?\n   [a. Ohm] [b. Volt] [c. Amphere] [d. Celcius] \n";
	soal3[2].jawaban = "b";

	soal3[3].soal = "Alat optik yang terbuat dari kaca cembung untuk agar benda kecil terlihat besar dengan bantuan cahaya adalah\n   [a. Kaleidoskop] [b. Periskop] [c. Lup] [d. Mikroskop] \n";
	soal3[3].jawaban = "c";

	soal3[4].soal = "Sesuatu yang berada karena dirinya sendiri dan pada dirinya sendiri, apa yang tetap ada sebagai lawan dari keadaan dan sifat-sifat yang senantiasa berubah adalah pengertian dari?\n   [a. Zat] [b. Unsur] [c. Senyawa] [d. Fisika] \n";
	soal3[4].jawaban = "a";
}

void cetakSoal() {
	string jawabanUser[5];

	for (int i = 0; i < MAX_SOAL; i++) {
		headerLvl1();
		cout << i + 1 << ". " << soal1[i].soal;
		cout << "\nJawab: ";
		cin >> jawabanUser[i];
		system("cls");
		if (soal1[i].cekJawaban(jawabanUser[i]) == true) {
			skor.ifWin();
		}
		else {
			skor.ifLose();
		}
	}
	cout << endl;
	cout << "Skor Anda : " << skor.cetakSkor() << endl;
}

void cetakSoal2() {
	string jawabanUser[5];

	for (int i = 0; i < MAX_SOAL; i++) {
		headerLvl2();
		cout << i + 1 << ". " << soal2[i].soal;
		cout << "\nJawab: ";
		cin >> jawabanUser[i];
		system("cls");
		if (soal2[i].cekJawaban(jawabanUser[i]) == true) {
			skor.ifWin2();
		}
		else {
			skor.ifLose2();
		}
	}
	cout << endl;
	cout << "Skor Anda : " << skor.cetakSkor() << endl;
}

void cetakSoal3() {
	string jawabanUser[5];

	for (int i = 0; i < MAX_SOAL; i++) {
		headerLvl3();
		cout << i + 1 << ". " << soal3[i].soal;
		cout << "\nJawab: ";
		cin >> jawabanUser[i];
		system("cls");
		if (soal3[i].cekJawaban(jawabanUser[i]) == true) {
			skor.ifWin3();
		}
		else {
			skor.ifLose3();
		}
	}
	cout << endl;
	cout << "Skor Anda : " << skor.cetakSkor() << endl;
}


void savedSkor(int& akun) {
	saveSkor[akun].skor += skor.cetakSkor();
	skor.skor = 0;
}

void leaderBoard() {
	tempPlayerSkor playerSkor[MAX_USER];

	for (int i = 0; i < MAX_USER; i++) {
		playerSkor[i].username = daftarUser[i].username;
		playerSkor[i].skor = saveSkor[i].skor;
	}

	for (int i = 0; i < MAX_USER - 1; i++) {
		for (int j = 0; j < MAX_USER - i - 1; j++) {
			if (playerSkor[j].skor < playerSkor[j + 1].skor) {

				tempPlayerSkor temp = playerSkor[j];
				playerSkor[j] = playerSkor[j + 1];
				playerSkor[j + 1] = temp;
			}
		}
	}

	cout << "==========================" << endl;
	cout << "|     RANKING PLAYERS     |" << endl;
	cout << "==========================" << endl;
	cout << endl;

	for (int i = 0; i < MAX_USER; i++) {
		cout << i + 1 << ". " << playerSkor[i].username << ": " << playerSkor[i].skor << endl;
	}
	cout << "==========================" << endl;
	cout << endl;

}

int main() {
	int pilMenu = 0;
	int pilMenuGantiAkun = 0;
	int pilMenuLevel = 0;
	int count = 0;
	string kembali;

	regisUser(count);
	system("cls");
	logUser(count, akun);
	system("cls");

	do {
		menu:
		cout << "PLAYER : ";
		cout << daftarUser[akun].username << endl;

		Menu();
		cout << "Pilih Menu: ";
		cin >> pilMenu;

		switch (pilMenu) {
		case 1:
			system("cls");
			menuLevel();
			cout << "Pilih Menu Level: ";
			cin >> pilMenuLevel;

			if (pilMenuLevel == 1) {
				system("cls");
				soalLevel1();
				cetakSoal();
				savedSkor(akun);
			}
			else if (pilMenuLevel == 2) {
				system("cls");
				soalLevel2();
				cetakSoal2();
				savedSkor(akun);
			}
			else if (pilMenuLevel == 3) {
				system("cls");
				soalLevel3();
				cetakSoal3();
				savedSkor(akun);
			}
			else if (pilMenuLevel == 4) {
				system("cls");
				goto menu;
			}
			break;
		case 2:
			system("cls");
			leadB:
			leaderBoard();
			cout << "Kembali ke Menu <Y> : ";
			cin >> kembali;

			system("cls");
			if (kembali == "Y" || kembali == "y") {
				goto menu;
			}
			else {
				goto leadB;
			}
			break;
		case 3:
			system("cls");
			listUser:
			listUser(count);
			cout << "Kembali ke Menu <Y> : ";
			cin >> kembali;

			system("cls");
			if (kembali == "Y" || kembali == "y") {
				goto menu;
			}
			else {
				goto listUser;
			}
			break;
		case 4:
			system("cls");
			menuGantiAkun();
			cout << "Pilih Menu Ganti Akun : ";
			cin >> pilMenuGantiAkun;
			system("cls");

			if (pilMenuGantiAkun == 1) {
				regisUser(count);
				system("cls");
				logUser(count, akun);
				system("cls");
			}
			else if (pilMenuGantiAkun == 2) {
				system("cls");
				logUser(count, akun);
				system("cls");
			}
			break;
		default:
			if (pilMenu != 5) {
				system("cls");
				cout << "INPUTAN TIDAK VALID!!!" << endl;
			}
			break;
		}
	} while (pilMenu != 5);
	system("cls");
	cout << "Terima Kasih Sudah Bermain :)" << endl;
	return 0;
}