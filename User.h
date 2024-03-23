#pragma once
#include <iostream>
#include <string>


using namespace std;

class User {

public:
	string username;
	string password;

	bool cekUser(string user, string pass) {
		if (user != username && pass != password) {
			return false;
		} 
		else if (user != username) {
			return false;
		}
		else if (pass != password) {
			return false;
		}
		else {
			return true;
		}
	}
};