# gtk3-helloworld-mingw
A GTK3 example that works on MinGW(for now)

Main changes from https://www.gtk.org/docs/getting-started/hello-world

1. `gtk_window_set_child` did not exist, needed to use `gtk_container_add` instead, with lpWindow gtk-cast to GTK_CONTAINER, rather than GTK_WINDOW.
2. had to try different pkg-config combinations, `pkg config --cflags gtk+-3.0 --libs gtk+-3.0` ended up working.
3. Added hungarian notation because I felt like it.
4. Split long lines into multiple lines to be easier to visually parse.
