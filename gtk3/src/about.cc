#include "about.h"

void onAboutClick(GtkWidget* btn,GtkWindow* parent){
	gtk_show_about_dialog(parent,"logo-icon-name","application-x-executable","program-name","meson expamle","version","0.0","comments","just a expamlae",NULL);

}

GtkWidget* exp3_insert_about_button(GtkWindow* parent){
	GtkWidget* btn = gtk_button_new_with_label("about");
	g_signal_connect(btn,"clicked",G_CALLBACK(onAboutClick),parent);
	return btn;
}
