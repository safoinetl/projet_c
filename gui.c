#include <gtk/gtk.h>
#include "reglog.c"

GtkWidget *window1, *emailLabel, *emailEntry, *PasswordLabel, *PasswordEntry, *signupBtn, *alert, *signIn, *grid;
GtkApplication *app;
GtkWidget *namelabel, *lastnamelabel, *usernamelabel, *passlab, *aletsginin;
GtkWidget *name, *lastname, *username, *userpass, *adduser, *gobacktologin;

GtkWidget *poggers;

int test = 0;
static void activate(GtkApplication *app, gpointer user_data);
static void logged_in(GtkButton *butt, gpointer boxes);

void signup_button_clicked(GtkWidget *wid, gpointer data)
{
     const gchar *emailData = gtk_entry_get_text(GTK_ENTRY(emailEntry));
     const gchar *passData = gtk_entry_get_text(GTK_ENTRY(PasswordEntry));
     int a = login(emailData, passData);
     if (a == 1)
     {
          g_signal_connect(wid, "clicked", G_CALLBACK(logged_in), data);
          int *pt = &test;
          *pt = 1;
     }
     else
     {
          gtk_label_set_text(GTK_LABEL(alert), "Login failed");
     }
}
void signin_button_clicked(GtkWidget *wid, gpointer data)
{
     const gchar *Name = gtk_entry_get_text(GTK_ENTRY(name));
     const gchar *Pass = gtk_entry_get_text(GTK_ENTRY(lastname));
     const gchar *Uname = gtk_entry_get_text(GTK_ENTRY(username));
     const gchar *Upass = gtk_entry_get_text(GTK_ENTRY(userpass));

     int test = registration(Name, Pass, Uname, Upass);
     if (test == 1)
     {
          gtk_label_set_text(GTK_LABEL(aletsginin), "user added");
     }
     else
     {
          gtk_label_set_text(GTK_LABEL(aletsginin), "something went wrong");
     }
}
void go_sigin_in_button(GtkWidget *wid, gpointer data)
{
     gtk_widget_hide(emailLabel);
     gtk_widget_hide(emailEntry);
     gtk_widget_hide(PasswordLabel);
     gtk_widget_hide(PasswordEntry);
     gtk_widget_hide(signupBtn);
     gtk_widget_hide(signIn);
     gtk_widget_hide(alert);

     gtk_widget_show(namelabel);
     gtk_widget_show(name);
     gtk_widget_show(lastnamelabel);
     gtk_widget_show(lastname);
     gtk_widget_show(usernamelabel);
     gtk_widget_show(username);
     gtk_widget_show(passlab);
     gtk_widget_show(userpass);
     gtk_widget_show(adduser);
     gtk_widget_show(gobacktologin);
     gtk_widget_show(aletsginin);
}
void goback_sigin_in_button(GtkWidget *wid, gpointer data)
{
     gtk_widget_show(emailLabel);
     gtk_widget_show(emailEntry);
     gtk_widget_show(PasswordLabel);
     gtk_widget_show(PasswordEntry);
     gtk_widget_show(signupBtn);
     gtk_widget_show(signIn);
     gtk_widget_show(alert);

     gtk_widget_hide(namelabel);
     gtk_widget_hide(name);
     gtk_widget_hide(lastnamelabel);
     gtk_widget_hide(lastname);
     gtk_widget_hide(usernamelabel);
     gtk_widget_hide(username);
     gtk_widget_hide(passlab);
     gtk_widget_hide(userpass);
     gtk_widget_hide(adduser);
     gtk_widget_hide(gobacktologin);
     gtk_widget_hide(aletsginin);
}

static void activate(GtkApplication *app, gpointer user_data)
{

     window1 = gtk_application_window_new(app);
     GtkWidget *box;
     box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
     gtk_window_set_title(GTK_WINDOW(window1), "User Input");
     gtk_window_set_default_size(GTK_WINDOW(window1), 500, 600);

     emailLabel = gtk_label_new("Email:");
     emailEntry = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry), "Email");
     GIcon *mailicon;
     GFile *pathIconMail;
     pathIconMail = g_file_new_for_path("mail.png");
     mailicon = g_file_icon_new(pathIconMail);
     gtk_entry_set_icon_from_gicon(GTK_ENTRY(emailEntry), GTK_ENTRY_ICON_PRIMARY, mailicon);

     PasswordLabel = gtk_label_new("Password:");
     PasswordEntry = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(PasswordEntry), "Password");
     gtk_entry_set_visibility(GTK_ENTRY(PasswordEntry), FALSE);
     GIcon *passicon;
     GFile *pathIconpass;
     pathIconpass = g_file_new_for_path("password.png");
     passicon = g_file_icon_new(pathIconpass);
     gtk_entry_set_icon_from_gicon(GTK_ENTRY(PasswordEntry), GTK_ENTRY_ICON_PRIMARY, passicon);

     signupBtn = gtk_button_new_with_label("login");
     alert = gtk_label_new("");

     g_signal_connect(signupBtn, "clicked", G_CALLBACK(signup_button_clicked), box);

     signIn = gtk_button_new_with_label("Sign up");

     g_signal_connect(signIn, "clicked", G_CALLBACK(go_sigin_in_button), box);

     gtk_box_pack_start(GTK_BOX(box), emailLabel, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), emailEntry, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), PasswordLabel, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), PasswordEntry, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), signupBtn, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), signIn, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), alert, FALSE, FALSE, 0);

     gtk_container_add(GTK_CONTAINER(window1), box);
     gtk_widget_show_all(window1);

     // singup part

     namelabel = gtk_label_new("First name:");

     name = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(name), "First name");

     lastnamelabel = gtk_label_new("Last name:");

     lastname = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(lastname), "Last name");

     usernamelabel = gtk_label_new("Username:");

     username = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(username), "Username");

     passlab = gtk_label_new("Password:");

     userpass = gtk_entry_new();
     gtk_entry_set_placeholder_text(GTK_ENTRY(userpass), "Password");
     gtk_entry_set_visibility(GTK_ENTRY(userpass), FALSE);

     adduser = gtk_button_new_with_label("sign up");
     g_signal_connect(adduser, "clicked", G_CALLBACK(signin_button_clicked), box);

     gobacktologin = gtk_button_new_with_label("Go back to login");
     g_signal_connect(gobacktologin, "clicked", G_CALLBACK(goback_sigin_in_button), box);

     aletsginin = gtk_label_new(" ");

     gtk_box_pack_start(GTK_BOX(box), namelabel, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), name, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), lastnamelabel, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), lastname, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), usernamelabel, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), username, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), passlab, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), userpass, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), adduser, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), gobacktologin, FALSE, FALSE, 0);
     gtk_box_pack_start(GTK_BOX(box), aletsginin, FALSE, FALSE, 0);
}

static void logged_in(GtkButton *butt, gpointer boxs)
{
     gtk_container_remove(GTK_CONTAINER(window1), boxs);

     gtk_window_set_title(GTK_WINDOW(window1), "Welcome");
     gtk_window_set_default_size(GTK_WINDOW(window1), 500, 600);

     GtkWidget *box;
     box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);

     poggers = gtk_label_new("you are logged in");

     gtk_box_pack_start(GTK_BOX(box), poggers, FALSE, FALSE, 0);
     gtk_container_add(GTK_CONTAINER(window1), box);
     gtk_widget_show_all(window1);
}

int main(int argc, char **argv)
{

     int status;
     app = gtk_application_new("com.test", G_APPLICATION_FLAGS_NONE);
     g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
     status = g_application_run(G_APPLICATION(app), argc, argv);
     g_object_unref(app);
     return status;
}