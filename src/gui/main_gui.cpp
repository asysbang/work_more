#include "gui/main_gui.h"

int initGui(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	initWindow();
	initList();
	g_signal_connect(G_OBJECT (window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(window);

	gtk_main();
	return 0;
}

