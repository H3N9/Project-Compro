#include "gtk/gtk.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


// Varible of Function save
static GtkWidget *income, *expense, *want, *day, *need, *ans_save, *ans_save2;

// Varible of Function save_money
static GtkWidget *percent, *year, *money, *ans2_save;

// Varible of Function save_long_money
static GtkWidget *percent_long, *money_long, *ans_long, *year_long;

GtkCssProvider *provide;
GdkDisplay *display;
GdkScreen *screen;

const gchar *style = "style.css";
GError *error = 0;

void save_calculate();
void save(GtkWidget *window);
void save_money(GtkWidget *window);
void save_money_calculate();
void save_long_money(GtkWidget *window);
void save_long_money_calculate();

int main(int argc, char **argv){
                          
    gtk_init(&argc, &argv); // IDK

    GtkWidget *window, *grid, *button1, *button2, *button3;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  //call css
    provide = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provide), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_css_provider_load_from_file(provide, g_file_new_for_path(style), &error);
    g_object_unref(provide);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    button1 = gtk_button_new_with_label("Saving");
    g_signal_connect(button1, "clicked", G_CALLBACK(save), NULL);
    gtk_grid_attach(GTK_GRID(grid), button1, 0,0,1,1);

    button2 = gtk_button_new_with_label("Deposit");
    g_signal_connect(button2, "clicked", G_CALLBACK(save_money), NULL);
    gtk_grid_attach(GTK_GRID(grid), button2, 0,1,1,1);

    button3 = gtk_button_new_with_label("Long Term Deposit");
    g_signal_connect(button3, "clicked", G_CALLBACK(save_long_money), NULL);
    gtk_grid_attach(GTK_GRID(grid), button3, 0,2,1,1);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

void save_calculate(){

	long selec1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(income)));
	long selec2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(expense)));
	long selec3 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(want)));
	long selec4 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(day)));
	long selec5 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(need)));

	long cap = ((selec1-selec2)*selec4);
    long want = cap+selec3;
	char wrong[100];

	if(cap<selec5+selec3){
		strcpy(wrong,"You lack : ");
		cap = selec5+selec3-cap;
	}
	else{
		strcpy(wrong,"You need: ");
	}


	char text[32], text2[32];
	snprintf(text, sizeof(text), " %s %ld per day.", wrong, (selec5+selec3)/selec4);
	snprintf(text2, sizeof(text2), "Total %s %ld Bath", wrong, selec5+selec3);

	gtk_label_set_text(GTK_LABEL(ans_save), text);
	gtk_label_set_text(GTK_LABEL(ans_save2), text2);
}

void save_money_calculate(){

	double selector1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(money)));
	long selector2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(year)));
	double selector3 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(percent)));

	selector3 = selector3/100.0+1;

	for(int i=1;i<=selector2;i++){
		selector1 = selector1*selector3;
	}


	char text[32];
	snprintf(text, sizeof(text), "Total: %.2lf Bath", selector1);

	gtk_label_set_text(GTK_LABEL(ans2_save), text);
}

void save_long_money_calculate(){

	double selector1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(money_long)));
	long selector2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(year_long)));
	double selector3 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(percent_long)));
	long keep = selector1;

	selector3 = selector3/100.0+1;

	for(int i=1;i<=selector2;i++){
		selector1 *= selector3;
		selector1 += i==selector2? 0:keep;
	}

	char text[32];
	snprintf(text, sizeof(text), "Total: %.2lf Bath", selector1);

	gtk_label_set_text(GTK_LABEL(ans_long), text);

}

void save(GtkWidget *window){

    GtkWidget *grid, *quit, *call;
    GtkWidget *bath1, *bath2, *bath3, *day_label2, *need_label2;
    GtkWidget *income_label, *want_label, *need_label, *day_label, *expense_label;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //set window app
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //if you quit window CMD will show command line
    gtk_window_set_title(GTK_WINDOW(window), "Application"); //set title
    gtk_window_set_default_size(GTK_WINDOW(window),300,300); // size of window
    gtk_container_set_border_width(GTK_CONTAINER(window), 150);


    grid = gtk_grid_new(); // set grid .. grid is button set
    gtk_container_add(GTK_CONTAINER(window), grid); // add grid to window

    quit = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(quit, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), quit, 2,8,1,1);

    income = gtk_entry_new();
    income_label = gtk_label_new("Income: ");
    bath1 = gtk_label_new("Bath");
    gtk_grid_attach(GTK_GRID(grid), income_label, 0,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), income, 1,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), bath1, 2,1,1,1);

    expense = gtk_entry_new();
    expense_label = gtk_label_new("Expense: ");
    bath2 = gtk_label_new("Bath");
    gtk_grid_attach(GTK_GRID(grid), expense_label, 0,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), expense, 1,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), bath2, 2,2,1,1);

    want = gtk_entry_new();
    want_label = gtk_label_new("Want: ");
    bath3 = gtk_label_new("Bath");
    gtk_grid_attach(GTK_GRID(grid), want_label, 0,3,1,1);
    gtk_grid_attach(GTK_GRID(grid), want, 1,3,1,1);
    gtk_grid_attach(GTK_GRID(grid), bath3, 2,3,1,1);

    day = gtk_entry_new();
    day_label = gtk_label_new("Day");
    day_label2 = gtk_label_new("Day: ");
    gtk_grid_attach(GTK_GRID(grid), day_label2, 0,4,1,1);
    gtk_grid_attach(GTK_GRID(grid), day, 1,4,1,1);
    gtk_grid_attach(GTK_GRID(grid), day_label, 2,4,1,1);

    need_label2 = gtk_label_new("Bath");
    need = gtk_entry_new();
    need_label = gtk_label_new("Need: ");
    gtk_grid_attach(GTK_GRID(grid), need_label, 0,5,1,1);
    gtk_grid_attach(GTK_GRID(grid), need, 1,5,1,1);
    gtk_grid_attach(GTK_GRID(grid), need_label2, 2,5,1,1);

    call = gtk_button_new_with_label("Process");
    g_signal_connect(call, "clicked", G_CALLBACK(save_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), call, 1,6,1,1);

    ans_save = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), ans_save, 1,8,1,1);

    ans_save2 = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), ans_save2, 1,9,1,1);

    gtk_widget_show_all(window); //show window
    gtk_main(); // call loop function
}

