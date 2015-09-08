#include <gtk/gtk.h>
#include <string.h>

char buffer[256] = "0";

int num1, num2;
char operator = 0;

void append(char *string, gpointer label) {
	if (!strcmp(buffer, "0")) {
		strcpy(buffer, string);
	} else {
		strcat(buffer, string);
	}
	
	gtk_label_set_text(label, buffer);
}

void append_0(GtkWidget *widget, gpointer label) {
	append("0", label);
}

void append_1(GtkWidget *widget, gpointer label) {
	append("1", label);
}

void append_2(GtkWidget *widget, gpointer label) {
	append("2", label);
}

void append_3(GtkWidget *widget, gpointer label) {
	append("3", label);
}

void append_4(GtkWidget *widget, gpointer label) {
	append("4", label);
}

void append_5(GtkWidget *widget, gpointer label) {
	append("5", label);
}

void append_6(GtkWidget *widget, gpointer label) {
	append("6", label);
}

void append_7(GtkWidget *widget, gpointer label) {
	append("7", label);
}

void append_8(GtkWidget *widget, gpointer label) {
	append("8", label);
}

void append_9(GtkWidget *widget, gpointer label) {
	append("9", label);
}

void append_decimal(GtkWidget *widget, gpointer label) {
	append(".", label);
}

void divide(GtkWidget *widget, gpointer label) {
	if (!operator) {
		num1 = atoi(buffer);
		strcpy(buffer, "");
		operator = '/';
	}
}

void multiply(GtkWidget *widget, gpointer label) {
	if (!operator) {
		num1 = atoi(buffer);
		strcpy(buffer, "");
		operator = '*';
	}
}

void subtract(GtkWidget *widget, gpointer label) {
	if (!operator) {
		num1 = atoi(buffer);
		strcpy(buffer, "");
		operator = '-';
	}
}

void add(GtkWidget *widget, gpointer label) {
	if (!operator) {
		num1 = atoi(buffer);
		strcpy(buffer, "");
		operator = '+';
	}
}

void change_sign(GtkWidget *widget, gpointer label) {
	num2 = atoi(buffer) * -1;
	sprintf(buffer, "%d", num2);
	gtk_label_set_text(label, buffer);
}

void clear(GtkWidget *widget, gpointer label) {
	strcpy(buffer, "0");
	gtk_label_set_text(label, buffer);
}

void clear_all(GtkWidget *widget, gpointer label) {
	strcpy(buffer, "0");
	gtk_label_set_text(label, buffer);
	
	operator = 0;
}

void equals(GtkWidget *widget, gpointer label) {
	int new_num;

	if (operator) {
		num2 = atoi(buffer);
		
		switch (operator) {
			case '+':
				new_num = num1 + num2;
				break;
			case '-':
				new_num = num1 - num2;
				break;
			case '*':
				new_num = num1 * num2;
				break;
			case '/':
				new_num = num1 / num2;
				break;
		}
		
		operator = 0;
		sprintf(buffer, "%d", new_num);
		
		gtk_label_set_text(label, buffer);
	}
}

