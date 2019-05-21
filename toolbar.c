#include <stdio.h>
#include <gtk/gtk.h>

static void show_about_dialog(GtkWidget *parent)
{
    gtk_show_about_dialog(GTK_WINDOW(parent), "program-name", "Demo",
                          "title", "About this demo",
                          "version", "1.2.0",
                          "comments", "Just a demo for Gtk2 IconView, Menubar and ToolBar.",
                          "license", "GPLv2",
                          "website", "https://github.com", NULL);
}

void toolbar_demo(void)
{
    GtkWidget *win, *vbox;
    GtkWidget *toolbar;
    GtkToolItem *item;

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(win), 300, 200);

    toolbar = gtk_toolbar_new();
    item = gtk_tool_button_new_from_stock("gtk-new");
    gtk_tool_item_set_tooltip_text(item, "Add New item");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), item, 0);

    item = gtk_tool_button_new_from_stock("gtk-about");
    gtk_tool_item_set_tooltip_text(item, "About me");
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), item, 1);

    g_signal_connect_swapped(item, "clicked", G_CALLBACK(show_about_dialog), win);


    vbox = gtk_vbox_new(FALSE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(win), vbox);

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);
}

