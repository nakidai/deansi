RM ?= rm -f
PREFIX ?= /usr/local/
BINDIR ?= ${PREFIX}/bin
MANDIR ?= ${PREFIX}/man


.PHONY: all
all: deansi

install: all
	install -d ${BINDIR} ${MANDIR}/man1
	install -m755 deansi ${BINDIR}
	install -m644 deansi.1 ${MANDIR}/man1

uninstall:
	${RM} ${BINDIR}/deansi
	${RM} ${MANDIR}/man1/deansi.1

.PHONY: clean
clean:
	${RM} deansi

README: deansi.1
	mandoc -Ios=deansi -Tascii deansi.1 | col -b > README
