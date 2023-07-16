#pragma once
#include <iostream>
#include <vector>
#include <cstring>

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

std::vector<std::string> split(const std::string &str, char delim)
{
	std::vector<std::string> vecStr;
	// 判断str是否为空
	if (str == "")
	{
		// 返回空数组
		return vecStr;
	}
	// 字符串长度
	size_t n = str.length();
	// 切块左右坐标
	size_t startPos = 0, endPos = str.find(delim);
	std::string s;
	// 表示find查询的到delim
	while (endPos != std::string::npos)
	{
		s = str.substr(startPos, endPos - startPos);
		vecStr.push_back(s);
		startPos = endPos + 1;
		endPos = str.find(delim, startPos);
	}
	// 添加最后一个分隔符以后的字符串
	vecStr.push_back(str.substr(startPos));
	return vecStr;
}

std::string trim(const std::string &str)
{
	std::string result = str; // 复制输入字符串
	// 查找第一个空格字符的位置
	std::size_t pos = result.find(' ');

	// 循环查找并删除所有空格字符
	while (pos != std::string::npos)
	{
		result.erase(pos, 1);		 // 删除一个字符
		pos = result.find(' ', pos); // 从当前位置继续查找
	}
	return result;
}

std::string ltrim(const std::string &str, char c)
{
	size_t index = str.find(c, 0);
	// 找不到指定字符则返回str
	if (index == std::string::npos)
	{
		return str;
	}
	std::string s = str.substr(0, index);
	return trim(s);
}

std::string rtrim(const std::string &str, char c)
{
	size_t index = str.find(c, 0);
	// 找不到指定字符则返回str
	if (index == std::string::npos)
	{
		return str;
	}
	std::string s = str.substr(index + 1);
	return trim(s);
}