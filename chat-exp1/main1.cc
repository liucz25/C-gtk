#include <cstdio>

int main(int argc,char* agrv[]){
    printf("欢迎使用XXX,聊天系统\n请选择聊天对象\n");
    printf("1、韩梅梅\n2、李雷\n3、miss Gao \n0、退出\n");
    printf("请输入你的选择：\n");
    int choice =0;
    while(true){
        scanf("%d",&choice);
        if (!choice){
            printf("感谢使用，祝你生活愉快!\n");
            return 0;
        }
        if (1==choice){
            //韩梅梅
            printf("韩梅梅：臭男人，滚开。\n");
            printf("韩梅梅拒绝跟你聊天，请重试。\n");
        }else if(2==choice){
            //李雷
            printf("李雷：没看到我在和韩梅梅亲热吗？别在这里碍事。\n");
            printf("李雷拒绝跟你聊天，请重试。\n");
        }else if(3==choice){
            //miss Gao
            printf("？？？：ya! movo plade!Biat ye!\n");
            printf("连接出现异常，请重试。\n");
        }else{
            printf("输入错误，请重试\n");
        }
    }




    return 0;

}