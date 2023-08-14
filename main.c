#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>

static void on_close_window() {
    gtk_main_quit();
}

static void usage() {
    puts("Usage: img [OPÇÃO]... [ARQUIVO]...");
    puts("A simple image viewer");
    puts("\n  --help  display this help and exit\n");
    puts("Examples:");
    puts("\n  img /path/to/file");
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        usage();

        return 0;
    }

    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "img");
    gtk_widget_show(window);
    g_signal_connect(window, "delete-event", G_CALLBACK(on_close_window), NULL);
    gtk_main();

    return  0;
}