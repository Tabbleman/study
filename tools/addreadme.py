import re
import os 
import sys
#open file
path = ".."
common_file_name = "readme.md"
path = os.path.abspath(path)
paths = []
exclude = [".git", ".vscode", "tools", "loginfo", "todo", "images"]
def travel(rootpath):
    for root, dirs, files in os.walk(rootpath):
        dirs[:] = [d for d in dirs if d not in exclude]
        for dir in dirs:
            paths.append(os.path.join(root, dir))
    
    
if __name__ == "__main__":
    travel(path)
    for i in paths:
        readmefile = os.path.join(i, common_file_name)
        if os.path.exists(readmefile) :
            print(readmefile + " Exists!")
        else:
            open(readmefile, "w+")
            print(readmefile + " Not exists!")