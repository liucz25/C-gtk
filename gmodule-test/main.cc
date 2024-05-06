#include <cstdio>
#include <gmodule.h>

typedef void (*TFn)();

int main(int argc,char* argv[]){
    GModule* module = g_module_open("./toollib.so",G_MODULE_BIND_LAZY);
    TFn fn =NULL;
    if (!module){
        printf("模块加载失败：%s\n",g_module_error());
    }
    if (!g_module_symbol(module,"test_fn",(gpointer*)&fn)){
        printf("获取函数地址失败：%s\n",g_module_error());
        g_module_close(module);
        return -1;
    }
    fn();
    g_module_close(module);
    return 0;
}