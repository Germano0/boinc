#ifndef USER_IDLE_TIME_DETECTION_H
#define USER_IDLE_TIME_DETECTION_H
#include <gio/gio.h>
#include "gnome/gnome_dbus_interface.h"

GDBusProxy* proxy = NULL;
GDBusProxy* create_proxy();
double get_user_idle_time();
#endif /* USER_IDLE_TIME_DETECTION_H */

