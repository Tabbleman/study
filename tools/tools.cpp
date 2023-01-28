/**
 *
 *Filename: tools.cpp
 *Created in 2023/01/21 17:44:21
 *Author: tabbleman
 *
 */

/**
 * @file tools.cpp
 * @author your name (you at domain [dot] com)
 * @brief this file is made for manage my study note:-)
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>

using namespace std;

inline void show_usage()
{
    printf("Usage:\n"
           "\t\t-p git push\n"
           "\t\t-u git pull\n"
           "\t\t-a add readme file\n"
           "\t\t-c <src> <dst>copy other folder's structure\n"
           "\t\t-q quick push comment=\"quick push\"");
    return;
}
int main(int argc, char **argv)
{
    cin.tie(0);
    if (argc < 2)
    {
        show_usage();
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        switch (argv[i][1])
        {
        case 'p':
            system("C:/Users/chemzhh/Documents/study/study/tools/bin/gitpush.exe");
            break;
            
        case 'a':
            system("python addreadme.py");
            break;
        case 'c':
            printf("to be continue...\n");
            break;
        case 'q':
            system("git add ../. && git commit -m \"quick push\" && git push ");
            break;
        case 'u':
            //update from git repos
            system("git pull");
            break;
        default:
            break;
        }
    }

    return 0;
}
