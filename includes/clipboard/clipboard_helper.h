#ifndef CLIPBOARD_HELPER_H_
#define CLIPBOARD_HELPER_H_
#include <gtk/gtk.h>
#include <string.h>

class ClipboardHelper {
public:
	ClipboardHelper();
	void copy2Clipboard(gchar* value);
private:
	GtkClipboard* clipboard;
};
#endif /* CLIPBOARD_HELPER_H_ */
