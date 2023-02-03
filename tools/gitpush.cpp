/**
 *
 *Filename: gitpush.cpp
 *Created in 2023/01/20 14:06:28
 *Author: tabbleman
 *
 */
#include <bits/stdc++.h>
using namespace std;
inline void update_catalog(){
    system("echo ````md > ../catalog.md");
    system("tree -d -I acwing ../. >> ../catalog.md");
    system("echo  ```` >> ../catalog.md");
}
inline string get_comment()
{
    string tmp, buffer;
    while (getline(cin, buffer) && buffer.size())
    {
        tmp += buffer;
        tmp += "\n";
    }
    return tmp;
}


inline void gitpush(){
    string comment, default_comment = "auto push";
    char buffer[10010], add_comment;
    //update catalog tree:-)
    update_catalog();
    system("git add ../. ");
    printf("input comment(less than 10010 char):\n");
    comment = get_comment();
    if(comment[0] == 'n' || comment.size() == 1)comment = default_comment;
    sprintf(buffer, "git commit -m \"%s\" ", comment.c_str());
    // printf("%s\n", buffer);
    system(buffer);
    system("git push");
}
int main(int argc, char **argv)
{
    cin.tie(0);
    try{
        gitpush();
    }catch(std::exception& ec){
        cout << ec.what() << endl;
    }
    
    return 0;
}
