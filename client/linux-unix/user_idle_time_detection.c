#include <gio/gio.h>
#include "linux-unix/gnome/gnome_dbus_interface.h"
#include "linux-unix/user_idle_time_detection.h"
GDBusProxy* create_proxy()
{
    proxy = g_dbus_proxy_new_for_bus_sync (G_BUS_TYPE_SESSION,
	                                       G_DBUS_PROXY_FLAGS_NONE,
	                                       NULL,
	                                       GNOME_DBUS_SERVICE,
	                                       GNOME_DBUS_PATH_SETTINGS,
	                                       GNOME_DBUS_INTERFACE_SETTINGS,
	                                       NULL, NULL);
    return proxy;
}

double get_user_idle_time()
{
    guint64 user_idle_time;
    double user_idle_time_double;
    GError* error = NULL;
    GVariant* ret = NULL;
    // TODO
    // add check if(proxy == NULL)
    // add also code to free proxy resource when BOINC client is closed
    if(!proxy)
    {
        proxy = create_proxy();
    }
    
    ret = g_dbus_proxy_call_sync(proxy,
	                         GNOME_DBUS_METHOD_SETTINGS,
	                         NULL,
	                         G_DBUS_CALL_FLAGS_NONE, -1,
	                         NULL, &error);
    if (!ret)
    {
        g_dbus_error_strip_remote_error (error);
        g_print ("GetIdletime failed: %s\n", error->message);
        g_error_free (error);
        return;
    }

    g_variant_get(ret, "(t)", &user_idle_time);
    user_idle_time_double = (double)user_idle_time;
    g_variant_unref (ret);
    return user_idle_time_double;
}