void save_money(GtkWidget *window){

	GtkWidget *grid, *call, *quit;
	GtkWidget *year_label, *money_label, *percent_label;
	GtkWidget *year_label2, *money_label2, *percent_label2;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //set window app
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //if you quit window CMD will show command line
    gtk_window_set_title(GTK_WINDOW(window), "Application"); //set title
    gtk_container_set_border_width(GTK_CONTAINER(window), 150);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    money = gtk_entry_new();
    money_label = gtk_label_new("Money: ");
    money_label2 = gtk_label_new("Bath");
    gtk_grid_attach(GTK_GRID(grid), money, 1,0,1,1);
    gtk_grid_attach(GTK_GRID(grid), money_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), money_label2, 2, 0, 1, 1);


    year = gtk_entry_new();
    year_label = gtk_label_new("Year: ");
    year_label2 = gtk_label_new("Year");
    gtk_grid_attach(GTK_GRID(grid), year, 1,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), year_label, 0,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), year_label2, 2,1,1,1);

    percent = gtk_entry_new();
    percent_label = gtk_label_new("Interest: ");
    percent_label2 = gtk_label_new("%");
    gtk_grid_attach(GTK_GRID(grid), percent, 1,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), percent_label, 0,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), percent_label2, 2,2,1,1);

    call = gtk_button_new_with_label("Calculate");
    g_signal_connect(call, "clicked", G_CALLBACK(save_money_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), call, 1,3,1,1);

    ans2_save = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), ans2_save, 1,4,1,1);

    quit = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(quit, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), quit, 2,4,1,1);

    gtk_widget_show_all(window);
    gtk_main();
}

void save_long_money(GtkWidget *window){

	GtkWidget *grid, *call, *quit;
	GtkWidget *money_long_label, *year_long_label, *percent_long_label;
	GtkWidget *money_long_label2, *year_long_label2, *percent_long_label2;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //set window app
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //if you quit window CMD will show command line
    gtk_window_set_title(GTK_WINDOW(window), "Application"); //set title
    gtk_container_set_border_width(GTK_CONTAINER(window), 150);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    money_long = gtk_entry_new();
    money_long_label = gtk_label_new("Money: ");
    money_long_label2 = gtk_label_new("Bath");
    gtk_grid_attach(GTK_GRID(grid), money_long, 1,0,1,1);
    gtk_grid_attach(GTK_GRID(grid), money_long_label, 0,0,1,1);
    gtk_grid_attach(GTK_GRID(grid), money_long_label2, 2,0,1,1);

    year_long = gtk_entry_new();
    year_long_label = gtk_label_new("Year: ");
    year_long_label2 = gtk_label_new("Year");
    gtk_grid_attach(GTK_GRID(grid), year_long, 1,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), year_long_label, 0,1,1,1);
    gtk_grid_attach(GTK_GRID(grid), year_long_label2, 2,1,1,1);

    percent_long = gtk_entry_new();
    percent_long_label = gtk_label_new("Interest: ");
    percent_long_label2 = gtk_label_new("%");
    gtk_grid_attach(GTK_GRID(grid), percent_long, 1,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), percent_long_label, 0,2,1,1);
    gtk_grid_attach(GTK_GRID(grid), percent_long_label2, 2,2,1,1);

    call = gtk_button_new_with_label("Calculate");
    g_signal_connect(call, "clicked", G_CALLBACK(save_long_money_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), call, 1,3,1,1);

    ans_long = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), ans_long, 1,4,1,1);

    quit = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(quit, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), quit, 2,4,1,1);

    gtk_widget_show_all(window);
    gtk_main();
}