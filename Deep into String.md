# 模拟字符串

### 394、字符串解码

### 93、复原IP地址

### 71、简化路径

### 17、电话号码的字母组合



# 字符串匹配算法

### 28、实现strstr



# 高精度加减乘除

### 415、字符串相加



### 43、字符串相乘







# 常用函数

- isdigit，判断是不是数字

- isalpha，判断是不是字母

- substr，切割字符串

  - ```cpp
    stirng s1 = "0123456789";
    string s2 = s1.substr(4);//只有一个参数的话，默认开始的位置就是4（下标），然后一直到最后一位（是包含开始位置的）
    //456789
    
    string s3 = s1.substr(1, 3);//默认开始的位置是1（下标），长度是3
    //123
    
    string s4 = s1.substr();//没有参数的话，就是整个字符串了
    //0123456789
    ```

- string可以当作char一样操作

  - ```cpp
    string s1 = "sdfse";
    string s2 = "";
    s1 += s2[3];
    if (s1[0] == 's') {
        cout << "---------" << endl;
    }
    ```

- stoi，将字符串转换为数字

  - ```cpp
    string s1 = "123";
    int number = stoi(s1);//超过z
    ```

- erase，删除字符

  - ```cpp
    string s1 = "0123456789";
    s1.erase(1);//从下标1的位置开始删除，直到结尾
    
    s1.erase(2, 3);//从下标2的位置，删除3个字符
    
    s1.erase(s1.begin() + 1);//删除下标为10的位置的字符
    
    s1.erase(s1.begin() + 10， s1.end());//删除下标10后面所有的字符
    
    s1.erase(s1.begin(), s1.begin() + 1);//删除第一个元素，即[begin, begin + 1)
    ```

- to_string，数字转字符串

  - ```cpp
    string s1 = to_string()
    ```

  - 