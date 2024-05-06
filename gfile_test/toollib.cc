#include <cstdio>
#include <gio/gio.h>

extern "C"{
    void test_fn(){
        GFile* curr = g_file_new_for_path(".");
        GFile* child;
        GFileInfo* info;
        char* path = NULL;
        GFileEnumerator* enumerator = g_file_enumerate_children(curr,"standard::",G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS,NULL,NULL);
        while (g_file_enumerator_iterate(enumerator,&info,&child,NULL,NULL) && info && child){
            printf("path: %s\ninfo name: %s\ninfo size: %ld\n\n",g_file_get_path(child),g_file_info_get_name(info),g_file_info_get_size(info));
            g_free(path);
        }
        g_object_unref(enumerator);
        g_object_unref(curr);
    }
}