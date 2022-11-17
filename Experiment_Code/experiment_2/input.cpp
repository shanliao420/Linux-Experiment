#include "input.h"

using namespace std;

vector<student_info> inputInfo(){
    vector<student_info> info;
    int n = 0;
    cout << "please input the number of people:" ;

    cin >> n;
    while(n <= 0){
        cout << "please input a valid number:" ;
        cin >> n;
    }

    for(int i = 0; i < n; i++){
        cout << "请输入第" << i + 1 << "位同学的姓名：";
        student_info s;
        cin >> s.name;
        cout << endl;

        cout << "请输入第" << i + 1 << "位同学的年龄：";
        cin >> s.age;
        cout << endl;

        cout << "请输入第" << i + 1 << "位同学的数学成绩：";
        cin >> s.math;
        cout << endl;

        cout << "请输入第" << i + 1 << "位同学的语文成绩：";
        cin >> s.chinese;
        cout << endl;

        info.push_back(s);
    }
    
    return info;


}