// #include <stdio.h>
// // #include "x11_utils.h"
// #include <stdlib.h>


// static Display* connect_to_xserver(){

//     Display *display = XOpenDisplay(NULL);

//     if(!display){
//         printf("cannot connect to x server");
//         exit(5);
//     }
//     return display;
// }


// // https://tronche.com/gui/x/xlib/window-information/XQueryTree.html
// void get_active_windows() {
    
//     Display *display = connect_to_xserver(); // implement connection to X server
//     Window root = XDefaultRootWindow(display);

//     Window root_return;
//     Window parent_return;
//     Window *children_return = NULL;
//     unsigned int nchildren_return;

//     if (XQueryTree(display, root, &root_return, &parent_return, &children_return, &nchildren_return)) {
//         if (children_return) {
//             char *name = NULL;
//             for (unsigned int i=0; i<nchildren_return; i++){
//                 Window w = children_return[i];
//                 if (XFetchName(display, w, &name)){
//                     printf("%s \n", name);
//                     XFree(name);
//                 }
//             }
//         }
//     } else {
//         printf("failed to get list\n");
//     }
// }
