#include <gtk/gtk.h>

void iconview_demo() {
    GtkWidget *win, *icon_view, *vbox;
    GtkListStore *store;
    GtkTreeIter iter;
    GdkPixbuf *pixbuf;

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(win), 300, 200);

    pixbuf = gdk_pixbuf_new_from_file("/tmp/test.bmp", NULL);

    store = gtk_list_store_new(2, G_TYPE_STRING, GDK_TYPE_PIXBUF);
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "locale", 1, pixbuf, -1);
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, "locale2", 1, pixbuf, -1);

    icon_view = gtk_icon_view_new();
    gtk_icon_view_set_model(GTK_ICON_VIEW(icon_view), GTK_TREE_MODEL(store));
    gtk_icon_view_set_text_column(GTK_ICON_VIEW(icon_view), 0);
    gtk_icon_view_set_pixbuf_column(GTK_ICON_VIEW(icon_view), 1);

    vbox = gtk_vbox_new(FALSE, 0);

    gtk_box_pack_end(GTK_BOX(vbox), icon_view, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(win), vbox);

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);

}



