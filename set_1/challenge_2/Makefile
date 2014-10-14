# base64 - crypto challange 1
# Makefile taken from suckless style.

include config.mk

HEADERS =
SRC = main.c xor.c hex_decode.c
OBJ = ${SRC:.c=.o}

all: options main

options:
	@echo ${PROG_NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "LD       = ${LD}"

%.o: %.c
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

main: ${OBJ}
	@echo LD $@
	@${LD} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f main ${OBJ} ${PROG_NAME}-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p ${PROG_NAME}-${VERSION}
	@cp -R Makefile LICENSE README config.mk ${SRC} ${HEADERS} ${PROG_NAME}-${VERSION}
	@tar -cf ${PROG_NAME}-${VERSION}.tar ${PROG_NAME}-${VERSION}
	@gzip ${PROG_NAME}-${VERSION}.tar
	@rm -rf ${PROG_NAME}-${VERSION}

.PHONY: all options clean dist
