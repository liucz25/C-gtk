#include "hmm.h"
static void ec_chat_hanmeimei(){
    //韩梅梅
    printf("韩梅梅：臭男人，滚开。\n");
    printf("韩梅梅拒绝跟你聊天，请重试。\n");
}
TChat* ec_chat_hanmeimei_new(){
    return ec_chat_new("1.韩梅梅",1,ec_chat_hanmeimei);
}