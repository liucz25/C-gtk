#include <cstdio>
#include "config.h"
#include "hmm.h"
#include "lilei.h"
#include "missgao.h"

typedef struct {
    char* menu;
    int chatCnt;
    TChat** chats;
    GMainLoop* loop;
    GIOChannel* channel;
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
    app->loop = g_main_loop_new(NULL,FALSE);
    app->channel = g_io_channel_unix_new(fileno(stdin));
    return app;
}
static void ec_app_free(TCApp* app){
    if (!app)
        return;
    for (int i =0;i < app->chatCnt;i++){
        ec_chat_free(app->chats[i]);
    }
    g_free(app->menu);
    g_io_channel_shutdown(app->channel,FALSE,NULL);
    g_main_loop_unref(app->loop);
    g_free(app);
}
  
static gboolean ec_stdin_data(GIOChannel* channel,GIOCondition condition,TCApp* app){
    if (condition & G_IO_IN){
        char* input = NULL;
        unsigned long len = 0;
        if (g_io_channel_read_line(channel,&input,&len,NULL,NULL));
        printf("你输入了%ld个字符：%s\n",len-1,input);
        if (g_str_has_prefix(input,"0")){
            g_main_loop_quit(app->loop);
            return FALSE;
        }
        if (atoi(input) < 0||atoi(input) > app->chatCnt){
            printf("输入错误，请重试\n");
            
        }else{
            app->chats[atoi(input) -1]->fn();
        }    
        g_free(input);
    }
    return TRUE;
}

int main(int argc,char* agrv[]){
    TCApp* app = ec_app_new();
    printf("\n\n欢迎使用XXX,聊天系统\n请选择聊天对象\n");
    printf(app->menu);
    printf("请输入你的选择：\n");
    g_io_add_watch(app->channel,G_IO_IN,(GIOFunc)ec_stdin_data,app);
    // printf("ss%d",sid);
    // app->chats[sid-1]->fn();
    g_main_loop_run(app->loop);
    printf("感谢使用，祝你生活愉快!\n");
    ec_app_free(app);
    return 0;

}