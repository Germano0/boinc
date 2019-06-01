#ifndef USER_IDLE_TIME_DETECTION_H
#define USER_IDLE_TIME_DETECTION_H
#include <gio/gio.h>



#ifdef __cplusplus
extern "C" GDBusProxy* proxy;
#else
GDBusProxy* proxy;
#endif
#ifdef __cplusplus
extern "C" GDBusProxy* create_proxy();
#else
GDBusProxy* create_proxy();
#endif
#ifdef __cplusplus
extern "C" double get_user_idle_time();
#else
double get_user_idle_time();
#endif
#endif /* USER_IDLE_TIME_DETECTION_H */

