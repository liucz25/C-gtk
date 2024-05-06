#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <cstdio>
#include <glib.h>
typedef void (*TFnChat)();
typedef struct {
    char* menu;
    int key;
    TFnChat fn;
}TChat;

TChat* ec_chat_new(const char* menu,int key,TFnChat fn);
TChat* ec_chat_take(const char** menu,int key,TFnChat fn);
void ec_chat_free(TChat* chat);




#endif