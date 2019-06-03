#ifndef USER_IDLE_TIME_DETECTION_H
#define USER_IDLE_TIME_DETECTION_H
#include <gio/gio.h>


#ifdef __cplusplus
extern "C" GDBusProxy* proxy;
extern "C" GDBusProxy* create_proxy();
extern "C" double get_user_idle_time();
#else
GDBusProxy* proxy;
GDBusProxy* create_proxy();
double get_user_idle_time();
#endif
#endif /* USER_IDLE_TIME_DETECTION_H */

