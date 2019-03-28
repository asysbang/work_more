

#ifndef MAIN_GUI_H_
#define MAIN_GUI_H_
#include <gtk/gtk.h>

extern GtkWidget *window;
extern GtkWidget *list;
extern GtkWidget *vbox;
extern char * pwd;

int initGui(int argc, char *argv[]);
int initWindow();
int initList();

#endif /* MAIN_GUI_H_ */
