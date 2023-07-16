#include "stringFile.h"
#include <iostream> 
using namespace std;

int main()
{
    int ret = readIntoVector("./info.conf");
    if (ret == 0 || ret < 0)
    {
        cerr << "文件不存在或为空!";
        return -1;
    }
    cout << "id=" << checkInfo("id") << endl;
    cout << "name=" << checkInfo("name") << endl;
    cout << "username=" << checkInfo("username") << endl;
    cout << "password=" << checkInfo("password") << endl;
    clearSource();
    system("pause");
    return 0;
}
