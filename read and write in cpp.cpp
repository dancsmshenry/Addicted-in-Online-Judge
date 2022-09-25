#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
}

// 单组输入
void test1()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    {
        int a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}

// 多组输入数据，且不说明多少组，直到读至输入文件末尾为止
void test2()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }

    {
        int a, b;
        while (cin >> a >> b)
        {
            cout << a + b << endl;
        }
    }
}

// 多组输入数据，不说明多少组，以某特殊输入为结束标志
void test3()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        printf("%d\n", a + b);
    }

    {
        int a, b;
        while (cin >> a >> b)
        {
            if (a == 0 && b == 0)
                break;
            cout << a + b << endl;
        }
    }
}

// 多组输入数据，开始输入一个T，接下来是T组数据
void test4()
{
    int T;
    int a, b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", a + b);
    }

    {
        int T;
        int a, b;
        cin >> T;
        while (T--)
        {
            cin >> a >> b;
            cout << a + b << endl;
        }
    }
}

void test5()
{
    // 每个字符串中不含空格、制表符及回车
    char str[10];
    scanf("%s", str); // scanf函数读入字符串时，是以空格、制表符及回车作为不同字符串之间的分隔符的

    // 字符串中含有空格、制表符，但不含回车
    {
        char str[10];
        gets(str); //   gets函数读入字符串时，只以回车作为不同字符串之间的分隔符；另外，如果要用gets读入多个字符串，可以写成 while(gets(str)){......}
    }

    // 字符串中有回车，一边读一遍判断分界条件是否满足
    {
        char *ch;
        scanf("%c", &ch);
    }

    // 输出空行，\n，或者endl都可以
}

void test6() {
    // 保留x位小数
    // printf("%.xf\n",ans);
    // 比如说：printf("%.6f\n",ans);

    // 没有说明要求保留几位，但要求与结果的误差不大于1e-x;
    // printf("%.(x+3)f\n",ans);
    // 比如说：要求与结果的误差不大于1e-9 : printf("%.12f\n",ans);
}