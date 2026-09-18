#include <stdio.h>

//若要关闭以下所有内容的文件中的警告，请使用警告杂注。此处关闭的是针对scanf的警告。
#pragma warning(disable : 4996)

typedef struct Student
{
    int id;
    char name[20];
    double score;
} Student;

// 指针修改结构体分数
void setScore(Student* s, double newSc)
{
    s->score = newSc;
}

// 求数组平均值
double getAverage(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return (double)sum / len;
}

int main(void)
{
    int nums[4] = { 75, 88, 91, 66 };
    Student stu = { 2001, "李四", 79.5 };

    printf("=== Visual Studio C测试程序 ===\n");

    printf("数组元素：");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", nums[i]);
    }
    double avg = getAverage(nums, 4);
    printf("\n数组平均值：%.2f\n", avg);

    printf("\n修改前学生：id=%d 姓名=%s 分数=%.1f\n", stu.id, stu.name, stu.score);
    setScore(&stu, 93.0);
    printf("指针修改后分数：%.1f\n", stu.score);

    int num;
    printf("\n请输入一个整数：");
    scanf("%d", &num);
    printf("你输入的数字：%d\n", num);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
