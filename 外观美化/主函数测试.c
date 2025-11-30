#include<stdio.h>
#include"title.h"
#include <stdlib.h>
#include <locale.h>   // 本地化支持
#include <fcntl.h>    // 文件控制
#include <io.h>       // 控制台I/O支持
#include <math.h>
#include <string.h>
#include <wchar.h>
#include <Windows.h>
//全局变量 链表的头节点
struct personal_file *head = NULL;

#define SAMPLE_RATE 44100  // 采样率
#define FREQUENCY 8000     // 固定频率8kHz
#define PI 3.14159265358979323846
// 波形音频格式结构体
WAVEFORMATEX waveFormat;
HWAVEOUT hWaveOut;  // 波形输出设备句柄
WAVEHDR waveHeader; // 波形数据头
short *buffer;       // 音频缓冲区
int bufferSize;      // 缓冲区大小
// 设置控制台颜色
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// 获取控制台宽度
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

// 居中打印字符串
void printCentered(wchar_t* str, int color) {
    int consoleWidth = getConsoleWidth();
    int strLength = wcslen(str);
    int padding = (consoleWidth - strLength) / 2;
    
    setColor(color);
    for (int i = 0; i < padding; i++) {
        wprintf(L" ");
    }
    wprintf(L"%s\n", str);
    setColor(7); // 恢复默认颜色
}

//主菜单
void main_menu()
{
    
    int choice;
    while(1)
    {
        system("cls");
        
        // 设置控制台标题
        SetConsoleTitle(L"生活中的物理解题器");
        
        // 打印美化的标题
        setColor(11); // 亮青色
        printCentered(L"╔══════════════════════════════════════════════════╗", 11);
        printCentered(L"              生活中的物理解题器                ", 11); // 亮黄色
        printCentered(L"╚══════════════════════════════════════════════════╝", 11);
        
        wprintf(L"\n");
        
        // 打印主菜单
        printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
        printCentered(L"                  主菜单选项                  ", 10);
        printCentered(L"╠══════════════════════════════════════════════════╣", 10);
        setColor(15); // 白色
        
        // 打印带边框的菜单选项
        wchar_t menuItems[][50] = {
            L"                   1. 声学问题                    ",
            L"                   2. 光学问题                    ",
            L"                   3. 热学问题                    ",
            L"                   4. 力学问题                    ",
            L"                   5. 电学问题                    ",
            L"                   0. 退出程序                    "
        };
        
        for (int i = 0; i < 6; i++) {
            printCentered(menuItems[i], 15);
        }
        
        printCentered(L"╚══════════════════════════════════════════════════╝", 10);
        
        wprintf(L"\n");
        
        // 打印选择提示
        printCentered(L"请输入您的选择 (0-5): ", 13); // 亮紫色
        
        setColor(15); // 白色
        
        // 定位输入位置
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        COORD pos;
        pos.X = (getConsoleWidth() - 1) / 2;
        pos.Y = csbi.dwCursorPosition.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:menu_01();
            break;
            case 2:menu_02();
            break;
            case 3:menu_03();
            break;
            case 4:menu_04();
            break;
            case 5:menu_05();
            break;
            case 0: 
                setColor(12); // 红色
                printCentered(L"感谢使用，再见！", 12);
                Sleep(1000);
                exit(0);
            break;
            default:
                setColor(12); // 红色
                printCentered(L"输入错误，请重新选择！", 12);
                Sleep(1500);
                system("pause");
        }
    }
    
}
//子菜单 - 声学问题
void menu_01()
{
    int choice;
    while(1)
    {
        system("cls");
        
        // 打印美化的声学问题子菜单
        printCentered(L"╔══════════════════════════════════════════════════╗", 11);
        printCentered(L"生活中的物理解题器", 11);
        printCentered(L"╚══════════════════════════════════════════════════╝", 11);
        
        wprintf(L"\n");
        
        printCentered(L"╔══════════════════════════════════════════════════╗", 9); // 亮蓝色
        printCentered(L"声学问题子菜单", 9);
        printCentered(L"╠══════════════════════════════════════════════════╣", 9);
        
        // 菜单选项
        wchar_t menuItems[][50] = {
            L"1. 回声测距",
            L" 2. 耳鸣风险自测",
            L"0. 返回主菜单"
        };
        
        for (int i = 0; i < 3; i++) {
            printCentered(menuItems[i], 15);
        }
        
        printCentered(L"╚══════════════════════════════════════════════════╝", 9);
        
        wprintf(L"\n");
        
        // 打印选择提示
        printCentered(L"请输入您的选择 (0-2): ", 13); // 亮紫色
        
        setColor(15); // 白色
        
        // 定位输入位置
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        COORD pos;
        pos.X = (getConsoleWidth() - 1) / 2;
        pos.Y = csbi.dwCursorPosition.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: menu_01_function_01(); break;
            case 2: menu_01_function_02(); break;
            case 0: return;
            default:
                setColor(12); // 红色
                printCentered(L"输入错误，请重新选择！", 12);
                Sleep(1500);
        }
    }
}
//子功能模块
//01 回声测距   02 耳鸣风险自测
void menu_01_function_01()
{
    system("cls");
    
    // 设置控制台标题
    SetConsoleTitleW(L"生活中的物理解题器 - 回声测距");
    
    // 打印美化的标题和介绍
    setColor(11); // 亮青色
    printCentered(L"╔══════════════════════════════════════════════════╗", 11);
    printCentered(L"                    回声测距功能                    ", 14); // 亮黄色
    printCentered(L"╚══════════════════════════════════════════════════╝", 11);
    
    wprintf(L"\n");
    
    // 打印介绍信息
    printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
    setColor(15); // 白色
    printCentered(L"回声测距，利用声波传播的反射特性来确定距离", 15);
    printCentered(L"你需要提供温度和测量声音从发出到接收的时间", 15);
    printCentered(L" 间隔来求得距离", 15);
    printCentered(L"╚══════════════════════════════════════════════════╝", 10);
    
    wprintf(L"\n");
    printCentered(L"                  按任意键继续...                  ", 13); // 亮紫色
    setColor(15); // 白色
    system("pause > nul");
    
    // 温度输入和音速计算部分
    system("cls");
    setColor(11); // 亮青色
    printCentered(L"╔══════════════════════════════════════════════════╗", 11);
    printCentered(L"                    回声测距功能                    ", 14); // 亮黄色
    printCentered(L"╚══════════════════════════════════════════════════╝", 11);
    
    wprintf(L"\n");
    
    printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
    printCentered(L"为减小误差，需要输入五次数据求平均值", 15);
    printCentered(L"╚══════════════════════════════════════════════════╝", 10);
    
    wprintf(L"\n");
    wprintf(L"\n");
    
    // 输入温度
    printCentered(L"             请输入当前环境的温度：             ", 13); // 亮紫色
    
    // 定位输入位置
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD pos;
    pos.X = csbi.dwCursorPosition.X + 10;
    pos.Y = csbi.dwCursorPosition.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    
    //输入温度，计算音速
    int temp=0;
    scanf("%d",&temp);
    
    system("cls");
    
    setColor(11); // 亮青色
    printCentered(L"╔══════════════════════════════════════════════════╗", 11);
    printCentered(L"                    回声测距功能                    ", 14); // 亮黄色
    printCentered(L"╚══════════════════════════════════════════════════╝", 11);
    
    wprintf(L"\n");
    
    printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
    setColor(15); // 白色
    
    // 显示温度和计算的音速
    wchar_t tempStr[50];
    swprintf(tempStr, 50, L"当前环境温度：%d°C", temp);
    printCentered(tempStr, 15);
    
    double v=331+0.6*temp;
    wchar_t vStr[50];
    swprintf(vStr, 50, L"经计算当前声速近似为：%.0lf m/s", v);
    printCentered(vStr, 15);
    
    printCentered(L"╚══════════════════════════════════════════════════╝", 10);
    
    wprintf(L"\n");
    printCentered(L"                按任意键继续输入时间数据...                ", 13); // 亮紫色
    setColor(15); // 白色
    system("pause > nul");
    
    // 录入五次时间数据
    system("cls");
    setColor(11); // 亮青色
    printCentered(L"╔══════════════════════════════════════════════════╗", 11);
    printCentered(L"                    回声测距功能                    ", 14); // 亮黄色
    printCentered(L"╚══════════════════════════════════════════════════╝", 11);
    
    wprintf(L"\n");
    
    printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
    printCentered(L"           请输入五次时间间隔测量数据           ", 15);
    printCentered(L"╚══════════════════════════════════════════════════╝", 10);
    
    wprintf(L"\n");
    
    double result[5];
    for(int i=0; i<5; i++)
    {
        result[i] = 0;
        wprintf(L"\n");
        wchar_t timePrompt[50];
        swprintf(timePrompt, 50, L"请输入第%d次测量的时间间隔 (单位：秒): ", i+1);
        printCentered(timePrompt, 13); // 亮紫色
        
        // 定位输入位置
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        pos.X = csbi.dwCursorPosition.X + 10;
        pos.Y = csbi.dwCursorPosition.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        
        scanf("%lf", &result[i]);
    }
    
    // 显示警告信息
    system("cls");
    setColor(12); // 红色
    printCentered(L"╔══════════════════════════════════════════════════════════════╗", 12);
    printCentered(L"                       *****警告*****                       ", 12);
    printCentered(L" 人为测量的时间可能存在错误数据，接下来使用", 12);
    printCentered(L" “两倍中位差法”进行精度提升操作", 12);
    printCentered(L"╚══════════════════════════════════════════════════════════════╝", 12);
    
    wprintf(L"\n");
    printCentered(L"                  按任意键继续...                  ", 13); // 亮紫色
    setColor(15); // 白色
    system("pause > nul");
    
    // 数据处理和结果显示
    system("cls");
    setColor(11); // 亮青色
    printCentered(L"╔══════════════════════════════════════════════════╗", 11);
    printCentered(L"                    回声测距功能                    ", 14); // 亮黄色
    printCentered(L"╚══════════════════════════════════════════════════╝", 11);
    
    wprintf(L"\n");
    
    printCentered(L"╔══════════════════════════════════════════════════╗", 10); // 绿色
    setColor(15); // 白色
    printCentered(L"                    数据处理结果                    ", 15);
    printCentered(L"╠══════════════════════════════════════════════════╣", 10);
    
    // 显示原始数据
    printCentered(L"              原始测量数据：              ", 15);
    wchar_t originalData[100] = L"";
    for(int i=0; i<5; i++)
    {
        wchar_t tempNum[20];
        swprintf(tempNum, 20, L"%.2lf ", result[i]);
        wcscat(originalData, tempNum);
    }
    printCentered(originalData, 15);
    
    // 调用两倍中位差法的函数，去除离群值
    int len = 5;
    chazhi(result, len);
    
    // 显示处理后的数据
    printCentered(L"           处理后剩余时间数据：           ", 15);
    wchar_t processedData[100] = L"";
    for(int i=0; i<5; i++)
    {
        if(result[i] != 0)
        {
            wchar_t tempNum[20];
            swprintf(tempNum, 20, L"%.2lf ", result[i]);
            wcscat(processedData, tempNum);
        }
    }
    printCentered(processedData, 15);
    
    // 计算时间的平均值和距离
    double sum = 0;
    len = 5;
    for(int i=0; i<5; i++)
    {
        if(result[i] == 0)
        {
            len--;
        }
        else
        {
            sum += result[i];
        }
    }
    
    sum = sum / (2 * len);
    double distance = distance_01(sum, 0, v);
    
    // 显示最终结果
    printCentered(L"╠══════════════════════════════════════════════════╣", 10);
    printCentered(L"                      计算结果                      ", 14); // 亮黄色
    
    wchar_t distanceStr[50];
    swprintf(distanceStr, 50, L"测算的大致距离为：%.2lf 米", distance);
    printCentered(distanceStr, 11); // 亮青色
    
    printCentered(L"╚══════════════════════════════════════════════════╝", 10);
    
    wprintf(L"\n");
    printCentered(L"                按任意键返回...                ", 13); // 亮紫色
    setColor(15); // 白色
    system("pause > nul");
}
void menu_01_function_02()
{
    system("cls");
    int choice;
    while(1) {
        wprintf(L"====== 耳鸣风险自测======\n");
        wprintf(L"    1. 操作指南\n");
        wprintf(L"    2. 即时评估\n");
        wprintf(L"    3. 查看及分析听力档案\n");
        wprintf(L"    0. 返回上一级菜单\n");
        wprintf(L"\n");
        wprintf(L"    请选择: ");
        scanf("%d", &choice);
        system("pause");
        system("cls");
        switch(choice) {
            case 1: operation_guide();
                    continue;
                    break;
            case 2: evaluation();
                    system("cls");
                    continue;
                    break;
            case 3: view_analysis(head);
                    system("cls");
                    continue;
                    break;
            case 0:return;
            default:
                wprintf(L"输入错误\n");
                system("pause");
                continue;
        }
    }
}

