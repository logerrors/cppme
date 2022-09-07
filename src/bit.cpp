#include <stdio.h>

#define BIT(x) (1<<x)

enum EnumTask{
  ETask1 = BIT(0),
  ETask2 = BIT(1),
  ETask3 = BIT(2),
  ETask4 = BIT(3),
  ETask5 = BIT(4),
  ETask6 = BIT(5),
  ETask7 = BIT(6),
  ETask8 = BIT(7),
  ETask9 = BIT(8),
  ETask10 = BIT(9)
};

int main(int argc, char* argv[]){
  unsigned int task  = 8;

  if(task & ETask7){ // check 1
    printf("task 7 done\n");
  }else{
    printf("task 7 not done\n");
    task = task | ETask7; // set 1
  }

  if(task & ETask7){
    printf("task 7 done\n");
 }

  return 0;
}