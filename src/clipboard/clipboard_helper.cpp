#include "clipboard/clipboard_helper.h"

ClipboardHelper::ClipboardHelper(){
	this->clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
}

void ClipboardHelper::copy2Clipboard(gchar* value) {
	gtk_clipboard_set_text(this->clipboard, value, strlen(value));
}
