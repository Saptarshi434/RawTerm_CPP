#include <menu.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

/********************-CLASS-**********************/

class SubMenu_Class {
 private:
 protected:
 public:
  enum colour {
    YELLOW = 11,
    BLUE,
    CYAN,
    RED,
    GREEN,
    MAGENTA,
  };

  enum log { enable_log = 21, disable_log };

  enum device { usb0 = 31, usb1, usb2, acm0, acm1 };

  enum time { enable_time = 41, disable_time };

  enum newline { enable_nl = 51, disable_nl };

  enum baudrate { br2400 = 61, br9600, br115200 };
} SubMenuObj;

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

/********************-CLASS-**********************/

class menu {
 private:
 protected:
 public:
  void display_menu() {}
};
/******************-FUNCTIONS-*********************/

/*********************-END-************************/

/********************-CLASS-**********************/

class colour : public menu {
 private:
  int markdown_colour = 0;

 protected:
 public:
  void change_clor_scheme(int i) {
    switch (i) {
      case 0:
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        break;

      case 1:
        init_pair(1, COLOR_BLUE, COLOR_BLACK);
        break;

      case 2:
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        break;

      case 3:
        init_pair(1, COLOR_RED, COLOR_BLACK);
        break;

      case 4:
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        break;

      case 5:
        init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
        break;
    }
  }
  int return_colourStatus() { return markdown_colour; }
  void menu_call(void);
};
/******************-FUNCTIONS-*********************/

/*********************-END-************************/

void menu_call(void);

/********************-CLASS-**********************/

class switch_class {
 private:
  colour clr_obj;

 protected:
 public:
  void switch_ClassMenu(int i) {
    switch (i) {
      case SubMenuObj.YELLOW:
        clr_obj.change_clor_scheme(0);
        break;

      case SubMenuObj.BLUE:
        clr_obj.change_clor_scheme(1);
        break;

      case SubMenuObj.CYAN:
        clr_obj.change_clor_scheme(2);
        break;

      case SubMenuObj.RED:
        clr_obj.change_clor_scheme(3);
        break;

      case SubMenuObj.GREEN:
        clr_obj.change_clor_scheme(4);
        break;

      case SubMenuObj.MAGENTA:
        clr_obj.change_clor_scheme(5);
        break;

      case SubMenuObj.enable_log:
        break;

      case SubMenuObj.disable_log:
        break;

      case SubMenuObj.usb0:
        break;

      case SubMenuObj.usb1:
        break;

      case SubMenuObj.usb2:
        break;

      case SubMenuObj.acm0:
        break;

      case SubMenuObj.enable_nl:
        break;

      case SubMenuObj.disable_nl:
        break;

      case SubMenuObj.br2400:
        break;

      case SubMenuObj.br9600:
        break;

      case SubMenuObj.br115200:
        break;
    }
  }
} MENU_Obj;

/******************-FUNCTIONS-*********************/

/*********************-END-************************/

ITEM* my_item[] = {
    new_item("Colour Scheme", " "), new_item("Device", " "),
    new_item("Time Stamp", " "),    new_item("Generate log", " "),
    new_item("Clear Screen", " "),  new_item("Baud Rate", " "),
    new_item("Send Newline", " "),  new_item("EXIT Console", " "),
    new_item("EXIT MENU", " "),     NULL};
ITEM* my_item1[] = {new_item("Yellow", " "), new_item("Blue", " "),
                    new_item("Cyan", " "),   new_item("Green", " "),
                    new_item("Red", " "),    new_item("Magenta", " "),
                    new_item("Exit", " "),   NULL};
ITEM* my_item2[] = {new_item("ttyACM0", " "),
                    new_item("ttyACM1", " "),
                    new_item("USB 0", " "),
                    new_item("USB 1", " "),
                    new_item("USB 2", " "),
                    new_item("Exit", " "),
                    NULL};
ITEM* my_item3[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};
ITEM* my_item4[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};
ITEM* my_item5[] = {new_item("2400", " "), new_item("9600", " "),
                    new_item("115200", " "), new_item("Exit", " "), NULL};
ITEM* my_item6[] = {new_item("Enable", " "), new_item("Disable", " "),
                    new_item("Exit", " "), NULL};

void setting(MENU*, WINDOW*, int);
void select(WINDOW*, MENU*, int, ITEM**, int);

