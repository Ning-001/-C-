#pragma once
//主菜单
void main_menu();
//子菜单
void menu_01();
void menu_02();
void menu_03();
void menu_04();
void menu_05();
//子菜单下的功能模块
void menu_01_function_01();
void menu_01_function_02();
void menu_01_function_03();

void menu_02_function_01();
void menu_02_function_02();

void menu_03_function_01();
void menu_03_function_02();
void menu_03_function_03();

void menu_04_function_01();
void menu_04_function_02();
void menu_04_function_03();

void menu_05_function_01();
void menu_05_function_02();
void menu_05_function_03();

//牛顿第二定律
double Acceleration(double F,double m);

//运动学公式
double distance_01(double t,double a,double v0);

//摩擦力计算公式
double f(double Fn,double u);

//两倍中位差法去除离群值
void chazhi(double *result, int len);

//视觉效果的距离选择计算公式
double distance_02(double height,double angle);

//电视尺寸计算（不同角度标准）
double size(double distance,double angle);
int size1(double view_distance,double k1);
int size2(double view_distance,double k2);
double angle(int size,double distance);

//耳鸣风险自测操作指南
void operation_guide();

//耳鸣风险评价功能
void evaluation();

//耳鸣风险判断功能
void judgement(double db,double distance);

//存储个人听力档案的结构体
struct personal_file
{
    wchar_t name[30];
    double db[5];
    double dist[5];
    int count;
    struct personal_file * next;
};

//链表的各项操作

//添加节点
void add_node(struct personal_file * head01,wchar_t name[30],double db,double dist);

//存在节点，进行数据添加
void add_data(struct personal_file * head01,wchar_t name[30],double db,double dist);

//检查输入姓名是否在链表中已经存在
int check_name(struct personal_file * head01,wchar_t name[30]);

//创建个人听力档案功能
void personal_file_make(double result_end,double distance_end,struct personal_file*head01);

//打印档案/分析个人听力档案功能
void view_analysis(struct personal_file*head01);
void view_file(struct personal_file * head01);
void analysis_file(struct personal_file * head01);

//计算常数R
double R(double db,double distance);

// 计算最佳水温（℃）：冷藏蛋90℃防裂，常温蛋95℃提效
int calc_optimal_water_temp(int egg_state);

// 计算预热时间（分钟）：结合自定义功率、热效率、水量与初始水温
int calc_preheat_time(double water_volume, int target_temp, int init_water_temp, int stove_type, int power);

// 计算煮制时间（分钟）：蛋规格+熟度+水温修正
int calc_cook_time(int egg_size, int target_done, int water_temp);

// 生成正弦波
void generateSineWave(double amplitude, int durationMs);

// 将分贝转换为振幅
double dBToAmplitude(double dB);

// 播放音频
void playAudio();

// 清理资源
void cleanup();

// 播放指定分贝和持续时间的声音
void playSoundByDB(double dB, double durationSeconds);