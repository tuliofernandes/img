#include <stdio.h>

#include <gtk/gtk.h>

static void on_close_window() {
    gtk_main_quit();
}

int main(int argc, char **argv) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "img");
    gtk_widget_show(window);
    g_signal_connect(window, "delete-event", G_CALLBACK(on_close_window), NULL);
    gtk_main();

    return  0;
}