int main(int argc, char **argv) {
	GtkWidget *label;
	GtkWidget *window;
	GtkWidget *frame;
	
	// Buttons
	GtkWidget *button_7;
	GtkWidget *button_8;
	GtkWidget *button_9;
	GtkWidget *button_slash;
	GtkWidget *button_4;
	GtkWidget *button_5;
	GtkWidget *button_6;
	GtkWidget *button_asterisk;
	GtkWidget *button_1;
	GtkWidget *button_2;
	GtkWidget *button_3;
	GtkWidget *button_minus;
	GtkWidget *button_0;
	GtkWidget *button_decimal;
	GtkWidget *button_sign;
	GtkWidget *button_plus;
	GtkWidget *button_clear;
	GtkWidget *button_clear_all;
	GtkWidget *button_equals;
	
	int buttons_x = 20, buttons_y = 50;
	
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 195, 250);
	gtk_window_set_title(GTK_WINDOW(window), "Calculator");
	gtk_window_set_icon(GTK_WINDOW(window), gdk_pixbuf_new_from_file("/home/jeremy/Pictures/art/icons/a-e/calculator.png", NULL));
	
	frame = gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(window), frame);
	
	// Set up buttons
	button_7 = gtk_button_new_with_label("7");
	gtk_widget_set_size_request(button_7, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_7, buttons_x + 0, buttons_y + 0);
	
	button_8 = gtk_button_new_with_label("8");
	gtk_widget_set_size_request(button_8, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_8, buttons_x + 40, buttons_y + 0);
	
	button_9 = gtk_button_new_with_label("9");
	gtk_widget_set_size_request(button_9, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_9, buttons_x + 80, buttons_y + 0);
	
	button_slash = gtk_button_new_with_label("/");
	gtk_widget_set_size_request(button_slash, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_slash, buttons_x + 120, buttons_y + 0);
	
	button_4 = gtk_button_new_with_label("4");
	gtk_widget_set_size_request(button_4, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_4, buttons_x + 0, buttons_y + 40);
	
	button_5 = gtk_button_new_with_label("5");
	gtk_widget_set_size_request(button_5, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_5, buttons_x + 40, buttons_y + 40);
	
	button_6 = gtk_button_new_with_label("6");
	gtk_widget_set_size_request(button_6, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_6, buttons_x + 80, buttons_y + 40);
	
	button_asterisk = gtk_button_new_with_label("*");
	gtk_widget_set_size_request(button_asterisk, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_asterisk, buttons_x + 120, buttons_y + 40);
	
	button_1 = gtk_button_new_with_label("1");
	gtk_widget_set_size_request(button_1, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_1, buttons_x + 0, buttons_y + 80);
	
	button_2 = gtk_button_new_with_label("2");
	gtk_widget_set_size_request(button_2, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_2, buttons_x + 40, buttons_y + 80);
	
	button_3 = gtk_button_new_with_label("3");
	gtk_widget_set_size_request(button_3, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_3, buttons_x + 80, buttons_y + 80);
	
	button_minus = gtk_button_new_with_label("-");
	gtk_widget_set_size_request(button_minus, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_minus, buttons_x + 120, buttons_y + 80);
	
	button_0 = gtk_button_new_with_label("0");
	gtk_widget_set_size_request(button_0, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_0, buttons_x + 0, buttons_y + 120);
	
	button_decimal = gtk_button_new_with_label(".");
	gtk_widget_set_size_request(button_decimal, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_decimal, buttons_x + 40, buttons_y + 120);
	
	button_sign = gtk_button_new_with_label("+/-");
	gtk_widget_set_size_request(button_sign, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_sign, buttons_x + 80, buttons_y + 120);
	
	button_plus = gtk_button_new_with_label("+");
	gtk_widget_set_size_request(button_plus, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_plus, buttons_x + 120, buttons_y + 120);
	
	button_clear = gtk_button_new_with_label("C");
	gtk_widget_set_size_request(button_clear, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_clear, buttons_x + 0, buttons_y + 160);
	
	button_clear_all = gtk_button_new_with_label("CE");
	gtk_widget_set_size_request(button_clear_all, 35, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_clear_all, buttons_x + 40, buttons_y + 160);
	
	button_equals = gtk_button_new_with_label("=");
	gtk_widget_set_size_request(button_equals, 75, 35);
	gtk_fixed_put(GTK_FIXED(frame), button_equals, buttons_x + 80, buttons_y + 160);
	
	label = gtk_label_new("0");
	gtk_fixed_put(GTK_FIXED(frame), label, buttons_x + 0, buttons_y - 40);
	
	gtk_widget_show_all(window);
	
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	g_signal_connect(button_7, "clicked", G_CALLBACK(append_7), label);
	g_signal_connect(button_8, "clicked", G_CALLBACK(append_8), label);
	g_signal_connect(button_9, "clicked", G_CALLBACK(append_9), label);
	g_signal_connect(button_slash, "clicked", G_CALLBACK(divide), label);
	g_signal_connect(button_4, "clicked", G_CALLBACK(append_4), label);
	g_signal_connect(button_5, "clicked", G_CALLBACK(append_5), label);
	g_signal_connect(button_6, "clicked", G_CALLBACK(append_6), label);
	g_signal_connect(button_asterisk, "clicked", G_CALLBACK(multiply), label);
	g_signal_connect(button_1, "clicked", G_CALLBACK(append_1), label);
	g_signal_connect(button_2, "clicked", G_CALLBACK(append_2), label);
	g_signal_connect(button_3, "clicked", G_CALLBACK(append_3), label);
	g_signal_connect(button_minus, "clicked", G_CALLBACK(subtract), label);
	g_signal_connect(button_0, "clicked", G_CALLBACK(append_0), label);
	g_signal_connect(button_decimal, "clicked", G_CALLBACK(append_decimal), label);
	g_signal_connect(button_sign, "clicked", G_CALLBACK(change_sign), label);
	g_signal_connect(button_plus, "clicked", G_CALLBACK(add), label);
	g_signal_connect(button_clear, "clicked", G_CALLBACK(clear), label);
	g_signal_connect(button_clear_all, "clicked", G_CALLBACK(clear_all), label);
	g_signal_connect(button_equals, "clicked", G_CALLBACK(equals), label);
	
	gtk_main();
	
	return 0;
}
