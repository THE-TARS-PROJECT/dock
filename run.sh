gcc main.c x11_utils.c dock_config.c `pkg-config --cflags --libs gtk+-3.0 ` -o app -lX11
./app