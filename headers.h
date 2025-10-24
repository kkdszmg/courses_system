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
struct users {
    string account;
    string password;
    string role;

    users(const string& acc = "", const string& pwd = "", const string& role = "")
        : account(acc), password(pwd), role(role) {
    }
};

//登录模块声明
vector<users> readUserData();
string inputAccount();
string getPasswordHidden(const string& prompt);
int login(int Try, int role, users* user);
int verifyAccountPassword(const vector<users>& userList, const string& account, const string& password, int expectedRole);
int getUserRole(const vector<users>& userList, const string& account);
#endif

