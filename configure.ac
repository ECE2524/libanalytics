AC_INIT([wordfreq], [0.2.0], [dmaczka@vt.edu])

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wportability -Wall -Werror subdir-objects])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
AC_LIBTOOL_WIN32_DLL
LT_INIT
AC_PROG_CC
AC_PROG_CC_C89
AM_PROG_CC_C_O
AC_C_CONST
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([lib/analytics.h])
AC_CONFIG_FILES([Makefile analytics.pc])
AC_OUTPUT
