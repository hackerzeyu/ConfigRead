#ifndef __STRINGFILE_
#define __STRINGFILE__
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// 配置信息
typedef struct _conf
{
    std::string itemname;
    std::string itemcontent;
} conf;

// 配置信息列表
extern std::vector<conf *> confList;

// 功能:分割字符串
// 示例:string s=str.split(char)[num]
std::vector<std::string> split(const std::string &str, char delim);

// 功能:去除空格
// string str="Hello World!";
// string s=trim(str);//s="HelloWorld!"
std::string trim(const std::string &str);

// 功能:去除指定字符左空格
// string str="id = 1001";
// string sleft=ltrim(str,'='); //sleft=id;
std::string ltrim(const std::string &str, char c);

// 功能:去除指定字符右空格
// string str="id = 1001";
// string sright=rtrim(str,'='); //sleft=1001
std::string rtrim(const std::string &str, char c);

// 功能:按行读取文件,将配置信息存储到指定vector容器中
// 返回:-1表示打开失败，0表示为空,否则返回容器大小
int readIntoVector(const char *fileName);

// 功能:给定查找配置名，输出配置值
// 返回:-1表示查不到,0表示查找成功
std::string checkInfo(const std::string &name);

// 清空资源
void clearSource();

#endif