bin_PROGRAMS = xarasvgfilter xarasvgfilterui

# Note TOPDIR seems to have one too many ".."s in to work. So don't use it
if LOCAL_XARLIB_ENABLE
# note includes are built, so no need to refer to topdir
XARLIB_CFLAGS2 = -DEXCLUDE_FROM_XARLIB -DUSE_NATIVE_XLONG -DBUILDSHADOWS -DOLD_MATRIX_TRANSFORMATIONS -DVECTOR_STROKING -DEXCLUDE_FROM_XARLIB -DNEW_SHADOW_RENDER -DNO_XARACMS \
				-DNEW_FEATURES -DSHOWPORTNOTE -DDO_EXPORT \
				-I../../xarlib/include $(WX_CXXFLAGS)
XARLIB_LIBS2 = -L../../xarlib -lXar
else
XARLIB_CFLAGS2 =
XARLIB_LIBS2 =
endif

# the application source, library search path, and link libraries
xarasvgfilter_SOURCES = svgfilter.cpp svgfilter.h import.cpp svgimporter.cpp \
		    svgimporter.h export.cpp utils.cpp utils.h styles.cpp \
		    styles.h gradients.cpp gradients.h trans.cpp trans.h \
		    xargenerator.cpp xargenerator.h version.h
xarasvgfilter_CPPFLAGS = $(XARLIB_CFLAGS2) $(LIBXML2_CFLAGS) $(XARLIB_CFLAGS)
xarasvgfilter_LDADD = $(XARLIB_LIBS2) $(LIBXML2_LIBS) $(XARLIB_LIBS)

xarasvgfilterui_SOURCES = svgfilterui.cpp svgfilterui.h svgexportdialog.cpp \
		      svgexportdialog.h version.h
xarasvgfilterui_CPPFLAGS = $(XARLIB_CFLAGS) $(XARLIB_CFLAGS2) $(LIBXML2_CFLAGS)
xarasvgfilterui_LDADD = $(XARLIB_LIBS) $(XARLIB_LIBS2) $(LIBXML2_LIBS)

EXTRA_DIST = svgfilterui.pjd svgfilter.xml svgfilterc.xml \
	     batchconvert.sh \
	     images/*.png samples/*.xar \
	     tests/*.svg tests/*.dia tests/*.el tests/*.sh \
	     openclipart/*.svg

install-data-local:
	mkdir -p $(DESTDIR)$(prefix)/share/xaralx/filters/
	$(INSTALL_DATA) $(srcdir)/svgfilter.xml $(DESTDIR)$(prefix)/share/xaralx/filters
	$(INSTALL_DATA) $(srcdir)/svgfilterc.xml $(DESTDIR)$(prefix)/share/xaralx/filters

uninstall-local:
	rm -f $(DESTDIR)$(prefix)/share/xaralx/filters/svgfilter.xml
	rm -f $(DESTDIR)$(prefix)/share/xaralx/filters/svgfilterc.xml
