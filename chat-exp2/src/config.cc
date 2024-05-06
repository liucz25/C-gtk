#include "config.h"

TChat* ec_chat_new(const char* menu,int key,TFnChat fn){
    TChat* chat = (TChat*)g_malloc0(sizeof(TChat));
    chat->menu = g_strdup(menu);
    chat->key = key;
    chat->fn = fn;
    return chat;

}
TChat* ec_chat_take(char** menu,int key,TFnChat fn){
    TChat* chat = (TChat*)g_malloc0(sizeof(TChat));
    // chat->menu = *menu;
    // *menu = NULL;
    //等价于
    chat->menu = g_steal_pointer(menu);
    chat->key = key;
    chat->fn = fn;
    return chat;

}
void ec_chat_free(TChat* chat){
    if (!chat) return;
    g_free(chat->menu);
    g_free(chat);

}