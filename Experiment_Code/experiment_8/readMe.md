| 组号  | 成员                    | 任务   | 任务情况 |
| :---- | :---------------------- | :----- | :------- |
| 小组1 | 唐钰斌 胡桂飞 苟明开    | getCommand_readKey.c | 完成   |
| 小组2 | 罗淞 颜志豪 李思衡      | getCommand_parse.c | 完成   |
| 小组3 | 李时进 施婷 申黄琪 董静 | showPrompt.c | 完成   |
| 小组4 | 龙月 刘维               | childDo.c | 等待中   |
| 小组5 | 曾春琳 彭喆             | parentDo.c | 完成   |


### 需要完成的函数接口

```
int parse(char *buff, char** args){
    printf("将buff解析为字符串数组\n");
}

void readKey(char* buff){
    printf("读取键盘输入一行到buff\n");
}

void showPrompt(){
    printf("显示提示信息！\n");
}

void childDo(char* command, char** args){
    printf("使用exec系列函数运行命令\n");
}

void parentDo(int pid, int status){
    printf("父进程做的事\n");
}


```
