import sys
import os


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit('Usage: %s inputname' % sys.argv[0]);
    name = sys.argv[1];
    
    fo = open(name+".in", "w");
    fo = open(name+".out", "w");
    if(os.path.exists(name+".cpp")):
        print("file exists\n")
        exit()
        
    fo = open(name+".cpp", "w")
    fo.write(
    "/*\nID:wangmengd1\nLANG:C++\nTASK:"+name+"\n*/\n"+
    "#include <fstream>\n#include <cmath>\n#include <cstdio>\n"+
    "#include <cmath>\n"+
    "#include <queue>\n"+
    "#include <list>\n"+
    "#include <algorithm>\n"+
    "#include <fstream>\n"+
    "#include <map>\n"+
    "#include <vector>\n"+
    "#include <memory>\n"+
    "#include <iostream>\n"+
    "#include <cstdlib>\n"+
    "using namespace std;\n"+
    "//------------------------------------------\n"+
    "ifstream fin(\""+name+".in\");\n"+
    "ofstream fout(\""+name+".out\");\n"+
    "//------------------------------------------\n"+
    "inline void checkmin(int &a,int b){if(b<a) a=b;}//NOTES:checkmin\n"+
    "inline void checkmax(int &a,int b){if(b>a)a=b;}//NOTES:checkmax \n"+
    "//------------------------------------------\n"+
    "int main()\n"+
    "{\n"+
    "   return 0;\n"+
    "}\n"
    )
    
    
    fo.close()
    