//子菜单 - 光学问题
void menu_02()
{
    int choice;
    while(1)
    {
        system("cls");
        
               // 打印美化的光学问题子菜单
        printCentered(L"╔══════════════════════════════════════════════════╗", 11);
        printCentered(L"生活中的物理解题器", 11);
        printCentered(L"╚══════════════════════════════════════════════════╝", 11);
        
        wprintf(L"\n");
         printCentered(L"╔══════════════════════════════════════════════════╗", 9); // 亮蓝色
        printCentered(L"光学问题子菜单", 9);
        printCentered(L"╠══════════════════════════════════════════════════╣", 9);
    // 菜单选项
        wchar_t menuItems[][50] = {
            L"    1. 最佳视角的距离选取",
            L"    2. 电视最佳尺寸选取",
            L"0. 返回主菜单"
        };
        
        
        for (int i = 0; i < 3; i++) {
            printCentered(menuItems[i], 15);
        }
        
        printCentered(L"╚══════════════════════════════════════════════════╝", 9);
        
        wprintf(L"\n");
        
        // 打印选择提示
        printCentered(L"请输入您的选择 (0-2): ", 13); // 亮紫色
        
        setColor(15); // 白色
        
        // 定位输入位置
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        COORD pos;
        pos.X = (getConsoleWidth() - 1) / 2;
        pos.Y = csbi.dwCursorPosition.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:menu_02_function_01();
            break;
            case 2:menu_02_function_02();
            break;
            case 0:return;
            break;
            default:
                setColor(12); // 红色
                printCentered(L"输入错误，请重新选择！", 12);
                Sleep(1500);
        }
    }
    
}
//子功能模块
//01 视觉距离  02 电视尺寸推荐
void menu_02_function_01()
{
    int choice;
    while(1)
    {
    system("cls");
    wprintf(L"====== 最佳视角距离选取 ======\n");
    wprintf(L"   1. 护眼视角距离选取\n");
    wprintf(L"   2. 沉浸观影视角距离选取\n");
    wprintf(L"\n");
    wprintf(L"请选择: \n");
    scanf("%d", &choice);
    system("pause");
    system("cls");
    switch(choice)
    {
        case 1:wprintf(L"请输入屏幕长度:  (单位为cm)\n");
               double length = 0 ;
               scanf("%lf",&length);
               double dis = 0;
               dis = distance_02(length,0.35);//0.35 是基于视觉角度20°，运用视觉角公式计算出的常数
               wprintf(L"护眼最佳视觉角为 20° \n");
               wprintf(L"在此视觉角下眼部较为放松\n");
               wprintf(L"距离屏幕的最佳距离为：%.2lfcm\n",dis);
               system("pause");
               return;
        break;
        case 2: wprintf(L"请输入屏幕长度:  (单位为cm)\n");
               double length1 = 0 ;
               scanf("%lf",&length1);
               double dis1 = 0;
               dis1 = distance_02(length1,0.7);//0.7 是基于视觉角度40°，运用视觉角公式计算出的常数
               wprintf(L"沉浸观影最佳视觉角为 40° \n");
               wprintf(L"距离屏幕的最佳距离为：%.2lfcm\n",dis1);
               system("pause");
               return;
        break;
        default:
        wprintf(L"输入错误");
        system("pause");
    }
    }
}
void menu_02_function_02()
{ 
    //基础尺寸
    int base_size = 0;
    //基于像素密度计算出的尺寸
    int size_PPI = 0;
    //基于55°视觉角警戒线计算出的尺寸
    int size_55 = 0;
    //存储选择的分辨率和视觉效果
    char fenbian[10];
    char xiaoguo[30];
    //观看距离
    double view_distance = 0;
    double k2 = 0;//待选择的分辨率系数
    //不同视觉角度下，运用视觉角公式计算出的常数
    double k3 = 0.3640;
    double k4 = 0.2679;
    double k5 = 0.1763;
    int size_1 =0;
    int size_2 = 0;
    int size_3 = 0;
    while(1)
    {
    int choice = 0;
    system("cls");
    wprintf(L"====== 电视尺寸推荐问题 ======\n");
    wprintf(L"====== 请选择需要的效果 ======\n");
    wprintf(L"     1. 影院沉浸式\n");
    wprintf(L"     2. 通用舒适观影\n");
    wprintf(L"     3. 兼顾背景墙协调\n");
    wprintf(L"\n");
    wprintf(L"请选择: \n");
    scanf("%d", &choice);
    system("pause");
    system("cls");
    double k1 = 0;
    switch(choice)
    {
        //不同视觉角度下，运用视觉角公式计算出的常数
        case 1:k1 = 0.3640;
         wcscpy(xiaoguo, L"影院沉浸式");
        break;
        case 2:k1 = 0.2679;
         wcscpy(xiaoguo, L"通用舒适观影");
        break;
        case 3:k1 = 0.1763;
         wcscpy(xiaoguo, L"兼顾背景墙协调");
        break;
        default:
        wprintf(L"输入错误");
        system("pause");
        continue;
    }
    wprintf(L"===== 请输入观看距离 单位(m) ======\n");
    scanf("%lf",&view_distance);
    base_size = size1(view_distance,k1);
    wprintf(L"\n");
    system("pause");
    system("cls");
    break;
    }
    
   while(1)
    {
    int choice2 = 0;
    wprintf(L"====== 请选择分辨率 ======\n");
    wprintf(L"      1. 1080P\n");
    wprintf(L"      2. 4K\n");
    wprintf(L"      3. 8K\n");
    wprintf(L"\n");
    wprintf(L"请选择: \n");
    scanf("%d",&choice2);
    system("pause");
    system("cls");
    switch(choice2)
    {
        case 1:k2 =1;
            wcscpy(fenbian, L"1080P");
        break;
        case 2:k2 =2;
            wcscpy(fenbian, L"4k");
        break;
        case 3:k2 = 4;
            wcscpy(fenbian, L"8K");
        break;
        default:
        wprintf(L"输入错误");
        system("pause");
        continue;
    } 
    break;
    }
    size_55 = size1(view_distance,0.5206);
    size_PPI = size2(view_distance,k2);
    size_1 = size1(view_distance,k5);//小
    size_2 = size1(view_distance,k4);
    size_3 = size1(view_distance,k3);//大
    wprintf(L"===== 电视尺寸推荐报告 =====\n");
    wprintf(L"观看距离：%.2lf 米\n",(view_distance));
    wprintf(L"选择分辨率： %s\n",fenbian);
    wprintf(L"选择的视觉效果：%s\n",xiaoguo);
    wprintf(L"基础尺寸为：%d寸\n",base_size);
    wprintf(L"分辨率下保证清晰度的最大尺寸为：%d寸\n",size_PPI);
    wprintf(L"视觉角度55°警戒线为:%d寸\n",size_55);

    wprintf(L"\n=====基础尺寸评价=====\n");
    wprintf(L"基础尺寸为：%d寸\n",base_size);
     if(base_size >= size_3) {
        wprintf(L"沉浸式影院体验(IMAX级视觉包裹感)\n");
    } else if(base_size >=size_2 ) {
        wprintf(L"舒适观影体验（平衡画质与眼睛舒适度）\n");
    } else {
        wprintf(L"协调性优先（适合背景装饰为主的场景）\n");
    }

    wprintf(L"\n====分辨率下保证清晰度的最大尺寸评价====\n");
    wprintf(L"分辨率下保证清晰度的最大尺寸为：%d寸\n",size_PPI);
    if(size_PPI > size_55) {
        wprintf(L"警告: 视角过大(>55°)可能导致眩晕\n");
        wprintf(L"建议尺寸不超过%d英寸\n", size_55);
    } else if(size_PPI >= size_3) {
        wprintf(L"沉浸式影院体验(IMAX级视觉包裹感)\n");
    } else if(size_PPI >= size_2) {
        wprintf(L"舒适观影体验（平衡画质与眼睛舒适度）\n");
    } else {
        wprintf(L"协调性优先（适合背景装饰为主的场景）\n");
    }
    wprintf(L"\n");
    system("pause");
    system("cls");
    wprintf(L"\n====尺寸购买建议====\n");
    //通过罗列所有情况，去给出尺寸购买建议
     if(base_size>=size_PPI)
    {
        wprintf(L"***警告***\n");
        wprintf(L"当前清晰度不支持你所选择的视觉效果\n");
        wprintf(L"建议降低视觉效果，或者提高清晰度\n");
    }
   if(size_PPI<size_55||size_PPI>=size_55)
    {
        if(size_1<=base_size&&base_size<size_2
        )
        {
        wprintf(L"基础尺寸为：%d寸\n",base_size);
        wprintf(L"当前视觉效果为：%s\n",xiaoguo);
        wprintf(L"\n");
        wprintf(L"可以升高尺寸到：%d寸\n",size_2);
        wprintf(L"获得视觉效果：通用舒适观影\n");
        wprintf(L"\n");
        wprintf(L"可以升高尺寸到：%d寸\n",size_3);
        wprintf(L"获得视觉效果：影院沉浸式\n"); 
        }
        if(base_size>=size_2&&base_size<size_3)
        {
        wprintf(L"基础尺寸为：%d寸\n",base_size);
        wprintf(L"当前视觉效果为：%s\n",xiaoguo);
        wprintf(L"\n");
        wprintf(L"可以升高尺寸到：%d寸\n",size_3);
        wprintf(L"获得视觉效果：影院沉浸式\n"); 
        }
        if(base_size>=size_3)
        {
        wprintf(L"基础尺寸为：%d寸\n",base_size);
        wprintf(L"当前视觉效果为：%s\n",xiaoguo);
        wprintf(L"非必要无需升高尺寸\n"); 
        }
        if(size_PPI<size_55)
        {
        wprintf(L"\n***注意***\n");
        wprintf(L"购买的区间严格控制为：%d-%d寸\n",base_size,(size_PPI-5));
        }
        if(size_PPI>=size_55)
        {
        wprintf(L"***注意***\n");
        wprintf(L"购买的区间严格控制为：%d-%d寸\n",base_size,(size_55-5));
        }
        
    }
    system("pause");
    return;
     
}

