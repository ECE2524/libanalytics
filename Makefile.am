ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh
AM_CPPFLAGS = -I$(top_srcdir)/lib

lib_LTLIBRARIES = lib/libstreamtoken.la lib/libanalytics.la

lib_libstreamtoken_includes = lib/stream_tokens.h
lib_libstreamtoken_la_SOURCES = lib/stream_tokens.c

lib_libanalytics_includes = lib/analytics.h lib/word_list.h lib/word_map.h
lib_libanalytics_la_LIBADD = lib/libstreamtoken.la
lib_libanalytics_la_SOURCES = lib/split_words.c lib/word_list.c lib/word_map.c lib/count_words.c lib/sort_counted_words.c

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = analytics.pc

include_HEADERS = $(lib_libanalytics_includes) $(lib_libstreamtoken_includes)

noinst_PROGRAMS = bin/stream_token bin/split_words bin/count_words 

LDADD = lib/libstreamtoken.la  lib/libanalytics.la

bin_stream_token_SOURCES = test/stream_token.c
bin_split_words_SOURCES = test/split_words.c
bin_count_words_SOURCES = test/count_words.c
