#include "gui/main_gui.h"
#include "module/config.h"
#include "clipboard/clipboard_helper.h"
#include  <iostream>

GtkWidget *list;
GtkWidget *label;

GtkTreeSelection *selection;


enum {
	LIST_ITEM = 0, N_COLUMNS
};

void init_list(GtkWidget *list) {

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkListStore *store;

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("List Items", renderer, "text", LIST_ITEM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

	store = gtk_list_store_new(N_COLUMNS, G_TYPE_STRING);

	gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));

	g_object_unref(store);
}

void add_to_list(GtkWidget *list, char *str) {
	GtkListStore *store;
	GtkTreeIter iter;

	store = GTK_LIST_STORE(gtk_tree_view_get_model (GTK_TREE_VIEW(list)));

	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, LIST_ITEM, g_locale_to_utf8(str,-1,0,0,0), -1);
}



void on_changed(GtkWidget *widget, gpointer label) {
	GtkTreeIter iter;
	GtkTreeModel *model;
	char *value;
	if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {
		gtk_tree_model_get(model, &iter, LIST_ITEM, &value, -1);
		gtk_label_set_text(GTK_LABEL(label), value);
		ClipboardHelper clipboard_helper;
		clipboard_helper.copy2Clipboard(value);
		g_free(value);
	}

}
int initList() {
	list = gtk_tree_view_new();
	gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(list), FALSE);

	gtk_box_pack_start(GTK_BOX(vbox), list, TRUE, TRUE, 5);

	label = gtk_label_new("");
	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
	gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 5);

	init_list(list);
	char* data[50] ;
	int length = loadListData(data);
	int i;
	for (i = 0; i < length; i++) {
		add_to_list(list, data[i]);
	}
	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
	g_signal_connect(selection, "changed", G_CALLBACK(on_changed), label);
	return 0;
}

