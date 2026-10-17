#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

void ui_clear_screen(void);
void ui_pause_screen(void);
void ui_display_menu(void);
void ui_display_submenu(int);
void ui_display_header(const char *title);
void ui_display_notification(const char *notification);
int ui_get_valid_option(int min_option, int max_option);

#endif
