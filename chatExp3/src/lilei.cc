#include "lilei.h"
static void ec_chat_lilei(){
//李雷
    printf("李雷：没看到我在和韩梅梅亲热吗？别在这里碍事。\n");
    printf("李雷拒绝跟你聊天，请重试。\n");
}
TChat* ec_chat_lilei_new(){
    return ec_chat_new("2.李雷",2,ec_chat_lilei);
}