void menu_call() {
  int i, c;
  ITEM* cur_item;
  WINDOW *my_menu_win, *my_menu_win1, *my_menu_win2, *my_menu_win3,
      *my_menu_win4, *my_menu_win5, *my_menu_win6;

  /* Initialize curses */
  initscr();
  start_color();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  colour colourfulObj;

  colourfulObj.change_clor_scheme(colourfulObj.return_colourStatus());
  init_pair(2, COLOR_GREEN, COLOR_BLACK);

  /* Initialize items */
  MENU* my_menu = new_menu(my_item);

  /* Set fore ground and back ground of the menu */
  set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(my_menu, COLOR_PAIR(2));
  set_menu_format(my_menu, 1, 9);
  menu_opts_off(my_menu, O_SHOWDESC);

  /*Create the window to be associated with the menu*/
  my_menu_win = newwin(5, 149, 0, 15);
  keypad(my_menu_win, TRUE);

  /*Set main window and sub window*/
  set_menu_win(my_menu, my_menu_win);
  set_menu_sub(my_menu, derwin(my_menu_win, 0, 0, 2, 1));
  set_menu_mark(my_menu, " * ");

  /* Post the menu */
  mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
  mvprintw(LINES - 2, 0, "Up,Down,Left & Right arrow keys to navigate ");
  post_menu(my_menu);
  refresh();
  wrefresh(my_menu_win);
  while (c = wgetch(my_menu_win)) switch (c) {
      case KEY_LEFT:
        menu_driver(my_menu, REQ_LEFT_ITEM);
        break;
      case KEY_RIGHT:
        menu_driver(my_menu, REQ_RIGHT_ITEM);
        break;
      case 10: /* Enter */
        move(20, 0);
        clrtoeol();
        mvprintw(20, 0, "Item selected is : %s",
                 item_name(current_item(my_menu)));
        if (!strncmp("EXIT MENU", item_name(current_item(my_menu)), 6)) {
          unpost_menu(my_menu);
          for (int i = 0; i < 9; ++i) free_item(my_item[i]);
          free_menu(my_menu);
          endwin();
          return;
        }

        else if (!strncmp("Col", item_name(current_item(my_menu)), 3))
          select(my_menu_win1, my_menu, 7, my_item1, 21);

        else if (!strncmp("Dev", item_name(current_item(my_menu)), 3))
          select(my_menu_win2, my_menu, 6, my_item2, 38);

        else if (!strncmp("Tim", item_name(current_item(my_menu)), 3))
          select(my_menu_win3, my_menu, 3, my_item3, 55);

        else if (!strncmp("Gen", item_name(current_item(my_menu)), 3))
          select(my_menu_win4, my_menu, 3, my_item4, 72);

        else if (!strncmp("Baud", item_name(current_item(my_menu)), 4))
          select(my_menu_win5, my_menu, 4, my_item5, 106);

        else if (!strncmp("Send", item_name(current_item(my_menu)), 4))
          select(my_menu_win6, my_menu, 3, my_item6, 123);
    }
}

void setting(MENU* m, WINDOW* w) {
  set_menu_fore(m, COLOR_PAIR(1) | A_REVERSE);
  set_menu_back(m, COLOR_PAIR(2));
  set_menu_format(m, 3, 1);
  menu_opts_off(m, O_SHOWDESC);
  keypad(w, TRUE);
  set_menu_win(m, w);
  set_menu_sub(m, derwin(w, 0, 12, 0, 0));
  set_menu_mark(m, " * ");
  post_menu(m);
  refresh();
  wrefresh(w);
}

void select(WINDOW* w, MENU* main_menu, int row, ITEM** it, int x_axis) {
  int d, flag = 0;

  unpost_menu(main_menu);
  MENU* m = new_menu(it);
  w = newwin(4, 16, 4, x_axis);
  setting(m, w);

  while (d = wgetch(w)) switch (d) {
      case KEY_UP:
        menu_driver(m, REQ_UP_ITEM);
        break;
      case KEY_DOWN:
        menu_driver(m, REQ_DOWN_ITEM);
        break;
      case 10:
        move(20, 0);
        clrtoeol();
        mvprintw(20, 0, "Item selected is : %s", item_name(current_item(m)));
        refresh();
        /*
         *
         */
        if (!strcmp(item_name(current_item(m)), "Yellow"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.YELLOW);
        if (!strcmp(item_name(current_item(m)), "Blue"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.BLUE);
        if (!strcmp(item_name(current_item(m)), "Cyan"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.CYAN);
        if (!strcmp(item_name(current_item(m)), "Green"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.GREEN);
        if (!strcmp(item_name(current_item(m)), "Red"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.RED);
        if (!strcmp(item_name(current_item(m)), "Magenta"))
          MENU_Obj.switch_ClassMenu(SubMenuObj.MAGENTA);
        if (!strncmp("Exit", item_name(current_item(m)), 4)) {
          werase(w);
          wrefresh(w);
          unpost_menu(m);
          for (int i = 0; i < row; ++i) free_item(it[i]);
          free_menu(m);
          post_menu(main_menu);
          flag = 1;
        }
        if (flag == 1) return;
        pos_menu_cursor(m);
    }
}
