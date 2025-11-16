#include <gtk/gtk.h>
#include <stdbool.h>
#include "dock_config.h"
// #include "x11_utils.h"

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gint layout_spacing = 4;

    set_dimension(window);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    gtk_window_set_gravity(GTK_WINDOW(window), GDK_GRAVITY_SOUTH);

    GtkCssProvider *provider = gtk_css_provider_new();
    set_window_style(provider, window);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, layout_spacing);
    gtk_container_add(GTK_CONTAINER(window), box);

    GtkWidget *btn = gtk_button_new_with_label("TARS");
    gtk_widget_set_hexpand(btn, FALSE);
    gtk_widget_set_margin_start(GTK_WIDGET(btn), 10);
    gtk_widget_set_margin_top(GTK_WIDGET(btn), 6);
    gtk_widget_set_margin_bottom(GTK_WIDGET(btn), 6);

    GtkWidget *search_box = gtk_entry_new();
    gtk_widget_set_hexpand(GTK_WIDGET(search_box), TRUE);
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_box), "Search....");
    gtk_widget_set_margin_start(GTK_WIDGET(search_box), 10);
    gtk_widget_set_margin_top(GTK_WIDGET(search_box), 6);
    gtk_widget_set_margin_bottom(GTK_WIDGET(search_box), 6);

    // box holding date above and text below
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    GtkWidget *date_label = gtk_label_new_with_mnemonic("16 Nov 2025");
    GtkWidget *time_label = gtk_label_new_with_mnemonic("18:37");

    gtk_widget_set_halign(GTK_WIDGET(vbox), GTK_ALIGN_END);

    gtk_box_pack_start(GTK_BOX(vbox), date_label, FALSE, FALSE, 3);
    gtk_box_pack_start(GTK_BOX(vbox), time_label, FALSE, FALSE, 3);

    gtk_box_pack_start(GTK_BOX(box), btn, FALSE, FALSE, 6);
    gtk_box_pack_start(GTK_BOX(box), search_box, TRUE, TRUE, 6);
    gtk_box_pack_start(GTK_BOX(box), vbox, TRUE, TRUE, 6);

    gtk_widget_show_all(window);
}


int main(int argc, char **argv) {
    // get_active_windows();
    
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.cooper.dock", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
