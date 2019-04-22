#include "gui/main_gui.h"

GtkWidget *window;
GtkWidget *vbox;

GdkPixbuf *create_pixbuf(const gchar* filename) {
	GdkPixbuf *pixbuf;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf) {
		fprintf(stderr, "=====%s\n", error->message);
		g_error_free(error);
	}
	return pixbuf;
}

void show_about(GtkWidget *widget, gpointer label) {
	printf("===show_about\n");
	GtkWidget *dialog = gtk_about_dialog_new();
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "0.9");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Jan Bodnar");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Battery is a simple tool for battery checking.");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://www.batteryhq.net");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

const gchar * WINDOW_TITLE;

void initMenu() {

	GtkWidget *menubar;

	GtkWidget *filemenu, *edit_menu, *help_menu;

	GtkWidget *file, *quit;

	GtkWidget *edit, *edit_redo;
	GtkWidget *help, *about;
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new(); //菜单栏

	filemenu = gtk_menu_new(); //文件菜单项
	edit_menu = gtk_menu_new(); //编辑菜单项
	help_menu = gtk_menu_new(); //帮助菜单项

	file = gtk_menu_item_new_with_label("  File  "); //文件子条目
	quit = gtk_menu_item_new_with_label("Quit"); //退出子条目
	edit = gtk_menu_item_new_with_label("  Edit  ");
	edit_redo = gtk_menu_item_new_with_label("Redo");
	help = gtk_menu_item_new_with_label("  Help  ");
	about = gtk_menu_item_new_with_label("About");

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu); //将filemenu子菜单设置成file的条目
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit); //将quit加入到filemenu菜单
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file); //将file条目加入到menubar菜单
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), edit_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(edit_menu), edit_redo);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), help_menu); //将filemenu子菜单设置成file的条目
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu), about); //将quit加入到filemenu菜单
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help); //将file条目加入到menubar菜单
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 1);

	g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(G_OBJECT(about), "activate", G_CALLBACK(show_about), NULL);
}

int initWindow() {
	WINDOW_TITLE = "Make u work more"; //pwd;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 0);
	gtk_widget_set_size_request(window, 1024, 480);
	gtk_window_set_title(GTK_WINDOW(window), WINDOW_TITLE);
	gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("~/.workmore/img/icon.png"));
	initMenu();
	return 0;
}

