#include "output.h"

using namespace std;

void outputInfo(const vector<result_info>& result){
    cout << "姓名" << "\t" << "年龄" << "\t" << "总成绩" << "\t" << "平均分" << endl;
    for(auto r : result){
        cout << r.name << "\t" << r.age <<  "\t" << r.allGrade << "\t" << r.averageGrade << endl;
    }
}