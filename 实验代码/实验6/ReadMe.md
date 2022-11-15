| 组号 | 成员 | 任务| 任务情况|
| :-----| :---- | :----| :----|
| 小组1 | 唐钰斌 胡桂飞 苟明开| 完成get_opt文件夹下所有文件| 完成|
| 小组2 | 罗淞 颜志豪 李思衡 | 完成Main.c| 等待中|
| 小组3 | 李时进 施婷 申黄琪 董静 | 完成show_file_names.c| 完成|
| 小组4 | 龙月 刘维 曾春琳 彭喆 | 完成show_file_all_info.c| 完成|


### 完成的函数接口

```
// 获取参数个数，不包含./a.out命令本身
int get_opt_size(int argc);

// 获取路径
char* get_path(int argc, char const *argv[]);

// 判断是否有-l参数
int is_l(int argc,char const *argv[]);

// 显示路径path下所有文件的长格式
void show_file_all_info(char* path);

// 显示路径paht下所有文件的文件名
void show_file_names(char* path);


```
