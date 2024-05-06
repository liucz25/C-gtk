#include "missgao.h"
static void ec_chat_missgao(){
    //miss Gao
    printf("？？？：ya! movo plade!Biat ye!\n");
    printf("连接出现异常，请重试。\n");
}
TChat* ec_chat_missgao_new(){
    return ec_chat_new("3.missGao",2,ec_chat_missgao);
}