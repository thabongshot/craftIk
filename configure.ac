#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([craftIk], [0.0-20130122], [craftik@cyrusian.com],[craftik],
        [http://craftIk.cyrusian.com])
AS_VAR_SET_IF(CC,
              [AS_VAR_SET(SET_CC,[yes])],
              [AS_VAR_SET(SET_CC,[no])]
)
AS_VAR_SET_IF(CFLAGS,
              [AS_VAR_SET(SET_CFLAGS,[yes])],
              [AS_VAR_SET(SET_CFLAGS,[no])]
)
AS_VAR_SET_IF(CPPFLAGS,
              [AS_VAR_SET(SET_CPPFLAGS,[yes])],
              [AS_VAR_SET(SET_CPPFLAGS,[no])]
)
AS_VAR_IF(DEBUG,[1],[AS_VAR_SET(SET_DEBUG,[yes])],[AS_VAR_SET(SET_DEBUG,[no])])
AC_ARG_ENABLE(debugging,
              [AC_HELP_STRING([--enable-debugging],
                              [Enable debugging. \
                               It will turn off optimization, \
                               add debugging symbols, \
                               and define DEBUG. \
                               You can treat as -g -O0 -DDEBUG. \
                               It will disabled by default.]
                              )
AC_HELP_STRING([--disable-debugging],
                              [Disable debugging. This is default.]
                             )
              ],
              [AS_VAR_IF(enable_debugging,[yes],
                         [AS_VAR_SET(SET_DEBUG,[yes])],
                         [AS_VAR_SET(SET_DEBUG,[no])]
                        )
              ]
)
AS_VAR_IF(SET_DEBUG,[yes],[AS_ECHO("@<:@craftIk@:>@Debugging enabled...")])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE([enable])
LT_INIT

# Checks for programs.
AC_PROG_AWK
AS_VAR_IF(SET_CFLAGS,[no],
          [AS_VAR_IF(SET_DEBUG,[no],
                     [AS_VAR_SET(CFLAGS,["-Wall -O2"])],
                     [AS_VAR_SET(CFLAGS,["-Wall -g -O0"])]
          )]
)
AC_CANONICAL_HOST
AS_ECHO("@<:@craftIk@:>@System $host detected...")
AS_CASE([$host_os],
        [linux*],[AC_PROG_CC([gcc clang cc])],
        [*bsd*],[AC_PROG_CC([clang gcc cc])],
        [darwin*],[AC_PROG_CC([clang gcc cc])],
        [*],[AC_PROG_CC]
)
AS_ECHO("@<:@craftIk@:>@Use $CC as C compiler...")
AS_VAR_IF(SET_CPPFLAGS,[no],
          [AS_VAR_IF(SET_DEBUG,[yes],
                     [AS_VAR_SET(CPPFLAGS,[-DDEBUG])]
          )]
)
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

# Compiler Options.
AS_VAR_IF(SET_CFLAGS,[yes],
          [AS_ECHO("@<:@craftIk@:>@Use $CFLAGS as compile option...")],
          [AX_CHECK_COMPILE_FLAG(-std=c11,
              [CFLAGS="$CFLAGS -std=c11"],
              [AX_CHECK_COMPILE_FLAG(-std=c1x,
                  [CFLAGS="$CFLAGS -std=c1x"],
                  [CFLAGS="$CFLAGS -std=c99"]
              )]
          )]
)
AS_ECHO("@<:@craftIk@:>@Compile using $CC $CPPFLAGS $CFLAGS on $host_os.")


# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK
#AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 src/Makefile])
AC_OUTPUT
