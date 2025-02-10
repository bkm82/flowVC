#!/bin/sh
SCRIPT_DIR="$(dirname "$(realpath "$0")")"
emacs -Q --script $SCRIPT_DIR/build-site.el
