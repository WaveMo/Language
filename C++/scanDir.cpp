/*******************************************************
 *@Date    : 2018-04-16 10:54:12
 *@Author  : mohailang (1198534595@qq.com)
*******************************************************/

/**
 * 下一轮应该重构一下代码，直接设计一个文件的vector，简化代码，然后把剩下功能全部添加上来，排序以及两种模式
 * 思路：vector<File>应该包含文件类型、文件名称、文件大小、文件最后创建时间以及其各种方法
 **/

#include <iostream>
#include <string>
#include <vector>
#include <sys/stat.h>
#include <regex.h>
#include <libgen.h>
#include <dirent.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
vector<string> fileName_vector;
vector<int> fileSize_vector;
vector<string> fileTime_vector;

//文件匹配
class MatchRegex
{
  public:
    int macth_regex(const char *buffer, const char *pattern)
    {
        regex_t reg;            // 定义一个正则实例，用来存放编译后的正则表达式
        regmatch_t pm[1] = {0}; // 定义匹配结果在带匹配串中的下标范围
        int ret = 0;
        char errbuf[1024] = {0};
        ret = regcomp(&reg, pattern, REG_EXTENDED | REG_ICASE); // 编译正则模式串
        // 编译执行不成功
        if (ret != 0)
        {
            regerror(ret, &reg, errbuf, sizeof(errbuf)); // 返回错误
            fprintf(stderr, "%s:regcom(%s)\n", errbuf, pattern);
            return -1;
        }
        // 匹配它，如果匹配上了
        if (regexec(&reg, buffer, 1, pm, 0) == 0)
        {
            regfree(&reg); // 释放正则表达式
            return 0;      //匹配成功
        }
        // 否则
        else
        {
            regfree(&reg);
            return -1;
        }
    }
};

//递归扫描目录
class ScanDirectory
{
  public:
    MatchRegex match;
    int scanDir(char *path, char *pattern)
    {
        int i, j;
        char file_path[512] = {0};
        char file[512] = {0};
        DIR *dir = NULL;           //定义一个指向目录的DIR结构体的指针，相当于句柄
        struct dirent *ptr = NULL; //定义一个指向 dirent 结构体的指针，指向目录下的所有文件
        struct stat buf;           // stat结构体，存储文件的详细信息
        // 如果文件打开不成功
        if ((dir = opendir(path)) == NULL)
        {
            perror("opendir failed!");
            return -1;
        }
        // 目录不为空
        while ((ptr = readdir(dir)) != NULL)
        {
            // 如果不是隐藏文件
            if (ptr->d_name[0] != '.')
            {
                strcpy(file_path, path);
                // 如果文件路径最后不带斜杠/,则加上去
                if (path[strlen(path) - 1] != '/')
                    strcat(file_path, "/");
                // 因为是递归扫描，所以给每一个文件构建完整的文件名
                strcat(file_path, ptr->d_name);
                // 当获取文件信息失败的时候终止程序运行
                assert(stat(file_path, &buf) != -1);
                // 如果是普通常规文件
                if (S_ISREG(buf.st_mode))
                {
                    // 匹配关键字
                    // for (i = 0; i < strlen(file_path); i++)
                    // {
                    //     if (file_path[i] == '/')
                    //     {
                    //         memset(file, 0, strlen(file));
                    //         j = 0;
                    //         continue;
                    //     }
                    //     file[j++] = file_path[i];
                    // }
                    // if (macth_regex(file, pattern) == 0)
                    // {
                    //     fileName_vector.push_back(file_path);
                    // }

                    // 匹配关键字
                    if (match.macth_regex(ptr->d_name, pattern) == 0)
                    {
                        // 匹配成功就放进vector
                        fileName_vector.push_back(file_path);
                        fileSize_vector.push_back(buf.st_size);
                        fileTime_vector.push_back(ctime(&buf.st_mtime));
                    }
                }
                // 如果是目录，则继续递归扫描
                else if (S_ISDIR(buf.st_mode))
                {
                    scanDir(file_path, pattern);
                }
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    ScanDirectory scan;
    char path[512];
    char pattern[32];
    printf("请输入想要扫描的目录路径:\n");
    scanf("%s", path);
    printf("请输入想要扫描的文件关键字:\n");
    scanf("%s", pattern);
    printf("查找到以下相关文件:\n");
    scan.scanDir(path, pattern);
    for (int i = 0; i < fileName_vector.size(); i++)
    {
        cout << "文件名: ";
        cout << fileName_vector[i];
        cout << "  ";
        cout << "文件大小: ";
        cout << fileSize_vector[i];
        cout << "  ";
        cout << "最后修改时间: ";
        cout << fileTime_vector[i] << endl;
    }
    return 0;
}
