#!/usr/bin/env bash

url="http://localhost:8080"

# Path to emsdk repo...
source ../emsdk/emsdk_set_env.sh 

emcc --bind -Oz cat.cc -o cat.js \
-s WASM=1 -s NO_EXIT_RUNTIME=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']" \
|| exit 1

case "$OSTYPE" in
  msys)
    start $url;;
  cygwin)
    cygstart $url;;
  darwin*)
    open $url;;
  *)
    xdg-open $url;;
esac
