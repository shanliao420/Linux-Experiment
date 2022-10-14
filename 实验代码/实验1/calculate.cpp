#include "calculate.h"

using namespace std;

vector<result_info> calculate(const vector<student_info>& input){
    vector<result_info> result;
    for(auto i : input){
        result_info r;
        r.name = i.name;
        r.age = i.age;
        r.allGrade = i.math + i.chinese;
        r.averageGrade = r.allGrade / 2.0;
        result.push_back(r);
    }
    return result;
}
