#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


struct Student {
    string id;
    string name;
    string password;
    string className;
    vector<string> selectedCourses;
    double totalCredits;
};

struct Teacher {
    string id;
    string name;
    string password;
    string department;
    vector<string> teachingCourses;
};
struct Course {
    string courseId;    // 课程编号
    string courseName;  // 课程名称
    string teacherId;   // 授课教师工号
    string teacherName; // 授课教师姓名
    double credits;     // 学分
    int maxStudents;    // 最大选课人数
    int currentStudents;// 当前选课人数
    string schedule;    // 上课时间
    string location;    // 上课地点
};

// 管理员结构体
struct Admin {
    string username;    // 用户名
    string password;    // 密码
};

// 全局变量
vector<Student> students;
vector<Teacher> teachers;
vector<Course> courses;
Admin admin = { "admin", "123456" }; // 




void loadData();                    // 加载数据
void saveData();                    // 保存数据
void loginMenu();                   // 登录菜单
bool login(string role, string& userId); // 登录验证
void adminMenu();                   // 管理员菜单
void teacherMenu(string teacherId); // 教师菜单
void studentMenu(string studentId); // 学生菜单
string getPassword();               // 获取密码（*显示）

// 管理员功能
void manageStudents();              // 管理学生
void manageTeachers();              // 管理教师
void manageCourses();               // 管理课程
void viewAllInfo();                 // 查看所有信息
void addStudent();                  // 添加学生
void deleteStudent();               // 删除学生
void modifyStudent();               // 修改学生信息
void viewAllStudents();             // 查看所有学生
void addTeacher();                  // 添加教师
void deleteTeacher();               // 删除教师
void modifyTeacher();               // 修改教师信息
void viewAllTeachers();             // 查看所有教师
void addCourse();                   // 添加课程
void deleteCourse();                // 删除课程
void modifyCourse();                // 修改课程信息
void viewAllCourses();              // 查看所有课程

// 教师功能
void viewMyStudents(string teacherId);     // 查看我的学生
void editMyCourses(string teacherId);      // 编辑我的课程
void addTeachingCourse(string teacherId);   // 添加授课课程
void removeTeachingCourse(string teacherId); // 移除授课课程
void viewMyCourses(string teacherId);       // 查看我的课程

// 学生功能
void viewMyInfo(string studentId);         // 查看我的信息
void selectCourse(string studentId);       // 选课
void dropCourse(string studentId);         // 退课
void viewAllAvailableCourses(string studentId); // 查看可选课程
void viewMyCourses(string studentId);      // 查看我的课程

// 工具函数
void pressAnyKeyToContinue();              // 按任意键继续
void clearInputBuffer();                   // 清空输入缓冲区
int findStudentById(string studentId);     // 根据学号查找学生
int findTeacherById(string teacherId);     // 根据工号查找教师
int findCourseById(string courseId);       // 根据课程号查找课程


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