//子菜单 - 热学问题
void menu_03()
{
    int choice;
    while(1)
    {
        system("cls");
        
        // 打印美化的热学问题子菜单
        printCentered(L"╔══════════════════════════════════════════════════╗", 11);
        printCentered(L"生活中的物理解题器", 11);
        printCentered(L"╚══════════════════════════════════════════════════╝", 11);
        
        wprintf(L"\n");
        
        printCentered(L"╔══════════════════════════════════════════════════╗", 12); // 红色
        printCentered(L"热学问题子菜单", 12);
        printCentered(L"╠══════════════════════════════════════════════════╣", 12);
        
        // 菜单选项
        wchar_t menuItems[][50] = {
            L" 1. 空调功率推荐",
            L" 2. 煮出完美鸡蛋",
            L"0. 返回主菜单"
        };
        
        for (int i = 0; i < 3; i++) {
            printCentered(menuItems[i], 15);
        }
        
        printCentered(L"╚══════════════════════════════════════════════════╝", 12);
        
        wprintf(L"\n");
        
        // 打印选择提示
        printCentered(L"请输入您的选择 (0-2): ", 13); // 亮紫色
        
        setColor(15); // 白色
        
        // 定位输入位置
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        COORD pos;
        pos.X = (getConsoleWidth() - 1) / 2;
        pos.Y = csbi.dwCursorPosition.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:menu_03_function_01();
            break;
            case 2:menu_03_function_02();
            break;
            case 0:return;
            break;
            default:
                setColor(12); // 红色
                printCentered(L"输入错误，请重新选择！", 12);
                Sleep(1500);
        }
    }
}
//子功能模块
//01 空调选取  02 煮出完美鸡蛋
void menu_03_function_01()
{
    system("cls");
    wprintf(L"====== 空调功率推荐 ======\n");
    wprintf(L"根据房间面积、层高、朝向等因素\n推荐合适的空调功率\n");
    wprintf(L"\n");
    system("pause");
    system("cls");
    wprintf(L"请输入房间面积（平方米）: ");
    double area;
    if(scanf("%lf", &area) != 1 || area <= 0) {
        wprintf(L"输入错误！面积必须大于0！\n");
        while(getchar() != '\n');
        system("pause");
        return;
    }
    
    wprintf(L"请输入房间层高（米）: ");
    double height;
    if(scanf("%lf", &height) != 1 || height <= 0) {
        wprintf(L"输入错误！层高必须大于0！\n");
        while(getchar() != '\n');
        system("pause");
        return;
    }
    
    wprintf(L"请选择房间朝向:\n");
    wprintf(L"    1. 南向（阳光充足，+20%%）\n");
    wprintf(L"    2. 东/西向（有阳光，+10%%）\n");
    wprintf(L"    3. 北向（无直射阳光，0%%）\n");
    wprintf(L"请选择: ");
    wprintf(L"\n");
    int direction;
    scanf("%d", &direction);
    double direction_factor = 1.0;
    switch(direction) {
        case 1: direction_factor = 1.2; break;
        case 2: direction_factor = 1.1; break;
        case 3: direction_factor = 1.0; break;
        default:
            wprintf(L"输入错误，默认按北向计算\n");
            direction_factor = 1.0;
    }
    
    wprintf(L"请选择楼层位置:\n");
    wprintf(L"    1. 顶层（+15%%）\n");
    wprintf(L"    2. 中间层（0%%）\n");
    wprintf(L"    3. 底层（-5%%）\n");
    wprintf(L"请选择: ");
    int floor_choice;
    scanf("%d", &floor_choice);
    double floor_factor = 1.0;
    switch(floor_choice) {
        case 1: floor_factor = 1.15; break;
        case 2: floor_factor = 1.0; break;
        case 3: floor_factor = 0.95; break;
        default:
            floor_factor = 1.0;
    }
    
    // 计算所需制冷量（W）
    // 基础公式：每平方米需要150W制冷量
    double volume = area * height;
    double base_power = area * 150; // 基础功率
    double total_power = base_power * direction_factor * floor_factor;
    
    // 转换为匹数（1匹 ≈ 2500W）
    double horse_power = total_power / 2500.0;
    
    system("cls");
    wprintf(L"====== 空调功率推荐结果 ======\n");
    wprintf(L"房间面积: %.2lf 平方米\n", area);
    wprintf(L"房间层高: %.2lf 米\n", height);
    wprintf(L"房间体积: %.2lf 立方米\n", volume);
    wprintf(L"\n");
    wprintf(L"推荐制冷量: %.0lf W\n", total_power);
    wprintf(L"推荐匹数: %.1lf 匹\n", horse_power);
    wprintf(L"\n");
    wprintf(L"建议选择: ");
    if(horse_power < 1.0) {
        wprintf(L"1匹（适合小房间）\n");
    } else if(horse_power < 1.5) {
        wprintf(L"1.5匹（适合中小房间）\n");
    } else if(horse_power < 2.0) {
        wprintf(L"2匹（适合中等房间）\n");
    } else if(horse_power < 3.0) {
        wprintf(L"2.5-3匹（适合大房间）\n");
    } else {
        wprintf(L"3匹以上（适合超大房间或商业场所）\n");
    }
    wprintf(L"\n");
    wprintf(L"注意：实际选择时可适当增加10-20%%余量\n");
    system("pause");
    
}
void menu_03_function_02() {
    while(1) {
     // 输入参数
    int egg_size = 0, egg_state = 0, target_done = 0, stove_type = 0, power = 0;
    int init_water_temp = 0; // 新增：初始水温（℃）
    double water_volume = 0.0;
    // 输出参数
    int optimal_temp = 0, preheat_time = 0, cook_time = 0;
    const int cool_time = 3; // 固定冷却时间
    // 描述变量
    wchar_t size_desc[30], state_desc[30], done_desc[30], stove_desc[30], power_desc[30];
        // ===== 第一步：蛋品基础信息 =====
        while(1) {
            system("cls");
            wprintf(L"====== 煮蛋熟度精准控制方案 ======\n");
            wprintf(L"====== 第一步：蛋品基础信息 ======\n");
            wprintf(L"1. 蛋的规格（按重量）：\n");
            wprintf(L"   1-小型（≤50g，土鸡蛋）\n   2-中型（50-60g，普通鸡蛋）\n   3-大型（≥60g，柴鸡蛋）\n   0.返回上级菜单\n");
            wprintf(L"请选择（0-3）：");
            if(scanf("%d", &egg_size) != 1 || egg_size < 0 || egg_size > 3) {
                wprintf(L"输入错误！请输入1-3\n");
                while(getchar() != '\n'); // 清空输入缓冲区
                system("pause");
                continue;
            }
            // 赋值描述
            switch(egg_size) {
                case 1: wcscpy(size_desc, L"小型（≤50g，土鸡蛋）"); break;
                case 2: wcscpy(size_desc, L"中型（50-60g，普通鸡蛋）"); break;
                case 3: wcscpy(size_desc, L"大型（≥60g，柴鸡蛋）"); break;
                case 0: return; break;
            }

            wprintf(L"\n2. 蛋的状态：\n");
            wprintf(L"   1-冷藏（冰箱取出，约4℃）\n   2-常温（放置2小时以上，约20℃）\n");
            wprintf(L"请选择（1-2）：");
            if(scanf("%d", &egg_state) != 1 || egg_state < 1 || egg_state > 2) {
                wprintf(L"输入错误！请输入1或2\n");
                while(getchar() != '\n');
                system("pause");
                continue;
            }

            switch(egg_state) {
                case 1: wcscpy(state_desc, L"冷藏（约4℃）"); break;
                case 2: wcscpy(state_desc, L"常温（约20℃）"); break;
            }
            break;
        }

        // ===== 第二步：熟度、水量与初始水温 =====
        while(1) {
            system("cls");
            wprintf(L"====== 第二步：熟度、水量与初始水温 ======\n");
            wprintf(L"1. 目标熟度：\n");
            wprintf(L"   1-溏心（蛋黄流质，蛋白凝固）\n   2-半熟（蛋黄绵密，中心微凝）\n   3-全熟（蛋黄凝固，口感沙软）\n");
            wprintf(L"请选择（1-3）：");
            if(scanf("%d", &target_done) != 1 || target_done < 1 || target_done > 3) {
                wprintf(L"输入错误！请输入1-3\n");
                while(getchar() != '\n');
                system("pause");
                continue;
            }

            wprintf(L"\n2. 请输入加水量（升，建议≥0.3L且没过蛋2cm）：");
            if(scanf("%lf", &water_volume) != 1 || water_volume < 0.3 || water_volume > 5.0) {
                wprintf(L"输入错误！请输入0.3-5.0之间的数值\n");
                while(getchar() != '\n');
                system("pause");
                continue;
            }

            wprintf(L"\n3. 请输入初始水温（℃，常温约20℃，热水约40-60℃）：");
            if(scanf("%d", &init_water_temp) != 1 || init_water_temp < 5 || init_water_temp > 80) {
                wprintf(L"输入错误！请输入5-80之间的数值（避免结冰或过热）\n");
                while(getchar() != '\n');
                system("pause");
                continue;
            }

            // 赋值熟度描述
            switch(target_done) {
                case 1: wcscpy(done_desc, L"溏心蛋（蛋黄流质，蛋白凝固）"); break;
                case 2: wcscpy(done_desc, L"半熟蛋（蛋黄绵密，中心微凝）"); break;
                case 3: wcscpy(done_desc, L"全熟蛋（蛋黄凝固，口感沙软）"); break;
            }
            break;
        }

        // ===== 第三步：炉灶与功率选择 =====
        while(1) {
            system("cls");
            wprintf(L"====== 第三步：炉灶与功率选择 ======\n");
            wprintf(L"1. 炉灶类型：\n");
            wprintf(L"   1-电磁炉\n   2-燃气灶\n   3-电陶炉\n");
            wprintf(L"请选择（1-3）：");
            if(scanf("%d", &stove_type) != 1 || stove_type < 1 || stove_type > 3) {
                wprintf(L"输入错误！请输入1-3\n");
                while(getchar() != '\n');
                system("pause");
                continue;
            }

            // 功率选择
            wprintf(L"\n2. 功率选择：\n");
            if(stove_type == 1) { // 电磁炉功率选项
                wprintf(L"   1-1600W（低档）\n   2-2100W（中档）\n   3-2600W（高档）\n");
                wprintf(L"请选择（1-3）：");
                int power_choice;
                if(scanf("%d", &power_choice) != 1 || power_choice < 1 || power_choice > 3) {
                    wprintf(L"输入错误！请输入1-3\n");
                    while(getchar() != '\n');
                    system("pause");
                    continue;
                }
                power = (power_choice == 1) ? 1600 : (power_choice == 2) ? 2100 : 2600;
            } else if(stove_type == 2) { // 燃气灶功率（按火力档位估算）
                wprintf(L"   1-小火（≈1500W）\n   2-中火（≈3000W）\n   3-大火（≈4500W）\n");
                wprintf(L"请选择（1-3）：");
                int power_choice;
                if(scanf("%d", &power_choice) != 1 || power_choice < 1 || power_choice > 3) {
                    wprintf(L"输入错误！请输入1-3\n");
                    while(getchar() != '\n');
                    system("pause");
                    continue;
                }
                power = (power_choice == 1) ? 1500 : (power_choice == 2) ? 3000 : 4500;
            } else { // 电陶炉功率选项
                wprintf(L"   1-1200W（低档）\n   2-2000W（中档）\n   3-2800W（高档）\n");
                wprintf(L"请选择（1-3）：");
                int power_choice;
                if(scanf("%d", &power_choice) != 1 || power_choice < 1 || power_choice > 3) {
                    wprintf(L"输入错误！请输入1-3\n");
                    while(getchar() != '\n');
                    system("pause");
                    continue;
                }
                power = (power_choice == 1) ? 1200 : (power_choice == 2) ? 2000 : 2800;
            }

            // 赋值描述
            switch(stove_type) {
                case 1: wcscpy(stove_desc, L"电磁炉"); break;
                case 2: wcscpy(stove_desc, L"燃气灶"); break;
                case 3: wcscpy(stove_desc, L"电陶炉"); break;
            }
            swprintf(power_desc, sizeof(power_desc)/sizeof(wchar_t), L"%dW", power);
            break;
        }

        // ===== 核心计算 =====
        optimal_temp = calc_optimal_water_temp(egg_state);
        preheat_time = calc_preheat_time(water_volume, optimal_temp, init_water_temp, stove_type, power);
        cook_time = calc_cook_time(egg_size, target_done, optimal_temp);

        // ===== 输出报告（优化格式）=====
        system("cls");
        wprintf(L"=====================================\n");
        wprintf(L"======== 煮蛋精准控制方案报告 ========\n");
        wprintf(L"=====================================\n");
        wprintf(L"蛋品规格：%s\n", size_desc);
        wprintf(L"蛋品状态：%s\n", state_desc);
        wprintf(L"目标熟度：%s\n", done_desc);
        wprintf(L"加水量：%.1fL（建议确保没过蛋2cm）\n", water_volume);
        wprintf(L"初始水温：%d℃\n", init_water_temp);
        wprintf(L"炉灶配置：%s（%s）\n", stove_desc, power_desc);

        system("\npause");
        system("cls");

        wprintf(L"=====================================\n");
        wprintf(L"======== 核心操作参数 ========\n");
        wprintf(L"最佳水温：%d℃\n", optimal_temp);
        if(preheat_time == 0) {
            wprintf(L"冷水下锅预热时间：无需预热（初始水温已达标）\n");
        } else {
            wprintf(L"冷水下锅预热时间：%d分钟\n", preheat_time);
        }
        wprintf(L"恒温煮制时间：%d分钟\n", cook_time);
        wprintf(L"出锅冷却时间：%d分钟（冰水更佳）\n", cool_time);

        system("\npause");
        system("cls");

        wprintf(L"=====================================\n");
        wprintf(L"======== 关键操作技巧 ========\n");
        if(egg_state == 1) {
            wprintf(L"- 冷藏蛋防破壳：提前回温10分钟，或90℃温水下锅\n");
            wprintf(L"- 下锅时沿锅边轻放，避免撞击蛋壳\n");
        }
        if(target_done == 1) {
            wprintf(L"- 溏心蛋控时：煮制时间误差≤30秒，用计时器精准把控\n");
            wprintf(L"- 冷却用冰水，快速锁鲜蛋黄流质状态\n");
        } else if(target_done == 3) {
            wprintf(L"- 全熟蛋优化：煮后焖5分钟，蛋黄口感更沙软，避免外层发黑\n");
        }
        if(power < 2000) {
            wprintf(L"- 低功率提示：预热时间会延长，建议适当增加水量避免烧干\n");
        } else if(power > 3000) {
            wprintf(L"- 高功率提示：煮制时需调小火保持恒温，防止水温骤沸破壳\n");
        }
        if(water_volume < 0.5) {
            wprintf(L"- 水量较少提示：需频繁观察水温，避免干锅\n");
        }
        if(init_water_temp > optimal_temp) {
            wprintf(L"- 初始水温过高提示：直接将蛋下锅，无需等待升温，避免水温过高破壳\n");
        }
        system("\npause");
        system("cls");

    }
}


