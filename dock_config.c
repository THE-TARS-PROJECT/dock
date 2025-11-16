#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <strings.h>
#include <X11/Xlib.h>
#include <gdk/gdkdisplay.h>
#include "dock_config.h"

void set_dimension(GtkWidget *window){
    GdkDisplay *display = gdk_display_get_default();
    GdkMonitor *monitor = gdk_display_get_primary_monitor(display);

    GdkRectangle geo;
    gdk_monitor_get_geometry(monitor, &geo);

    gtk_window_set_default_size(GTK_WINDOW(window), geo.width, 30);
}
