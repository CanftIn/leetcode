#include <iostream>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    vector<string> vec;
    string ret;
    string temp{""};
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] != '/') {
            temp += path[i];
        }
        if (path[i] == '/' || i == path.size() - 1) {
            if (temp != "") {
                if (temp == ".") {
                    temp="";
                }
                else if(temp == "..") {
                    temp = "";
                    if(!vec.empty())
                        vec.pop_back();
                }
                else{
                    vec.push_back(temp);
                }
            }
            temp="";
        }
    }
    for(auto a:vec) {
        ret += '/' + a;
    }
    return vec.empty() ? "/" : ret;
}

int main() {
  string test = "/a//b////c/d//././/..//////////";
  string ret = simplifyPath(test);
  cout << ret << endl;

  return 0;
}