void menu_04()
{
    int choice;
    while(1)
    {
    system("cls");
    wprintf(L"====== 子菜单04 ======\n");
    wprintf(L"1. 进入功能1\n");
    wprintf(L"2. 进入功能2\n");
    wprintf(L"3. 进入功能3\n");
    wprintf(L"0. 返回主菜单\n");
    wprintf(L"请选择: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:menu_04_function_01();
        break;
        case 2:menu_04_function_02();
        break;
        case 3:menu_04_function_03();
        break;
        case 0:return;
        break;
        default:
        wprintf(L"输入错误");
        system("pause");
    }
    }

}

void menu_04_function_01()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
    
}
void menu_04_function_02()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
}
void menu_04_function_03()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
}


void menu_05()
{
    int choice;
    while(1)
    {
    system("cls");
    wprintf(L"====== 子菜单05 ======\n");
    wprintf(L"1. 进入功能1\n");
    wprintf(L"2. 进入功能2\n");
    wprintf(L"3. 进入功能3\n");
    wprintf(L"0. 返回主菜单\n");
    wprintf(L"请选择: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:menu_05_function_01();
        break;
        case 2:menu_05_function_02();
        break;
        case 3:menu_05_function_03();
        break;
        case 0:return;
        break;
        default:
        wprintf(L"输入错误");
        system("pause");
    }
    }

}

