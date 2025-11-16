#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <strings.h>
#include <X11/Xlib.h>
#include <gdk/gdkdisplay.h>
#include "dock_config.h"

#define DOCK_HEIGHT 40

void set_dimension(GtkWidget *window){
    GdkDisplay *display = gdk_display_get_default();
    GdkMonitor *monitor = gdk_display_get_primary_monitor(display);

    GdkRectangle geo;
    gdk_monitor_get_geometry(monitor, &geo);

    gtk_window_set_default_size(GTK_WINDOW(window), geo.width, DOCK_HEIGHT);
    gtk_window_move(GTK_WINDOW(window), 0, geo.height - DOCK_HEIGHT);
}

void set_window_style(GtkCssProvider *provider, GtkWindow *window){
    GFile *css_file = g_file_new_for_path("style.css");
    GError *error = NULL;
    gtk_css_provider_load_from_file(provider, css_file, &error);
    if (error){
        g_print("failed to load styles");
        exit(3);
    }
    g_print("styles loaded");
    GtkStyleContext *win_context = gtk_widget_get_style_context(GTK_WIDGET(window));
    gtk_style_context_add_provider(
        win_context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER
    );
}
