#include <gtk/gtk.h>

static void onActivate(GtkApplication* app,gpointer usd){
	GtkWidget* lab1 = gtk_label_new("hello from fedora");
	GtkWidget* win = gtk_application_window_new(app);
	gtk_window_set_child(GTK_WINDOW(win),lab1);
	gtk_window_present(GTK_WINDOW(win));
}

int main(int argc,char* argv[]){
	GtkApplication* app =gtk_application_new("org.warmsnow.fedora_exp1",G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app,"activate",G_CALLBACK(onActivate),NULL);
	return g_application_run(G_APPLICATION(app),argc,argv);
}