void menu_05_function_01()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
}
void menu_05_function_02()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
}
void menu_05_function_03()
{
    wprintf(L"你已经进入这个功能");
    system("pause");
}

//加速度计算公式   F力  m质量
double Acceleration(double F,double m)
{
    if(m!=0)
    {
      double a=F/m;
      return a;  
    }
    else 
    {
        return 0;
    }
    
}
//运动学公式   计算距离  t时间 a加速度 v0初速度
double distance_01(double t,double a,double v0)
{
    double dis=v0*t+(a*t*t)/2;
    return  dis; 
}
//摩擦力计算公式 Fn正压力 u摩擦系数
double f(double Fn,double u)
{
    double f=u*Fn;
    return f;
}
//距离计算  height 屏幕高度  angle 视觉角度
double distance_02(double height,double angle)
{
    double d=height/(2*tan(angle/2));
    return d;
}
//两倍中位差法 传入数组，为记录的数据，len为数组长度
void chazhi(double a[],int len)
{
//原数组排序
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(*(a+i)>*(a+j))
            {
                double temp = *(a+i);
                *(a+i)=*(a+j);
                *(a+j)=temp;
            }
        }
    }
    double zhong1 = 0;
    //查找原数组的中位数
    if(len%2==0)
    {
        zhong1=(*(a+len/2)+*(a+(len/2)-1))/2;
    }
    else{
        zhong1=*(a+((len+1)/2)-1);
    }
    double cha[len];
    //计算差值
    for(int i=0;i<len;i++)
    {
        cha[i]=fabs(zhong1-(*(a+i)));
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(cha[i]>cha[j])
            {
                double temp=cha[i];
                cha[i]=cha[j];
                cha[j]=temp;
            }
        }
    }
    //找到差值的中位数
    double zhong2 = 0;
    if(len%2==0)
    {
        zhong2=(cha[len/2]+cha[((len/2)-1)])/2;
    }
    else{
        zhong2=cha[(((len+1)/2)-1)];
    }
    //计算出上下限
    double shang = zhong1+2*zhong2;
    double xia = zhong1-2*zhong2;
    for(int i=0;i<len;i++)
    {
        if(*(a+i)>shang||*(a+i)<xia)
        {
            *(a+i) = 0;
        }
    }
}
//电视尺寸问题,视觉角公式 distance为观看距离 angle 为视觉角度
double size(double distance,double angle)
{
    double height = 2*distance*tan(angle/2);
    return height;
}
//不同视觉效果 view_distance 为观看角度  k为系数
int size1(double view_distance,double k)
{
    double width = 2*view_distance*k;
    int TV_size =(int)( width*1.147*39.37);
    return TV_size;
}
//视觉角度计算   size为尺寸大小  distance为观看距离
double angle(int size,double distance)
{
    double width =size*16/(39.37*sqrt(16*16+9*9));
    double temp =2*atan(width/(2*distance));
    double ang = temp*180/3.1415926;
    return ang;
}
//PPI尺寸计算
int size2(double view_distance,double k2)
{
    int size =(int) (view_distance*k2*37.88);//换算单位本来应该是39.37，但是算大的话可能会错，宁可算小不能算大
    return size;
}
//耳鸣自测操作指南打印
void operation_guide()
{
        wprintf(L"====== 操作指南======\n");
        wprintf(L" *所需工具*\n");
        wprintf(L"1.使用在线网页生成正弦波纯音\n");
        wprintf(L"2.使用在线网页分贝仪用于测量分贝值\n");
        wprintf(L"3.能够播放声音且可调节音量的设备：手机或者电脑");
        wprintf(L"4.一个纸团用于发出声音\n");
        wprintf(L" \n*操作方法*\n");
        wprintf(L" 1.使用在线网页生成一段8k赫兹的正弦波纯音\n");
        wprintf(L" 2.打开在线网页分贝仪，并保证周围环境的相对安静\n");
        wprintf(L" 3.使用设备先以最小音量播放生成的音频\n");
        wprintf(L" 4.慢慢调高音量，记录下刚刚好听到声音时的分贝值\n");
        wprintf(L" 6.记录下阈值后马上进行下步操作\n");
        wprintf(L" 7.用手轻柔纸团，并缓慢远离自己，直到听不见纸团的声音\n");
        wprintf(L" 8.测量并输入距离值\n");
        wprintf(L" 9.为了减小误差，请重复进行三次\n");
        system("\npause");
        system("cls");
}
//结果评估
void evaluation()
{
    system("cls");
    wprintf(L"        ====== 即时评估 ======\n");
    wprintf(L"你需要提供8kHz纯音分贝阈值和测量的距离值\n");
    wprintf(L"\n");
    system("pause");
    system("cls");
    wprintf(L"             ====== 即时评估 ======\n");
    wprintf(L"====== 为减小误差，需要输入3次数据求平均值======\n");
    wprintf(L"\n");
    double result[3];
    double distance[3];
    double sum1 = 0;
    double sum2 = 0;
    for(int i=0;i<3;i++)
    {
        result[i]=0;
        distance[i]=0;
    }
    for(int i=0;i<3;i++)
    {
         while(1)
    {
        double dB;
        double seconds;
        // 获取用户输入
        wprintf(L"====第%d次数据收集====\n",i+1);
        wprintf(L"\n");
        wprintf(L"====建议从20dB开始递增测量====\n");
        wprintf(L"\n");
        wprintf(L"请输入分贝值（建议范围：0-90 dB）：");
        scanf("%lf", &dB);
        wprintf(L"请输入播放时间（秒）：");
        scanf("%lf", &seconds);
        // 调用封装的声音播放函数
        playSoundByDB(dB, seconds);
        wprintf(L"====是否继续测量分贝值====\n");
        wprintf(L"1.如果刚好听到可以退出\n");
        wprintf(L"2.如果没有听到请重新测量\n");
        wprintf(L"请输入：\n");
        int choice = 0;
        scanf("%d",&choice);
        if(choice==1)
        {
            system("cls");
            wprintf(L"\n");
            wprintf(L"====开始自行测量距离值====\n");
            system("pause");
            system("cls");
            break;
        }
        else if(choice==2)
        {
            system("cls");
            continue;
        }
        else{
            wprintf(L"输入错误\n");
            system("pause");
            system("cls");
            continue;
        }
    }
        wprintf(L"请输入第%d测量的分贝值,单位（dB）\n",i+1);
        scanf("%lf",&result[i]);
        sum1+=result[i];
        wprintf(L"请输入第%d测量的距离,单位（cm）\n",i+1);
        scanf("%lf",&distance[i]);
        sum2+=distance[i];
        system("\npause");
        system("cls");
    }
    double result_end = sum1/3;
    double distance_end = sum2/3;
    wprintf(L"====测量结果====\n");
    wprintf(L"平均分贝值为：%.2lf dB\n",result_end);
    wprintf(L"平均测量距离为： %.2lf cm\n",distance_end);
    system("\npause");
    system("cls");
    judgement(result_end,distance_end);
    system("\npause");
    system("cls");
    while(1)
    {
        int choice = 0;
        wprintf(L"====是否建立个人听力档案====\n");
        wprintf(L"1.建立档案\n");
        wprintf(L"2.不建立档案并退出\n");
        wprintf(L"请选择：\n");
        scanf("%d", &choice);
        struct personal_file *head_02 = head ;
        switch(choice) 
        {
            
            case 1: personal_file_make(result_end,distance_end, head_02);
                    return;
                    break;
            case 2: return;
                    break;
            default:
            wprintf(L"输入错误\n");
            system("pause");
            continue;
        }    
    }
    system("pause");
}
//根据测量的数据进行分析  db为测量的分贝值  distance为距离值
void judgement(double db,double distance)
{
    if(db<=63&&distance>=30)
    {
        wprintf(L"====评估结果====\n");
        wprintf(L"1.生理状态：听力正常\n");
        wprintf(L"2.建议:遵循60/60原则进行听力保护\n");
    }
    if((db>63&&db<=75)&&distance>=25)
    {
        wprintf(L"====评估结果====\n");
        wprintf(L"1.生理状态：正常范围\n");
        wprintf(L"2.建议:遵循60/60原则进行听力保护\n");
    }
   if((db>75&&db<=82)||distance<20)
    {
        wprintf(L"====评估结果====\n");
        wprintf(L"1.生理状态：噪声性听力疲劳\n");
        wprintf(L"2.建议:禁耳机48h + 补镁锌片\n");
    }
    if(db>82||distance<15)
    {
        wprintf(L"====评估结果====\n");
        wprintf(L"1.生理状态：急性声损伤\n");
        wprintf(L"2.建议:72h内就医 + 口服泼尼松\n");
    }

}
//尾插入法 添加链表节点  head01为头节点  name为输入的姓名 db为测量的分贝 dist为测量的距离
void add_node(struct personal_file * head01,wchar_t name[30],double db,double dist)
{
    struct personal_file *temp = head01;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct personal_file*fresh = (struct personal_file *)malloc(sizeof(struct personal_file));
    temp->next = fresh;
    fresh->count=0;
    *(fresh->db) = db;
    *(fresh->dist)=dist;
    wcscpy(fresh->name, name);
    fresh->next= NULL;
}
//查看名字是否在链表内存在  head01 为头节点   name 为姓名  返回值 1/0
int check_name(struct personal_file * head01,wchar_t name[30])
{
    struct personal_file *current = head01;
    while (current != NULL) {
        if (wcscmp(current->name, name) == 0) {
            return 1; 
        }
        current = current->next;
    }
    return 0;
};
//添加链表内已经存在的节点信息 head01为头节点  name为输入的姓名 db为测量的分贝 dist为测量的距离
void add_data(struct personal_file * head01,wchar_t name[30],double db,double dist)
{
    struct personal_file *temp = head01;
    while(!(wcscmp(temp->name, name) == 0))
    {
    
        temp=temp->next;
    }
    
    temp->count=(temp->count)+1;
    *((temp->db)+(temp->count)) = db;
    *((temp->dist)+(temp->count))=dist;
}
//个人档案建立模块  result_end 分贝  distance_end距离  head01头节点
void personal_file_make( double result_end,double distance_end,struct personal_file*head01)
{
    struct personal_file* temp = head01;
    wprintf(L"输入姓名\n");
    wchar_t  name[30];
    wscanf(L"%ls", name);
    if(check_name(temp,name))
    {
        add_data(temp,name,result_end,distance_end);
    }
    else
    {
        add_node(temp,name,result_end,distance_end);
    }

    wprintf(L"%ls录入成功\n",name);
    system("pause");
    system("cls");
};

