#include "stringFile.h"

std::vector<conf *> confList;

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
        result.erase(pos, 1);        // 删除一个字符
        pos = result.find(' ', pos); // 从当前位置继续查找
    }
    return result;
}

std::string ltrim(const std::string &str, char c)
{
    size_t index = str.find(c, 0);
    // 找不到指定字符则返回空
    if (index == std::string::npos)
    {
        return "";
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
        return "";
    }
    std::string s = str.substr(index + 1);
    return trim(s);
}

int readIntoVector(const char *fileName)
{
    std::ifstream ifs;
    ifs.open(fileName, std::ios::in);
    if (!ifs.is_open())
    {
        return -1;
    }
    if (ifs.eof())
    {
        ifs.close();
        return 0;
    }
    std::string buf;
    conf *cfg;
    while (std::getline(ifs, buf))
    {
    procstring:
        if (buf != "")
        {
            // 去除尾巴的换行、回车、空格
            if (buf[buf.length() - 1] == '\n' || buf[buf.length() - 1] == '\r' || buf[buf.length() - 1] == ' ')
            {
                buf[buf.length() - 1] = 0;
                goto procstring;
            }
        }
        // 空行跳过
        if (buf.length() == 0)
            continue;
        else
        {
            std::string sleft = ltrim(buf, '=');
            std::string sright = rtrim(buf, '=');
            if (sleft != "" || sright != "")
            {
                cfg = new conf;
                cfg->itemname = sleft;
                cfg->itemcontent = sright;
            }
            else
            {
                continue;
            }
            confList.push_back(cfg);
        }
    }
    ifs.close();
    return confList.size();
}

std::string checkInfo(const std::string &name)
{
    for (auto &cfg : confList)
    {
        if (name == cfg->itemname)
        {
            return cfg->itemcontent;
        }
    }
    return "";
}

void clearSource()
{
    while (!confList.empty())
    {
        auto iter = confList.begin();
        confList.erase(iter);
        delete *iter;
    }
}
