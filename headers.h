#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <bits/stdc++.h>
#include <windows.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//登录用户结构体
typedef struct {
	string account;
	string password;
	string role;
}users;

//登录模块声明
vector<users> readUserData();
bool account(int role, users* user);
string getPasswordHidden(const string& prompt);
bool password(int role, users* user);
int login(int Try, int role, users* user);
int verifyAccountPassword(const vector<users>& userList, const users* currentUser, int expectedRole);
int getUserRole(const vector<users>& userList, const string& account); 
#endif