//听力档案分析  head01头节点
void view_analysis(struct personal_file*head01)
{
        struct personal_file *temp = head01;
        system("cls");
        while(1) {
        int choice = 0;
        wprintf(L"====== 查看及分析听力档案======\n");
        wprintf(L"    1. 查看听力档案\n");
        wprintf(L"    2. 分析听力档案\n");
        wprintf(L"    请选择: ");
        wprintf(L"\n");
        scanf("%d", &choice);
        system("pause");
        system("cls");
        switch(choice) {
            case 1: view_file(temp);
                    return;
                    break;
            case 2: analysis_file(temp);
                    return;
                    break;
            default:
                wprintf(L"输入错误\n");
                system("pause");
                continue;
        }
    }
}
//听力档案打印  head01头节点
void view_file(struct personal_file * head01)
{
    struct personal_file * temp = head01;
    wprintf(L"请输入您的姓名：\n");
    wchar_t  name[30];
    wscanf(L"%ls", name);
    if(check_name(temp,name))
    {
         while ((temp->next) != NULL) {
        if (wcscmp(temp->name, name) == 0) {
            break;
        }
        temp = temp->next;
    }
    wprintf(L"======听力档案打印======\n");
    wprintf(L"姓名：%ls\n",temp->name);
    for(int i=0;i<=(temp->count);i++)
    {
        wprintf(L"第%d次数据为: \n",(i+1));
        wprintf(L"分贝阈值为:%.2lf dB\n",*((temp->db)+i));
        wprintf(L"测量距离为:%.2lf cm\n ",*((temp->dist)+i));
    }
    system("pause");
    }
    else
    {
        wprintf(L"抱歉您没有创建过个人听力档案\n");
        system("pause");
    }
}
//听力档案分析  head01头节点
void analysis_file(struct personal_file * head01)
{
    wprintf(L"======听力档案分析======\n");
    struct personal_file * temp = head01;
    wprintf(L"请输入您的姓名：\n");
    wchar_t  name[30];
    wscanf(L"%ls", name);
    if(check_name(temp,name))
    {
        wprintf(L"======周期性分析报告======\n");
        while (temp != NULL) {
        if (wcscmp(temp->name, name) == 0) {
            break;
        }
        temp = temp->next;
    }
        if(temp->count>=3)
        {
            double R1 = 0;
            double change = 0;
            for(int i=0;i<=temp->count;i++)
            {
                R1+=R(*((temp->db)+i),*((temp->dist)+i));
            }
            R1/=((temp->count)+1);
            wprintf(L"R值为:%lf\n",R1);
            if(R1<=8.5)
            {
                wprintf(L"听力处于安全区\n");
            }
            else if(R1>8.5&&R1<=9.8)
            {
                wprintf(L"听力处于关注区\n");
            }
            else if(R1>9.8&&R1<=11)
            {
                wprintf(L"听力处于警戒区\n");
            }
            else if(R1>11)
            {
                wprintf(L"听力处于危险区\n");
            }

            for(int i=0;i<=(temp->count)-1;i++)
            {
                change+=R(*((temp->db)+(i+1)),*((temp->dist)+(i+1))-R(*((temp->db)+i),*((temp->dist)+i)));
            }
            change/=(temp->count);
            change=abs(change);
            wprintf(L"R值平均变化率为:%lf\n",change);
            if(change<=0.15)
            {
                wprintf(L"正常生理波动/测试误差\n");
            }
            else if(change<=0.4&&change>0.15)
            {
                wprintf(L"可逆性听力疲劳\n");
            }
            else if(change>0.4)
            {
                wprintf(L"病理性损伤\n");
            }
            system("pause");
        }
        else
        {
        wprintf(L"抱歉您创建过个人听力档案少于三次，无法进行分析\n");
        system("pause");
        }
    }
    else
    {
        wprintf(L"抱歉您没有创建过个人听力档案，无法进行分析\n");
        system("pause");
    }
}
//系数计算  db分贝  distance距离
double R(double db,double distance)
{
    double temp = db/10 +25/distance;
    return temp;
}
// 计算最佳水温（℃）：冷藏蛋90℃防裂，常温蛋95℃提效
int calc_optimal_water_temp(int egg_state) {
    return (egg_state == 1) ? 90 : 95;
}

