#include <cstdio>
#include "config.h"
#include "hmm.h"
#include "lilei.h"
#include "missgao.h"

typedef struct {
    char* menu;
    int chatCnt;
    TChat** chats;
    // GMainLoop* loop;
}TCApp;

static TCApp* ec_app_new(){
    TCApp* app = (TCApp*)g_malloc0(sizeof(TCApp));
    // app->chatCnt = 3;
    // app->chats = (TChat**)g_malloc0(sizeof(TChat*)*app->chatCnt);
    app->chats=g_new0(TChat*,app->chatCnt = 3);
    app->chats[0] = ec_chat_hanmeimei_new();
    app->chats[1] = ec_chat_lilei_new();
    app->chats[2] = ec_chat_missgao_new();
    app->menu = (char*)g_malloc0(1024);
    app->menu = g_strdup_printf("%s\n%s\n%s\n",app->chats[0]->menu,app->chats[1]->menu,app->chats[2]->menu);
    return app;
}
static void ec_app_free(TCApp* app){
    if (!app)
        return;
    for (int i =0;i < app->chatCnt;i++){
        ec_chat_free(app->chats[i]);
    }
    g_free(app->menu);
    g_free(app);
}
  
/*while true 作为主循环，下一版本 gmodule的loop作为主循环，能异步操作，不阻塞*/
int main(int argc,char* agrv[]){
    TCApp* app = ec_app_new();
    printf("\n\n欢迎使用XXX,聊天系统\n请选择聊天对象\n");
    printf(app->menu);
    printf("请输入你的选择：\n");
    int choice =0;
    while(true){
        scanf("%d",&choice);
        if (!choice)
            break;        
        if (choice<0||choice>3){
            printf("输入错误，请重试\n");
            continue;  
        }    
        app->chats[choice -1]->fn();
    }
    printf("感谢使用，祝你生活愉快!\n");
    ec_app_free(app);
    return 0;

}