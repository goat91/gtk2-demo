#include <stdio.h>
#include <gtk/gtk.h>

void menubar_demo(void)
{
    GtkWidget *win, *icon_view, *vbox;
    GdkPixbuf *pixbuf;
    GtkWidget *menubar, *menuitem, *menuitem2;
    GtkWidget *menu;

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(win), 300, 200);

    menubar = gtk_menu_bar_new();

    menuitem = gtk_menu_item_new_with_label("File");
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

    menu = gtk_menu_new();
    menuitem2 = gtk_image_menu_item_new_from_stock("gtk-new", NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem2);
    menuitem2 = gtk_image_menu_item_new_from_stock("gtk-quit", NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem2);
    g_signal_connect(menuitem2, "activate", G_CALLBACK(gtk_main_quit), NULL);

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);

    vbox = gtk_vbox_new(FALSE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(win), vbox);

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);
    return 0;
}
