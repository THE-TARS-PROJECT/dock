#include <stdio.h>
#include "x11_utils.h"
#include <stdlib.h>


static Display* connect_to_xserver(){

    Display *display = XOpenDisplay(NULL);

    if(!display){
        printf("cannot connect to x server");
        exit(5);
    }
    return display;
}


// https://tronche.com/gui/x/xlib/window-information/XQueryTree.html
void get_active_windows(){
    Display *display = connect_to_xserver();
    Window root_win = XDefaultRootWindow(display);
    if(!root_win){
        printf("failed to get root win\n");
        exit(19);
        
    }

    Window parent;
    Window *children;

    unsigned int *n;

    if(!XQueryTree(
        display,
        root_win, &root_win, &parent, &children, n
    )){
        printf("failed to list windows\n");
    }

    for(int i=0; i<n; i++){
        Window win = children[i];
        char *name = NULL;
        
        if(XFetchName(display, win, &name)){
            printf("failed to fetch names");
            XFree(name);
        }
    }

    XCloseDisplay(display);
}