// 计算预热时间（分钟）：结合自定义功率、热效率、水量与初始水温
int calc_preheat_time(double water_volume, int target_temp, int init_water_temp, int stove_type, int power) {
    const double c_water = 4.2;       // 水的比热容(kJ/(kg·℃))
    double heat_need = c_water * water_volume * (target_temp - init_water_temp);
    
    // 不同炉灶的热效率
    double efficiency[] = {0.85, 0.60, 0.70};// 电磁炉/燃气灶/电陶炉
    double effective_power = power * efficiency[stove_type-1] / 60.0; // 转换为kJ/min
    
    // 若初始水温≥目标水温，无需预热
    if(heat_need <= 0) return 0;
    return (effective_power > 0) ? (int)(heat_need / effective_power) : 5;
}

// 计算煮制时间（分钟）：蛋规格+熟度+水温修正
int calc_cook_time(int egg_size, int target_done, int water_temp) {
    double base_time[] = {6.0, 9.0, 12.0};  // 中型蛋溏心/半熟/全熟基础时间
    double size_factor = (egg_size == 1) ? 0.8 : (egg_size == 2) ? 1.0 : 1.2;
    double temp_factor = (water_temp == 90) ? 1.3 : (water_temp == 95) ? 1.1 : 1.0;
    return (int)(base_time[target_done-1] * size_factor * temp_factor);
}
int initAudioDevice() {
    // 设置波形格式
    waveFormat.wFormatTag = WAVE_FORMAT_PCM;
    waveFormat.nChannels = 1;                // 单声道
    waveFormat.nSamplesPerSec = SAMPLE_RATE;
    waveFormat.wBitsPerSample = 16;          // 16位采样
    waveFormat.nBlockAlign = waveFormat.nChannels * waveFormat.wBitsPerSample / 8;
    waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
    waveFormat.cbSize = 0;

    // 打开波形输出设备
    if (waveOutOpen(&hWaveOut, WAVE_MAPPER, &waveFormat, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR) {
        printf("无法打开音频设备！\n");
        return 0;
    }

    return 1;
}

// 生成正弦波
void generateSineWave(double amplitude, int durationMs) {
    int samples = (int)((double)SAMPLE_RATE * durationMs / 1000.0);
    bufferSize = samples * waveFormat.nBlockAlign;
    buffer = (short *)malloc(bufferSize);

    if (buffer == NULL) {
        printf("内存分配失败！\n");
        return;
    }

    // 生成精确的8kHz正弦波
    double phase = 0.0;
    double phaseIncrement = 2 * PI * FREQUENCY / SAMPLE_RATE;
    
    for (int i = 0; i < samples; i++) {
        double sineValue = sin(phase);
        buffer[i] = (short)(amplitude * sineValue);
        phase += phaseIncrement;
        // 防止相位溢出
        if (phase > 2 * PI) {
            phase -= 2 * PI;
        }
    }
}

// 将分贝转换为振幅
double dBToAmplitude(double dB) {
    // 定义参考振幅（0分贝对应的值）
    // 参考振幅设为1.0，这样0分贝时声音很小，接近听不到
    double refAmplitude = 1.0;
    // 计算实际振幅：amplitude = refAmplitude * 10^(dB/20)
    return refAmplitude * pow(10.0, dB / 20.0);
}

// 播放音频
void playAudio() {
    // 准备波形数据头
    waveHeader.lpData = (LPSTR)buffer;
    waveHeader.dwBufferLength = bufferSize;
    waveHeader.dwBytesRecorded = 0;
    waveHeader.dwUser = 0;
    waveHeader.dwFlags = 0;
    waveHeader.dwLoops = 0;

    // 准备波形数据
    waveOutPrepareHeader(hWaveOut, &waveHeader, sizeof(WAVEHDR));
    // 写入波形数据到输出设备
    waveOutWrite(hWaveOut, &waveHeader, sizeof(WAVEHDR));
    // 等待播放完成
    while (waveOutUnprepareHeader(hWaveOut, &waveHeader, sizeof(WAVEHDR)) == WAVERR_STILLPLAYING) {
        Sleep(100);
    }
}

// 清理资源
void cleanup() {
    if (buffer != NULL) {
        free(buffer);
        buffer = NULL;
    }
    // 关闭波形输出设备
    waveOutClose(hWaveOut);
}

// 播放指定分贝和持续时间的声音
void playSoundByDB(double dB, double durationSeconds) {
    // 设置控制台为UTF-8模式
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 初始化音频设备
    if (!initAudioDevice()) {
        return;
    }

    // 将秒转换为毫秒
    int durationMs = (int)(durationSeconds * 1000);

    // 将分贝转换为振幅，限制最大振幅为32767
    double amplitude = dBToAmplitude(dB);
    if (amplitude > 32767.0) {
        amplitude = 32767.0;
    }

    // 生成正弦波
    generateSineWave(amplitude, durationMs);
    // 播放音频
    playAudio();
    // 清理资源
    cleanup();

    printf("音频播放完成！\n");
    printf("\n");
    system("pause");
    system("cls");
}
//主函数
int main()
{
    head = (struct personal_file *)malloc(sizeof(struct personal_file));
    head->next = NULL;
// 设置 stdout 为宽字符输出模式（避免中文输出乱码）
    _setmode(_fileno(stdout), _O_U16TEXT);  // 关键设置
    setlocale(LC_ALL, "");                  // 本地化支持
    main_menu();
    //free(head);
    return 0;
}