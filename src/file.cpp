#include <stdio.h>
#include "icecream.hpp"

int main(int argc, char const *argv[])
{
    // write file string
    FILE* fp = fopen("txt", "w");
    if(fp == nullptr){
        printf("open failed\n");
    }else{
        printf("open ok\n");
        int rc = fputc('h', fp);
        if(rc == EOF){
            printf("write char failded\n");
        }else{
            printf("write char  ok\n");
        }

        rc = fputs("hello world", fp);
        if(rc == EOF){
            printf("write str failed\n");
        }
        fclose(fp);
    }

    // read file string
    
    fp = fopen("txt", "r");
    if(fp == nullptr){
        printf("open failed\n");
    }else{
        printf("open ok\n");
        char rc = fgetc(fp);
        if(rc == EOF){ // 没法区分读取失败还是读到的就是 -1 这种情况
            printf("read char failed\n");
        }else{
            printf("read char ok: %c \n", rc);
        }

        while(!feof(fp)){
            char line[100] = {0};
            fgets(line, sizeof(line), fp);
            printf("read content: %s \n", line);
        }
        fclose(fp);
    }

    // write file struct
    struct stu{
        char name[30];
        int age;
        double score;
    };

    struct stu students[2] = {
        {"张三 abc", 21, 92.1},
        {"李四 def", 19, 86.2}
    };

    fp = fopen("bin", "wb");
    if(fp == nullptr){
        printf("open failed\n");
    }else{
        constexpr int students_len = sizeof(students);
        int ret = fwrite(students, sizeof(struct stu), 2, fp);
        if(ret == EOF){
            printf("write struct failed\n");
        }else{
            printf("write struct ok: %d \n", ret);
        }
        fclose(fp);
    }

    // read file struct
    fp = fopen("bin", "rb");
    struct stu students_new[2];
    if(fp == nullptr){
        printf("open failed\n");
    }else{
        int ret = fread(students_new, sizeof(struct stu), 2, fp);
        if(ret == EOF){
            printf("read struct failed\n");
        }else{
            printf("read struct ok: %d \n", ret);
        }
        IC(students_new);
        fclose(fp);
    }

    return 0;
}
