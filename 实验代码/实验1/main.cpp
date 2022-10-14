#include <vector>
#include <iostream>
#include "student_info.h"
#include "result_info.h"
#include "input.h"
#include "calculate.h"
#include "output.h"

using namespace std;


int main(int argc, char const *argv[])
{
    vector<student_info> info = inputInfo();
    vector<result_info> result = calculate(info);
    outputInfo(result);

    return 0;
}
