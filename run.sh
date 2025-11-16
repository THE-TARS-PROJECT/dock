gcc main.c dock_config.c `pkg-config --cflags --libs gtk+-3.0 ` -o app -lX11
gcc x11_utils.c `pkg-config --cflags --libs gtk+-3.0 ` -o wm -lX11
./app &
./wm