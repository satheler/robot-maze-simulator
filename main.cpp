#include <gtk/gtk.h>
#include "MainGL.h"

using namespace std;

int main()
{
    gtk_init(NULL, NULL);

    char *filename;
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    GtkWidget *dialog;

    //criando o filtro para arquivos txt
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter,"Maze txt");
    gtk_file_filter_add_pattern(filter,"*.txt");

    //criando o explorador de arquivos
    dialog = gtk_file_chooser_dialog_new("Choose a file",
                                         GTK_WINDOW(window),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_OK,
                                         GTK_RESPONSE_OK,
                                         GTK_STOCK_CANCEL,
                                         GTK_RESPONSE_CANCEL,
                                         NULL);

    //adicionando o filtro no explorador
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),filter);

    gtk_widget_show_all(dialog);

    gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), g_get_home_dir());
    gint resp = gtk_dialog_run(GTK_DIALOG(dialog));

    //verificando se foi clicado em ok ou se foi cancelada a seleção de arquivos
    if(resp == GTK_RESPONSE_OK)
    {
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    }
    else
    {
        g_print("You don't choose a file!\n");
    }

    gtk_widget_destroy(dialog);

    //convertendo o caminho do arquivo para string
    std::string filenameString(filename);

    //executando a ação principal do openGL maze
    MainGL::runGL(filenameString);

    gtk_main();

}
