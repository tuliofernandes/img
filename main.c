#include <stdio.h>
#include <string.h>

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

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

    GtkWidget *window, *box, *image;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "img");
    gtk_widget_show(window);
    g_signal_connect(window, "delete-event", G_CALLBACK(on_close_window), NULL);

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);

    image = gtk_image_new();
    gtk_box_pack_start(GTK_BOX(box), image, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    if (argc > 1) {
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(argv[1], NULL);
        if (pixbuf != NULL) {
            gtk_image_set_from_pixbuf(GTK_IMAGE(image), pixbuf);
            g_object_unref(pixbuf);
        } else {
            // TODO: Show an error dialog
            g_print("Failed to load image\n");
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return  0;
}