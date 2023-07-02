dnl config.m4 for extension easy_science

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([easy_science],
dnl   [for easy_science support],
dnl   [AS_HELP_STRING([--with-easy_science],
dnl     [Include easy_science support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([easy_science],
  [whether to enable easy_science support],
  [AS_HELP_STRING([--enable-easy_science],
    [Enable easy_science support])],
  [no])

if test "$PHP_EASY_SCIENCE" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, EASY_SCIENCE_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-easy_science -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/easy_science.h"  # you most likely want to change this
  dnl if test -r $PHP_EASY_SCIENCE/$SEARCH_FOR; then # path given as parameter
  dnl   EASY_SCIENCE_DIR=$PHP_EASY_SCIENCE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for easy_science files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       EASY_SCIENCE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$EASY_SCIENCE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the easy_science distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-easy_science -> add include path
  dnl PHP_ADD_INCLUDE($EASY_SCIENCE_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-easy_science -> check for lib and symbol presence
  dnl LIBNAME=EASY_SCIENCE # you may want to change this
  dnl LIBSYMBOL=EASY_SCIENCE # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_EASY_SCIENCE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your easy_science library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $EASY_SCIENCE_DIR/$PHP_LIBDIR, EASY_SCIENCE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_EASY_SCIENCE_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your easy_science library.])
  dnl ],[
  dnl   -L$EASY_SCIENCE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(EASY_SCIENCE_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_EASY_SCIENCE, 1, [ Have easy_science support ])

  PHP_NEW_EXTENSION(easy_science, easy_science.c, $ext_shared)
fi
