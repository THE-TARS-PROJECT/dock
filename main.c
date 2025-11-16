#include <gtk/gtk.h>
#include "dock_config.h"
#include "x11_utils.h"

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    set_dimension(window);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);
    gtk_window_set_gravity(GTK_WINDOW(window), GDK_GRAVITY_SOUTH);

    GtkCssProvider *provider = gtk_css_provider_new();
    set_window_style(provider, window);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    get_active_windows();
    
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.cooper.dock", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
