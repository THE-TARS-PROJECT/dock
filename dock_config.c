#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <strings.h>
#include <X11/Xlib.h>
#include "dock_config.h"
#include <gdk/x11/gdkx11display.h>

void set_dimension(GtkWidget *window){
    GdkDisplay *display = gdk_display_get_default();
    GListModel *monitors = gdk_display_get_monitors(display);

    GdkRectangle geo;
    gdk_monitor_get_geometry(g_list_model_get_item(monitors, 0), &geo);

    g_print("width: %d", geo.width);
    gtk_window_set_default_size(GTK_WINDOW(window), geo.width, 30);
}

void set_window_gravity_south(GtkWindow *window){
    // // Display *xdisplay = gdk_x11_display_get_xdisplay(display);
    // Display *xdisplay = GDK_DISPLAY_XDISPLAY(gdk_display_get_default());
    // if(!xdisplay){
    //     gprint("failed to get display");
    //     exit(2);
    // }

    // GdkSurface *surface = gtk_native_get_surface(GTK_NATIVE(window));
    // Window xwin = 
}
