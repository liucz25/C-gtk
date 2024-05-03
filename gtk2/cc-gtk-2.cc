#include <gtk/gtk.h>

static void onActivate(GtkApplication* app,gpointer usd){
	GtkWidget* lab1 = gtk_label_new("hello from fedora");
	GtkWidget* lab2 = gtk_label_new("gou jian gong ju");
	GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
	gtk_box_append(GTK_BOX(box),lab1);
	gtk_box_append(GTK_BOX(box),lab2);
	GtkWidget* win = gtk_application_window_new(app);
	gtk_window_set_child(GTK_WINDOW(win),box);
	gtk_window_present(GTK_WINDOW(win));
}

int main(int argc,char* argv[]){
	GtkApplication* app =gtk_application_new("org.warmsnow.fedora_exp1",G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(app,"activate",G_CALLBACK(onActivate),NULL);
	return g_application_run(G_APPLICATION(app),argc,argv);
}
