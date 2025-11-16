#include <stdio.h>
#include <X11/Xlib.h>
#include <gtk/gtk.h>
#include <X11/Xatom.h>

/* 
my plan:
intercept events, get window names when they are opened or closed
define a struct with name and icon
add when open
remove when closed
highlight when focused 
*/

struct App{
    GString name;
    GString icon_path;
};

char* app[100] = {};
int ele_count = 0;

void add_window(Display *display, Window window){
    Atom prop = XInternAtom(display, "_NET_WM_WINDOW_TYPE", False);
    Atom actual_type;
    int actual_format;
    unsigned long nitems, bytes_after_return;
    unsigned char *data = NULL;

    if(XGetWindowProperty(
        display, window, prop, 0, 32, False, XA_ATOM,
        &actual_type, &actual_format, &nitems, &bytes_after_return, &data
    ) == Success){
        Atom *types = (Atom*)data;
        for (unsigned long i = 0; i<nitems; i++){
            char *type_name = XGetAtomName(display, types[i]);
            printf("Window name: %s\n", type_name);
            app[ele_count++] = type_name;
            XFree(type_name);
        }
    }

    if(data){
        XFree(data);
    }
}

int main(){
    Display *display = XOpenDisplay(NULL);
    if (!display){
        printf("failed to connect to xserver");
    }

    Window root_win = XDefaultRootWindow(display);
    if(!root_win){
        printf("failed to get the root window");
    }
    int screen = XDefaultScreen(display);


    XEvent event;
    while(1){
        XNextEvent(display, &event);
        switch(event.type){
            case MapRequest:
                printf("map request incoming");
                add_window(display, event.xmaprequest.window);
                XMapWindow(display, event.xmaprequest.window);
        }
    }

    return 0;
}
