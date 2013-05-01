
all: clean build

build:
	node-gyp --python /usr/bin/python2 configure build

clean:
	node-gyp --python /usr/bin/python2 configure clean
