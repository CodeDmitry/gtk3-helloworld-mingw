/**
 * @file example.c
 * Based on https://www.gtk.org/docs/getting-started/hello-world.
 */
#include <gtk/gtk.h>

static void print_hello (
    GtkWidget *lpWidget,
    gpointer lpData )
{
    g_print("Hello World\n");
}

static void activate (
    GtkApplication *lpApp,
    gpointer lpUserData )
{
    GtkWidget *lpWindow;
    GtkWidget *lpButton;

    lpWindow = gtk_application_window_new(lpApp);
    gtk_window_set_title (
        GTK_WINDOW(lpWindow), 
        "Window"
    );
  
    gtk_window_set_default_size(
        GTK_WINDOW(lpWindow), 
        200, 
        200
    );

    lpButton = gtk_button_new_with_label("Hello World");
    
    g_signal_connect (
        lpButton, 
        "clicked", 
        G_CALLBACK(print_hello), 
        NULL
    );
    
    gtk_container_add (
        GTK_CONTAINER(lpWindow), 
        lpButton
    );

    gtk_window_present(GTK_WINDOW(lpWindow));
}


int main(int argc, char **argv) {
    GtkApplication *lpApp = (GtkApplication *)0;
    int appRunResult = 0;

    lpApp = gtk_application_new(
        "org.gtkmm.example.HelloApp", 
        G_APPLICATION_FLAGS_NONE
    );
    
    lpApp = gtk_application_new (
        "org.gtk.example", 
        G_APPLICATION_FLAGS_NONE
    );
    
    g_signal_connect (
        lpApp, 
        "activate", 
        G_CALLBACK(activate), 
        NULL
    );
    
    appRunResult = g_application_run (
        G_APPLICATION(lpApp), 
        argc, 
        argv
    );

    g_object_unref(lpApp);

    return 0;
}
